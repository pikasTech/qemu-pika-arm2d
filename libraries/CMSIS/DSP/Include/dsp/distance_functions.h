/******************************************************************************
 * @file     distance_functions.h
 * @brief    Public header file for CMSIS DSP Library
 * @version  V1.10.0
 * @date     08 July 2021
 * Target Processor: Cortex-M and Cortex-A cores
 ******************************************************************************/
/*
 * Copyright (c) 2010-2020 Arm Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 
#ifndef _DISTANCE_FUNCTIONS_H_
#define _DISTANCE_FUNCTIONS_H_

#include "arm_math_types.h"
#include "arm_math_memory.h"

#include "dsp/none.h"
#include "dsp/utils.h"

#include "dsp/statistics_functions.h"
#include "dsp/basic_math_functions.h"
#include "dsp/fast_math_functions.h"

#ifdef   __cplusplus
extern "C"
{
#endif


/**
 * @defgroup groupDistance Distance functions
 *
 * Distance functions for use with clustering algorithms.
 * There are distance functions for float vectors and boolean vectors.
 *
 */

/* 6.14 bug */
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6100100) && (__ARMCC_VERSION < 6150001)
 
__attribute__((weak)) float __powisf2(float a, int b);

#endif 

/**
 * @brief        Euclidean distance between two vectors
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */

float32_t arm_euclidean_distance_f32(const float32_t *pA,const float32_t *pB, uint32_t blockSize);

/**
 * @brief        Bray-Curtis distance between two vectors
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */
float32_t arm_braycurtis_distance_f32(const float32_t *pA,const float32_t *pB, uint32_t blockSize);

/**
 * @brief        Canberra distance between two vectors
 *
 * This function may divide by zero when samples pA[i] and pB[i] are both zero.
 * The result of the computation will be correct. So the division per zero may be
 * ignored.
 *
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */
float32_t arm_canberra_distance_f32(const float32_t *pA,const float32_t *pB, uint32_t blockSize);


/**
 * @brief        Chebyshev distance between two vectors
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */
float32_t arm_chebyshev_distance_f32(const float32_t *pA,const float32_t *pB, uint32_t blockSize);


/**
 * @brief        Cityblock (Manhattan) distance between two vectors
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */
float32_t arm_cityblock_distance_f32(const float32_t *pA,const float32_t *pB, uint32_t blockSize);

/**
 * @brief        Correlation distance between two vectors
 *
 * The input vectors are modified in place !
 *
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */
float32_t arm_correlation_distance_f32(float32_t *pA,float32_t *pB, uint32_t blockSize);

/**
 * @brief        Cosine distance between two vectors
 *
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */

float32_t arm_cosine_distance_f32(const float32_t *pA,const float32_t *pB, uint32_t blockSize);

/**
 * @brief        Jensen-Shannon distance between two vectors
 *
 * This function is assuming that elements of second vector are > 0
 * and 0 only when the corresponding element of first vector is 0.
 * Otherwise the result of the computation does not make sense
 * and for speed reasons, the cases returning NaN or Infinity are not
 * managed.
 *
 * When the function is computing x log (x / y) with x 0 and y 0,
 * it will compute the right value (0) but a division per zero will occur
 * and shoudl be ignored in client code.
 *
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */

float32_t arm_jensenshannon_distance_f32(const float32_t *pA,const float32_t *pB,uint32_t blockSize);

/**
 * @brief        Minkowski distance between two vectors
 *
 * @param[in]    pA         First vector
 * @param[in]    pB         Second vector
 * @param[in]    n          Norm order (>= 2)
 * @param[in]    blockSize  vector length
 * @return distance
 *
 */



float32_t arm_minkowski_distance_f32(const float32_t *pA,const float32_t *pB, int32_t order, uint32_t blockSize);

/**
 * @brief        Dice distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    order           Distance order
 * @param[in]    blockSize       Number of samples
 * @return distance
 *
 */


float32_t arm_dice_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Hamming distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_hamming_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Jaccard distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_jaccard_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Kulsinski distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_kulsinski_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Roger Stanimoto distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_rogerstanimoto_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Russell-Rao distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_russellrao_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Sokal-Michener distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_sokalmichener_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Sokal-Sneath distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_sokalsneath_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);

/**
 * @brief        Yule distance between two vectors
 *
 * @param[in]    pA              First vector of packed booleans
 * @param[in]    pB              Second vector of packed booleans
 * @param[in]    numberOfBools   Number of booleans
 * @return distance
 *
 */

float32_t arm_yule_distance(const uint32_t *pA, const uint32_t *pB, uint32_t numberOfBools);



#ifdef   __cplusplus
}
#endif

#endif /* ifndef _DISTANCE_FUNCTIONS_H_ */
