// Hive Jimbo Library
// Copyright (C) 2008 Hive Solutions Lda.
//
// This file is part of Hive Jimbo Library.
//
// Hive Jimbo Library is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Hive Jimbo Library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hive Jimbo Library. If not, see <http://www.gnu.org/licenses/>.
//
// __author__    = João Magalhães <joamag@hive.pt>
// __version__   = 1.0.0
// __revision__  = $LastChangedRevision$
// __date__      = $LastChangedDate$
// __copyright__ = Copyright (c) 2008 Hive Solutions Lda.
// __license__   = GNU General Public License (GPL), Version 3

#pragma once

#include "handler.h"
#include "formatter.h"

#define DEFAULT_HANDLER JBLoggerStandardOutHandler
#define DEFAULT_FORMATTER JBLoggerTimeFormatter

#define DEFAULT_FILE_STREAM_MODE std::ios_base::app

#define DEFAULT_LOGGER_NAME "default"

class JBLogger;
class JBLoggerHandler;
class JBLoggerFormatter;
class JBLoggerRecord;

typedef std::vector<JBLoggerHandler *> handlersListType;
typedef std::map<std::string, JBLogger *> loggersMapType;

class JBLogger {
    public:
        JB_EXPORT JBLogger();
        JB_EXPORT ~JBLogger();
        JB_EXPORT void debug(std::string &value);
        JB_EXPORT void info(std::string &value);
        JB_EXPORT void warning(std::string &value);
        JB_EXPORT void fault(std::string &value);
        JB_EXPORT void critical(std::string &value);
        JB_EXPORT void handle(JBLoggerRecord &record);
        JB_EXPORT void setLevel(unsigned int level);
        JB_EXPORT void addHandler(JBLoggerHandler *loggerHandler);
        JB_EXPORT void setDefaultHandler(JBLoggerHandler *defaultLoggerHandler);
        JB_EXPORT void setFormatter(JBLoggerFormatter *loggerFormatter);
        JB_EXPORT static JBLogger *getLogger(std::string &loggerName);
        JB_EXPORT static JBLogger *getLogger(char *loggerName);
        JB_EXPORT static JBLogger *getLogger();
    private:
        unsigned int logLevel;
        JBLoggerHandler *defaultLoggerHandler;
        handlersListType handlersList;
        JBLoggerFormatter *loggerFormatter;
        static loggersMapType loggersMap;
};

enum JBLogLevel {
    NOTSET = 0,
    DEBUG,
    INFO,
    WARNING,
    FAULT,
    CRITICAL
};
