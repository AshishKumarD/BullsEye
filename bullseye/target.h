#pragma once
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>

using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")
class target
{
public:
    
    float rad;
    float r;
    float g;
    float b;
	float x , y;//position
    boolean selected = false;
    float speed = 2.0;
    int counter = rand() % 301 - 300;

	target(float rad, float x, float y, float r, float g, float b) {
		this->rad = rad;
		this->x = x;
		this->y = y;
		this->r = r;
		this->g = g;
		this->b = b;

		srand(time(NULL));
	}

	target(float rad, float x, float y) {
		this->rad = rad;
		this->x = x;
		this->y = y;

	}



	void draw_board() {
		target t1(rad, x, y, 1.0, 1.0, 1.0);//white
		target t2(rad*0.8, x, y, 0, 0, 0);//black
		target t3(rad*0.6, x, y, 0, 0.6, 0.78);//blue
		target t4(rad*0.4, x, y, 0.85, 0.1, 0.1);//o
		target t5(rad*0.2, x, y, 0.98, 0.83, 0);//white

		
		t1.draw_target();
		t2.draw_target();
		t3.draw_target();
		t4.draw_target();
		t5.draw_target();
	}

    void draw_target() {

        glPushMatrix();
        glTranslatef(100, 100, 0);
      //  glScalef(0.38, 0.55, 0);
      //  glRotatef(90, 0, 0, 1);


		float angle_theta;


		// Matrix mode
		glMatrixMode(GL_PROJECTION);
		//glClear(GL_COLOR_BUFFER_BIT);

		glLoadIdentity();

		// Given the coordinates
		gluOrtho2D(0.0, 800.0, 0.0, 600.0);
		

			// Begin the pointer
			glBegin(GL_POLYGON);

			// Iterate through all the
			// 360 degrees

			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(r, g, b);
			for (int i = 0; i < 360; i++) {

				angle_theta = i * 3.142 / 180;
				glVertex2f(x + rad * cos(angle_theta),
					y + rad * sin(angle_theta));

			}



			// Set the vertex
			glEnd();
		

		// Flushes the frame buffer to
		// the screen
		glFlush();
        glPopMatrix();
    }

   

    
};