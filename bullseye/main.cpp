
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define xpix 500
#define PI 3.1416
#include <cstring>
#include"target.h"
using namespace std;

float cx=0.0, cx1=0.0, cy1=100;
float r, g=0.0, b, x, y;
bool flag = false ;
bool start = true;
bool moveleft = false, moveright = true;
int counter = 1;
int hearts = 10;
float speed;
int level = 1; 

float targetx=200, targety=350;

void bow_model() {
	int x1 = 0, y1 = 0;
	glPushMatrix();
	glLineWidth(2);
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	glVertex2i(x1 - 50, y1 + 40);
	glVertex2i(x1, y1);
	glVertex2i(x1 + 65, y1 - 29);
	glEnd();
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 0);
	glVertex2i(x1 + 65, y1 - 34);

	glVertex2i(x1 + 40, y1 + 40);
	glVertex2i(x1 - 55, y1 + 40);
	
	glEnd();

	glPopMatrix();

}
void arrow_model(){
	int x1=0,y1=0;
	glPushMatrix();
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	glVertex2i(x1 - 15, y1);
	glVertex2i(x1, y1);
	glVertex2i(x1, y1-15);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x1 + 40, y1 + 40);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex2i(x1 + 20, y1 + 40);
	glVertex2i(x1 + 40, y1 + 40);
	glVertex2i(x1 + 40, y1 + 20);
	glEnd();
	glPopMatrix();
}

void circle(GLdouble rad){

	GLint points = 50;
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 0.0;

	glBegin(GL_POLYGON);
	{
		for (int i = 0; i <= 50; i++, theta += delTheta)
		{
			glVertex2f(rad * cos(theta), rad * sin(theta));
		}
	}
	glEnd();
}

