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

#include "stdafx.h"

#include "packer.h"

JBPacker::JBPacker() {
}

JBPacker::~JBPacker() {
}

void JBPacker::AddFile(std::string &file_path, std::fstream &file_stream) {
    this->base_directory.AddFile(file_path, new JBPackerFile(file_path, file_path, &file_stream));
}

void JBPacker::RemoveFile(std::string &file_path) {
}

void JBPacker::PackFile(std::string &file_path, std::string &target_path) {
}

void JBPacker::UnpackFile(std::string &file_path, std::string &target_path) {
}
