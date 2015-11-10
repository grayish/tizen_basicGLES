//
// Created by hobbang5 on 2015-11-09.
//

#ifndef __GL_TEXTURE_UTIL_H__
#define __GL_TEXTURE_UTIL_H__

#include <Elementary.h>

/**
 * Create GL Texture object from image file path
 *
 * @param[in] parent parent evas object
 * @param[in] filename image file path
 * @return texture id
 */
unsigned int create_texture(Evas_Object *parent, const char *filename);

#endif /* __GL_TEXTURE_UTIL_H__ */
