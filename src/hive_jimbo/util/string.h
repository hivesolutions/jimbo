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

#pragma once

/**
 * Class containing a series of general util
 * method used to operate and mofify string object.
 * The method contained in these class are meant
 * to be used with the standard string implementation.
 */
class CString {
    public:
        /**
         * Trims te given string, removing its initial and final
         * space "like" chracters.
         * The given string character is modified during the operation.
         *
         * @param stringValue The string value to be trimmed, this value
         * is going to be changed durint the operation.
         * @return The resulting string value after the trimming operation.
         */
        JIMBO_EXPORT_PREFIX static std::string &trim(std::string &stringValue);

        /**
         * "Left" trims te given string, removing its initial space
         * "like" chracters.
         * The given string character is modified during the operation.
         *
         * @param stringValue The string value to be "left" trimmed,
         * this value is going to be changed durint the operation.
         * @return The resulting string value after the trimming operation.
         */
        JIMBO_EXPORT_PREFIX static std::string &ltrim(std::string &stringValue);

        /**
         * "Right" trims te given string, removing its final space
         * "like" chracters.
         * The given string character is modified during the operation.
         *
         * @param stringValue The string value to be "right" trimmed,
         * this value is going to be changed durint the operation.
         * @return The resulting string value after the trimming operation.
         */
        JIMBO_EXPORT_PREFIX static std::string &rtrim(std::string &stringValue);
};
