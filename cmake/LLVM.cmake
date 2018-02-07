find_package(LLVM REQUIRED CONFIG PATHS "/usr/local/Cellar/llvm/5.0.0")


function(check_llvm_target TARGET HAS_TARGET)
    set(${HAS_TARGET} OFF PARENT_SCOPE)
    set(_llvm_required_version ${LLVM_VERSION})
    if (ARGV2)
        set(_llvm_required_version ${ARGV2})
    endif()
    if (NOT LLVM_VERSION LESS _llvm_required_version)
        list(FIND LLVM_TARGETS_TO_BUILD ${TARGET} _found_target)
        if (_found_target GREATER -1)
            set(${HAS_TARGET} ON PARENT_SCOPE)
        else()
            set(${HAS_TARGET} OFF PARENT_SCOPE)
        endif()
    endif()
endfunction()


if (LLVM_FOUND)
    include_directories(${LLVM_INCLUDE_DIRS})
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

    file(TO_NATIVE_PATH "${LLVM_TOOLS_BINARY_DIR}/llvm-as${CMAKE_EXECUTABLE_SUFFIX}" LLVM_AS)
    file(TO_NATIVE_PATH "${LLVM_TOOLS_BINARY_DIR}/llvm-nm${CMAKE_EXECUTABLE_SUFFIX}" LLVM_NM)
    file(TO_NATIVE_PATH "${LLVM_TOOLS_BINARY_DIR}/clang${CMAKE_EXECUTABLE_SUFFIX}" CLANG)
    file(TO_NATIVE_PATH "${LLVM_TOOLS_BINARY_DIR}/llvm-config${CMAKE_EXECUTABLE_SUFFIX}" LLVM_CONFIG)


    check_llvm_target(X86 WITH_X86)
    check_llvm_target(ARM WITH_ARM)
    check_llvm_target(AArch64 WITH_AARCH64)
    check_llvm_target(Hexagon WITH_HEXAGON 40)
    check_llvm_target(Mips WITH_MIPS)
    check_llvm_target(PowerPC WITH_POWERPC)
    check_llvm_target(NVPTX WITH_NVPTX)
endif ()