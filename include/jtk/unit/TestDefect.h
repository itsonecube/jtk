/*
 * Copyright 2017-2020 Samuel Rowe
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Saturday, June 20, 2018

#ifndef JTK_UNIT_TEST_DEFECT_H
#define JTK_UNIT_TEST_DEFECT_H

#include <jtk/Configuration.h>
#include <jtk/unit/TestDefectType.h>

/*******************************************************************************
 * TestDefect                                                                  *
 *******************************************************************************/

/**
 * @class TestDefect
 * @ingroup jtk_unit
 * @author Samuel Rowe <samuelrowe1999@gmail.com>
 * @since JTK 1.0
 */
struct jtk_TestDefect_t {
    int32_t m_lineNumber;
    uint8_t* m_message;
    uint8_t* m_sourceCodePath;
    jtk_TestDefectType_t m_type;
};

/**
 * @memberof TestDefect
 */
typedef struct jtk_TestDefect_t jtk_TestDefect_t;

/**
 * @memberof TestDefect
 */
jtk_TestDefect_t* jtk_TestDefect_new(const uint8_t* sourceCodePath, int32_t lineNumber, const uint8_t* message, jtk_TestDefectType_t type);

/**
 * @memberof TestDefect
 */
jtk_TestDefect_t* jtk_TestDefect_newFailure(const uint8_t* sourceCodePath, int32_t lineNumber, const uint8_t* message);

/**
 * @memberof TestDefect
 */
jtk_TestDefect_t* jtk_TestDefect_newError(const uint8_t* sourceCodePath, int32_t lineNumber, const uint8_t* message);

/**
 * @memberof TestDefect
 */
jtk_TestDefect_t* jtk_TestDefect_newUnknownError(const uint8_t* sourceCodePath, int32_t lineNumber, const uint8_t* message);

/**
 * @memberof TestDefect
 */
void jtk_TestDefect_delete(jtk_TestDefect_t* defect);

/**
 * @memberof TestDefect
 */
const uint8_t* jtk_TestDefect_getMessage(jtk_TestDefect_t* defect);

/**
 * @memberof TestDefect
 */
const uint8_t* jtk_TestDefect_getSourceCodePath(jtk_TestDefect_t* defect);

/**
 * @memberof TestDefect
 */
int32_t jtk_TestDefect_getLineNumber(jtk_TestDefect_t* defect);

/**
 * @memberof TestDefect
 */
jtk_TestDefectType_t jtk_TestDefect_getType(jtk_TestDefect_t* defect);

#endif /* JTK_UNIT_TEST_DEFECT_H */