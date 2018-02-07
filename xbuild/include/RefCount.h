//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_REFCOUNT_H
#define XBUILD_REFCOUNT_H

#include <atomic>

namespace xbuild {


    class RefCount {
        std::atomic<int> count;
    public:
        RefCount() : count(0) {}

        int increment() { return ++count; }

        int decrement() { return --count; }

        bool is_zero() const { return count == 0; }
    };

    template<typename T>
    RefCount &getRefCount(const T *t);
    template<typename T>
    void destroy(const T *t);
}

#endif //XBUILD_REFCOUNT_H
