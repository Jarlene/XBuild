//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_EXPR_H
#define XBUILD_EXPR_H

#include <stdlib.h>
#include <atomic>
#include <assert.h>

#include "IntrusivePtr.h"
#include "RefCount.h"
#include "IRHandle.h"

namespace xbuild {

    class IRVisitor;

    class IRMutator;

    enum class IRNodeType : int {
        IntImm,
        UIntImm,
        FloatImm,
        StringImm,
        Cast,
        Variable,
        Add,
        Sub,
        Mul,
        Div,
        Mod,
        Min,
        Max,
        EQ,
        NE,
        LT,
        LE,
        GT,
        GE,
        And,
        Or,
        Not,
        Select,
        Load,
        Ramp,
        Broadcast,
        Call,
        Let,
        LetStmt,
        AssertStmt,
        ProducerConsumer,
        For,
        Store,
        Provide,
        Allocate,
        Free,
        Realize,
        Block,
        IfThenElse,
        Evaluate,
        Shuffle,
        Prefetch,
        AttrStmt,
        ExtensionExpr
    };


    struct IRNode {
        virtual void accept(IRVisitor *v) const = 0;

        virtual ~IRNode() {

        }

        IRNode(IRNodeType t) : node_type(t) {

        }

        mutable RefCount ref_count;

        IRNodeType node_type;
    };

    class Stmt;

    struct BaseStmtNode : public IRNode {
        BaseStmtNode(IRNodeType t) : IRNode(t) {

        }

        virtual Stmt mutate_stmt(IRMutator *v) const = 0;

    };

    struct BaseExprNode : public IRNode {
        BaseExprNode(IRNodeType t) : IRNode(t) {

        }

        virtual Expr mutate_expr(IRMutator *v) const = 0;

        Type type;
    };

    template<typename T>
    struct ExprNode : public BaseExprNode {
        void accept(IRVisitor *v) const override;

        Expr mutate_expr(IRMutator *v) const override;

        ExprNode() : BaseExprNode(T::_node_type) {

        }

        virtual ~ExprNode() {

        }
    };

    template<typename T>
    struct StmtNode : public BaseStmtNode {
        void accept(IRVisitor *v) const;

        Stmt mutate_stmt(IRMutator *v) const;

        StmtNode() : BaseStmtNode(T::_node_type) {}

        virtual ~StmtNode() {}
    };


    struct IntImm : public ExprNode<IntImm> {
        int64_t value;

        NODE_TYPE(IntImm)

        static const IntImm *make(Type t, int64_t value) {
            assert(t.is_int() && t.is_scalar());
            assert(t.bits() == 8 || t.bits() == 16 || t.bits() == 32 || t.bits() == 64);
            value = (int64_t) (((uint64_t) value) << (64 - t.bits()));
            value >>= (64 - t.bits());

            IntImm * node = new IntImm;
            node->type = t;
            node->value = value;
            return node;
        }
    };

    struct UIntImm : public ExprNode<UIntImm> {
        uint64_t value;

        NODE_TYPE(UIntImm)

        static const UIntImm *make(Type t, uint64_t value) {
            assert(t.is_uint() && t.is_scalar());
            assert(t.bits() == 1 || t.bits() == 8 || t.bits() == 16 || t.bits() == 32 || t.bits() == 64);
            value <<= (64 - t.bits());
            value >>= (64 - t.bits());
            UIntImm * node = new UIntImm;
            node->type = t;
            node->value = value;
            return node;
        }
    };

    struct FloatImm : public ExprNode<FloatImm> {
        double value;
        NODE_TYPE(FloatImm)

        static const FloatImm *make(Type t, double value) {
            assert(t.is_float() && t.is_scalar());
            FloatImm * node = new FloatImm;
            node->type = t;
            switch (t.bits()) {
                case 16:
                    node->value = value; // TODO::截断
                    break;
                case 32:
                    node->value = (float) value;
                    break;
                case 64:
                    node->value = value;
                    break;
                default:
                    break;
            }

            return node;
        }
    };

    struct StringImm : public ExprNode<StringImm> {
        std::string value;
        NODE_TYPE(StringImm)

        static const StringImm *make(const std::string &val) {
            StringImm * node = new StringImm;
            node->type = type_of<const char *>();
            node->value = val;
            return node;
        }
    };


    struct IRHandle : public IntrusivePtr<const IRNode> {
        IRHandle() : IntrusivePtr<const IRNode>() {

        }

        IRHandle(const IRNode *p) : IntrusivePtr<const IRNode>(p) {

        }

        void accept(IRVisitor *v) const {
            ptr->accept(v);
        }

        template<typename T>
        const T *as() const {
            if (ptr && ptr->node_type == T::_node_type) {
                return (const T *) ptr;
            }
            return nullptr;
        }
    };

    struct Stmt : public IRHandle {
        Stmt() : IRHandle() {

        }

        Stmt(const BaseStmtNode *n) : IRHandle(n) {

        }

        struct Compare {
            bool operator()(const Stmt &a, const Stmt &b) const {
                return a.ptr < b.ptr;
            }
        };
    };

    struct Expr : public IRHandle {
        Expr() : IRHandle() {

        }

        Expr(const BaseExprNode *n) : IRHandle(n) {

        }


        explicit Expr(int8_t x) : IRHandle(IntImm::make(Int(8), x)) {}

        explicit Expr(int16_t x) : IRHandle(IntImm::make(Int(16), x)) {}

        Expr(int32_t x) : IRHandle(IntImm::make(Int(32), x)) {}

        explicit Expr(int64_t x) : IRHandle(IntImm::make(Int(64), x)) {}

        explicit Expr(uint8_t x) : IRHandle(UIntImm::make(UInt(8), x)) {}

        explicit Expr(uint16_t x) : IRHandle(UIntImm::make(UInt(16), x)) {}

        explicit Expr(uint32_t x) : IRHandle(UIntImm::make(UInt(32), x)) {}

        explicit Expr(uint64_t x) : IRHandle(UIntImm::make(UInt(64), x)) {}

        Expr(float x) : IRHandle(FloatImm::make(Float(32), x)) {}

        explicit Expr(double x) : IRHandle(FloatImm::make(Float(64), x)) {}

        Expr(const std::string &s) : IRHandle(StringImm::make(s)) {}

        Type type() const {
            return ((const BaseExprNode *) ptr)->type;
        }
    };


    template<>
    inline RefCount &getRefCount<IRNode>(const IRNode *node) {
        return node->ref_count;
    }

    template<>
    inline void destroy<IRNode>(const IRNode *node) {
        delete node;
    }
}

#endif //XBUILD_EXPR_H
