/*
 Hive Jimbo Library
 Copyright (C) 2008 Hive Solutions Lda.

 This file is part of Hive Jimbo Library.

 Hive Jimbo Library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Hive Jimbo Library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Hive Jimbo Library. If not, see <http://www.gnu.org/licenses/>.

 __author__    = João Magalhães <joamag@hive.pt>
 __version__   = 1.0.0
 __revision__  = $LastChangedRevision$
 __date__      = $LastChangedDate$
 __copyright__ = Copyright (c) 2008 Hive Solutions Lda.
 __license__   = GNU General Public License (GPL), Version 3
*/

#include "stdafx.h"

#include "packer_structures.h"

CPackerElement::CPackerElement() {
}

CPackerElement::CPackerElement(std::string &name, std::string &path) {
    this->name = name;
    this->path = path;
}

CPackerElement::~CPackerElement() {
}

CPackerFile::CPackerFile() : CPackerElement() {
}

CPackerFile::CPackerFile(std::string &name, std::string &path, std::fstream *fileStream, std::string &mimeType) : CPackerElement(name, path) {
    this->fileStream = fileStream;
    this->mimeType = mimeType;
}

CPackerFile::~CPackerFile() {
}

void CPackerFile::addFile(std::string &filePath, CPackerFile *packerFile) {
    CPackerElement::addFile(filePath, packerFile);

}

void CPackerFile::removeFile(std::string &filePath) {
    CPackerElement::removeFile(filePath);
}

CPackerDirectory::CPackerDirectory() {
}

CPackerDirectory::CPackerDirectory(std::string &name, std::string &path) : CPackerElement(name, path) {
}

CPackerDirectory::~CPackerDirectory() {
}

void CPackerDirectory::addFile(std::string &filePath, CPackerFile *packerFile) {
    CPackerElement::addFile(filePath, packerFile);

    int index = filePath.find("/");

    if(index == std::string::npos) {
        this->elementsMap[filePath] = packerFile;
    }
    else {
        std::string fileDirectoryName = filePath.substr(0, index);
        std::string fileNewPath = filePath.substr(index + 1);

        if(this->elementsMap.find(fileDirectoryName) == this->elementsMap.end())
            this->elementsMap[fileDirectoryName] = new CPackerDirectory(fileDirectoryName, fileDirectoryName);

         this->elementsMap[fileDirectoryName]->addFile(fileNewPath, packerFile);
    }
}

void CPackerDirectory::removeFile(std::string &filePath) {
    CPackerElement::removeFile(filePath);
}
