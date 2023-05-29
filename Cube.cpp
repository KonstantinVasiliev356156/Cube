//
// Created by vadim on 14.05.23.
//

#include "Cube.h"
using std::swap;

void Cube::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glutSolidCube(0.99);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            glBegin(GL_POLYGON);
            glColor3f(front[i][j].r, front[i][j].g, front[i][j].b);
            glVertex3f(-0.5 + j * 0.34, 0.5 - i * 0.34, -0.5);
            glVertex3f(-0.5 + j * 0.34, 0.18 - i * 0.34, -0.5);
            glVertex3f(-0.18 + j * 0.34, 0.18 - i * 0.34, -0.5);
            glVertex3f(-0.18 + j * 0.34, 0.5 - i * 0.34, -0.5);
            glEnd();

            glRotatef(-90.0f,0.0f,0.0f,1.0f);

            glBegin(GL_POLYGON);
            glColor3f(back[j][i].r, back[j][i].g, back[j][i].b);
            glVertex3f(-0.5 + j * 0.34, 0.5 - i * 0.34, 0.5);
            glVertex3f(-0.5 + j * 0.34, 0.18 - i * 0.34, 0.5);
            glVertex3f(-0.18 + j * 0.34, 0.18 - i * 0.34, 0.5);
            glVertex3f(-0.18 + j * 0.34, 0.5 - i * 0.34, 0.5);
            glEnd();

            glRotatef(90.0f,0.0f,0.0f,1.0f);
            glRotatef(90.0f,1.0f,0.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(right[j][i].r, right[j][i].g, right[j][i].b);
            glVertex3f(0.5, -0.5 + i * 0.34, -0.5 + j * 0.34);
            glVertex3f(0.5, -0.5 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(0.5, -0.18 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(0.5, -0.18 + i * 0.34, -0.5 + j * 0.34);
            glEnd();

            glRotatef(-90.0f,1.0f,0.0f,0.0f);
            glRotatef(180.0f,1.0f,0.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(left[i][j].r, left[i][j].g, left[i][j].b);
            glVertex3f(-0.5, -0.5 + i * 0.34, -0.5 + j * 0.34);
            glVertex3f(-0.5, -0.5 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(-0.5, -0.18 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(-0.5, -0.18 + i * 0.34, -0.5 + j * 0.34);
            glEnd();

            glRotatef(-180.0f,1.0f,0.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(down[j][i].r, down[j][i].g, down[j][i].b);
            glVertex3f(-0.5 + i * 0.34, -0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, -0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, -0.5, -0.18 + j * 0.34);
            glVertex3f(-0.5 + i * 0.34, -0.5, -0.18 + j * 0.34);
            glEnd();

            glRotatef(90.0f,0.0f,1.0f,0.0f);

            glBegin(GL_POLYGON);
            glColor3f(up[i][j].r, up[i][j].g, up[i][j].b);
            glVertex3f(-0.5 + i * 0.34, 0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, 0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, 0.5, -0.18 + j * 0.34);
            glVertex3f(-0.5 + i * 0.34, 0.5, -0.18 + j * 0.34);
            glEnd();

            glRotatef(-90.0f,0.0f,1.0f,0.0f);

        }
    glFlush();
    glutSwapBuffers();

}

void rotate(rgbPairs** matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            rgbPairs tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            rgbPairs tmp = matrix[i][j];
            matrix[i][j] = matrix[i][2 - j];
            matrix[i][2 - j] = tmp;
        }
    }
}

void rotate_back(rgbPairs** matrix){
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            rgbPairs tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            rgbPairs tmp = matrix[j][i];
            matrix[j][i] = matrix[2 - j][i];
            matrix[2 - j][i] = tmp;
        }
    }
}

Cube::Cube() {
    up = (rgbPairs**) malloc(3*sizeof (rgbPairs*));
    down = (rgbPairs**) malloc(3*sizeof (rgbPairs*));
    back = (rgbPairs**) malloc(3*sizeof (rgbPairs*));
    right = (rgbPairs**) malloc(3*sizeof (rgbPairs*));
    front = (rgbPairs**) malloc(3*sizeof (rgbPairs*));
    left = (rgbPairs**) malloc(3*sizeof (rgbPairs*));
    for(int i = 0; i < 3; i++){
        front[i] = (rgbPairs*) malloc(3*sizeof(rgbPairs));
        left[i] = (rgbPairs*) malloc(3*sizeof(rgbPairs));
        up[i] = (rgbPairs*) malloc(3*sizeof(rgbPairs));
        down[i] = (rgbPairs*) malloc(3*sizeof(rgbPairs));
        back[i] = (rgbPairs*) malloc(3*sizeof(rgbPairs));
        right[i] = (rgbPairs*) malloc(3*sizeof(rgbPairs));
    }
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            front[i][j] = g;
            back[i][j] = b;
            left[i][j] = o;
            right[i][j] = r;
            up[i][j] = w;
            down[i][j] = y;
        }
    void ((*functptr[8]))();
    functptr[0] = L();
}

