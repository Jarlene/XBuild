//
// Created by Jarlene on 2018/2/13.
//

#include "xbuild/include/codegen/OpenCLCodeGen.h"

namespace xbuild {

    OpenCLCodeGen::OpenCLCodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int OpenCLCodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int OpenCLCodeGen::compile() {
        return PosixCodeGen::compile();
    }
}