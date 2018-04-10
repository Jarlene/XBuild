//
// Created by Jarlene on 2018/4/10.
//

#ifndef XBUILD_X86_64CODEGEN_H
#define XBUILD_X86_64CODEGEN_H




#include "xbuild/include/codegen/X86CodeGen.h"


namespace xbuild {

    class X86_64CodeGen : public X86CodeGen {
    public:
        X86_64CodeGen(const Target &target);

        int codegen() override ;

        int compile() override ;
    };

}
#endif //XBUILD_X86_64CODEGEN_H
