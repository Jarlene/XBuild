//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_ARMCODEGEN_H
#define XBUILD_ARMCODEGEN_H

#include "PosixCodeGen.h"


namespace xbuild {

    class ARMCodeGen : public PosixCodeGen {
    public:
        ARMCodeGen(const Target &target);
        int codegen() override ;

        int compile() override ;
    };

}

#endif //XBUILD_ARMCODEGEN_H
