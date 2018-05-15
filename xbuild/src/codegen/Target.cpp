//
// Created by Jarlene on 2018/2/23.
//

#include "xbuild/include/codegen/Target.h"

namespace xbuild {


    Target::Target(const std::string &s) {
//        Target host = get_host_target();
//        if (target.empty()) {
//            *this = host;
//        } else {
//            os = host.os;
//            arch = host.arch;
//            bits = host.bits;
//            if (!merge_string(*this, target)) {
//                bad_target_string(target);
//            }
//        }
    }

    Target::Target(const char *s) {
        *this = Target(std::string(s));
    }

    bool Target::validate_target_string(const std::string &s) {
        return false;
    }

    bool Target::features_any_of(std::vector<Target::Feature> test_features) const {
        for(auto &f : test_features) {
            if (has_feature(f)) return true;
        }
        return false;
    }

    void Target::set_feature(Target::Feature f, bool value) {
        if(f == FeatureEnd) return;
        features.set(f, value);
    }

    bool Target::features_all_of(std::vector<Target::Feature> test_features) const {
        for(auto &f : test_features) {
            if (!has_feature(f)) return false;
        }
        return true;
    }

    bool Target::has_feature(Feature f) const {
        if(f == FeatureEnd) return true;
        return features[f];
    }
}