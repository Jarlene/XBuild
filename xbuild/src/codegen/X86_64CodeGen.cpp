//
// Created by Jarlene on 2018/4/10.
//


#include "xbuild/include/codegen/X86_64CodeGen.h"

namespace xbuild {

    X86_64CodeGen::X86_64CodeGen(const Target &target) : X86CodeGen(target) {

    }

    int X86_64CodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int X86_64CodeGen::compile() {
        return PosixCodeGen::compile();
    }
}