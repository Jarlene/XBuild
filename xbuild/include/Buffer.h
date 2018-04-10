//
// Created by Jarlene on 2018/2/7.
//

#ifndef XBUILD_BUFFER_H
#define XBUILD_BUFFER_H

#include "IntrusivePtr.h"

namespace xbuild {


    struct BufferContents {
        mutable RefCount ref_count;
        std::string name;
    };


    template<typename T = void>
    class Buffer {
        IntrusivePtr <BufferContents> contents;

        template<typename T2>
        static void assert_can_convert_from(const Buffer<T2> &other) {
            if (!other.defined()) {
                static_assert((!std::is_const<T2>::value || std::is_const<T>::value),
                              "Can't convert from a Buffer<const T> to a Buffer<T>");
                static_assert(std::is_same<typename std::remove_const<T>::type,
                                      typename std::remove_const<T2>::type>::value ||
                              std::is_void<T>::value ||
                              std::is_void<T2>::value,
                              "type mismatch constructing Buffer");
            }
        }




    public:
        typedef T ElemType;

        Buffer() {

        }

        virtual ~Buffer() {

        }

        template<typename T2>
        Buffer(const Buffer<T2> &other) : contents(other.contents) {
            assert_can_convert_from(other);
        }

        template<typename T2>
        Buffer(Buffer<T2> &&other) {
            assert_can_convert_from(other);
            contents = std::move(other.contents);
        }

        bool defined() const {
            return contents.defined();
        }

        template<typename T2>
        bool same_as(const Buffer<T2> &other) {
            return (const void *)(contents.get()) == (const void *)(other.contents.get());
        }

        const std::string &name() const {
            return contents->name;
        }

        void set_name(const std::string &n) {
            contents->name = n;
        }
    };

}

#endif //XBUILD_BUFFER_H
