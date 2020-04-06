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

// Wednesday, August 28, 2019

#ifndef JTK_MATH_DISTANCE_METRIC_H
#define JTK_MATH_DISTANCE_METRIC_H

/*******************************************************************************
 * DistanceMetric                                                              *
 *******************************************************************************/

/**
 * @class DistanceMetric
 * @ingroup
 * @author Samuel Rowe <samuelrowe1999@gmail.com>
 * @since JTK 1.1
 */
enum jtk_DistanceMetric_t {

    /**
     * The Euclidean distance is the "ordinary" straight-line distance between
     * two points in Euclidean space.
     *
     * The Euclidean distance between points p and q is the length of the line
     * segment connecting them. In Cartesian coordinates, if p = (p1, p2,..., pN)
     * and q = (q1, q2,..., qN) are two points in Euclidean n-space, then the
     * distance from p to q, or from q to p is given by the the following formula:
     * d(p, q) = d(q, p) = ((q1 - p1) ^ 2 + (q2 - p2) ^ 2 + ... + (qN - pN) ^ 2) ^ (1 / 2)
     *
     * Please visit the page <a href="https://en.wikipedia.org/wiki/Euclidean_distance">Euclidean distance</a>
     * on Wikipedia for more information.
     */
    JTK_DISTANCE_METRIC_EUCLIDEAN,

    /**
     * The Manhattan distance between two vectors p and q in an n-dimensional
     * real vector space with fixed Cartesian coordinate system, is the sum of
     * the lengths of the projections of the line segment between the points
     * onto the coordinate axes. In other words, the Manhattan distance between
     * two points is measured along axes at right angles. In a plane with p1 at
     * (x1, y1) and p2 at (x2, y2), it is |x1 - x2| + |y1 - y2|.
     * More generally in Cartesian coordinates, if p = (p1, p2,..., pN) and q = (q1, q2,..., qN)
     * are two points, then the distance from p to q, or from q to p is given by
     * the the following formula:
     * d(p, q) = d(q, p) = |p1 - q1| + |p2 - q2| + ... + |pN - qN|
     *
     * Manhattan distance is often used in integrated circuits where wires only
     * run parallel to the X or Y axis.
     *
     * Please visit the page <a href="https://en.wikipedia.org/wiki/Taxicab_geometry">Taxicab geometry</a>
     * on Wikipedia for more information.
     */
    JTK_DISTANCE_METRIC_MANHATTAN,

    /**
     * The Chebyshev distance between two vectors p and q in an n-dimensional
     * real vector space with fixed Cartesian coordinate system, is the
     * maximum of the absolute magnitude of the differences between the coordinate
     * dimensions. Chebyshev distance is also called the maximum value distance,
     * or chessboard distance.
     *
     * Generally in Cartesian coordinates, if p = (p1, p2,..., pN) and q = (q1, q2,..., qN)
     * are two points, then the Chebyshev distance from p to q is given by the
     * following formula:
     * d(p, q) = max(|p1 - q1|, |p2 - q2|, ..., |pN - qN|)
     *
     * Please visit the page <a href="https://en.wikipedia.org/wiki/Chebyshev_distance">Chebyshev distance</a>
     * on Wikipedia for more information.
     */
    JTK_DISTANCE_METRIC_CHEBYSHEV,

    /**
     * The Minkowski distance is a generalized metric distance in a normed vector
     * space. When the order is 1, it evaluates the Manhattan distance. Similarly,
     * when the order is 2, it evaluates the Euclidean distance. The Chebyshev
     * distance is a special case of Minkowski distance where the order is infinite.
     *
     * The Minkowski distance of order p between two points p and q, with
     * p = (p1, p2,..., pN) and q = (q1, q2,..., qN), then the Minkowski distance
     * from p to q is given by the following formula:
     * d(p, q) = ((|x1 - y1| ^ p) + (|x2 - y2| ^ p) + ... + (|xN - yN| ^ p)) ^ (1 / p)
     *
     * Please visit the page <a href="https://en.wikipedia.org/wiki/Minkowski_distance">Minkowski distance</a>
     * on Wikipedia for more information.
     */
    JTK_DISTANCE_METRIC_MINKOWSKI,

