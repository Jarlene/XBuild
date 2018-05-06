//
// Created by Jarlene on 2018/4/13.
//

#ifndef XBUILD_IRPRINTER_H
#define XBUILD_IRPRINTER_H

#include "IRVisitor.h"

namespace xbuild {
    class IRPrinter : public IRVisitor {
    public:
        virtual ~IRPrinter();

        IRPrinter(std::ostream &);

        void print(Expr expr);

        void print(Stmt stmt);

        void print_list(const std::vector<Expr> &exprs);

    protected:
        std::ostream &stream;


        int indent;


        void do_indent();

        void visit(const IntImm *);
        void visit(const UIntImm *);
        void visit(const FloatImm *);
        void visit(const StringImm *);
        void visit(const Cast *);
        void visit(const Variable *);
        void visit(const Add *);
        void visit(const Sub *);
        void visit(const Mul *);
        void visit(const Div *);
        void visit(const Mod *);
        void visit(const Min *);
        void visit(const Max *);
        void visit(const EQ *);
        void visit(const NE *);
        void visit(const LT *);
        void visit(const LE *);
        void visit(const GT *);
        void visit(const GE *);
        void visit(const And *);
        void visit(const Or *);
        void visit(const Not *);
        void visit(const Select *);
        void visit(const Load *);
        void visit(const Ramp *);
        void visit(const Broadcast *);
//        void visit(const Call *);
        void visit(const Let *);
        void visit(const LetStmt *);
        void visit(const AssertStmt *);
        void visit(const ProducerConsumer *);
        void visit(const For *);
        void visit(const Store *);
        void visit(const Provide *);
        void visit(const Allocate *);
        void visit(const Free *);
        void visit(const Realize *);
        void visit(const Block *);
        void visit(const IfThenElse *);
        void visit(const Evaluate *);
        void visit(const Shuffle *);
        void visit(const Prefetch *);
    };
}



#endif //XBUILD_IRPRINTER_H
