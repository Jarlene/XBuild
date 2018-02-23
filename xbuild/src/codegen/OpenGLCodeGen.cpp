//
// Created by Jarlene on 2018/2/13.
//



#include "xbuild/include/codegen/OpenGLCodeGen.h"

namespace xbuild {

    OpenGLCodeGen::OpenGLCodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int OpenGLCodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int OpenGLCodeGen::compile() {
        return PosixCodeGen::compile();
    }
}