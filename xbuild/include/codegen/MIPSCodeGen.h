//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_MIPSCODEGEN_H
#define XBUILD_MIPSCODEGEN_H


#include "PosixCodeGen.h"


namespace xbuild {

    class MIPSCodeGen : public PosixCodeGen {
    public:
        MIPSCodeGen(const Target &target);

        int codegen() override;

        int compile() override;
    };

}

#endif //XBUILD_MIPSCODEGEN_H
