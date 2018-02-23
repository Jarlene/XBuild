//
// Created by Jarlene on 2018/2/13.
//


#include "xbuild/include/codegen/X86CodeGen.h"

namespace xbuild {

    X86CodeGen::X86CodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int X86CodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int X86CodeGen::compile() {
        return PosixCodeGen::compile();
    }
}