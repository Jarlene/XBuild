//
// Created by Jarlene on 2018/2/13.
//

#include "xbuild/include/codegen/HexagonCodeGen.h"

namespace xbuild {

    HexagonCodeGen::HexagonCodeGen(const Target &target) : PosixCodeGen(target) {

    }

    int HexagonCodeGen::codegen() {
        return PosixCodeGen::codegen();
    }

    int HexagonCodeGen::compile() {
        return PosixCodeGen::compile();
    }
}