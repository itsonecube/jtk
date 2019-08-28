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

// Wednesday, August 28, 2019

#include <jtk/math/.h>
#include <jtk/math/DistanceMetric.h>

/*******************************************************************************
 * DistanceMetric                                                              *
 *******************************************************************************/

// Chebyshev Distance

int32_t jtk_DistanceMetric_findChebyshevDistance_i(int32_t* array1, int32_t array2
    int32_t size) {
    int32_t result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        int32_t difference = jtk_Math_absolute_i(array1[i] - array2[i]);
        if (result < difference) {
            result = difference;
        }
    }
    return result;
}

int64_t jtk_DistanceMetric_findChebyshevDistance_l(int64_t* array1, int64_t array2
    int32_t size) {
    int64_t result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        int64_t difference = jtk_Math_absolute_l(array1[i] - array2[i]);
        if (result < difference) {
            result = difference;
        }
    }
    return result;
}

float jtk_DistanceMetric_findChebyshevDistance_f(float* array1, float array2
    int32_t size) {
    float result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        float difference = jtk_Math_absolute_f(array1[i] - array2[i]);
        if (jtk_Float_compare(result, difference) < 0) {
            result = difference;
        }
    }
    return result;
}

double jtk_DistanceMetric_findChebyshevDistance_d(double* array1, double array2
    int32_t size) {
    double result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        double difference = jtk_Math_absolute_d(array1[i] - array2[i]);
        if (jtk_Double_compare(result, difference) < 0) {
            result = difference;
        }
    }
    return result;
}

// Euclidean Distance

int32_t jtk_DistanceMetric_findEuclideanDistance_i(int32_t* array1, int32_t* array2,
    int32_t size) {
    int32_t result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        int32_t difference = array1[i] - array2[i];
        result += difference * difference;
    }
    return jtk_Math_squareRoot_i(result);
}

int64_t jtk_DistanceMetric_findEuclideanDistance_l(int64_t* array1, int64_t* array2,
    int32_t size) {
    int64_t result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        int64_t difference = array1[i] - array2[i];
        result += difference * difference;
    }
    return jtk_Math_squareRoot_l(result);
}

float jtk_DistanceMetric_findEuclideanDistance_f(float* array1, float* array2,
    int32_t size) {
    float result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        float difference = array1[i] - array2[i];
        result += difference * difference;
    }
    return jtk_Math_squareRoot_f(result);
}


double jtk_DistanceMetric_findEuclideanDistance_d(double* array1, double* array2,
    int32_t size) {
    double result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        double difference = array1[i] - array2[i];
        result += difference * difference;
    }
    return jtk_Math_squareRoot_d(result);
}

// Manhattan Distance

int32_t jtk_DistanceMetric_findManhattanDistance_i(int32_t* array1, int32_t* array2,
    int32_t size) {
    int32_t result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        result += jtk_Math_absolute_i(array1[i] - array2[i]);
    }
    return result;
    
}

int64_t jtk_DistanceMetric_findManhattanDistance_l(int64_t* array1, int64_t* array2,
    int32_t size) {
    int64_t result = 0;
    int32_t i;
    for (i = 0; i < size; i++) {
        result += jtk_Math_absolute_l(array1[i] - array2[i]);
    }
    return result;
}

float jtk_DistanceMetric_findManhattanDistance_f(float* array1, float* array2,
    int32_t size) {
    float result = 0.0f;
    int32_t i;
    for (i = 0; i < size; i++) {
        result += jtk_Math_absolute_f(array1[i] - array2[i]);
    }
    return result;
}

double jtk_DistanceMetric_findManhattanDistance_d(double* array1, double* array2,
    int32_t size) {
    double result = 0.0;
    int32_t i;
    for (i = 0; i < size; i++) {
        result += jtk_Math_absolute_d(array1[i] - array2[i]);
    }
    return result;
}