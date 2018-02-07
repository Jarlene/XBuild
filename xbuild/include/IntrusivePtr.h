//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_INTRUSIVEPTR_H
#define XBUILD_INTRUSIVEPTR_H


#include <algorithm>
#include "RefCount.h"

namespace xbuild {

    template<class T>
    class IntrusivePtr {
    public:
        T *get() const {
            return ptr;
        }

        T &operator*() const {
            return *ptr;
        }

        T *operator->() const {
            return ptr;
        }

        ~IntrusivePtr() {
            decref(ptr);
        }


        IntrusivePtr() : ptr(nullptr) {
        }

        IntrusivePtr(T *p) : ptr(p) {
            incref(ptr);
        }

        IntrusivePtr(const IntrusivePtr<T> &other) : ptr(other.ptr) {
            incref(ptr);
        }

        IntrusivePtr(IntrusivePtr<T> &&other) : ptr(other.ptr) {
            other.ptr = nullptr;
        }

        IntrusivePtr<T> &operator=(const IntrusivePtr<T> &other) {
            if (other.ptr == ptr) return *this;
            T *temp = other.ptr;
            incref(temp);
            decref(ptr);
            ptr = temp;
            return *this;
        }

        IntrusivePtr<T> &operator=(IntrusivePtr<T> &&other) {
            std::swap(ptr, other.ptr);
            return *this;
        }

        bool defined() const {
            return ptr != nullptr;
        }

        bool same_as(const IntrusivePtr &other) const {
            return ptr == other.ptr;
        }

        bool operator<(const IntrusivePtr<T> &other) const {
            return ptr < other.ptr;
        }

    private:
        void incref(T *p) {
            if (p) {
                getRefCount(p).increment();
            }
        };

        void decref(T *p) {
            if (p) {
                if (getRefCount(p).decrement() == 0) {
                    destroy(p);
                }
            }
        }

    protected:
        T *ptr;


    };

}

#endif //XBUILD_INTRUSIVEPTR_H
