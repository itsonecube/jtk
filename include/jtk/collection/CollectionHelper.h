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

// Thursday, July 12, 2018

#ifndef JTK_COLLECTION_COLLECTION_HELPER_H
#define JTK_COLLECTION_COLLECTION_HELPER_H

#include <jtk/collection/CollectionType.h>
#include <jtk/collection/Iterator.h>

/**
 * @class CollectionHelper
 * @ingroup jtk_collection
 * @author Samuel Rowe <samuelrowe1999@gmail.com>
 * @since JTK 1.0
 */

/*******************************************************************************
 * CollectionHelper                                                            *
 *******************************************************************************/

/**
 * @memberof CollectionHelper
 */
jtk_Iterator_t* jtk_CollectionHelper_getIterator(jtk_CollectionType_t type, void* collection);

#endif /* JTK_COLLECTION_COLLECTION_HELPER_H */