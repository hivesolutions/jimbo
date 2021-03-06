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

#include "packer.h"

#define TAR_BUFFER_SIZE 1024
#define TAR_BUFFER_BASE 512
#define LARGE_NAME_SIZE 102400

struct TarHeaderType {
    char name[100];
    char mode[8];
    char uid[8];
    char gid[8];
    char size[12];
    char modified_time[12];
    char checksum[8];
    char link_flag[1];
    char link_name[100];
    char padding[255];
};

class JBPackerTar : JBPacker {
    private:
    public:
        JB_EXPORT JBPackerTar();
        JB_EXPORT ~JBPackerTar();
        JB_EXPORT static void PackFile(std::string &file_path, std::string &target_path);
        JB_EXPORT static void UnpackFile(std::string &file_path, std::string &target_path);
};
