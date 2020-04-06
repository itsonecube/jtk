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

// Tuesday, August 28, 2018

#ifndef JTK_CONCURRENT_THREAD_LOCAL_H
#define JTK_CONCURRENT_THREAD_LOCAL_H

/*******************************************************************************
 * ThreadLocal                                                                 *
 *******************************************************************************/

/**
 * @class ThreadLocal
 * @ingroup jtk_concurrent
 * @author Samuel Rowe <samuelrowe1999@gmail.com>
 * @since JTK 1.1
 */
struct jtk_ThreadLocal_t {
};

/**
 * @memberof ThreadLocal
 */
typedef struct jtk_ThreadLocal_t jtk_ThreadLocal_t;

/* Constructor */

/**
 * @memberof ThreadLocal
 */
jtk_ThreadLocal_t* jtk_ThreadLocal_new();

/* Destructor */

/**
 * @memberof ThreadLocal
 */
void jtk_ThreadLocal_delete(jtk_ThreadLocal_t* threadLocal);

#endif /* JTK_CONCURRENT_THREAD_LOCAL_H */