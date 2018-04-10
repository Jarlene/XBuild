//
// Created by Jarlene on 2018/2/23.
//

#include "xbuild/include/codegen/Target.h"

namespace xbuild {


    Target::Target(const std::string &s) {

    }

    Target::Target(const char *s) {

    }

    bool Target::validate_target_string(const std::string &s) {
        return false;
    }

    bool Target::features_any_of(std::vector<Target::Feature> test_features) const {
        return false;
    }

    void Target::set_feature(Target::Feature f, bool value) {

    }
}