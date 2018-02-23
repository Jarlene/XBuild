//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_METALCODEGEN_H
#define XBUILD_METALCODEGEN_H

#include "xbuild/include/codegen/GPUCodeGen.h"

namespace xbuild {

    class MetalCodeGen : public GPUCodeGen<> {
    public:
        MetalCodeGen(const Target &target) ;

        int codegen() override;

        int compile() override ;
    };

}

#endif //XBUILD_METALCODEGEN_H
