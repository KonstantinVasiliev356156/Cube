//
// Created by vadim on 14.05.23.
//
#pragma once
#ifndef RUBIK_S_CUBE_DRAWCUBES_H
#define RUBIK_S_CUBE_DRAWCUBES_H

void drawFromConsist(Cube cube) {
    glColor3f(0, 0, 0);
    glutSolidCube(0.99);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            glBegin(GL_POLYGON);
            glColor3f(cube.front[i][j].r, cube.front[i][j].g, cube.front[i][j].b);
            glVertex3f(-0.5 + j * 0.34, 0.5 - i * 0.34, -0.5);
            glVertex3f(-0.5 + j * 0.34, 0.18 - i * 0.34, -0.5);
            glVertex3f(-0.18 + j * 0.34, 0.18 - i * 0.34, -0.5);
            glVertex3f(-0.18 + j * 0.34, 0.5 - i * 0.34, -0.5);
            glEnd();

            glRotatef(-90.0f,0.0f,0.0f,1.0f);

            glBegin(GL_POLYGON);
            glColor3f(cube.back[j][i].r, cube.back[j][i].g, cube.back[j][i].b);
            glVertex3f(-0.5 + j * 0.34, 0.5 - i * 0.34, 0.5);
            glVertex3f(-0.5 + j * 0.34, 0.18 - i * 0.34, 0.5);
            glVertex3f(-0.18 + j * 0.34, 0.18 - i * 0.34, 0.5);
            glVertex3f(-0.18 + j * 0.34, 0.5 - i * 0.34, 0.5);
            glEnd();

            glRotatef(90.0f,0.0f,0.0f,1.0f);
            glRotatef(90.0f,1.0f,0.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(cube.right[j][i].r, cube.right[j][i].g, cube.right[j][i].b);
            glVertex3f(0.5, -0.5 + i * 0.34, -0.5 + j * 0.34);
            glVertex3f(0.5, -0.5 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(0.5, -0.18 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(0.5, -0.18 + i * 0.34, -0.5 + j * 0.34);
            glEnd();

            glRotatef(-90.0f,1.0f,0.0f,0.0f);
            glRotatef(180.0f,1.0f,0.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(cube.left[i][j].r, cube.left[i][j].g, cube.left[i][j].b);
            glVertex3f(-0.5, -0.5 + i * 0.34, -0.5 + j * 0.34);
            glVertex3f(-0.5, -0.5 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(-0.5, -0.18 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(-0.5, -0.18 + i * 0.34, -0.5 + j * 0.34);
            glEnd();

            glRotatef(-180.0f,1.0f,0.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(cube.down[j][i].r, cube.down[j][i].g, cube.down[j][i].b);
            glVertex3f(-0.5 + i * 0.34, -0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, -0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, -0.5, -0.18 + j * 0.34);
            glVertex3f(-0.5 + i * 0.34, -0.5, -0.18 + j * 0.34);
            glEnd();

            glRotatef(90.0f,0.0f,1.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(cube.up[i][j].r, cube.up[i][j].g, cube.up[i][j].b);
            glVertex3f(-0.5 + i * 0.34, 0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, 0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, 0.5, -0.18 + j * 0.34);
            glVertex3f(-0.5 + i * 0.34, 0.5, -0.18 + j * 0.34);
            glEnd();

            glRotatef(-90.0f,0.0f,1.0f,0.0f);
        }
}

#endif //RUBIK_S_CUBE_DRAWCUBES_H

