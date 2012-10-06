/*
 * vector.cpp
 *
 *  Created on: 2012-09-29
 *      Author: francis
 */

#include "vector.h"

/********************
 * vec3f functions
 ********************/

/* Convenience funtion for setting fields of vec3f */
GLvoid setVec3f(vec3f* vec, GLfloat x, GLfloat y, GLfloat z) {
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

/* Add lhs to rhs storing the result in res */
GLvoid addVec3f(vec3f* lhs, vec3f* rhs, vec3f* res) {
	res->x = lhs->x + rhs->x;
	res->y = lhs->y + rhs->y;
	res->z = lhs->z + rhs->z;
}

/* Salar multiply rhs by scalar storing the result in res */
GLvoid scalarMultVec3f(GLfloat scalar, vec3f* rhs, vec3f* res) {
	res->x = scalar * rhs->x;
	res->y = scalar * rhs->y;
	res->z = scalar * rhs->z;
}

/* Return the dot product of rhs and lhs */
GLfloat dotVec3f(vec3f* lhs, vec3f* rhs) {
	return lhs->x*rhs->x + lhs->y*rhs->y + lhs->z*rhs->y;
}


/********************
 * vec2f functions
 ********************/

/* Convenience funtion for setting fields of vec2f */
GLvoid setVec2f(vec2f* vec, GLfloat x, GLfloat y) {
	vec->x = x;
	vec->y = y;
}

/* Add lhs to rhs storing the result in res */
GLvoid addVec2f(vec2f* lhs, vec2f* rhs, vec2f* res) {
	res->x = lhs->x + rhs->x;
	res->y = lhs->y + rhs->y;
}

/* Salar multiply rhs by scalar storing the result in res */
GLvoid scalarMultVec2f(GLfloat scalar, vec2f* rhs, vec2f* res) {
	res->x = scalar * rhs->x;
	res->y = scalar * rhs->y;
}

/* Return the dot product of rhs and lhs */
GLfloat dotVec2f(vec2f* lhs, vec2f* rhs) {
	return lhs->x*rhs->x + lhs->y*rhs->y;
}


/********************
 * vec2i functions
 ********************/

/* Convenience funtion for setting fields of vec2i */
GLvoid setVec2i(vec2i* vec, GLint x, GLint y) {
	vec->x = x;
	vec->y = y;
}

/* Add lhs to rhs storing the result in res */
GLvoid addVec2i(vec2i* lhs, vec2i* rhs, vec2i* res) {
	res->x = lhs->x + rhs->x;
	res->y = lhs->y + rhs->y;
}

/* Salar multiply rhs by scalar storing the result in res */
GLvoid scalarMultVec2i(GLint scalar, vec2i* rhs, vec2i* res) {
	res->x = scalar * rhs->x;
	res->y = scalar * rhs->y;
}

/* Return the dot product of rhs and lhs */
GLint dotVec2i(vec2i* lhs, vec2i* rhs) {
	return lhs->x*rhs->x + lhs->y*rhs->y;
}
