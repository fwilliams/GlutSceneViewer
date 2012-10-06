/*
 * camera.c
 *
 *  Created on: 2012-09-28
 *      Author: francis
 */

#include "camera.h"

GLvoid resetCamera(Camera* camera) {
	camera->yaw = 0.0;
	camera->pitch = 0.0;
	camera->roll = 0.0;
	camera->x = 0.0;
	camera->y = 0.0;
	camera->z = 0.0;
}

GLvoid initCamera6f(
Camera* camera,
GLfloat x, GLfloat y, GLfloat z,
GLfloat pitch, GLfloat yaw, GLfloat roll) {
	camera->pitch = pitch;
	camera->yaw = yaw;
	camera->roll = roll;
	camera->x = x;
	camera->y = y;
	camera->z = z;
}

GLvoid initCamera2fv(Camera* camera, vec3f* pos, vec3f* orientation) {
	initCamera6f(camera,
				 orientation->x, orientation->y, orientation->z,
				 pos->x, pos->y, pos->z);
}

GLvoid cameraTransform(Camera* camera) {
	glRotatef(-camera->yaw, 1.0f, 0.0f, 0.0f);
	glRotatef(-camera->pitch, 0.0f, 1.0f, 0.0f);
	glRotatef(-camera->roll, 0.0f, 0.0f, 1.0f);
	glTranslatef(-camera->x, -camera->y, -camera->z);
};

GLvoid cameraRotationTransform(Camera* camera) {
	glRotatef(-camera->yaw, 1.0f, 0.0f, 0.0f);
	glRotatef(-camera->pitch, 0.0f, 1.0f, 0.0f);
	glRotatef(-camera->roll, 0.0f, 0.0f, 1.0f);
}

GLvoid moveCamera3f(Camera* camera, GLfloat dx, GLfloat dy, GLfloat dz) {
	camera->x += dx;
	camera->y += dy;
	camera->z += dz;
}

GLvoid moveCamerafv(Camera* camera, vec3f* dPos) {
	moveCamera3f(camera, dPos->x, dPos->y, dPos->z);
}

GLvoid rotateCamera3f(
Camera* camera, GLfloat dPitch, GLfloat dYaw, GLfloat dRoll) {
	camera->pitch += dPitch;
	if(camera->pitch > 360.0) camera->pitch = camera->pitch - 360.0;
	if(camera->pitch < 0.0) camera->pitch = 360.0 + camera->pitch;

	camera->yaw += dYaw;
	if(camera->yaw > 360.0) camera->yaw = camera->yaw - 360.0;
	if(camera->yaw < 0.0) camera->yaw = 360.0 + camera->yaw;

	camera->roll += dRoll;
	if(camera->roll > 360.0) camera->roll = camera->roll - 360.0;
	if(camera->roll < 0.0) camera->roll = 360.0 + camera->roll;
}

GLvoid rotateCamerafv(Camera* camera, vec3f* dOrientation) {
	rotateCamera3f(camera, dOrientation->x, dOrientation->y, dOrientation->z);
}

GLvoid setCameraPos3f(Camera* camera, GLfloat x, GLfloat y, GLfloat z) {
	camera->x = x;
	camera->y = y;
	camera->z = z;
}

GLvoid setCameraPosfv(Camera* camera, vec3f* pos) {
	setCameraPos3f(camera, pos->x, pos->y, pos->z);
}

GLvoid setCameraOrientation3f(
Camera* camera, GLfloat pitch, GLfloat yaw, GLfloat roll) {
	camera->pitch = pitch;
	if(camera->pitch > 360.0) camera->pitch = camera->pitch - 360.0;
	if(camera->pitch < 0.0) camera->pitch = 360.0 + camera->pitch;

	camera->yaw = yaw;
	if(camera->yaw > 360.0) camera->yaw = camera->yaw - 360.0;
	if(camera->yaw < 0.0) camera->yaw = 360.0 + camera->yaw;

	camera->roll = roll;
	if(camera->roll > 360.0) camera->roll = camera->roll - 360.0;
	if(camera->roll < 0.0) camera->roll = 360.0 + camera->roll;
}

GLvoid setCameraOrientationfv(Camera* camera , vec3f* orientation) {
	setCameraOrientation3f(
			camera, orientation->x, orientation->y, orientation->z);
}
