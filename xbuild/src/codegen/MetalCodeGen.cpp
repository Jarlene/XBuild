//
// Created by Jarlene on 2018/2/13.
//

#include "xbuild/include/codegen/MetalCodeGen.h"


namespace xbuild {


    MetalCodeGen::MetalCodeGen(const Target &target) : GPUCodeGen(target) {

    }

    int MetalCodeGen::codegen() {
        return GPUCodeGen::codegen();
    }

    int MetalCodeGen::compile() {
        return GPUCodeGen::compile();
    }
}