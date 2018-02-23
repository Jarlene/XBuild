//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_GPUCODEGEN_H
#define XBUILD_GPUCODEGEN_H


#include "X86CodeGen.h"
#include "ARMCodeGen.h"
#include "MIPSCodeGen.h"

namespace xbuild {

    template <class CPUCodeGen = X86CodeGen>
    class GPUCodeGen : public  CPUCodeGen {
    public:
        GPUCodeGen(const Target &target);

        virtual int codegen();

        virtual int compile();

    };




    template class GPUCodeGen<X86CodeGen>;
    template class GPUCodeGen<ARMCodeGen>;
    template class GPUCodeGen<MIPSCodeGen>;

}

#endif //XBUILD_GPUCODEGEN_H
