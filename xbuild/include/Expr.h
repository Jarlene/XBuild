//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_EXPR_H
#define XBUILD_EXPR_H

#include <stdlib.h>
#include <atomic>

namespace xbuild {

    class IRVisitor;

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

    class RefCount {
        std::atomic<int> count;
    public:
        RefCount() : count(0) {}

        int increment() { return ++count; }

        int decrement() { return --count; }

        bool is_zero() const { return count == 0; }
    };

    struct IRNode {
        virtual void accept(IRVisitor *v) const = 0;

        virtual ~IRNode() {}

        IRNode(IRNodeType t) : node_type(t) {}

        mutable RefCount ref_count;

        IRNodeType node_type;
    };

    inline RefCount &getRefCount(const IRNode *node) {
        return node->ref_count;
    }

    inline void destroy(const IRNode *node) {
        delete node;
    }
}

#endif //XBUILD_EXPR_H
