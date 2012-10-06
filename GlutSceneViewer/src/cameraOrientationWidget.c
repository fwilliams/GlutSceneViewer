/*
 * cameraOrientationWidget.c
 *
 *  Created on: 2012-09-30
 *      Author: francis
 */

#include "cameraOrientationWidget.h"
#include <stdio.h>

GLvoid drawCameraOrientationWidget(CameraOrientationWidget* widget) {
	GLint lineWidth;
	GLint viewportdims[4];

	glGetIntegerv(GL_LINE_WIDTH, &lineWidth);
	glGetIntegerv(GL_VIEWPORT, viewportdims);

	glLineWidth(3.0);

	glViewport(widget->pos.x, widget->pos.y,
			    widget->size.x, widget->size.y);

	glPushMatrix();

	glLoadIdentity();
	glTranslatef(0.0, 0.0, -1.0);

	cameraRotationTransform(widget->camera);

	glScalef(0.5, 0.5, 0.5);

	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(0.8, 0.2, 0.0);
		glVertex3f(0.8, -0.2, 0.0);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(0.2, 0.8, 0.0);
		glVertex3f(-0.2, 0.8, 0.0);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, -1.0);
		glVertex3f(0.2, 0.0, -0.8);
		glVertex3f(-0.2, 0.0, -0.8);
	glEnd();

	glPopMatrix();
	glViewport(viewportdims[0], viewportdims[1],
				viewportdims[2], viewportdims[3]);

	glLineWidth(lineWidth);
}

GLvoid initCameraOrientationWidget4f(
		CameraOrientationWidget* widget, Camera* camera,
		GLint x, GLint y, GLint width, GLint height) {
	widget->camera = camera;
	setVec2i(&(widget->pos), x, y);
	setVec2i(&(widget->size), width, height);
}

GLvoid initCameraOrientationWidget2iv(
		CameraOrientationWidget* widget, Camera* camera,
		vec2i* pos, vec2i* size) {
	widget->camera = camera;
	setVec2i(&(widget->pos), pos->x, pos->y);
	setVec2i(&(widget->size), size->x, size->y);
}

