//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_LLVM_H
#define XBUILD_LLVM_H

#include <llvm>

namespace llvm {
    class Value;
    class Module;
    class Function;
    class IRBuilderDefaultInserter;
    class ConstantFolder;
    template<typename, typename> class IRBuilder;
    class LLVMContext;
    class Type;
    class StructType;
    class Instruction;
    class CallInst;
    class ExecutionEngine;
    class AllocaInst;
    class Constant;
    class Triple;
    class MDNode;
    class NamedMDNode;
    class DataLayout;
    class BasicBlock;
    class GlobalVariable;
}

#endif //XBUILD_LLVM_H
