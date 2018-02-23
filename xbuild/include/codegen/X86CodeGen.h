//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_X86CODEGEN_H
#define XBUILD_X86CODEGEN_H


#include "xbuild/include/codegen/PosixCodeGen.h"


namespace xbuild {

    class X86CodeGen : public PosixCodeGen {
    public:
        X86CodeGen(const Target &target);

        int codegen() override ;

        int compile() override ;
    };

}

#endif //XBUILD_X86CODEGEN_H
