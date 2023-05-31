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
#include <unistd.h>
#include <chrono>
#include <thread>
#include<functional>
#ifndef RUBIK_S_CUBE_CUBECLASS_H
#define RUBIK_S_CUBE_CUBECLASS_H
using std::pair;
using namespace std::chrono_literals;
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
    rgbPairs** front;
    rgbPairs** back;
    rgbPairs** left;
    rgbPairs** right;
    rgbPairs** up;
    rgbPairs** down;
    rgbPairs*** sides[6] = {&up,&down,&left,&front,&right,&back};

    Cube();
    ~Cube() = default;
    void display();
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
    void C();
    void (*rotations[6][8])();

    int find_side(rgbPairs);
    rgbPairs find_another_color(int, int , int );
    rgbPairs find_down_side(int side);
    void cross_turn(int);
    void pick_rotation(int,int);
    void Phase_1();
    void Phase_2();
    void Phase_3();
    void Phase_4();
    void Phase_5();
    void Phase_6();
    void Phase_7();
    void Solve();

};


#endif //RUBIK_S_CUBE_CUBECLASS_H
