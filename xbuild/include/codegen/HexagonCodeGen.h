//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_HEXAGONCODEGEN_H
#define XBUILD_HEXAGONCODEGEN_H

#include "PosixCodeGen.h"


namespace xbuild {

    class HexagonCodeGen : public PosixCodeGen {
    public:
        HexagonCodeGen(const Target &target);

        int codegen() override;

        int compile() override ;
    };

}

#endif //XBUILD_HEXAGONCODEGEN_H
