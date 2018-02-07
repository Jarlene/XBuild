//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_IRMUTATOR_H
#define XBUILD_IRMUTATOR_H

#include "IRVisitor.h"

namespace xbuild {

    class IRMutator {
    public:
        IRMutator();
        virtual ~IRMutator();

        virtual Expr mutate(const Expr &expr);
        virtual Stmt mutate(const Stmt &stmt);

    protected:
        template<typename T> friend struct ExprNode;
        template<typename T> friend struct StmtNode;
        virtual Expr visit(const IntImm *);
        virtual Expr visit(const UIntImm *);
        virtual Expr visit(const FloatImm *);
        virtual Expr visit(const StringImm *);
        virtual Expr visit(const Cast *);
        virtual Expr visit(const Variable *);
        virtual Expr visit(const Add *);
        virtual Expr visit(const Sub *);
        virtual Expr visit(const Mul *);
        virtual Expr visit(const Div *);
        virtual Expr visit(const Mod *);
        virtual Expr visit(const Min *);
        virtual Expr visit(const Max *);
        virtual Expr visit(const EQ *);
        virtual Expr visit(const NE *);
        virtual Expr visit(const LT *);
        virtual Expr visit(const LE *);
        virtual Expr visit(const GT *);
        virtual Expr visit(const GE *);
        virtual Expr visit(const And *);
        virtual Expr visit(const Or *);
        virtual Expr visit(const Not *);
        virtual Expr visit(const Select *);
        virtual Expr visit(const Load *);
        virtual Expr visit(const Ramp *);
        virtual Expr visit(const Broadcast *);
//        virtual Expr visit(const Call *);
        virtual Expr visit(const Let *);
        virtual Expr visit(const Shuffle *);

        virtual Stmt visit(const LetStmt *);
        virtual Stmt visit(const AssertStmt *);
        virtual Stmt visit(const ProducerConsumer *);
        virtual Stmt visit(const For *);
        virtual Stmt visit(const Store *);
        virtual Stmt visit(const Provide *);
        virtual Stmt visit(const Allocate *);
        virtual Stmt visit(const Free *);
        virtual Stmt visit(const Realize *);
        virtual Stmt visit(const Block *);
        virtual Stmt visit(const IfThenElse *);
        virtual Stmt visit(const Evaluate *);
        virtual Stmt visit(const Prefetch *);
    };
}

#endif //XBUILD_IRMUTATOR_H
