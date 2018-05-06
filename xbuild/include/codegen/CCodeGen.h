//
// Created by Jarlene on 2018/4/13.
//

#ifndef XBUILD_CCODEGEN_H
#define XBUILD_CCODEGEN_H


#include "xbuild/include/Module.h"
#include "xbuild/include/IRPrinter.h"
#include "Target.h"


namespace xbuild {
    class CCodeGen : public IRPrinter {
    public:
        enum OutputKind {
            CHeader,
            CPlusPlusHeader,
            CImplementation,
            CPlusPlusImplementation,
        };

        CCodeGen(std::ostream &dest, Target target,
                 OutputKind output_kind = CImplementation,
                 const std::string &include_guard = "");

        ~CCodeGen();


        void compile(const Module &module);


        const Target &getTarget() const { return target; }


    protected:

        std::string id;

        Target target;

        OutputKind output_kind;


        std::string print(Expr expr);

        std::string print(Stmt stmt);
    };
}


#endif //XBUILD_CCODEGEN_H
