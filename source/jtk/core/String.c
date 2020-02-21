/*
 * Copyright 2018-2019 OneCube
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

// Saturday, May 11, 2019

#include <jtk/core/CString.h>
#include <jtk/core/String.h>
#include <jtk/core/StringBuilder.h>

/*******************************************************************************
 * String                                                                      *
 *******************************************************************************/

// Constructor

jtk_String_t* jtk_String_wrap(uint8_t* value, int32_t size, int32_t hashCode) {
    jtk_String_t* string = jtk_Memory_allocate(jtk_String_t, 1);
    string->m_value = value;
    string->m_size = size;
    string->m_hashCode = hashCode;

    return string;
}

jtk_String_t* jtk_String_new(const uint8_t* value) {
    jtk_Assert_assertObject(value, "The specified string is null.");

    return jtk_String_newEx(value, jtk_CString_getSize(value));
}

jtk_String_t* jtk_String_newEx(const uint8_t* value, int32_t size) {
    jtk_Assert_assertObject(value, "The specified string is null.");
    jtk_Assert_assertTrue(size >= 0, "The specified string size is invalid.");

    uint8_t* copy = jtk_CString_newWithSize(value, size);
    return jtk_String_wrap(copy, size, -1);
}

jtk_String_t* jtk_String_newFromJoin(const uint8_t* value1, const uint8_t* value2) {
    jtk_Assert_assertObject(value1, "The specified first string is null.");
    jtk_Assert_assertObject(value2, "The specified second string is null.");
    
    jtk_StringBuilder_t* builder = jtk_StringBuilder_new();
    jtk_StringBuilder_append_z(builder, value1);
    jtk_StringBuilder_append_z(builder, value2);
    
    jtk_String_t* result = jtk_StringBuilder_toString(builder);
    
    jtk_StringBuilder_delete(builder);
    
    return result;
}

jtk_String_t* jtk_String_newFromJoinEx(const uint8_t* value1, int32_t size1,
    const uint8_t* value2, int32_t size2) {
    jtk_Assert_assertObject(value1, "The specified first string is null.");
    jtk_Assert_assertTrue(size1 >= 0, "The specified first string size is invalid.");
    jtk_Assert_assertObject(value2, "The specified second string is null.");
    jtk_Assert_assertTrue(size2 >= 0, "The specified second string size is invalid.");
    
    jtk_StringBuilder_t* builder = jtk_StringBuilder_new();
    jtk_StringBuilder_appendEx_z(builder, value1, size1);
    jtk_StringBuilder_appendEx_z(builder, value2, size2);
    
    jtk_String_t* result = jtk_StringBuilder_toString(builder);
    jtk_StringBuilder_delete(builder);
    
    return result;
}

/* If the specified size is negative for a string entry, that particular string
 * is considered as null-terminated. The jtk_CString_getSize() function is invoked
 * against that string to determine its size.
 *
 * If a string is null, then the string literal "null" is appended.
 */
jtk_String_t* jtk_String_fromJoin(const uint8_t** strings, int32_t* sizes, int32_t count) {
    jtk_Assert_assertObject(strings, "The specified strings array is null.");
    jtk_Assert_assertObject(sizes, "The specified sizes array is null.");
    jtk_Assert_assertTrue(count >= 0, "The specified count is invalid.");
    
    jtk_String_t* result = NULL;
    
    if (count == 0) {
        result = jtk_String_newEx("", 0);
    }
    else {
        jtk_StringBuilder_t* builder = jtk_StringBuilder_new();
        int32_t i;
        for (i = 0; i < count; i++) {
            jtk_StringBuilder_appendEx_z(builder, strings[i], sizes[i]);
        }
        result = jtk_StringBuilder_toString(builder);
        jtk_StringBuilder_delete(builder);
    }
    
    return result;
}

/* If the specified size is negative for a string entry, that particular string
 * is considered as null-terminated. The jtk_CString_getSize() function is invoked
 * against that string to determine its size.
 *
 * If a string is null, then the string literal "null" is appended.
 *
 * The prefix, the suffix, and the separator parameters remain unused if the
 * number strings specified to join is zero.
 */
jtk_String_t* jtk_String_fromJoinEx(const uint8_t** strings, int32_t* sizes,
    int32_t count, const uint8_t* prefix, int32_t prefixSize, const uint8_t* suffix,
    int32_t suffixSize, const uint8_t* separator, int32_t separatorSize) {
    jtk_Assert_assertObject(strings, "The specified strings array is null.");
    jtk_Assert_assertObject(sizes, "The specified sizes array is null.");
    jtk_Assert_assertTrue(count >= 0, "The specified count is invalid.");
    
    jtk_String_t* result = NULL;
    
    if (count == 0) {
        result = jtk_String_newEx("", 0);
    }
    else {
        jtk_StringBuilder_t* builder = jtk_StringBuilder_new();
        jtk_StringBuilder_appendEx_z(builder, prefix, prefixSize);
        int32_t i;
        for (i = 0; i < count; i++) {
            jtk_StringBuilder_appendEx_z(builder, strings[i], sizes[i]);
            if (i + 1 < count) {
                jtk_StringBuilder_appendEx_z(builder, separator, separatorSize);
            }
        }
        jtk_StringBuilder_appendEx_z(builder, suffix, suffixSize);
        result = jtk_StringBuilder_toString(builder);
        jtk_StringBuilder_delete(builder);
    }
    
    return result;
}

// Destructor

void jtk_String_delete(jtk_String_t* string) {
    jtk_Assert_assertObject(string, "The specified string is null.");

    jtk_CString_delete(string->m_value);
    jtk_Memory_deallocate(string);
}

// Clone

jtk_String_t* jtk_String_clone(jtk_String_t* string) {
    jtk_Assert_assertObject(string, "The specified string is null.");

    return jtk_String_newEx(string->m_value, string->m_size);
}

// Equals

bool jtk_String_equals(jtk_String_t* string, jtk_String_t* other) {
    jtk_Assert_assertObject(string, "The specified string is null.");

    return jtk_CString_equals(string->m_value, string->m_size, other->m_value,
        other->m_size);
}

// Hash

int32_t jtk_String_hash(jtk_String_t* string) {
    jtk_Assert_assertObject(string, "The specified string is null.");

    if (string->m_hashCode == -1) {
        string->m_hashCode = jtk_CString_hashEx(string->m_value, string->m_size);
    }
    return string->m_hashCode;
}

// Size

int32_t jtk_String_getSize(jtk_String_t* string) {
    jtk_Assert_assertObject(string, "The specified string is null.");
    
    return string->m_size;
}

// Value

uint8_t* jtk_String_getValue(jtk_String_t* string) {
    jtk_Assert_assertObject(string, "The specified string is null.");
    
    return string->m_value;
}