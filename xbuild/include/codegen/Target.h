//
// Created by Jarlene on 2018/2/12.
//

#ifndef XBUILD_TARGET_H
#define XBUILD_TARGET_H

#include <vector>
#include <bitset>

namespace xbuild {

    struct Target {
        enum OS {
            OSUnknown = 0, Linux, Windows, OSX, Android, IOS, QuRT, NoOS
        } os;

        enum Arch {
            ArchUnknown = 0, X86, ARM, MIPS, Hexagon, POWERPC
        } arch;

        enum Feature {
            JIT = 0,
            Debug = 1,
            NoAsserts = 2,
            NoBoundsQuery = 3,
            SSE41 = 4,
            AVX = 5,
            AVX2 = 6,
            FMA = 7,
            FMA4 = 8,
            F16C = 9,
            ARMv7s = 10,
            NoNEON = 11,
            VSX = 12,
            POWER_ARCH_2_07 = 13,
            CUDA = 14,
            CUDACapability30 = 15,
            CUDACapability32 = 16,
            CUDACapability35 = 17,
            CUDACapability50 = 18,
            CUDACapability61 = 19,
            OpenCL = 20,
            CLDoubles = 21,
            CLHalf = 22,
            OpenGL = 23,
            OpenGLCompute = 24,
            UserContext = 25,
            Matlab = 26,
            Profile = 27,
            NoRuntime = 28,
            Metal = 29,
            MinGW = 30,
            CPlusPlusMangling = 31,
            LargeBuffers = 32,
            HVX_64 = 33,
            HVX_128 = 34,
            HVX_v62 = 35,
            HVX_v65 = 36,
            HVX_v66 = 37,
            HVX_shared_object = 38,
            FuzzFloatStores = 39,
            SoftFloatABI = 40,
            MSAN = 41,
            AVX512 = 42,
            AVX512_KNL = 43,
            AVX512_Skylake = 44,
            AVX512_Cannonlake = 45,
            TraceLoads = 46,
            TraceStores = 47,
            TraceRealizations = 48,
            FeatureEnd = 49
        };

        int bits;


        Target() : os(OSUnknown), arch(ArchUnknown), bits(0) {

        }

        Target(OS o, Arch a, int b, std::vector <Feature> initial_features = std::vector<Feature>())
                : os(o), arch(a), bits(b) {
            for (size_t i = 0; i < initial_features.size(); i++) {
                set_feature(initial_features[i]);
            }
        }

        explicit Target(const std::string &s);
        explicit Target(const char *s);

        static bool validate_target_string(const std::string &s);

        void set_feature(Feature f, bool value = true) ;

        bool features_any_of(std::vector<Feature> test_features) const;

    private:
        std::bitset<FeatureEnd> features;
    };

}

#endif //XBUILD_TARGET_H