void cloud_model_one() {

	glColor3f(1.25, 0.924, 0.930);

	///Top_Left

	glPushMatrix();
	glTranslatef(320, 210, 0);
	circle(15);
	glPopMatrix();

	///Top

	glPushMatrix();
	glTranslatef(340, 225, 0);
	circle(16);
	glPopMatrix();

	///Right

	glPushMatrix();
	glTranslatef(360, 210, 0);
	circle(16);
	glPopMatrix();


	///middle_Fill
	glPushMatrix();
	glTranslatef(355, 210, 0);
	circle(16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 210, 0);
	circle(16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(345, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(340, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(335, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(330, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(325, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(320, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(315, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(310, 204, 0);
	circle(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(305, 204, 0);
	circle(10);
	glPopMatrix();

	///****Fill End****

}

void cloud_model_Three() {
	glColor3f(1.25, 0.924, 0.930);

	///Left_Part
	glPushMatrix();
	glTranslatef(300, 200, 0);
	circle(15);
	glPopMatrix();

	///Top_Left

	glPushMatrix();
	glTranslatef(320, 210, 0);
	circle(15);
	glPopMatrix();

	///Top
	glPushMatrix();
	glTranslatef(340, 220, 0);
	circle(16);
	glPopMatrix();

	///Top_Right
	glPushMatrix();
	glTranslatef(360, 210, 0);
	circle(15);
	glPopMatrix();

	///Right_Part
	glPushMatrix();
	glTranslatef(380, 200, 0);
	circle(15);
	glPopMatrix();

	///Bottom_Right
	glPushMatrix();
	glTranslatef(360, 190, 0);
	circle(20);
	glPopMatrix();

	///Bottom_Left
	glPushMatrix();
	glTranslatef(320, 190, 0);
	circle(20);
	glPopMatrix();

	///Bottom
	glPushMatrix();
	glTranslatef(340, 190, 0);
	circle(20);
	glPopMatrix();




	///****Fill End****

}

void cloud_one() {
	glPushMatrix();
	glTranslatef(cx1, cy1, 0);
	cloud_model_one();
	glPopMatrix();

}

void cloud_two() {
	glPushMatrix();
	glTranslatef(cx-300, 150, 0);
	cloud_model_Three();
	glPopMatrix();

}

void arrow(void) {
	if (flag) {
		glClear(GL_COLOR_BUFFER_BIT);
		x += 1.0;
		y += 1.0;
		glPushMatrix();
		glTranslatef(x, y, 0);
		arrow_model();
		glPopMatrix();



		if ((x + 80 >= targetx && x <= targetx) && (y + 80 >= targety && y <= targety)) {
			counter++;
			x = 0; y = 0;
			
			
			glRasterPos3f(200, 250, 0);
			string s = "Win ";
			
				
			for (int i = 0; i < s.length(); i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s.at(i));
			}
			

			glClear(GL_COLOR_BUFFER_BIT);
			flag = false;

			
		}
		else if ((x + 80 >= cx && x <= cx) && (y + 80 >= cy1 && y <= cy1)) {
			counter=3;
		}
		else if (x+150 >= 800 || y+150 >= 600) {
			
			
			if (hearts > 0) {
				hearts--;
				flag = false;
			}
				
				//start = false;
				if (hearts == 0) {
					start = false;
					glRasterPos3f(250, 250, 0);
					string s = "GAME OVER";
					speed = 0.2;
					hearts = 5;


					for (int i = 0; i < s.length(); i++)
					{
						glutBitmapCharacter(((void*)5), s.at(i));
					}
					glColor3f(1, 1, 1);
					glRasterPos3f(250, 200, 0);

					s = "Score " + to_string(counter);
					for (int i = 0; i < s.length(); i++)
					{
						glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s.at(i));
					}
					flag = false;
					counter = 0;
				}			
		}
	}
	 
}

void keyboard(unsigned char key,
	int x, int y)
{
	switch (key) {
	case 27:
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		//glutHideWindow();
		break;
	
	case ' ':
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		break;
}
	glutPostRedisplay();
}

void level_1() {
	level = 1;
	target t1(50.0, targetx, targety);
	glClearColor(0.04, 0.43, 0.84,1);
	glClear(GL_COLOR_BUFFER_BIT);
	arrow();
	speed = 0.5;
	//if(counter>5){}
	t1.draw_board();
	if (!flag)
		arrow_model();
	bow_model();
}

void level_2() {
	level = 2;
	target t1(50.0, targetx, targety);
	glClearColor(0.04, 0.66, 0.84, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	arrow();
	speed = 1;
	//if(counter>5){}
	t1.draw_board();
	if (!flag)
		arrow_model();
	bow_model();
}

void level_3() {
	level = 3;
	target t1(50.0, targetx, targety);
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	arrow();
	speed = 1.5;
	t1.draw_board();
	if (!flag)
		arrow_model();
	bow_model();
	cloud_one();
	cloud_two();
}

void draw(void){
	

	

	
	if (counter< 3)
		level_1();



	else if (counter >= 3 && counter <= 6)
		level_2();
	else if (counter > 6) {
		level_3();
		
	}
	
	
	
	glColor3f(1, 1, 1);
	glRasterPos3f(300, 250, 0);
	
	string s2 = ("Score :"+to_string(counter)+"    Hearts :"+ to_string(hearts));

	string s3 = ("Level :" + to_string(level) );


	glRasterPos3f(-50, -50, 0);
	for(int i = 0; i < s2.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s2.at(i));
	}
	glColor3f(0, 0, 0);
	glRasterPos3f(250, 450, 0);
	for (int i = 0; i < s3.length(); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s3.at(i));
	}

	
	glFlush();
	glutSwapBuffers();


	
}

void move() {
	glFlush();
	

	if (start) {

		cx -= 0.1;
		if (cx < -170) cx = 800;
		cx1 -= 0.12;
		if (cx1 < -470) cx1 = 500;
		if (moveright) {
			targetx += speed;
			if (targetx > 650) {
				moveleft = true;
				moveright = false;
			}

		}
		else if (moveleft) {
			targetx -= speed;
			if (targetx < -50) {
				moveright = true;
				moveleft = false;
			}

		}
		glutPostRedisplay();

	}
	

}





void mouse(int button, int state,
	int mousex, int mousey)
{

	if (button == GLUT_LEFT_BUTTON
		&& state == GLUT_DOWN) {
		//flag = true;
		//radius = 50;
		x = 0;
		y = 0;
		start = true;
		flag = true;
	}


	else if (button == GLUT_RIGHT_BUTTON
		&& state == GLUT_DOWN) {
		g += 0.1;
		//x = mousex - 100;
		//y = 500 - mousey;
		start = true;
		//flag = true;
	}

	glutPostRedisplay();
	// Redisplay

}

// Driver Code
int main(int argc, char** argv)
{
	// Initialize the drivers
	srand(time(0));
	glutInit(&argc, argv);

	// Initialize the display mode
	glutInitDisplayMode(
		GLUT_DOUBLE | GLUT_RGB);

	// Update the window size
	glutInitWindowSize(800, 600);

	// Update the window position
	glutInitWindowPosition(100, 100);

	int mainWindow = glutCreateWindow(
		"Bulls eye"
		);
	glClearColor(0, 0, 0, 0);
	// Clears the frame buffer
	glClear(GL_COLOR_BUFFER_BIT);
	// Links display event with the
	// display the event handler

	glutDisplayFunc(draw);
	// Mouse event handler
	glutMouseFunc(mouse);
	glutInitWindowPosition(100, 100);
	glClear(GL_COLOR_BUFFER_BIT);
	// Mouse event handler
	glutMouseFunc(mouse);
	glutIdleFunc(move);
	// Loops the current event
	glutMainLoop();
	
}
