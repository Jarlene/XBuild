//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_POSIXCODEGEN_H
#define XBUILD_POSIXCODEGEN_H



#include "xbuild/include/codegen/BaseCodeGen.h"



namespace xbuild {

    class PosixCodeGen : public BaseCodeGen {
    public:
        PosixCodeGen(const Target &target);

        int codegen() override {
            return 0;
        }

        int compile() override {
            return 0;
        }
    };

}

#endif //XBUILD_POSIXCODEGEN_H
