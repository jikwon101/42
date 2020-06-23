

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
    glRasterPos3f(x, y, z); //문자열이 그려질 위치 지정
 
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
 
    glColor3f(0.0f, 1.0f, 0.0f);     // Green, -Z축 방향
    cubebase();
 
    glPushMatrix();
    glTranslated(1.0, 0.0, 0.0);
    glRotated(90.0, 0.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue, +X축 방향
    cubebase();
 
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.0);
    glRotated(-90.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange, -X축 방향
    cubebase();
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(0.0, 1.0, 0.0);
    glRotated(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red, +Y축 방향
    cubebase();
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(0.0, -1.0, 0.0);
    glRotated(90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow, -Y축 방향
    cubebase();
    glPopMatrix();
 
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta, +Z축 방향
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
 
    glPushMatrix(); //X축 붉은색
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(5.0, 0.0, 0.0);
            glVertex3f(-5.0, 0.0, 0.0);
        glEnd();
        drawBitmapText("+X", 0.8, 0.0, 0.0);
        drawBitmapText("-X", -0.8, 0.0, 0.0);
    glPopMatrix();
 
    glPushMatrix(); //Y축 녹색
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex3f(0.0, 5.0, 0.0);
            glVertex3f(0.0, -5.0, 0.0);
        glEnd();
        drawBitmapText("+Y", 0.0, 0.8, 0.0);
        drawBitmapText("-Y", 0.0, -0.8, 0.0);
    glPopMatrix();
 
    glPushMatrix(); //Z축 파란색
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
    glRotatef(pitch, 1.0, 0.0, 0.0); //x축에 대해 회전
    glRotatef(yaw, 0.0, 1.0, 0.0); //y축에 대해 회전
    glRotatef(roll, 0.0, 0.0, 1.0); //z축에 대해 회전
 
    draw_cube();
 
    draw_line();
 
    glutSwapBuffers();
}
 
 
void reshape(GLsizei width, GLsizei height) 
{  
    glViewport(0, 0, (GLsizei)width, (GLsizei)height); //윈도우 크기로 뷰포인트 설정 
 
    glMatrixMode(GL_PROJECTION); //이후 연산은 Projection Matrix에 영향을 준다. 카메라로 보이는 장면 같은거 설정 
    glLoadIdentity(); 
    gluPerspective(45, (GLfloat)width / (GLfloat)height, 1.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW); //이후 연산은 ModelView Matirx에 영향을 준다. 객체 조작
}
 
 
void timer(int value) {
 
    glutPostRedisplay();      //윈도우를 다시 그리도록 요청
    glutTimerFunc(30, timer, 0); //다음 타이머 이벤트는 30밀리세컨트 후  호출됨.
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
    else if (key == 43) // +키
    {
        roll += 1.0;
    }
    else if (key == 45) //-키
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
    glutInit(&argc, argv);  //GLUT 초기화
 
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); //더블 버퍼와 깊이 버퍼를 사용하도록 설정, GLUT_RGB=0x00임
    glutInitWindowSize(500, 500);   //윈도우의 width와 height
    glutInitWindowPosition(100, 100); //윈도우의 위치 (x,y)
    glutCreateWindow("OpenGL Example"); //윈도우 생성
 
 
    init();
 
    glutDisplayFunc(display); 
 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
 
    glutMainLoop();          
 
    return 0;
}
