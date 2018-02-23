//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_IR_H
#define XBUILD_IR_H

#include "Expr.h"
#include "Buffer.h"
#include "Parameter.h"


namespace xbuild {

    struct Cast : public ExprNode<Cast> {
        Expr value;
        NODE_TYPE(Cast)

        static Expr make(Type t, Expr v);

    };

    struct Add : public ExprNode<Add> {
        Expr a, b;
        NODE_TYPE(Add)

        static Expr make(Expr a, Expr b);

    };

    struct Sub : public ExprNode<Sub> {
        Expr a, b;
        NODE_TYPE(Sub)

        static Expr make(Expr a, Expr b);
    };

    struct Mul : public ExprNode<Mul> {
        Expr a, b;
        NODE_TYPE(Mul)

        static Expr make(Expr a, Expr b);
    };

    struct Div : public ExprNode<Div> {
        Expr a, b;
        NODE_TYPE(Div)

        static Expr make(Expr a, Expr b);
    };

    struct Mod : public ExprNode<Mod> {
        Expr a, b;
        NODE_TYPE(Mod)

        static Expr make(Expr a, Expr b);
    };

    struct Min : public ExprNode<Min> {
        Expr a, b;
        NODE_TYPE(Min)

        static Expr make(Expr a, Expr b);
    };

    struct Max : public ExprNode<Max> {
        Expr a, b;
        NODE_TYPE(Max)

        static Expr make(Expr a, Expr b);
    };

    struct EQ : public ExprNode<EQ> {
        Expr a, b;
        NODE_TYPE(EQ)

        static Expr make(Expr a, Expr b);
    };

    struct NE : public ExprNode<NE> {
        Expr a, b;
        NODE_TYPE(NE)

        static Expr make(Expr a, Expr b);
    };

    struct LT : public ExprNode<LT> {
        Expr a, b;
        NODE_TYPE(LT)

        static Expr make(Expr a, Expr b);
    };

    struct LE : public ExprNode<LE> {
        Expr a, b;
        NODE_TYPE(LE)

        static Expr make(Expr a, Expr b);
    };

    struct GT : public ExprNode<GT> {
        Expr a, b;
        NODE_TYPE(GT)

        static Expr make(Expr a, Expr b);
    };

    struct GE : public ExprNode<GE> {
        Expr a, b;
        NODE_TYPE(GE)

        static Expr make(Expr a, Expr b);
    };

    struct And : public ExprNode<And> {
        Expr a, b;
        NODE_TYPE(And)

        static Expr make(Expr a, Expr b);
    };

    struct Or : public ExprNode<Or> {
        Expr a, b;
        NODE_TYPE(Or)

        static Expr make(Expr a, Expr b);
    };

    struct Not : public ExprNode<Not> {
        Expr a;
        NODE_TYPE(Not)

        static Expr make(Expr a);
    };

    struct Select : public ExprNode<Select> {
        Expr condition, true_value, false_value;
        NODE_TYPE(Select)

        static Expr make(Expr condition, Expr true_value, Expr false_value);
    };

    struct Load : public ExprNode<Load> {
        std::string name;
//        Buffer<> image;
        Parameter param;
        Expr predicate, index;
        NODE_TYPE(Load)


        template <class T>
        static Expr make(Type type, const std::string &name,
                         Expr index, Buffer<T> image,
                         Parameter param, Expr predicate);

    };

    struct Ramp : public ExprNode<Ramp> {
        Expr base, stride;
        int lanes;
        NODE_TYPE(Ramp)

        static Expr make(Expr base, Expr stride, int lanes);
    };

    struct Broadcast : public ExprNode<Broadcast> {
        Expr value;
        int lanes;
        NODE_TYPE(Broadcast)

        static Expr make(Expr value, int lanes);
    };

    struct Let : public ExprNode<Let> {
        std::string name;
        Expr value, body;
        NODE_TYPE(Let)

        static Expr make(const std::string &name, Expr value, Expr body);
    };

    struct LetStmt : public StmtNode<LetStmt> {
        std::string name;
        Expr value;
        Stmt body;
        NODE_TYPE(LetStmt)

        static Stmt make(const std::string &name, Expr value, Stmt body);
    };

    struct AssertStmt : public StmtNode<AssertStmt> {
        // if condition then val else error out with message
        Expr condition;
        Expr message;
        NODE_TYPE(AssertStmt)

        static Stmt make(Expr condition, Expr message);
    };


    struct ProducerConsumer : public StmtNode<ProducerConsumer> {
        std::string name;
        bool is_producer;
        Stmt body;
        NODE_TYPE(ProducerConsumer)

        static Stmt make(const std::string &name, bool is_producer, Stmt body);

        static Stmt make_produce(const std::string &name, Stmt body);

        static Stmt make_consume(const std::string &name, Stmt body);
    };

    struct Store : public StmtNode<Store> {
        std::string name;
        Expr predicate, value, index;
        Parameter param;
        NODE_TYPE(Store)

        static Stmt make(const std::string &name, Expr value, Expr index,
                         Parameter param, Expr predicate);
    };


    struct Provide : public StmtNode<Provide> {
        std::string name;
        std::vector<Expr> values;
        std::vector<Expr> args;
        NODE_TYPE(Provide)

        static Stmt make(const std::string &name, const std::vector<Expr> &values, const std::vector<Expr> &args);
    };

    struct Allocate : public StmtNode<Allocate> {
        std::string name;
        Type type;
//        MemoryType memory_type;
        std::vector<Expr> extents;
        Expr condition;
        NODE_TYPE(Allocate)

        Expr new_expr;
        std::string free_function;

        Stmt body;

