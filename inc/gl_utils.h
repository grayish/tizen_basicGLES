//
// Created by hobbang5 on 2015-11-09.
//

#ifndef __GL_UTILS_H__
#define __GL_UTILS_H__

/**
 * Initialize 4x4 matrix as identity
 *
 * @param[out] result identity matrix
 */
void init_matrix(float* result);

/**
 * Provides matrix multiply
 *
 * @param[out] result 4x4 result matrix
 * @param[in] matrix0 source 4x4 matrix
 * @param[in] matrix1 source 4x4 matrix
 */
void multiply_matrix(float* result, const float matrix0[16], const float matrix1[16]);

/**
 * Provides rotate matrix
 *
 * @param[out] result 4x4 matrix for rotation
 * @param[in] anglex angle for x axis
 * @param[in] angley angle for y axis
 * @param[in] anglez angle for z axis
 */
void rotate_xyz(float* result, const float anglex, const float angley, const float anglez);

/**
 * Provides translate matrix
 *
 * @param[out] result 4x4 matrix for translation
 * @param[in] translatex distance for x axis
 * @param[in] translatey distance for y axis
 * @param[in] translatez distance for z axis
 */
void translate_xyz(float* result, const float translatex,
                   const float translatey, const float translatez);

/**
 * Provides othorgonal matrix
 *
 * @param[out] result 4x4 matrix for orthogonal projection
 * @param[in] left left of the screen
 * @param[in] right right of the screenv
 * @param[in] bottom bottom of the screen
 * @param[in] top top of the screen
 * @param[in] near near plane
 * @param[in] far far plane
 */
void view_set_ortho(float* result, const float left, const float right,
                    const float bottom, const float top, const float near, const float far);

/**
 * Provides perspective matrix
 *
 * @param[out] result 4x4 matrix for perspective projection
 * @param[in] fovy field of view
 * @param[in] aspect aspect ratio
 * @param[in] near near plane
 * @param[in] far far plane
 */
void view_set_perspective(float* result, const float fovy,
                          const float aspect, const float near, const float far);

/**
 * Get current time tick
 *
 * @return current time tick
 */
long long get_ticks();

/**
 * Calculate frame rate
 *
 * @return frames per second
 */
float get_fps();

#endif //__GL_UTILS_H__
