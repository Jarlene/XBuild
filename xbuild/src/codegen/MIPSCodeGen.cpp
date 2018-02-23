//
// Created by Jarlene on 2018/2/13.
//

#include "xbuild/include/codegen/MIPSCodeGen.h"


namespace xbuild {

    MIPSCodeGen::MIPSCodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int MIPSCodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int MIPSCodeGen::compile() {
        return PosixCodeGen::compile();
    }
}