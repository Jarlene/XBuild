//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_LLVM_H
#define XBUILD_LLVM_H


#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/ExecutionEngine/JITEventListener.h>

#include <llvm/IR/Verifier.h>
#include <llvm/Linker/Linker.h>
#include "llvm/Support/ErrorHandling.h"
#include <llvm/Support/FileSystem.h>
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/LegacyPassManager.h>
#if LLVM_VERSION < 50
#include <llvm/Support/Path.h>
#endif
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/raw_os_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/DataExtractor.h>
#include <llvm/Analysis/TargetLibraryInfo.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
#include <llvm/Transforms/IPO.h>
#include <llvm/Transforms/Utils/ModuleUtils.h>
#include <llvm/Transforms/Utils/SymbolRewriter.h>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include <llvm/ADT/StringMap.h>
#include <llvm/Object/ArchiveWriter.h>
#include <llvm/Object/ObjectFile.h>

#include <llvm/Transforms/Scalar/GVN.h>

#include <llvm/Transforms/IPO/AlwaysInliner.h>

#include <llvm/IR/Value.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/Analysis/TargetTransformInfo.h>
#include <llvm/IR/MDBuilder.h>

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
