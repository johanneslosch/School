// Farbwürfel mit den Pfeiltasten drehbar
#include <stdio.h>
#include <GL/glut2.h>

GLfloat xRotationAngle = 0.0f;       // aktueller Rotationswinkel
GLfloat yRotationAngle = 0.0f;

GLfloat xRotationSpeed = 0.0f;       // Rotationsgeschwindigkeit
GLfloat yRotationSpeed = 0.0f;

GLenum face=GL_FRONT_AND_BACK, mode=GL_FILL;
int width = 400;
int height = 400;


void display(void)									
{
	GLfloat point0[3] = { 0.0f, 0.0f, 0.0f };      // Wuerfeleckpunkte
	GLfloat point1[3] = { 1.0f, 0.0f, 0.0f };
	GLfloat point2[3] = { 1.0f, 1.0f, 0.0f };
	GLfloat point3[3] = { 0.0f, 1.0f, 0.0f };
	GLfloat point4[3] = { 0.0f, 0.0f, 1.0f };
	GLfloat point5[3] = { 1.0f, 0.0f, 1.0f };
	GLfloat point6[3] = { 1.0f, 1.0f, 1.0f };
	GLfloat point7[3] = { 0.0f, 1.0f, 1.0f };

	glPolygonMode( face, mode);
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Hintergrund & Tiefenpuffer loeschen

	glLoadIdentity();
	gluLookAt(0.5, 0.5, 3.0, 0.5, 0.5, 0.0, 0.0, 1.0, 0.0);   // Kamera setzen
	// gluLookAt(3, 3, 3, 0, 0, 0, 0.0, 1.0, 0.0);

	glTranslatef(0.5f, 0.5f, 0.5f);                      // Wuerfel zurueckschieben
	glRotatef(xRotationAngle, 1.0f, 0.0f, 0.0f);         // Wuerfel rotieren
	glRotatef(yRotationAngle, 0.0f, 1.0f, 0.0f);
	glTranslatef(-0.5f, -0.5f, -0.5f);                   // Wuerfel in Ursprung schieben

	glBegin(GL_POLYGON);                // Vierecke darstellen
		glColor3f(1,0,0);                 // Farbe fuer Wuerfelseite
		glVertex3fv(point0);              // 4 Eckpunkte der Seite
		glVertex3fv(point3);
		glVertex3fv(point2);
		glVertex3fv(point1);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0,1,0);
		glVertex3fv(point1);
		glVertex3fv(point2);
		glVertex3fv(point6);
		glVertex3fv(point5);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0,0,1);
		glVertex3fv(point5);
		glVertex3fv(point6);
		glVertex3fv(point7);
		glVertex3fv(point4);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,1,0);
		glVertex3fv(point4);
		glVertex3fv(point7);
		glVertex3fv(point3);
		glVertex3fv(point0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1,0,1);
		glVertex3fv(point7);
		glVertex3fv(point6);
		glVertex3fv(point2);
		glVertex3fv(point3);
	glEnd();
/*	glBegin(GL_POLYGON);
		glColor3f(0,1,1);
		glVertex3fv(point0);
		glVertex3fv(point1);
		glVertex3fv(point5);
		glVertex3fv(point4);
	glEnd();                        // Ende Darstellung
*/
	xRotationAngle += xRotationSpeed;       // Rotationswinkel erhoehen
	yRotationAngle += yRotationSpeed;

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'p':
			face = GL_FRONT; mode = GL_POINT;
			glutPostRedisplay();
			break;
		case 'P':
			face = GL_BACK; mode = GL_POINT;
			glutPostRedisplay();
			break;
		case 'l':
			face = GL_FRONT; mode = GL_LINE;
			glutPostRedisplay();
			break;			
		case 'L':
			face = GL_BACK; mode = GL_LINE;
			glutPostRedisplay();
			break;			
		case 'f':
			face = GL_FRONT; mode = GL_FILL;
			glutPostRedisplay();
			break;
		case 'F':
			face = GL_BACK; mode = GL_FILL;
			glutPostRedisplay();
			break;
      default:
         break;
   }
}

void special(int key, int x, int y)
{

	switch (key) {
	case GLUT_KEY_UP :
		xRotationSpeed -= 0.08f;     // Schrittweite fuer Drehwinkel durch Pfeiltasten aendern
		break;
	case GLUT_KEY_DOWN :
		xRotationSpeed += 0.08f;	
		break;
	case GLUT_KEY_LEFT :
		yRotationSpeed -= 0.08f;
		break;
	case GLUT_KEY_RIGHT :
		yRotationSpeed += 0.08f;
		break;
	}
}

void idle(void)
{
	display();               // display Funktion dauernd aufrufen
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("Farbwuerfel");

	glutDisplayFunc(display);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	glEnable(GL_DEPTH_TEST);             // z-Buffer aktivieren

	glViewport(0,0,width,height);        // Viewport auf komplettes Fenster setzen

	glMatrixMode(GL_PROJECTION);         // Projektionsmatrix aktivieren
	glLoadIdentity();
	gluPerspective(60, 1, 1, 20);      // Parallelprojektion
	glMatrixMode(GL_MODELVIEW);          // ab jetzt Modelview Matrix

	glutMainLoop();
}
