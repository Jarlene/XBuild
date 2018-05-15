//
// Created by Jarlene on 2018/5/6.
//

#ifndef XBUILD_LOGGER_H
#define XBUILD_LOGGER_H


#include <iostream>
#include <xbuild/include/utils/StringUtil.h>

namespace xbuild {


    enum LoggerType : int {
        INFO = 0,
        WARNING = 1,
        ERROR = 2,
        FATAL = 3
    };

    class Logger {
    public:
        Logger(const LoggerType &type) : type(type) {

        }

        ~Logger() {
            stream()  << std::endl << std::flush;
        }

        std::ostream &stream() {
            switch (type) {
                case LoggerType::INFO:
                    return std::cout;
                case LoggerType::WARNING:
                case LoggerType::ERROR:
                case LoggerType::FATAL:
                    return std::cerr;
                default :
                    return std::cout;
            }
        }

    private:
        LoggerType type;


    };
}


#define LOG(level) \
     xbuild::Logger(xbuild::LoggerType::level).stream() << "[" << __FILE__<< ":" <<  __LINE__ <<"("<< __FUNCTION__<<")" << "]:" << std::flush  \


#endif //XBUILD_LOGGER_H
