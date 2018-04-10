//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_BASECODEGEN_H
#define XBUILD_BASECODEGEN_H

#include <mutex>
#include "xbuild/include/llvm.h"
#include "xbuild/include/IRVisitor.h"
#include "Target.h"



#define LLVM_TARGET(target) \
    inline void Initialize##target##Target() {}
#include <llvm/Config/Targets.def>
#undef LLVM_TARGET

#define LLVM_ASM_PARSER(target)     \
    inline void Initialize##target##AsmParser() {}
#include <llvm/Config/AsmParsers.def>
#undef LLVM_ASM_PARSER

#define LLVM_ASM_PRINTER(target)    \
    inline void Initialize##target##AsmPrinter() {}
#include <llvm/Config/AsmPrinters.def>
#undef LLVM_ASM_PRINTER



#define InitializeTarget(target)              \
        LLVMInitialize##target##Target();     \
        LLVMInitialize##target##TargetInfo(); \
        LLVMInitialize##target##TargetMC();   \
        llvm_##target##_enabled = true;

#define InitializeAsmParser(target)           \
        LLVMInitialize##target##AsmParser();  \

#define InitializeAsmPrinter(target)          \
        LLVMInitialize##target##AsmPrinter(); \


#ifdef WITH_X86
#define InitializeX86Target()       InitializeTarget(X86)
#define InitializeX86AsmParser()    InitializeAsmParser(X86)
#define InitializeX86AsmPrinter()   InitializeAsmPrinter(X86)
#endif

#ifdef WITH_ARM
#define InitializeARMTarget()       InitializeTarget(ARM)
#define InitializeARMAsmParser()    InitializeAsmParser(ARM)
#define InitializeARMAsmPrinter()   InitializeAsmPrinter(ARM)
#endif

#ifdef WITH_PTX
#define InitializeNVPTXTarget()       InitializeTarget(NVPTX)
#define InitializeNVPTXAsmParser()    InitializeAsmParser(NVPTX)
#define InitializeNVPTXAsmPrinter()   InitializeAsmPrinter(NVPTX)
#endif

#ifdef WITH_AMDGPU
#define InitializeAMDGPUTarget()	InitializeTarget(AMDGPU)
#define InitializeAMDGPUAsmParser()	InitializeAsmParser(AMDGPU)
#define InitializeAMDGPUAsmPrinter()	InitializeAsmParser(AMDGPU)
#endif

#ifdef WITH_AARCH64
#define InitializeAArch64Target()       InitializeTarget(AArch64)
#define InitializeAArch64AsmParser()    InitializeAsmParser(AArch64)
#define InitializeAArch64AsmPrinter()   InitializeAsmPrinter(AArch64)
#endif

#ifdef WITH_MIPS
#define InitializeMipsTarget()       InitializeTarget(Mips)
#define InitializeMipsAsmParser()    InitializeAsmParser(Mips)
#define InitializeMipsAsmPrinter()   InitializeAsmPrinter(Mips)
#endif


#ifdef WITH_HEXAGON
#define InitializeHexagonTarget()       InitializeTarget(Hexagon)
#define InitializeHexagonAsmParser()    InitializeAsmParser(Hexagon)
#define InitializeHexagonAsmPrinter()   InitializeAsmPrinter(Hexagon)
#endif

using namespace llvm;

namespace xbuild {


    class BaseCodeGen : public  IRVisitor{
    public:

        static BaseCodeGen *create(const Target &target,  llvm::LLVMContext &context);

        virtual std::unique_ptr<llvm::Module> compile(const llvm::Module &module);

        const Target &getTarget() ;

        void setContext(llvm::LLVMContext &context);

        static void initialize_llvm() ;

        virtual ~BaseCodeGen();

        virtual int codegen() = 0;

        virtual int compile() = 0;

    protected:
        BaseCodeGen(const Target &target);
    protected:
        static bool llvm_initialized;
        static bool llvm_X86_enabled;
        static bool llvm_ARM_enabled;
        static bool llvm_Hexagon_enabled;
        static bool llvm_AArch64_enabled;
        static bool llvm_NVPTX_enabled;
        static bool llvm_Mips_enabled;
        static bool llvm_PowerPC_enabled;
        static bool llvm_AMDGPU_enabled;

    private:
        Target target;
        std::unique_ptr<llvm::Module> module;
        llvm::Function *function;
        llvm::LLVMContext *context;
        llvm::IRBuilder<llvm::ConstantFolder, llvm::IRBuilderDefaultInserter> *builder;
        llvm::Value *value;
        llvm::MDNode *very_likely_branch;
    };

}

#endif //XBUILD_BASECODEGEN_H
