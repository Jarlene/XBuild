//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_OPENCLCODEGEN_H
#define XBUILD_OPENCLCODEGEN_H


#include "PosixCodeGen.h"


namespace xbuild {

    class OpenCLCodeGen : public PosixCodeGen {
    public:
        OpenCLCodeGen(const Target &target);

        int codegen() override;

        int compile() override;
    };
}

#endif //XBUILD_OPENCLCODEGEN_H
