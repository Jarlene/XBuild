//
// Created by Jarlene on 2018/5/6.
//

#ifndef XBUILD_LOGGER_H
#define XBUILD_LOGGER_H


#include <iostream>
#include <xbuild/include/utils/StringUtil.h>

namespace xbuild {


    enum LoggerType : int {
        DEBUG,
        INFO,
        WARNING,
        FATAL
    };

    class Logger {
        const bool logging;
    public:

        Logger(LoggerType &type) : logging(type >= debug()) {

        }

        template<class T>
        Logger &operator<<(T &&x) {
            if (logging) {
                std::cerr << std::forward<T>(x);
            }
            return *this;
        }

        static LoggerType parse(const std::string &e) {
            std::transform(e.begin(), e.end(), e.begin(), std::tolower);
            if ("debug" == e) {
                return LoggerType::DEBUG;
            } else if ("info" == e) {
                return LoggerType::INFO;
            } else if ("warning" == e) {
                return LoggerType::WARNING;
            } else if ("fatal" == e) {
                return LoggerType::FATAL;
            }
            return LoggerType::DEBUG;
        }

        static int debug() {
            string s = getEnv("Xbuild_Logger");
            LoggerType type = parse(s);
            return type;
        }

    };
}


#endif //XBUILD_LOGGER_H
