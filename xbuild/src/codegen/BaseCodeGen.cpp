//
// Created by Jarlene on 2018/2/12.
//

#include "xbuild/include/codegen/BaseCodeGen.h"
#include "xbuild/include/codegen/ARMCodeGen.h"
#include "xbuild/include/codegen/X86CodeGen.h"
#include "xbuild/include/codegen/MIPSCodeGen.h"
#include "xbuild/include/codegen/HexagonCodeGen.h"
#include "xbuild/include/codegen/GPUCodeGen.h"




namespace xbuild {

    template<typename T>
    BaseCodeGen *make(const Target &target,
                              llvm::LLVMContext &context) {
        BaseCodeGen *ret = new T(target);
        ret->setContext(context);
        return ret;
    }


    BaseCodeGen *BaseCodeGen::create(const Target &target, llvm::LLVMContext &context) {

        if (target.features_any_of({Target::CUDA,
                                    Target::OpenCL,
                                    Target::OpenGL,
                                    Target::OpenGLCompute,
                                    Target::Metal})) {

            if (target.arch == Target::X86) {
                return make<GPUCodeGen<X86CodeGen>>(target, context);
            }

            if (target.arch == Target::ARM) {
                return make<GPUCodeGen<ARMCodeGen>>(target, context);
            }

            if (target.arch == Target::MIPS) {
                return make<GPUCodeGen<MIPSCodeGen>>(target, context);
            }

            return nullptr;
        } else if (target.arch == Target::X86) {
            return make<X86CodeGen>(target, context);
        } else if (target.arch == Target::ARM) {
            return make<ARMCodeGen>(target, context);
        } else if (target.arch == Target::MIPS) {
            return make<MIPSCodeGen>(target, context);
        }  else if (target.arch == Target::Hexagon) {
            return make<HexagonCodeGen>(target, context);
        }

        return nullptr;
    }

    BaseCodeGen::BaseCodeGen(const Target &target) : target(target) {

    }

    std::unique_ptr<llvm::Module> BaseCodeGen::compile(const llvm::Module &module) {
        return std::unique_ptr<llvm::Module>();
    }

    const Target &BaseCodeGen::getTarget() {
        return target;
    }

    void BaseCodeGen::setContext(llvm::LLVMContext &context) {
        this->context = &context;
    }

    void BaseCodeGen::initialize_llvm() {
        static std::mutex initialize_llvm_mutex;
        std::lock_guard<std::mutex> lock(initialize_llvm_mutex);
        if (!llvm_initialized) {
            InitializeNativeTarget();
//            InitializeNativeTargetAsmPrinter();
//            InitializeNativeTargetAsmParser();
#define LLVM_TARGET(target)         \
            Initialize##target##Target();
#include <llvm/Config/Targets.def>
#undef LLVM_TARGET

#define LLVM_ASM_PARSER(target)     \
            Initialize##target##AsmParser();
#include <llvm/Config/AsmParsers.def>
#undef LLVM_ASM_PARSER

#define LLVM_ASM_PRINTER(target)    \
            Initialize##target##AsmPrinter();
#include <llvm/Config/AsmPrinters.def>
#undef LLVM_ASM_PRINTER
            llvm_initialized = true;
        }
    }

    BaseCodeGen::~BaseCodeGen() {
        delete builder;
    }
}