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

class JBProcess {
    public:
        /**
         * Checks if the executable (exe) with the given name is running
         * and returns the value of it.
         *
         * @param exeName The name of the executable (exe) to be tested
         * for running.
         * @param running Pointer to the boolean to receive the result
         * of the executable running test.
         * @return The success of the function call.
         */
        JIMBO_EXPORT_PREFIX static bool isRunning(char *exeName, bool *processRunning);

        /**
         * Retrieves the of processes running for the executable (exe)
         * with the given name.
         *
         * @param exeName The name of the executable (exe) to retrieve
         * the number of processes running.
         * @param count Pointer to the interger to receive the the number
         * of processes running.
         * @return The success of the function call.
         */
        JIMBO_EXPORT_PREFIX static bool getRunning(char *exeName, int *count);
};