    /**
     * The Minkowski distance is a generalized metric distance in a normed vector
     * space. When the order is 1, it evaluates the Manhattan distance. Similarly,
     * when the order is 2, it evaluates the Euclidean distance. The Chebyshev
     * distance is a special case of Minkowski distance where the order is infinite.
     *
     * The Minkowski distance of order p between two points p and q, with
     * p = (p1, p2,..., pN) and q = (q1, q2,..., qN), then the Minkowski distance
     * from p to q is given by the following formula:
     * d(p, q) = ((|x1 - y1| ^ p) + (|x2 - y2| ^ p) + ... + (|xN - yN| ^ p)) ^ (1 / p)
     *
     * Please visit the page <a href="https://en.wikipedia.org/wiki/Minkowski_distance">Minkowski distance</a>
     * on Wikipedia for more information.
     */
    JTK_DISTANCE_METRIC_WEIGHTED_MINKOWSKI,

    /**
     * The Euclidean distance is the "ordinary" straight-line distance between
     * two points in Euclidean space.
     *
     * The Euclidean distance between points p and q is the length of the line
     * segment connecting them. In Cartesian coordinates, if p = (p1, p2,..., pN)
     * and q = (q1, q2,..., qN) are two points in Euclidean n-space, then the
     * distance from p to q, or from q to p is given by the the following formula:
     * d(p, q) = d(q, p) = ((q1 - p1) ^ 2 + (q2 - p2) ^ 2 + ... + (qN - pN) ^ 2) ^ (1 / 2)
     *
     * Please visit the page <a href="https://en.wikipedia.org/wiki/Euclidean_distance">Euclidean distance</a>
     * on Wikipedia for more information.
     */
    JTK_DISTANCE_METRIC_WEIGHTED_EUCLIDEAN,

    JTK_DISTANCE_METRIC_MAHALANOBIS,

    JTK_DISTANCE_METRIC_HAMMING,
    JTK_DISTANCE_METRIC_CANBERRA,
    JTK_DISTANCE_METRIC_BRAYCURTIS,

    JTK_DISTANCE_METRIC_EARTH_MOVERS,
    JTK_DISTANCE_METRIC_HAVERSINE,

    JTK_DISTANCE_METRIC_JACCARD,
    JTK_DISTANCE_METRIC_MATCHING,
    JTK_DISTANCE_METRIC_DICE,
    JTK_DISTANCE_METRIC_KULSINSKI,
    JTK_DISTANCE_METRIC_ROGERS_TANIMOTO,
    JTK_DISTANCE_METRIC_RUSSELL_RAO,
    JTK_DISTANCE_METRIC_SOKAL_MICHENER,
    JTK_DISTANCE_METRIC_SOKAL_SNEATH,
};

/**
 * @memberof DistanceMetric
 */
typedef enum jtk_DistanceMetric_t jtk_DistanceMetric_t;

// Manhattan

/**
 * @memberof DistanceMetric
 */
int32_t jtk_DistanceMetric_findManhattanDistance_i(int32_t* array1, int32_t* array2,
    int32_t size);

/**
 * @memberof DistanceMetric
 */
int64_t jtk_DistanceMetric_findManhattanDistance_l(int64_t* array1, int64_t* array2,
    int32_t size);

/**
 * @memberof DistanceMetric
 */
float jtk_DistanceMetric_findManhattanDistance_f(float* array1, float* array2,
    int32_t size);

/**
 * @memberof DistanceMetric
 */
double jtk_DistanceMetric_findManhattanDistance_d(double* array1, double* array2,
    int32_t size);

// Manhattan

/**
 * @memberof DistanceMetric
 */
int32_t jtk_DistanceMetric_findManhattanDistance_i(int32_t* array1, int32_t* array2,
    int32_t size);

/**
 * @memberof DistanceMetric
 */
int64_t jtk_DistanceMetric_findManhattanDistance_l(int64_t* array1, int64_t* array2,
    int32_t size);

/**
 * @memberof DistanceMetric
 */
float jtk_DistanceMetric_findManhattanDistance_f(float* array1, float* array2,
    int32_t size);

/**
 * @memberof DistanceMetric
 */
double jtk_DistanceMetric_findManhattanDistance_d(double* array1, double* array2,
    int32_t size);

#endif /* JTK_MATH_DISTANCE_METRIC_H */