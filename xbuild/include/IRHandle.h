//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_IRHANDLE_H
#define XBUILD_IRHANDLE_H

#include <string>
#include <vector>

#include "IntrusivePtr.h"
#include "Expr.h"

#define ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
#define NODE_TYPE(name)  \
    static const IRNodeType _node_type = IRNodeType::name;\

namespace xbuild {

    enum TypeCode : uint8_t {
        TYPE_INT = 0, //signed integers
        TYPE_UINT = 1, // unsigned integers
        TYPE_FLOAT = 2, // floating point numbers
        TYPE_HANDLE = 3, // opaque pointer type (void *)
    };

    struct Type_t {
        ATTRIBUTE_ALIGN(1) TypeCode code;
        ATTRIBUTE_ALIGN(1) uint8_t bits;
        ATTRIBUTE_ALIGN(2) uint16_t lanes;

        Type_t(TypeCode code, uint8_t bits, uint16_t lanes = 1) : code(code), bits(bits), lanes(lanes) {

        }

        Type_t() : code((TypeCode) 0), bits(0), lanes(0) {

        }

        bool operator==(const Type_t &other) const {
            return (code == other.code &&
                    bits == other.bits &&
                    lanes == other.lanes);
        }

        bool operator!=(const Type_t &other) const {
            return !(*this == other);
        }

        int bytes() const { return (bits + 7) / 8; }
    };

    struct cplusplus_type_name {
        enum CPPTypeType {
            Simple, ///< "int"
            Struct, ///< "struct Foo"
            Class,  ///< "class Foo"
            Union,  ///< "union Foo"
            Enum,   ///< "enum Foo"
        } cpp_type_type;  // Note: order is reflected in map_to_name table in CPlusPlusMangle.cpp

        std::string name;

        cplusplus_type_name(CPPTypeType cpp_type_type, const std::string &name)
                : cpp_type_type(cpp_type_type), name(name) {
        }

        bool operator==(const cplusplus_type_name &rhs) const {
            return cpp_type_type == rhs.cpp_type_type &&
                   name == rhs.name;
        }

        bool operator!=(const cplusplus_type_name &rhs) const {
            return !(*this == rhs);
        }

        bool operator<(const cplusplus_type_name &rhs) const {
            return cpp_type_type < rhs.cpp_type_type ||
                   (cpp_type_type == rhs.cpp_type_type &&
                    name < rhs.name);
        }
    };

    struct handle_cplusplus_type {
        cplusplus_type_name inner_name;
        std::vector<std::string> namespaces;
        std::vector<cplusplus_type_name> enclosing_types;

        enum Modifier : uint8_t {
            Const = 1 << 0,    ///< Bitmask flag for "const"
            Volatile = 1 << 1, ///< Bitmask flag for "volatile"
            Restrict = 1 << 2, ///< Bitmask flag for "restrict"
            Pointer = 1 << 3,  ///< Bitmask flag for a pointer "*"
        };

        /// Qualifiers and indirections on type. 0 is innermost.
        std::vector<uint8_t> cpp_type_modifiers;

        enum ReferenceType : uint8_t {
            NotReference = 0,
            LValueReference = 1, // "&"
            RValueReference = 2, // "&&"
        };
        ReferenceType reference_type;

        handle_cplusplus_type(const cplusplus_type_name &inner_name,
                              const std::vector<std::string> &namespaces = {},
                              const std::vector<cplusplus_type_name> &enclosing_types = {},
                              const std::vector<uint8_t> &modifiers = {},
                              ReferenceType reference_type = NotReference)
                : inner_name(inner_name),
                  namespaces(namespaces),
                  enclosing_types(enclosing_types),
                  cpp_type_modifiers(modifiers),
                  reference_type(reference_type) {}

        template<typename T>
        static const handle_cplusplus_type make();
    };

    class Expr;

    struct Type {
    private:
        Type_t type;

