//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_PTXCODEGEN_H
#define XBUILD_PTXCODEGEN_H


#include "xbuild/include/codegen/PosixCodeGen.h"


namespace xbuild {

    class PTXCodeGen : public PosixCodeGen {
    public:
        PTXCodeGen(const Target &target);

        int codegen() override;

        int compile() override;
    };

}


#endif //XBUILD_PTXCODEGEN_H
