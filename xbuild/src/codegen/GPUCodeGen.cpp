//
// Created by Jarlene on 2018/2/12.
//
#include "xbuild/include/codegen/GPUCodeGen.h"
namespace xbuild {

    template<class CPUCodeGen>
    GPUCodeGen<CPUCodeGen>::GPUCodeGen(const Target &target) : CPUCodeGen(target) {

    }

    template<class CPUCodeGen>
    int GPUCodeGen<CPUCodeGen>::codegen() {
        return CPUCodeGen::codegen();
    }

    template<class CPUCodeGen>
    int GPUCodeGen<CPUCodeGen>::compile() {
        return CPUCodeGen::compile();
    }
}