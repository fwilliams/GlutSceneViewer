/*
 * cameraOrientationWidget.h
 *
 *  Created on: 2012-09-30
 *      Author: francis
 */

#ifndef CAMERAORIENTATIONWIDET_H_
#define CAMERAORIENTATIONWIDET_H_

#include <GL/gl.h>
#include "vector.h"
#include "camera.h"

typedef struct CameraOrientationWidget {
	vec2i pos;
	vec2i size;
	Camera* camera;
} CameraOrientationWidget;

GLvoid drawCameraOrientationWidget(CameraOrientationWidget* widget);

GLvoid initCameraOrientationWidget4f(
	CameraOrientationWidget* widget, Camera* camera,
	GLint x, GLint y, GLint width, GLint height);

GLvoid initCameraOrientationWidget2iv(
		CameraOrientationWidget* widget, Camera* camera,
		vec2i* pos, vec2i* size);


#endif /* CAMERAORIENTATIONWIDET_H_ */