void Cube::U() {
    swap(front[0], left[0]);
    swap(front[0], back[0]);
    swap(front[0], right[0]);
    rotate(up);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::D_() {
    D();
    D();
    D();
}

void Cube::F() {
    swap(up[2][0], right[0][0]);
    swap(up[2][1],right[1][0]);
    swap(up[2][2], right[2][0]);
    swap(up[2][0], down[0][2]);
    swap(up[2][1], down[0][1]);
    swap(up[2][2], down[0][0]);
    swap(up[2][0], left[2][2]);
    swap(up[2][1], left[1][2]);
    swap(up[2][2],left[0][2]);
    rotate(front);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::R_() {
    swap(front[0][2],down[0][2]);
    swap(front[1][2],down[1][2]);
    swap(front[2][2],down[2][2]);
    swap(front[0][2],back[2][0]);
    swap(front[1][2],back[1][0]);
    swap(front[2][2],back[0][0]);
    swap(front[0][2],up[0][2]);
    swap(front[1][2],up[1][2]);
    swap(front[2][2],up[2][2]);
    rotate_back(right);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::B_() {
    swap(right[0][2],down[2][2]);
    swap(right[1][2],down[2][1]);
    swap(right[2][2],down[2][0]);
    swap(right[0][2],left[2][0]);
    swap(right[1][2],left[1][0]);
    swap(right[2][2],left[0][0]);
    swap(right[0][2],up[0][0]);
    swap(right[1][2],up[0][1]);
    swap(right[2][2],up[0][2]);
    rotate_back(back);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::L() {
    swap(front[0][0],down[0][0]);
    swap(front[1][0],down[1][0]);
    swap(front[2][0],down[2][0]);
    swap(front[0][0],back[2][2]);
    swap(front[1][0], back[1][2]);
    swap(front[2][0],back[0][2]);
    swap(front[0][0], up[0][0]);
    swap(front[1][0],up[1][0]);
    swap(front[2][0],up[2][0]);
    rotate(left);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::R() {
    R_();
    R_();
    R_();
}


void Cube::U_() {
    U();
    U();
    U();
}

void Cube::D() {
    swap(front[2], right[2]);
    swap(front[2], back[2]);
    swap(front[2], left[2]);
    rotate(down);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::F_() {
    F();
    F();
    F();
}

void Cube::B() {
    B_();
    B_();
    B_();
}

void Cube::L_() {
    L();
    L();
    L();
}

void Cube::Solve() {
    rgbPairs** tmp;
    for(int k = 0; k < 6; k++){
        tmp = *sides[k];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(tmp[i][j] == w){
                    std::cout << 'w' << " ";
                }
                if(tmp[i][j] == y){
                    std::cout << 'y' << " ";
                }
                if(tmp[i][j] == r){
                    std::cout << 'r' << " ";
                }
                if(tmp[i][j] == g){
                    std::cout << 'g' << " ";
                }
                if(tmp[i][j] == b){
                    std::cout << 'b' << " ";
                }
                if(tmp[i][j] == o){
                    std::cout << 'o' << " ";
                }
            }
            std::cout << '\n';
        }
        std::cout << "\n\n";
    }
    Phase_1();

}

int Cube::find_side(rgbPairs color){
    if(color == w){
        return 0;
    }
    if(color == y){
        return 1;
    }
    if(color == g){
        return 2;
    }
    if(color == b){
        return 3;
    }
    if(color == o){
        return 4;
    }
    if(color == r){
        return 5;
    }
}

rgbPairs Cube::find_another_color(char side, int i, int j){
    if(side == 'l'){
        if(i == 1){
            if(j == 0){
                return front[1][0];
            } else{
                return back[1][0];
            }
        } else if (i == 0){
            return down[0][1];
        } else {
            return up[0][1];
        }
    }

    if(side == 'r'){
        if(i == 1){
            if(j == 0){
                return front[1][2];
            } else{
                return back[1][2];
            }
        } else if (i == 0){
            return down[2][1];
        } else {
            return up[2][1];
        }
    }

    if(side == 'u'){
        if(i == 1){
            if(j == 0){
                return back[0][1];
            } else{
                return front[0][1];
            }
        } else if (i == 0){
            return left[2][1];
        } else {
            return right[2][1];
        }
    }

    if(side == 'd'){
        if(i == 1){
            if(j == 0){
                return front[2][1];
            } else{
                return back[2][1];
            }
        } else if (i == 0){
            return left[0][1];
        } else {
            return right[0][1];
        }
    }

    if(side == 'f'){
        if(i == 1){
            if(j == 0){
                return left[1][0];
            } else{
                return right[1][0];
            }
        } else if (i == 0){
            return up[1][2];
        } else {
            return down[1][0];
        }
    }

    if(side == 'b'){
        if(i == 1){
            if(j == 0){
                return left[1][2];
            } else{
                return right[1][2];
            }
        } else if (i == 0){
            return up[1][0];
        } else {
            return down[1][2];
        }
    }
}

void Cube::cross_turn(int right_side){
    if(right_side == 2){
        D();
        R();
        F_();
        R_();
    } else if (right_side == 3){
        D();
        L();
        B_();
        L_();
    } else if (right_side == 4){
        D();
        F();
        L_();
        F_();
    } else if(right_side == 5){
        D();
        B();
        R_();
        B_();
    }
}

void Cube::Phase_1() {
    int side_counter = 0,right_side;
    rgbPairs another_color;
    rgbPairs** tmp_side;

    while (up[1][2] != w || up[1][0] != w || up[0][1] != w || up[2][1] != w){
        side_counter = (side_counter+1)%6;
        if(side_counter == 0) {
            side_counter++;
        }
        if(side_counter == 1) {
            if(down[1][0] == w){
                another_color = find_another_color('d',1,0);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != another_color || (find_another_color('f',2,1) != w)){
                        D();
                    }
                    F();
                    F();
                } else if(right_side == 3){
                    while (tmp_side[2][1] != another_color || (find_another_color('b',2,1) != w)){
                        D();
                    }
                    B();
                    B();
                } else if(right_side == 4){
                    while (tmp_side[0][1] != another_color || (find_another_color('l',0,1) != w)){
                        D();
                    }
                    L();
                    L();
                } else if(right_side == 5){
                    while (tmp_side[0][1] != another_color || (find_another_color('r',0,1) != w)){
                        D();
                    }
                    R();
                    R();
                }
            }
            if(down[1][2] == w){
                another_color = find_another_color('d',1,2);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != another_color || (find_another_color('f',2,1) != w)){
                        D();
                    }
                    F();
                    F();
                } else if(right_side == 3){
                    while (tmp_side[2][1] != another_color || (find_another_color('b',2,1) != w)){
                        D();
                    }
                    B();
                    B();
                } else if(right_side == 4){
                    while (tmp_side[0][1] != another_color || (find_another_color('l',0,1) != w)){
                        D();
                    }
                    L();
                    L();
                } else if(right_side == 5){
                    while (tmp_side[0][1] != another_color || (find_another_color('r',0,1) != w)){
                        D();
                    }
                    R();
                    R();
                }
            }
            if(down[0][1] == w){
                another_color = find_another_color('d',0,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != another_color || (find_another_color('f',2,1) != w)){
                        D();
                    }
                    F();
                    F();
                } else if(right_side == 3){
                    while (tmp_side[2][1] != another_color || (find_another_color('b',2,1) != w)){
                        D();
                    }
                    B();
                    B();
                } else if(right_side == 4){
                    while (tmp_side[0][1] != another_color || (find_another_color('l',0,1) != w)){
                        D();
                    }
                    L();
                    L();
                } else if(right_side == 5){
                    while (tmp_side[0][1] != another_color || (find_another_color('r',0,1) != w)){
                        D();
                    }
                    R();
                    R();
                }
            }
            if(down[2][1] == w){
                another_color = find_another_color('d',2,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != another_color || (find_another_color('f',2,1) != w)){
                        D();
                    }
                    F();
                    F();
                } else if(right_side == 3){
                    while (tmp_side[2][1] != another_color || (find_another_color('b',2,1) != w)){
                        D();
                    }
                    B();
                    B();
                } else if(right_side == 4){
                    while (tmp_side[0][1] != another_color || (find_another_color('l',0,1) != w)){
                        D();
                    }
                    L();
                    L();
                } else if(right_side == 5){
                    while (tmp_side[0][1] != another_color || (find_another_color('r',0,1) != w)){
                        D();
                    }
                    R();
                    R();
                }
            }
        } else if(side_counter == 2){
            if(front[1][2] == w){
                R_();
                D();
                R();
                side_counter = 0;
                continue;
            } else if (front[1][0] == w){
                L();
                D();
                L_();
                side_counter = 0;
                continue;
            } else if (front[2][1] == w){
                another_color = find_another_color('f',2,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            } else if (front[0][1] == w){
                F();
                F();
                another_color = find_another_color('f',2,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            }
        } else if (side_counter == 3){
            if(back[1][0] == w){
                L_();
                D();
                L();
                side_counter = 0;
                continue;
            } else if (back[1][2] == w){
                R();
                D();
                R_();
                side_counter = 0;
                continue;
            } else if (back[2][1] == w){
                another_color = find_another_color('b',2,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            } else if (back[0][1] == w){
                B();
                B();
                another_color = find_another_color('b',2,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            }
        } else if (side_counter == 4){
            if(left[1][0] == w){
                F_();
                D();
                F();
                side_counter = 0;
                continue;
            } else if (left[1][2] == w){
                B();
                D();
                B_();
                side_counter = 0;
                continue;
            } else if (left[0][1] == w){
                another_color = find_another_color('l',0,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            } else if (left[2][1] == w){
                L();
                L();
                another_color = find_another_color('l',0,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            }
        } else if (side_counter == 5){
            if(right[1][2] == w){
                B_();
                D();
                B();
                side_counter = 0;
                continue;
            } else if (right[1][0] == w){
                F();
                D();
                F_();
                side_counter = 0;
                continue;
            } else if (right[0][1] == w){
                another_color = find_another_color('r',0,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            } else if (right[2][1] == w){
                R();
                R();
                another_color = find_another_color('r',0,1);
                right_side = find_side(another_color);
                tmp_side = *sides[right_side];
                if(right_side == 2){
                    while(tmp_side[2][1] != w || (find_another_color('f',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 3){
                    while (tmp_side[2][1] != w || (find_another_color('b',2,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 4){
                    while (tmp_side[0][1] != w || (find_another_color('l',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                } else if(right_side == 5){
                    while (tmp_side[0][1] != w || (find_another_color('r',0,1) != another_color)){
                        D();
                    }
                    cross_turn(right_side);
                }
            }
        }
    }
}

void Cube::Phase_2() {
    int side_counter = 0;
    rgbPairs** tmp_side;
    while (up[0][0] != w || up[0][2] != w || up[2][0] != w || up[2][2] != w){
        side_counter = (side_counter+1)%6;
        if(side_counter == 0){
            continue;
        }
        if(side_counter == 1){
            if(down[0][0] == w){
                F_();
                R_();
                D();
                D();
                R();
                F();
            } else if(down[2][0] == w){
                R_();
                B_();
                D();
                D();
                B();
                R();
            } else if(down[0][2] == w){
                L_();
                F_();
                D();
                D();
                F();
                L();
            } else if(down[2][2] == w){
                B_();
                L_();
                D();
                D();
                L();
                B();
            }
        } else if(side_counter == 2){
            if(front[2][0] == w){
                F_();
                D_();
                F();
            } else if(front[2][2] == w){
                F();
                D();
                F_();
            } else if(front[0][0] == w){
                F_();
                D();
                F();
            } else if(front[2][0] == w){
                F();
                D_();
                F_();
            }
        } else if (side_counter == 3){
            if(back[2][2] == w){
                B_();
                D_();
                B();
            } else if(back[2][0] == w){
                B();
                D();
                B_();
            } else if(back[0][2] == w){
                B_();
                D();
                B();
            } else if(back[0][0] == w){
                B();
                D_();
                B_();
            }
        } else if (side_counter == 4){
            if(left[0][2] == w){
                L_();
                D_();
                L();
            } else if(left[0][0] == w){
                L();
                D();
                L_();
            } else if(left[2][2] == w){
                L_();
                D();
                L();
            } else if(left[2][0] == w){
                L();
                D_();
                L_();
            }
        } else if (side_counter == 5){
            if(right[0][0] == w){
                R_();
                D_();
                R();
            } else if(right[0][2] == w){
                R();
                D();
                R_();
            } else if(right[2][0] == w){
                R_();
                D();
                R();
            } else if(right[2][2] == w){
                R();
                D_();
                R_();
            }
        }
    }
}
