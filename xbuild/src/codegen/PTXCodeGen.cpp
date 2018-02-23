//
// Created by Jarlene on 2018/2/13.
//


#include "xbuild/include/codegen/PTXCodeGen.h"

namespace xbuild {

    PTXCodeGen::PTXCodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int PTXCodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int PTXCodeGen::compile() {
        return PosixCodeGen::compile();
    }
}