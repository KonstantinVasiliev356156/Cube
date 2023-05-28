//
// Created by vadim on 14.05.23.
//
#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <GL/freeglut.h>
#ifndef RUBIK_S_CUBE_CUBECLASS_H
#define RUBIK_S_CUBE_CUBECLASS_H
using std::pair;

struct rgbPairs{
    GLfloat r;
    GLfloat g;
    GLfloat b;

    bool operator==(rgbPairs other){
        return r == other.r && g == other.g && b == other.b;
    }

    bool operator!=(rgbPairs other){
        return !(*this == other);
    }
};


const rgbPairs r = {1,0,0};
const rgbPairs g = {0,1,0};
const rgbPairs b = {0,0,1};
const rgbPairs w = {1,1,1};
const rgbPairs y = {1,1,0};
const rgbPairs o = {1,0.65,0};
const int side_size = sizeof(rgbPairs) * 9;

class Cube {
public:
    rgbPairs front[3][3];
    rgbPairs back[3][3];
    rgbPairs left[3][3];
    rgbPairs right[3][3];
    rgbPairs up[3][3];
    rgbPairs down[3][3];
    rgbPairs* sides[6] = {(rgbPairs*)up, (rgbPairs*)down, (rgbPairs*)front, (rgbPairs*)back, (rgbPairs*)left, (rgbPairs*)right};
    Cube(FILE *p);
    Cube();
    ~Cube() = default;

    void F();
    void B();
    void L();
    void R();
    void U();
    void D();
    void F_();
    void B_();
    void L_();
    void R_();
    void U_();
    void D_();

    int find_side(rgbPairs);
    rgbPairs find_another_color(char, int , int );
    void cross_turn(int);
    void Phase_1();
    void Solve();
};


#endif //RUBIK_S_CUBE_CUBECLASS_H
