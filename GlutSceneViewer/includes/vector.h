/*
 * vector.h
 *
 *  Created on: 2012-09-29
 *      Author: francis
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <GL/gl.h>

typedef struct vec3f {
	GLfloat x;
	GLfloat y;
	GLfloat z;
} vec3f;

typedef struct vec2f {
	GLfloat x;
	GLfloat y;
} vec2f;

typedef struct vec2i {
	GLint x;
	GLint y;
} vec2i;

/* Convenience funtion for setting fields of vec3f */
GLvoid setVec3f(vec3f* vec, GLfloat x, GLfloat y, GLfloat z);

/* Add lhs to rhs storing the result in res */
GLvoid addVec3f(vec3f* lhs, vec3f* rhs, vec3f* res);

/* Salar multiply rhs by scalar storing the result in res */
GLvoid scalarMultVec3f(GLfloat scalar, vec3f* rhs, vec3f* res);

/* Return the dot product of rhs and lhs */
GLfloat dotVec3f(vec3f* lhs, vec3f* rhs);


/* Convenience funtion for setting fields of vec2f */
GLvoid setVec2f(vec2f* vec, GLfloat x, GLfloat y);

/* Add lhs to rhs storing the result in res */
GLvoid addVec2f(vec2f* lhs, vec2f* rhs, vec2f* res);

/* Salar multiply rhs by scalar storing the result in res */
GLvoid scalarMultVec2f(GLfloat scalar, vec2f* rhs, vec2f* res);

/* Return the dot product of rhs and lhs */
GLfloat dotVec2f(vec2f* lhs, vec2f* rhs);


/* Convenience funtion for setting fields of vec2i */
GLvoid setVec2i(vec2i* vec, GLint x, GLint y);

/* Add lhs to rhs storing the result in res */
GLvoid addVec2i(vec2i* lhs, vec2i* rhs, vec2i* res);

/* Salar multiply rhs by scalar storing the result in res */
GLvoid scalarMultVec2i(GLint scalar, vec2i* rhs, vec2i* res);

/* Return the dot product of rhs and lhs */
GLint dotVec2i(vec2i* lhs, vec2i* rhs);

#endif /* VECTOR_H_ */