    public:
        static const TypeCode Int = TYPE_INT;
        static const TypeCode UInt = TYPE_UINT;
        static const TypeCode Float = TYPE_FLOAT;
        static const TypeCode Handle = TYPE_HANDLE;
        const handle_cplusplus_type *handle_type;

        Type() : type(Handle, 0, 0) {}

        Type(const Type_t &that, const handle_cplusplus_type *handle_type = nullptr)
                : type(that), handle_type(handle_type) {

        }

        Type(TypeCode code, int bits, int lanes, const handle_cplusplus_type *handle_type = nullptr)
                : type(code, (uint8_t) bits, (uint16_t) lanes), handle_type(handle_type) {
        }

        Type with_code(TypeCode new_code) const {
            return Type(new_code, bits(), lanes(),
                        (new_code == code()) ? handle_type : nullptr);
        }

        Type with_bits(int new_bits) const {
            return Type(code(), new_bits, lanes(),
                        (new_bits == bits()) ? handle_type : nullptr);
        }

        Type with_lanes(int new_lanes) const {
            return Type(code(), bits(), new_lanes, handle_type);
        }

        bool is_bool() const {
            return code() == UInt && bits() == 1;
        }

        int bytes() const {
            return (bits() + 7) / 8;
        }

        bool is_vector() const {
            return lanes() != 1;
        }

        bool is_scalar() const { return lanes() == 1; }

        bool is_float() const { return code() == Float; }

        bool is_int() const { return code() == Int; }

        bool is_uint() const { return code() == UInt; }

        bool is_handle() const { return code() == Handle; }

        bool same_handle_type(const Type &other) const {
            return false;
        };

        bool operator==(const Type &other) const {
            return code() == other.code() && bits() == other.bits() && lanes() == other.lanes() &&
                   (code() != Handle || same_handle_type(other));
        }

        bool operator!=(const Type &other) const {
            return code() != other.code() || bits() != other.bits() || lanes() != other.lanes() ||
                   (code() == Handle && !same_handle_type(other));
        }

        bool operator<(const Type &other) const {
            return code() < other.code() || (code() == other.code() &&
                                             (bits() < other.bits() || (bits() == other.bits() &&
                                                                        (lanes() < other.lanes() ||
                                                                         (lanes() == other.lanes() &&
                                                                          (code() == Handle &&
                                                                           handle_type < other.handle_type))))));
        }


        Type element_of() const {
            return with_lanes(1);
        }

        bool can_represent(Type other) const;

        bool can_represent(double x) const;

        bool can_represent(int64_t x) const;

        bool can_represent(uint64_t x) const;

        bool is_max(uint64_t) const;

        bool is_max(int64_t) const;

        bool is_min(uint64_t) const;

        bool is_min(int64_t) const;

        Expr max() const;

        Expr min() const;


        TypeCode code() const {
            return type.code;
        }

        int bits() const {
            return type.bits;
        }

        int lanes() const {
            return type.lanes;
        }

    };

    inline Type Int(int bits, int lanes = 1) {
        return Type(Type::Int, bits, lanes);
    }

    inline Type UInt(int bits, int lanes = 1) {
        return Type(Type::UInt, bits, lanes);
    }

    inline Type Float(int bits, int lanes = 1) {
        return Type(Type::Float, bits, lanes);
    }

    inline Type Bool(int lanes = 1) {
        return UInt(1, lanes);
    }

    inline Type Handle(int lanes = 1, const handle_cplusplus_type *handle_type = nullptr) {
        return Type(Type::Handle, 64, lanes, handle_type);
    }

    template<class T>
    const handle_cplusplus_type *handle_traits() {
        if (std::is_pointer<T>::value ||
            std::is_lvalue_reference<T>::value ||
            std::is_rvalue_reference<T>::value) {
            static const handle_cplusplus_type the_info = handle_cplusplus_type::make<T>();
            return &the_info;
        }
        return nullptr;
    }

    template<typename T>
    inline Type type_of() {
        return Type(Type_t(TYPE_HANDLE, 64), handle_traits<T>());
    }


}

#endif //XBUILD_IRHANDLE_H
