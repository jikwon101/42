

// gcc *.c -lglut -lGL -lGLU 

#include <GL/freeglut.h>
#include <stdio.h>
 
float cubeX = 0.0;
float cubeY = 0.0;
float cubeZ = -4.0;
 
float pitch = 0.0;
float yaw = 0.0;
float roll = 0.0;
 
 
 
void drawBitmapText(char *str, float x, float y, float z)
{
    glRasterPos3f(x, y, z); //���ڿ��� �׷��� ��ġ ����
 
    while (*str)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *str);
 
        str++;
    }
}
 
static void cubebase(void)
{
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, -0.5);
    glVertex3d(-0.5, 0.5, -0.5);
    glVertex3d(0.5, 0.5, -0.5);
    glVertex3d(0.5, -0.5, -0.5);
    glEnd();
}
 
void draw_cube()
{
    glMatrixMode(GL_MODELVIEW);
 
 
    glPushMatrix();
 
    glColor3f(0.0f, 1.0f, 0.0f);     // Green, -Z�� ����
    cubebase();
 
    glPushMatrix();
    glTranslated(1.0, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue, +X�� ����
    cubebase();
 
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange, -X�� ����
    cubebase();
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(0.0, 1.0, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red, +Y�� ����
    cubebase();
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(0.0, -1.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow, -Y�� ����
    cubebase();
    glPopMatrix();
 
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta, +Z�� ����
    glBegin(GL_POLYGON);
    glVertex3d(-0.5, -0.5, 0.5);
    glVertex3d(0.5, -0.5, 0.5);
    glVertex3d(0.5, 0.5, 0.5);
    glVertex3d(-0.5, 0.5, 0.5);
    glEnd();
 
 
    glPopMatrix();
 
    glFlush();
}
 
void draw_line()
{
    glPushMatrix();
 
    glPushMatrix(); //X�� ������
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(5.0, 0.0, 0.0);
            glVertex3f(-5.0, 0.0, 0.0);
        glEnd();
        drawBitmapText("+X", 0.8, 0.0, 0.0);
        drawBitmapText("-X", -0.8, 0.0, 0.0);
    glPopMatrix();
 
    glPushMatrix(); //Y�� ���
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(0.0, 5.0, 0.0);
            glVertex3f(0.0, -5.0, 0.0);
        glEnd();
        drawBitmapText("+Y", 0.0, 0.8, 0.0);
        drawBitmapText("-Y", 0.0, -0.8, 0.0);
    glPopMatrix();
 
    glPushMatrix(); //Z�� �Ķ���
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
            glVertex3f(0.0, 0.0, 5.0);
            glVertex3f(0.0, 0.0, -5.0);
        glEnd();
        drawBitmapText("+Z", 0.0, 0.0, 0.8);
        drawBitmapText("-Z", 0.0, 0.0, -0.8);
    glPopMatrix();
 
    glPopMatrix();
 
    glFlush();
}
 
void display() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
    glTranslatef(cubeX, cubeY, cubeZ);
    glRotatef(pitch, 1.0, 0.0, 0.0); //x�࿡ ���� ȸ��
    glRotatef(yaw, 0.0, 1.0, 0.0); //y�࿡ ���� ȸ��
    glRotatef(roll, 0.0, 0.0, 1.0); //z�࿡ ���� ȸ��
 
    draw_cube();
 
    draw_line();
 
    glutSwapBuffers();
}
 
 
void reshape(GLsizei width, GLsizei height) 
{  
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); //������ ũ��� ������Ʈ ���� 
 
    glMatrixMode(GL_PROJECTION); //���� ������ Projection Matrix�� ������ �ش�. ī�޶�� ���̴� ��� ������ ���� 
    glLoadIdentity(); 
    gluPerspective(45, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW); //���� ������ ModelView Matirx�� ������ �ش�. ��ü ����
}
 
 
void timer(int value) {
 
    glutPostRedisplay();      //�����츦 �ٽ� �׸����� ��û
    glutTimerFunc(30, timer, 0); //���� Ÿ�̸� �̺�Ʈ�� 30�и�����Ʈ ��  ȣ���.
}
 
 
 
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClearDepth(1.0);
 
    glEnable(GL_DEPTH_TEST);
}
 
void special(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        pitch += 1.0;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        pitch -= 1.0;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        yaw += 1.0;
    }
    else if (key == GLUT_KEY_LEFT)
    {
        yaw -= 1.0;
    }
}
 
void keyboard(unsigned char key, int x, int y)
{
 
    if (key == 27)
    {
        exit(0);
    }
    else if (key == 43) // +Ű
    {
        roll += 1.0;
    }
    else if (key == 45) //-Ű
    {
        roll -= 1.0;
    }
    else if (key == 113) //q
    {
        cubeZ += 0.1;
    }
    else if (key == 119) //w
    {
        cubeZ -= 0.1;
    }
    else if (key == 97) //a
    {
        cubeY += 0.1;
    }
    else if (key == 115) //s
    {
        cubeY -= 0.1;
    }
    else if (key == 122) //z
    {
        cubeX += 0.1;
    }
    else if (key == 120) //x
    {
        cubeX -= 0.1;
    }
}
 
 
 
int main(int argc, char** argv) 
{
    glutInit(&argc, argv);  //GLUT �ʱ�ȭ
 
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //���� ���ۿ� ���� ���۸� ����ϵ��� ����, GLUT_RGB=0x00��
    glutInitWindowSize(500, 500);   //�������� width�� height
    glutInitWindowPosition(100, 100); //�������� ��ġ (x,y)
    glutCreateWindow("OpenGL Example"); //������ ����
 
 
    init();
 
    glutDisplayFunc(display); 
 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
 
    glutMainLoop();          
 
    return 0;
}
