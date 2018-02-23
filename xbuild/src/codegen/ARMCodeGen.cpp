//
// Created by Jarlene on 2018/2/13.
//

#include "xbuild/include/codegen/ARMCodeGen.h"

namespace xbuild {

    ARMCodeGen::ARMCodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int ARMCodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int ARMCodeGen::compile() {
        return PosixCodeGen::compile();
    }
}