        static Stmt make(const std::string &name, Type type, /*MemoryType memory_type,*/
                         const std::vector<Expr> &extents,
                         Expr condition, Stmt body,
                         Expr new_expr = Expr(), const std::string &free_function = std::string());


        static int32_t constant_allocation_size(const std::vector<Expr> &extents, const std::string &name);

        int32_t constant_allocation_size() const;

    };


    struct Free : public StmtNode<Free> {
        std::string name;
        NODE_TYPE(Free)

        static Stmt make(const std::string &name);

    };


    struct Range {
        Expr min, extent;

        Range() {}

        Range(Expr min, Expr extent) : min(min), extent(extent) {
            assert(min.type() == extent.type());
        }
    };

    typedef std::vector<Range> Region;


    struct Realize : public StmtNode<Realize> {
        std::string name;
        std::vector<Type> types;
//        MemoryType memory_type;
        Region bounds;
        Expr condition;
        Stmt body;

        NODE_TYPE(Realize)

        static Stmt make(const std::string &name, const std::vector<Type> &types, /*MemoryType memory_type,*/
                         const Region &bounds, Expr condition, Stmt body);


    };

    struct Block : public StmtNode<Block> {
        Stmt first, rest;
        NODE_TYPE(Block)
        static Stmt make(Stmt first, Stmt rest);
        /** Construct zero or more Blocks to invoke a list of statements in order.
         * This method may not return a Block statement if stmts.size() <= 1. */
        static Stmt make(const std::vector<Stmt> &stmts);

    };

    struct IfThenElse : public StmtNode<IfThenElse> {
        Expr condition;
        Stmt then_case, else_case;
        NODE_TYPE(IfThenElse)
        static Stmt make(Expr condition, Stmt then_case, Stmt else_case = Stmt());
    };


    struct Evaluate : public StmtNode<Evaluate> {
        Expr value;
        NODE_TYPE(Evaluate)
        static Stmt make(Expr v);

    };

    struct Variable : public ExprNode<Variable> {
        std::string name;

        /** References to scalar parameters, or to the dimensions of buffer
         * parameters hang onto those expressions. */
//        Parameter param;

        /** References to properties of literal image parameters. */
//        Buffer<> image;

        /** Reduction variables hang onto their domains */
//        ReductionDomain reduction_domain;
        NODE_TYPE(Variable)
        static Expr make(Type type, const std::string &name) ;

//        static Expr make(Type type, const std::string &name/*, Parameter param*/) {
//            return make(type, name/*, Buffer<>(), param, ReductionDomain()*/);
//        }
//
//        static Expr make(Type type, const std::string &name/*, Buffer<> image*/) {
//            return make(type, name, image/*, Parameter(), ReductionDomain()*/);
//        }
//
//        static Expr make(Type type, const std::string &name, ReductionDomain reduction_domain) {
//            return make(type, name, Buffer<>(), Parameter(), reduction_domain);
//        }
//
//        static Expr make(Type type, const std::string &name, Buffer<> image,
//                         Parameter param, ReductionDomain reduction_domain);

    };


    struct For : public StmtNode<For> {
        std::string name;
        Expr min, extent;
//        ForType for_type;
//        DeviceAPI device_api;
        Stmt body;
        NODE_TYPE(For)
        static Stmt make(const std::string &name, Expr min, Expr extent, /*ForType for_type, DeviceAPI device_api,*/ Stmt body);

        /*bool is_parallel() const {
            return (for_type == ForType::Parallel ||
                    for_type == ForType::GPUBlock ||
                    for_type == ForType::GPUThread);
        }*/

    };


    struct Shuffle : public ExprNode<Shuffle> {
        std::vector<Expr> vectors;
        NODE_TYPE(Shuffle)
        /** Indices indicating which vector element to place into the
         * result. The elements are numbered by their position in the
         * concatenation of the vector argumentss. */
        std::vector<int> indices;

        static Expr make(const std::vector<Expr> &vectors,
                         const std::vector<int> &indices);

        /** Convenience constructor for making a shuffle representing an
         * interleaving of vectors of the same length. */
        static Expr make_interleave(const std::vector<Expr> &vectors);

        /** Convenience constructor for making a shuffle representing a
         * concatenation of the vectors. */
        static Expr make_concat(const std::vector<Expr> &vectors);

        /** Convenience constructor for making a shuffle representing a
         * contiguous subset of a vector. */
        static Expr make_slice(Expr vector, int begin, int stride, int size);

        /** Convenience constructor for making a shuffle representing
         * extracting a single element. */
        static Expr make_extract_element(Expr vector, int i);

        /** Check if this shuffle is an interleaving of the vector
         * arguments. */
        bool is_interleave() const;

        /** Check if this shuffle is a concatenation of the vector
         * arguments. */
        bool is_concat() const;

        /** Check if this shuffle is a contiguous strict subset of the
         * vector arguments, and if so, the offset and stride of the
         * slice. */
        ///@{
        bool is_slice() const;
        int slice_begin() const { return indices[0]; }
        int slice_stride() const { return indices.size() >= 2 ? indices[1] - indices[0] : 1; }
        ///@}

        /** Check if this shuffle is extracting a scalar from the vector
         * arguments. */
        bool is_extract_element() const;

    };



    struct Prefetch : public StmtNode<Prefetch> {
        std::string name;
        std::vector<Type> types;
        Region bounds;
        NODE_TYPE(Prefetch)
        /** If it's a prefetch load from an image parameter, this points to that. */
//        Parameter param;

        static Stmt make(const std::string &name, const std::vector<Type> &types,
                         const Region &bounds /*, Parameter param = Parameter()*/);

    };


}

#endif //XBUILD_IR_H
