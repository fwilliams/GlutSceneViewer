/*
 * camera.h
 *
 *  Created on: 2012-09-28
 *      Author: francis
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/gl.h>
#include "vector.h"

typedef struct camera {
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat pitch;
	GLfloat yaw;
	GLfloat roll;
} Camera;

/* Resets the camera to the default pose and orientation.
 * That is at position (0, 0, 0) looking down the -Z axis */
GLvoid resetCamera(Camera* camera);

/* Initializes the given camera with the given pose and orientation
 * specified as floating point values */
GLvoid initCamera6f(Camera* camera,
		GLfloat x, GLfloat y, GLfloat z,
		GLfloat pitch, GLfloat yaw, GLfloat roll);

/* Initializes the given camera with the given pose and orientation
 * specified as 3 dimensional floating point vectors */
GLvoid initCamera2fv(Camera* camera, vec3f* pos, vec3f* orientation);

/* Applies the camera transformation to the current active matrix */
GLvoid cameraTransform(Camera* camera);

/* Applies only the rotation component of the camera transformation
 * to the currently active matrix */
GLvoid cameraRotationTransform(Camera* camera);

/* Translates the camera by (dx, dy, dz) */
GLvoid moveCamera3f(Camera* camera, GLfloat dx, GLfloat dy, GLfloat dz);

/* Translates the camera by dPos vector */
GLvoid moveCamerafv(Camera* camera, vec3f* dPos);

/* Rotates the camera by the Euler angles dPitch dYaw and dRoll
 * which specify rotations about the X, Y and Z axes respectively */
GLvoid rotateCamera3f(
		Camera* camera, GLfloat dPitch, GLfloat dYaw, GLfloat dRoll);

/* Rotates the camera by the vector of Euler angles specified in
 * dOrientation vector. Where (x, y, z) = (dPitch, dYaw, dRoll) */
GLvoid rotateCamerafv(Camera* camera, vec3f* dOrientation);

/* Sets the position of the camera to (x, y, z) */
GLvoid setCameraPos3f(Camera* camera, GLfloat x, GLfloat y, GLfloat z);

/* Sets the position of the camera to the pos vector */
GLvoid setCameraPosfv(Camera* camera, vec3f* pos);

/* Set the orientation of the camera to the given Euler angles
 * pitch yaw and roll swhich specify rotations about the X, Y
 * and Z axes respectively */
GLvoid setCameraOrientation3f(
		Camera* camera, GLfloat pitch, GLfloat yaw, GLfloat roll);

/* Set the orientation of the camera to the Euler angles specified in
 * orientation vector. Where (x, y, z) = (pitc, yaw, roll) */
GLvoid setCameraOrientationfv(Camera* camera, vec3f* orientation);
#endif /* CAMERA_H_ */
