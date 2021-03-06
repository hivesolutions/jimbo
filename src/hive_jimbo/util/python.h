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

/**
 * The name of the key that can be used to retrieve
 * the installation path of the python system.
 */
#define PYTHON_KEY_NAME "SOFTWARE\\Python\\PythonCore"

class JBPython {
    private:
        /**
         * The length of the buffer to be used for the
         * reg key during the registration percolation
         * operations.
         * This value should be big enough to hold a
         * registry key name.
         */
        static const int buffer_length = 1024;
    public:
        /**
         * Checks if there is any python installation in the system
         * any version may exist in the system.
         *
         * @return The registry key containing the references to the python
         * installation details.
         */
        JB_EXPORT static HKEY CheckPython();

        /**
         * Checks if there is a python installation in the system
         * that meets the required given version.
         *
         * This function allows the version parameter to not be specified
         * in such case the function only checks if one python installation
         * is available in the system (no version matters).
         *
         * @param version The python system version to be checked for
         * availability, in case none is specified any python system is
         * considered to be valid.
         * @return The registry key containing the references to the python
         * installation details.
         */
        JB_EXPORT static HKEY CheckPython(const char *version);

        /**
         * Populats the given list (vector) with the various version string
         * of the installed python systems.
         *
         * This function uses the python checking function, so if no python
         * version is present in the system an exception is thrown.
         *
         * @param versions The list (vector) ti be populated with the various
         * available python versions.
         */
        JB_EXPORT static void GetAvailableVersions(std::vector<std::string> &versions);

        /**
         * Retrieves the installation path to the python system with the requested
         * version.
         * The function is extremely useful for situations where the interpreter must
         * be found in order to execute a command line.
         *
         * This function uses the python checking function, so if no python
         * version is present in the system an exception is thrown.
         *
         * @param version The python system version to retrieve the installation
         * path, this should be a valid python version.
         * @return The string containing the full file path to the requested python
         * installation.
         */
        JB_EXPORT static std::string GetInstallPath(std::string &version);
};
