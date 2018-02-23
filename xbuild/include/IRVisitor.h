//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_IRVISITOR_H
#define XBUILD_IRVISITOR_H

#include "Expr.h"
#include "IR.h"
#include <set>

namespace xbuild {

    class IRVisitor {
    public:
        IRVisitor();

        virtual ~IRVisitor();

    protected:
        template<typename T> friend
        struct ExprNode;
        template<typename T> friend
        struct StmtNode;

        virtual void visit(const IntImm *);

        virtual void visit(const UIntImm *);

        virtual void visit(const FloatImm *);

        virtual void visit(const StringImm *);

        virtual void visit(const Cast *);

        virtual void visit(const Variable *);

        virtual void visit(const Add *);

        virtual void visit(const Sub *);

        virtual void visit(const Mul *);

        virtual void visit(const Div *);

        virtual void visit(const Mod *);

        virtual void visit(const Min *);

        virtual void visit(const Max *);

        virtual void visit(const EQ *);

        virtual void visit(const NE *);

        virtual void visit(const LT *);

        virtual void visit(const LE *);

        virtual void visit(const GT *);

        virtual void visit(const GE *);

        virtual void visit(const And *);

        virtual void visit(const Or *);

        virtual void visit(const Not *);

        virtual void visit(const Select *);

        virtual void visit(const Load *);

        virtual void visit(const Ramp *);

        virtual void visit(const Broadcast *);

//        virtual void visit(const Call *);
        virtual void visit(const Let *);

        virtual void visit(const LetStmt *);

        virtual void visit(const AssertStmt *);

        virtual void visit(const ProducerConsumer *);

        virtual void visit(const For *);

        virtual void visit(const Store *);

        virtual void visit(const Provide *);

        virtual void visit(const Allocate *);

        virtual void visit(const Free *);

        virtual void visit(const Realize *);

        virtual void visit(const Block *);

        virtual void visit(const IfThenElse *);

        virtual void visit(const Evaluate *);

        virtual void visit(const Shuffle *);

        virtual void visit(const Prefetch *);
    };


    class IRGraphVisitor : public IRVisitor {
    protected:
        void visit(const IntImm *) override;
        void visit(const UIntImm *) override;
        void visit(const FloatImm *) override;
        void visit(const StringImm *) override;
        void visit(const Cast *) override;
        void visit(const Variable *) override;
        void visit(const Add *) override;
        void visit(const Sub *) override;
        void visit(const Mul *) override;
        void visit(const Div *) override;
        void visit(const Mod *) override;
        void visit(const Min *) override;
        void visit(const Max *) override;
        void visit(const EQ *) override;
        void visit(const NE *) override;
        void visit(const LT *) override;
        void visit(const LE *) override;
        void visit(const GT *) override;
        void visit(const GE *) override;
        void visit(const And *) override;
        void visit(const Or *) override;
        void visit(const Not *) override;
        void visit(const Select *) override;
        void visit(const Load *) override;
        void visit(const Ramp *) override;
        void visit(const Broadcast *) override;
//        void visit(const Call *) override;
        void visit(const Let *) override;
        void visit(const LetStmt *) override;
        void visit(const AssertStmt *) override;
        void visit(const ProducerConsumer *) override;
        void visit(const For *) override;
        void visit(const Store *) override;
        void visit(const Provide *) override;
        void visit(const Allocate *) override;
        void visit(const Free *) override;
        void visit(const Realize *) override;
        void visit(const Block *) override;
        void visit(const IfThenElse *) override;
        void visit(const Evaluate *) override;
        void visit(const Shuffle *) override;
        void visit(const Prefetch *) override;

    protected:
        virtual void include(const Expr &);

        virtual void include(const Stmt &);

    private:
        std::set<const IRNode *> visited;
    };
}

#endif //XBUILD_IRVISITOR_H
