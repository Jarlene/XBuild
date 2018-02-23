//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_OPENGLCODEGEN_H
#define XBUILD_OPENGLCODEGEN_H


#include "PosixCodeGen.h"


namespace xbuild {

    class OpenGLCodeGen : public PosixCodeGen {
    public:
        OpenGLCodeGen(const Target &target);

        int codegen() override;

        int compile() override;
    };
}


#endif //XBUILD_OPENGLCODEGEN_H
