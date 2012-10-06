/*
 * glutSceneViewer.cpp
 *
 *  Created on: 2012-09-30
 *      Author: francis
 */

#include "glutSceneViewer.h"

#include "camera.h"
#include "cameraOrientationWidget.h"

typedef int MouseButton;

#define GSV_NO_BUTTON 0x0003

struct SceneViewerContext {
	MouseButton button;
	Camera camera;
	CameraOrientationWidget camWidget;
	vec2i lastMousePos;
	vec3f transVel;
	vec2f degsPerPixel;
	vec2f metersPerPixel;
	vec2i windowDims;
	void (*mouseButtonHandler)(int, int, int, int);
	void (*mouseMotionHandler)(int, int);
	void (*keyHandler)(unsigned char, int, int);
	void (*specialKeyHandler)(int, int, int);
	void (*windowResizeHandler)(int, int);
	void (*drawHandler)(void);
} svCtx;


void drawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	cameraTransform(&svCtx.camera);

	if(svCtx.drawHandler != NULL)
		svCtx.drawHandler();

	drawCameraOrientationWidget(&svCtx.camWidget);

	glFlush();
	glutSwapBuffers();
}

void windowResize(int w, int h) {
	setVec2i(&svCtx.windowDims, w, h);
	initCameraOrientationWidget4f(
			&svCtx.camWidget, &svCtx.camera,
			svCtx.windowDims.x-w/4, 0, w/4, w/4);

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-0.5, 0.5, -0.5, 0.5, 0.5, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if(svCtx.windowResizeHandler != NULL)
		svCtx.windowResizeHandler(w, h);
}

void keyEvent(unsigned char key, int x, int y) {
	switch(key) {
		case 27: // 27 = ESC
			exit(0);
			break;
		case 'w':
			moveCamera3f(&svCtx.camera, 0.0, 0.0, -svCtx.transVel.z);
			break;
		case 's':
			moveCamera3f(&svCtx.camera, 0.0, 0.0, svCtx.transVel.z);
			break;
		case 'a':
			moveCamera3f(&svCtx.camera, svCtx.transVel.x, 0.0, 0.0);
			break;
		case 'd':
			moveCamera3f(&svCtx.camera, -svCtx.transVel.x, 0.0, 0.0);
			break;
		default:
			break;
	}

	if(svCtx.keyHandler != NULL)
		svCtx.keyHandler(key, x, y);

	glutPostRedisplay();
}

// TODO: Implement arrow key motion
void specialKeyEvent(int key, int x, int y) {
	if(svCtx.specialKeyHandler != NULL)
		svCtx.specialKeyHandler(key, x, y);

	glutPostRedisplay();
}

void mouseButtonEvent(int button, int state, int x, int y) {
	if(state == GLUT_UP) {
		svCtx.button = GSV_NO_BUTTON;
	} else if(state == GLUT_DOWN) {
		svCtx.button = button;
		setVec2i(&svCtx.lastMousePos, x, y);
	}

	if(svCtx.mouseButtonHandler != NULL)
		svCtx.mouseButtonHandler(button, state, x, y);

	glutPostRedisplay();
}

void mouseMotionEvent(int x, int y) {
	if(svCtx.button == GSV_NO_BUTTON) {
		return;
	} else if(svCtx.button == GLUT_LEFT_BUTTON) {
		float pitch = (x - svCtx.lastMousePos.x)*svCtx.degsPerPixel.x;
		float yaw = (y - svCtx.lastMousePos.y)*svCtx.degsPerPixel.y;
		rotateCamera3f(&svCtx.camera, pitch, yaw, 0.0);
	} else if(svCtx.button == GLUT_RIGHT_BUTTON) {
		float translateX = (x-svCtx.lastMousePos.x)*svCtx.metersPerPixel.x;
		float translateY = (y-svCtx.lastMousePos.y)*svCtx.metersPerPixel.y;
		moveCamera3f(&svCtx.camera, -translateX, translateY, 0.0);
	}

	setVec2i(&svCtx.lastMousePos, x, y);

	if(svCtx.mouseMotionHandler != NULL)
		svCtx.mouseMotionHandler(x, y);

	glutPostRedisplay();
}

void gsvInit(int* argc, char** argv,
		int windowWidth, int windowHeight,
		int windowX, int windowY, const char* windowName) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(windowX, windowY);
	glutCreateWindow(windowName);

	glEnable(GL_DEPTH_TEST);
	initCamera6f(&svCtx.camera, 0.0, 0.0, 5.0, 0.0, 0.0, 0.0);
	setVec2f(&svCtx.degsPerPixel, 0.1, 0.1);
	setVec2f(&svCtx.metersPerPixel, 0.01, 0.01);
	setVec3f(&svCtx.transVel, 0.5, 0.5, 0.5);

	glutDisplayFunc(drawScene);
	glutReshapeFunc(windowResize);
	glutKeyboardFunc(keyEvent);
	glutSpecialFunc(specialKeyEvent);
	glutMouseFunc(mouseButtonEvent);
	glutMotionFunc(mouseMotionEvent);
}

void gsvStart(void) {
	glutMainLoop();
}

void gsvSetMouseButtonHandler(void (*callback)(int, int, int, int)) {
	svCtx.mouseButtonHandler = callback;
}

void gsvSetMouseMotionHandler(void (*callback)(int, int)) {
	svCtx.mouseMotionHandler = callback;
}

void gsvSetKeyHandler(void (*callback)(unsigned char, int, int)) {
	svCtx.keyHandler = callback;
}

void gsvSetSpecialKeyHandler(void (*callback)(int, int, int)) {
	svCtx.specialKeyHandler = callback;
}

void gsvSetWindowResizeHandler(void (*callback)(int, int)) {
	svCtx.windowResizeHandler = callback;
}

void gsvSetDrawHandler(void (*callback)(void)) {
	svCtx.drawHandler = callback;
}


