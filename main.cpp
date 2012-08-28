#include <iostream>
#include <GLUT/GLUT.h>
#include <OpenGL/glu.h>
#include <OpenGL/OpenGL.h>
//#include "OpenGL.h"

/*
void myInit (void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0, 640, 0, 480);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3d (1, 0, 0);
	glBegin (GL_POLYGON);
	glVertex2i (100, 50);
	glVertex2i (100, 130);
	glVertex2i (150, 130);
	glVertex2i (100, 50);
	glEnd ();
	glFlush ();
}


int main (int argc, char * argv[])
{
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("My First Window");
	glutDisplayFunc (myDisplay);
	myInit ();
	glutMainLoop ();
    return 0;
}
*/

/*
static GLfloat spin = 0.0;

void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0); // Black, in RGBA form.
	glShadeModel (GL_FLAT);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT); // Clear the screen
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0); // Set color to white
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin = spin + 2.0;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}

// Function that is called whenever someone resizes the window
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); // Set the canvas to the entire window.
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (-50.0, 50.0, -50.0, 50.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y) 
{
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
		default:
			break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (250, 250); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
*/

/*
int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init();
	glutDisplayFunc (display); 
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	glutMainLoop();
	return 0;
}*/

#define WIDTH 300
#define HEIGHT 600

static int year = 0, day = 0, ypos = 1;

// Initialize OpenGL Coordinate System.
void init (void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0); // Black RGBA
	glShadeModel (GL_SMOOTH);
	//glMatrixMode (GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D (0, WIDTH, 0, HEIGHT);
}


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0); // White RGB
	
	glPushMatrix();
	glTranslatef(0.0, ypos, 0.0);
	glutSolidSphere(1.0, 20, 16);   /* draw sphere */
	//glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
	//glTranslatef (2.0, 0.0, 0.0);
	//glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
	//glutSolidSphere(0.2, 10, 8);    /* draw smaller planet */
	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 'd':
			day = (day + 10) % 360;
			glutPostRedisplay();
			break;
			case 'D':
			day = (day - 10) % 360;
			glutPostRedisplay();
			break;
		case 'y':
			year = (year + 5) % 360;
			glutPostRedisplay();
			break;
			case 'Y':
			year = (year - 5) % 360;
			glutPostRedisplay();
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

void idle (void)
{
	//year = (year + 5) % 360;
	//glutPostRedisplay();
	if (ypos == 1)
		ypos = -1;
	else
		ypos == 1;
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); // Double-buffered RGB display

	glutInitWindowSize (300, 600); 
	glutInitWindowPosition (100, 100);
	
	glutCreateWindow (argv[0]);
	init ();
	
	glutDisplayFunc (display); 
	glutReshapeFunc (reshape);
	glutKeyboardFunc (keyboard);
	glutIdleFunc (idle);
	
	glutMainLoop();
	
	return 0;
}