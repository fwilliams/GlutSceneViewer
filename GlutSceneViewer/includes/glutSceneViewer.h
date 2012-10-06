/*
 * glutSceneViewer.h
 *
 *  Created on: 2012-09-30
 *      Author: francis
 */

#ifndef GLUTSCENEVIEWER_H_
#define GLUTSCENEVIEWER_H_

#include <GL/glut.h>

void gsvInit(int* argc, char** argv,
		int windowWidth, int windowHeight,
		int windowX, int windowY, const char* windowName);

void gsvStart(void);
void gsvSetMouseButtonHandler(void (*callback)(int, int, int, int));
void gsvSetMouseMotionHandler(void (*callback)(int, int));
void gsvSetKeyHandler(void (*callback)(unsigned char, int, int));
void gsvSetSpecialKeyHandler(void (*callback)(int, int, int));

void gsvSetWindowResizeHandler(void (*callback)(int, int));
void gsvSetDrawHandler(void (*callback)(void));

#endif /* GLUTSCENEVIEWER_H_ */
