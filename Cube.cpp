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

            glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);

            glBegin(GL_POLYGON);
            glColor3f(back[j][i].r, back[j][i].g, back[j][i].b);
            glVertex3f(-0.5 + j * 0.34, 0.5 - i * 0.34, 0.5);
            glVertex3f(-0.5 + j * 0.34, 0.18 - i * 0.34, 0.5);
            glVertex3f(-0.18 + j * 0.34, 0.18 - i * 0.34, 0.5);
            glVertex3f(-0.18 + j * 0.34, 0.5 - i * 0.34, 0.5);
            glEnd();

            glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
            glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

            glBegin(GL_POLYGON);
            glColor3f(right[j][i].r, right[j][i].g, right[j][i].b);
            glVertex3f(0.5, -0.5 + i * 0.34, -0.5 + j * 0.34);
            glVertex3f(0.5, -0.5 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(0.5, -0.18 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(0.5, -0.18 + i * 0.34, -0.5 + j * 0.34);
            glEnd();

            glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
            glRotatef(180.0f, 1.0f, 0.0f, 0.0f);

            glBegin(GL_POLYGON);
            glColor3f(left[i][j].r, left[i][j].g, left[i][j].b);
            glVertex3f(-0.5, -0.5 + i * 0.34, -0.5 + j * 0.34);
            glVertex3f(-0.5, -0.5 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(-0.5, -0.18 + i * 0.34, -0.18 + j * 0.34);
            glVertex3f(-0.5, -0.18 + i * 0.34, -0.5 + j * 0.34);
            glEnd();

            glRotatef(-180.0f, 1.0f, 0.0f, 0.0f);

            glBegin(GL_POLYGON);
            glColor3f(down[j][i].r, down[j][i].g, down[j][i].b);
            glVertex3f(-0.5 + i * 0.34, -0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, -0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, -0.5, -0.18 + j * 0.34);
            glVertex3f(-0.5 + i * 0.34, -0.5, -0.18 + j * 0.34);
            glEnd();

            glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

            glBegin(GL_POLYGON);
            glColor3f(up[i][j].r, up[i][j].g, up[i][j].b);
            glVertex3f(-0.5 + i * 0.34, 0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, 0.5, -0.5 + j * 0.34);
            glVertex3f(-0.18 + i * 0.34, 0.5, -0.18 + j * 0.34);
            glVertex3f(-0.5 + i * 0.34, 0.5, -0.18 + j * 0.34);
            glEnd();

            glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);

        }
    glFlush();
    glutSwapBuffers();

}

void rotate(rgbPairs **matrix) {
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

void rotate_back(rgbPairs **matrix) {
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
    up = (rgbPairs **) malloc(3 * sizeof(rgbPairs *));
    down = (rgbPairs **) malloc(3 * sizeof(rgbPairs *));
    back = (rgbPairs **) malloc(3 * sizeof(rgbPairs *));
    right = (rgbPairs **) malloc(3 * sizeof(rgbPairs *));
    front = (rgbPairs **) malloc(3 * sizeof(rgbPairs *));
    left = (rgbPairs **) malloc(3 * sizeof(rgbPairs *));
    for (int i = 0; i < 3; i++) {
        front[i] = (rgbPairs *) malloc(3 * sizeof(rgbPairs));
        left[i] = (rgbPairs *) malloc(3 * sizeof(rgbPairs));
        up[i] = (rgbPairs *) malloc(3 * sizeof(rgbPairs));
        down[i] = (rgbPairs *) malloc(3 * sizeof(rgbPairs));
        back[i] = (rgbPairs *) malloc(3 * sizeof(rgbPairs));
        right[i] = (rgbPairs *) malloc(3 * sizeof(rgbPairs));
    }
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            front[i][j] = g;
            back[i][j] = b;
            left[i][j] = o;
            right[i][j] = r;
            up[i][j] = w;
            down[i][j] = y;
        };

}

void Cube::U() {
    swap(front[0], left[0]);
    swap(front[0], back[0]);
    swap(front[0], right[0]);
    rotate(up);
    display();
}

void Cube::D_() {
    D();
    D();
    D();
}

void Cube::F() {
    swap(up[2][0], right[0][0]);
    swap(up[2][1], right[1][0]);
    swap(up[2][2], right[2][0]);
    swap(up[2][0], down[0][2]);
    swap(up[2][1], down[0][1]);
    swap(up[2][2], down[0][0]);
    swap(up[2][0], left[2][2]);
    swap(up[2][1], left[1][2]);
    swap(up[2][2], left[0][2]);
    rotate(front);
    display();
}

void Cube::R_() {
    swap(front[0][2], down[0][2]);
    swap(front[1][2], down[1][2]);
    swap(front[2][2], down[2][2]);
    swap(front[0][2], back[2][0]);
    swap(front[1][2], back[1][0]);
    swap(front[2][2], back[0][0]);
    swap(front[0][2], up[0][2]);
    swap(front[1][2], up[1][2]);
    swap(front[2][2], up[2][2]);
    rotate_back(right);
    display();
}

void Cube::B_() {
    swap(right[0][2], down[2][2]);
    swap(right[1][2], down[2][1]);
    swap(right[2][2], down[2][0]);
    swap(right[0][2], left[2][0]);
    swap(right[1][2], left[1][0]);
    swap(right[2][2], left[0][0]);
    swap(right[0][2], up[0][0]);
    swap(right[1][2], up[0][1]);
    swap(right[2][2], up[0][2]);
    rotate_back(back);
    display();
    std::this_thread::sleep_for(100ms);
}

void Cube::L() {
    swap(front[0][0], down[0][0]);
    swap(front[1][0], down[1][0]);
    swap(front[2][0], down[2][0]);
    swap(front[0][0], back[2][2]);
    swap(front[1][0], back[1][2]);
    swap(front[2][0], back[0][2]);
    swap(front[0][0], up[0][0]);
    swap(front[1][0], up[1][0]);
    swap(front[2][0], up[2][0]);
    rotate(left);
    display();
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

void Cube::C(){
    swap(front[1], left[1]);
    swap(front[1], back[1]);
    swap(front[1], right[1]);
    display();
}

void Cube::pick_rotation(int side, int rotate) {
    if (side == 0) {
        if (rotate == 0) {
            L();
            return;
        }
        if (rotate == 1) {
            L_();
            return;
        }
        if (rotate == 2) {
            R_();
            return;
        }
        if (rotate == 3) {
            R();
            return;
        }
        if (rotate == 4) {
            B();
            return;
        }
        if (rotate == 5) {
            B_();
            return;
        }
        if (rotate == 6) {
            F_();
            return;
        }
        if (rotate == 7) {
            F();
            return;
        }
        if (rotate == 8) {
            U_();
            return;
        }
        if (rotate == 9) {
            U();
            return;
        }
    }
    if (side == 1) {
        if (rotate == 0) {
            L();
            return;
        }
        if (rotate == 1) {
            L_();
            return;
        }
        if (rotate == 2) {
            R_();
            return;
        }
        if (rotate == 3) {
            R();
            return;
        }
        if (rotate == 4) {
            F();
            return;
        }
        if (rotate == 5) {
            F_();
            return;
        }
        if (rotate == 6) {
            B_();
            return;
        }
        if (rotate == 7) {
            B();
            return;
        }
        if (rotate == 8) {
            D_();
            return;
        }
        if (rotate == 9) {
            D();
            return;
        }
    }
    if (side == 2) {
        if (rotate == 0) {
            B();
            return;
        }
        if (rotate == 1) {
            B_();
            return;
        }
        if (rotate == 2) {
            F_();
            return;
        }
        if (rotate == 3) {
            F();
            return;
        }
        if (rotate == 4) {
            U();
            return;
        }
        if (rotate == 5) {
            U_();
            return;
        }
        if (rotate == 6) {
            D_();
            return;
        }
        if (rotate == 7) {
            D();
            return;
        }
        if (rotate == 8) {
            L_();
            return;
        }
        if (rotate == 9) {
            L();
            return;
        }
    }
    if (side == 3) {
        if (rotate == 0) {
            L();
            return;
        }
        if (rotate == 1) {
            L_();
            return;
        }
        if (rotate == 2) {
            R_();
            return;
        }
        if (rotate == 3) {
            R();
            return;
        }
        if (rotate == 4) {
            U();
            return;
        }
        if (rotate == 5) {
            U_();
            return;
        }
        if (rotate == 6) {
            D_();
            return;
        }
        if (rotate == 7) {
            D();
            return;
        }
        if (rotate == 8) {
            F_();
            return;
        }
        if (rotate == 9) {
            F();
            return;
        }
    }
    if (side == 4) {
        if (rotate == 0) {
            F();
            return;
        }
        if (rotate == 1) {
            F_();
            return;
        }
        if (rotate == 2) {
            B_();
            return;
        }
        if (rotate == 3) {
            B();
            return;
        }
        if (rotate == 4) {
            U();
            return;
        }
        if (rotate == 5) {
            U_();
            return;
        }
        if (rotate == 6) {
            D_();
            return;
        }
        if (rotate == 7) {
            D();
            return;
        }
        if (rotate == 8) {
            R_();
            return;
        }
        if (rotate == 9) {
            R();
            return;
        }
    }
    if (side == 5) {
        if (rotate == 0) {
            R();
            return;
        }
        if (rotate == 1) {
            R_();
            return;
        }
        if (rotate == 2) {
            L_();
            return;
        }
        if (rotate == 3) {
            L();
            return;
        }
        if (rotate == 4) {
            U();
            return;
        }
        if (rotate == 5) {
            U_();
            return;
        }
        if (rotate == 6) {
            D_();
            return;
        }
        if (rotate == 7) {
            D();
            return;
        }
        if (rotate == 8) {
            B_();
            return;
        }
        if (rotate == 9) {
            B();
            return;
        }
    }
}


void Cube::Solve() {
    rgbPairs **tmp;
    for (int k = 0; k < 6; k++) {
        tmp = *sides[k];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tmp[i][j] == w) {
                    std::cout << 'w' << " ";
                }
                if (tmp[i][j] == y) {
                    std::cout << 'y' << " ";
                }
                if (tmp[i][j] == r) {
                    std::cout << 'r' << " ";
                }
                if (tmp[i][j] == g) {
                    std::cout << 'g' << " ";
                }
                if (tmp[i][j] == b) {
                    std::cout << 'b' << " ";
                }
                if (tmp[i][j] == o) {
                    std::cout << 'o' << " ";
                }
            }
            std::cout << '\n';
        }
        std::cout << "\n\n";
    }
    Phase_1();
    Phase_2();
    Phase_3();
    Phase_4();
    Phase_5();
    Phase_6();
    Phase_7();
}

int Cube::find_side(rgbPairs color) {
    if (color == w) {
        return 0;
    }
    if (color == y) {
        return 1;
    }
    if (color == g) {
        return 3;
    }
    if (color == b) {
        return 5;
    }
    if (color == o) {
        return 2;
    }
    if (color == r) {
        return 4;
    }
}

rgbPairs Cube::find_another_color(int side, int i, int j) {
    if (side == 0) {
        if (i == 1) {
            if (j == 0) {
                return left[0][1];
            } else {
                return right[0][1];
            }
        } else if (i == 0) {
            return back[0][1];
        } else {
            return front[0][1];
        }
    }
    if (side == 1) {
        if (i == 1) {
            if (j == 0) {
                return left[2][1];
            } else {
                return right[2][1];
            }
        } else if (i == 0) {
            return front[2][1];
        } else {
            return back[2][1];
        }
    }
    if (side == 2) {
        return down[1][0];
    }
    if (side == 3) {
        return down[0][1];
    }
    if (side == 4) {
        return down[1][2];
    }
    if (side == 5) {
        return down[2][1];
    }
}

rgbPairs Cube::find_down_side(int side) {
    if (side == 2) {
        return down[0][0];
    }
    if (side == 3) {
        return down[0][2];
    }
    if (side == 4) {
        return down[2][2];
    }
    if (side == 5) {
        return down[2][0];
    }
}

void Cube::Phase_1() {
    int side_counter = 0, right_side;
    rgbPairs another_color;
    rgbPairs **tmp_side;
    rgbPairs **tmp_side_2;
    if(up[1][2] == w && (find_another_color(0,1,2) != r || right[0][1] != r)){
        R();
        R();
    }
    if(up[1][0] == w && (find_another_color(0,1,0) != o || left[0][1] != r)){
        L();
        L();
    }
    if(up[0][1] == w && (find_another_color(0,0,1) != b || back[0][1] != b)){
        B();
        B();
    }
    if(up[2][1] == w && (find_another_color(0,2,1) != g || front[0][1] != g)){
        F();
        F();
    }

    while (up[1][2] != w || up[1][0] != w || up[0][1] != w || up[2][1] != w) {
        side_counter = (side_counter + 1) % 6;
        if (side_counter == 0) {
            side_counter++;
        }
        if(up[1][2] == w && (find_another_color(0,1,2) != r || right[0][1] != r)){
            R();
            R();
        }
        if(up[1][0] == w && (find_another_color(0,1,0) != o || left[0][1] != o)){
            L();
            L();
        }
        if(up[0][1] == w && (find_another_color(0,0,1) != b || back[0][1] != b)){
            B();
            B();
        }
        if(up[2][1] == w && (find_another_color(0,2,1) != g || front[0][1] != g)){
            F();
            F();
        }
        if (side_counter == 1) {
            if (down[1][2] == w) {
                another_color = right[2][1];
            } else if (down[1][0] == w) {
                another_color = left[2][1];
            } else if (down[0][1] == w) {
                another_color = front[2][1];
            } else if (down[2][1] == w) {
                another_color = back[2][1];
            } else {
                continue;
            }
            right_side = find_side(another_color);
            tmp_side = *sides[right_side];
            while (tmp_side[2][1] != another_color || find_another_color(right_side, 0, 0) != w) {
                D();
            }
            pick_rotation(right_side, 8);
            pick_rotation(right_side, 8);
            continue;
        }
        tmp_side = *sides[side_counter];
        another_color = find_another_color(side_counter, 0, 0);
        right_side = find_side(another_color);
        tmp_side_2 = *sides[right_side];
        if (tmp_side[2][1] == w) {
            while (find_another_color(right_side, 0, 0) != another_color || tmp_side_2[2][1] != w) {
                D();
                side_counter = (side_counter + 1) % 6;
                if (side_counter == 0 || side_counter == 1)
                    side_counter = 2;
            }
            D();
            pick_rotation(side_counter, 3);
            pick_rotation(side_counter, 8);
            pick_rotation(side_counter, 2);
            continue;
        }
        if (tmp_side[1][0] == w) {
            pick_rotation(side_counter, 8);
            D();
            pick_rotation(side_counter, 9);
        }
        if (tmp_side[1][2] == w) {
            pick_rotation(side_counter, 9);
            D();
            pick_rotation(side_counter, 8);
        }
        if (tmp_side[0][1] == w) {
            pick_rotation(side_counter, 8);
            pick_rotation(side_counter, 8);
            D();
            pick_rotation(side_counter, 9);
            pick_rotation(side_counter, 9);
        }
    }
}

void Cube::Phase_2() {
    int side_counter = 0;
    rgbPairs another_color;
    rgbPairs **tmp_side;
    while (up[0][0] != w || up[0][2] != w || up[2][0] != w || up[2][2] != w) {
        side_counter = (side_counter + 1) % 6;
        if (side_counter == 0 || side_counter == 1) {
            side_counter = 2;
        }
        tmp_side = *sides[side_counter];
        if (tmp_side[2][0] == w) {
            if (side_counter == 2) {
                side_counter = 6;
            }
            tmp_side = *sides[--side_counter];
            while (tmp_side[1][1] != tmp_side[2][2]) {
                D();
                if (side_counter == 5) {
                    side_counter = 1;
                }
                tmp_side = *sides[++side_counter];
            }
            pick_rotation(side_counter, 2);
            D_();
            pick_rotation(side_counter, 3);
        }
        if (tmp_side[2][2] == w) {
            another_color = find_down_side(side_counter);
            while (tmp_side[1][1] != another_color) {
                D();
                if (side_counter == 5) {
                    side_counter = 1;
                }
                tmp_side = *sides[++side_counter];
            }
            pick_rotation(side_counter, 9);
            D();
            pick_rotation(side_counter, 8);
        }
        if (find_down_side(side_counter) == w) {
            another_color = tmp_side[2][2];
            while (tmp_side[1][1] != another_color) {
                D();
                if (side_counter == 5) {
                    side_counter = 1;
                }
                tmp_side = *sides[++side_counter];
            }
            D_();
            pick_rotation(side_counter, 8);
            pick_rotation(side_counter, 2);
            D();
            D();
            pick_rotation(side_counter, 3);
            pick_rotation(side_counter, 9);
        }
        if (tmp_side[0][0] == w) {
            pick_rotation(side_counter, 8);
            D();
            pick_rotation(side_counter, 9);
        }
        if (tmp_side[0][2] == w) {
            pick_rotation(side_counter, 9);
            D();
            pick_rotation(side_counter, 8);
        }
    }
}

void Cube::Phase_3() {
    int side_counter = 0;
    rgbPairs another_color;
    rgbPairs **tmp_side;
    rgbPairs **l;
    while (front[1][0] != g || front[1][2] != g || left[1][0] != o || left[1][2] != o || right[1][0] != r ||
           right[1][2] != r || back[1][0] != b || back[1][2] != b) {
        side_counter = (side_counter + 1) % 6;
        if (side_counter == 0 || side_counter == 1) {
            side_counter = 2;
        }
        tmp_side = *sides[side_counter];
        if(tmp_side[1][0] != tmp_side[1][1]){
            pick_rotation(side_counter,8);
            D_();
            pick_rotation(side_counter,9);
            D();
            pick_rotation(side_counter,0);
            D();
            pick_rotation(side_counter,1);
            D_();
        } else if (tmp_side[1][2] != tmp_side[1][1]){
            pick_rotation(side_counter,9);
            D();
            pick_rotation(side_counter,8);
            D_();
            pick_rotation(side_counter,2);
            D_();
            pick_rotation(side_counter,3);
            D();
        }
        another_color = find_another_color(side_counter, 0, 0);
        if (another_color == y || tmp_side[2][1] == y) {
            continue;
        }
        while (tmp_side[1][1] != tmp_side[2][1]) {
            D();
            if (side_counter == 5) {
                side_counter = 1;
            }
            tmp_side = *sides[++side_counter];
        }
        if (side_counter == 0 || side_counter == 1) {
            side_counter = 2;
        }
        if (side_counter == 2) {
            l = *sides[5];
        } else {
            l = *sides[side_counter - 1];
        }
        if (another_color == l[1][1]) {
            D();
            pick_rotation(side_counter, 0);
            D_();
            pick_rotation(side_counter, 1);
            D_();
            pick_rotation(side_counter, 8);
            D();
            pick_rotation(side_counter, 9);
        } else {
            D_();
            pick_rotation(side_counter, 2);
            D();
            pick_rotation(side_counter, 3);
            D();
            pick_rotation(side_counter, 9);
            D_();
            pick_rotation(side_counter, 8);
        }
    }
}

void Cube::Phase_4(){
    int side_counter = 0, l_side, r_side;
    rgbPairs **tmp_side;
    while(!(((front[2][1] == g && down[0][1] == y)||(front[2][1] == y && down[0][1] == g))&&((left[2][1] == o && down[1][0] == y)||(left[2][1] == y && down[1][0] == o))&&((right[2][1] == r && down[1][2] == y)||(right[2][1] == y && down[1][2] == r))&&((back[2][1] == b && down[2][1] == y)||(back[2][1] == y && down[2][1] == b)))){
        side_counter = (side_counter+1)%6;
        if(side_counter == 0 || side_counter == 1){
            side_counter = 2;
        }
        tmp_side = *sides[side_counter];
        if((tmp_side[2][1] == tmp_side[1][1] && find_another_color(side_counter,0,0) == y)||(tmp_side[2][1] == y && find_another_color(side_counter,0,0) == tmp_side[1][1])){
            continue;
        }
        if (side_counter == 2) {
            l_side = 5;
        } else {
            l_side = side_counter - 1;
        }
        if (side_counter == 5) {
            r_side = 2;
        } else {
            r_side = side_counter + 1;
        }
        if(tmp_side[1][1] == find_another_color(l_side,0,0)){
            D();
            pick_rotation(side_counter,9);
            pick_rotation(side_counter,0);
            D();
            pick_rotation(side_counter,1);
            D_();
            pick_rotation(side_counter,8);
            continue;
        }
        if(tmp_side[1][1] == find_another_color(r_side,0,0)){
            D_();
            pick_rotation(side_counter,8);
            pick_rotation(side_counter,2);
            D_();
            pick_rotation(side_counter,3);
            D();
            pick_rotation(side_counter,9);
            continue;
        }
        D_();
        pick_rotation(side_counter,8);
        pick_rotation(side_counter,2);
        D_();
        pick_rotation(side_counter,3);
        D();
        pick_rotation(side_counter,9);
    }
}

void Cube::Phase_5(){
    int side_counter = 2;
    rgbPairs **tmp_side;
    rgbPairs **r_side;
    rgbPairs **b_side;
    if(down[0][1] != y && down[1][0] != y && down[1][2] != y && down[2][1] != y){
        pick_rotation(side_counter,3);
        C();
        pick_rotation(side_counter,3);
        C();
        pick_rotation(side_counter,3);
        C();
        pick_rotation(side_counter,3);
        C();
        D_();
        pick_rotation(side_counter,3);
        C();
        pick_rotation(side_counter,3);
        C();
        pick_rotation(side_counter,3);
        C();
        pick_rotation(side_counter,3);
        C();
        D();
    }
    while (left[2][1] != o || front[2][1] != g || right[2][1] != r || back[2][1] != b){
        side_counter = (side_counter+1)%6;
        if(side_counter == 0 || side_counter == 1){
            side_counter = 2;
        }
        tmp_side = *sides[side_counter];
        if (side_counter == 5) {
            r_side = *sides[2];
        } else {
            r_side = *sides[side_counter+1];
        }
        if (side_counter == 4) {
            b_side = *sides[2];
        } else if (side_counter == 5){
            b_side = *sides[3];
        } else {
            b_side = *sides[side_counter+2];
        }
        if(tmp_side[2][1] == y && r_side[2][1] == y){
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            D_();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            D();
        }
        if(tmp_side[2][1] == y && b_side[2][1] == y){
            side_counter--;
            if(side_counter == 1){
                side_counter =5;
            }
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            D_();
            D_();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            pick_rotation(side_counter,3);
            C();
            D();
            D();
        }
    }
}

void Cube::Phase_6(){
    int side_counter = 1,counter = 0;
    if(((front[2][0] == g && left[2][2] == o && down[0][0] == y) || (front[2][0] == g && left[2][2] == y && down[0][0] == o) || (front[2][0] == o && left[2][2] == y && down[0][0] == g)
        || (front[2][0] == o && left[2][2] == g && down[0][0] == y) || (front[2][0] == y && left[2][2] == g && down[0][0] == o) || (front[2][0] == y && left[2][2] == o && down[0][0] == g))){
        counter++;
        side_counter = 5;
    }
    if((front[2][2] == g && right[2][0] == r && down[0][2] == y) || (front[2][2] == g && right[2][0] == y && down[0][2] == r) || (front[2][2] == r && right[2][0] == y && down[0][2] == g)
       || (front[2][2] == r && right[2][0] == g && down[0][2] == y) || (front[2][2] == y && right[2][0] == g && down[0][2] == r) || (front[2][2] == y && right[2][0] == r && down[0][2] == g)){
        counter++;
        side_counter = 2;
    }
    if((left[2][0] == o && back[2][2] == b && down[2][0] == y) || (left[2][0] == o && back[2][2] == y && down[2][0] == b) || (left[2][0] == b && back[2][2] == y && down[2][0] == o)
       || (left[2][0] == b && back[2][2] == o && down[2][0] == y) || (left[2][0] == y && back[2][2] == o && down[2][0] == b) || (left[2][0] == y && back[2][2] == b && down[2][0] == o)){
        counter++;
        side_counter = 4;
    }
    if((right[2][2] == r && back[2][0] == b && down[2][2] == y) || (right[2][2] == r && back[2][0] == y && down[2][2] == b) || (right[2][2] == b && back[2][0] == y && down[2][2] == r)
       || (right[2][2] == b && back[2][0] == r && down[2][2] == y) || (right[2][2] == y && back[2][0] == r && down[2][2] == b) || (right[2][2] == y && back[2][0] == b && down[2][2] == r)){
        counter++;
        side_counter = 3;
    }
    if(counter == 4){
        return;
    }
    if(counter == 1){
        pick_rotation(side_counter,8);
        pick_rotation(side_counter,2);
        pick_rotation(side_counter,9);
        pick_rotation(side_counter,1);
        pick_rotation(side_counter,8);
        pick_rotation(side_counter,3);
        pick_rotation(side_counter,9);
        pick_rotation(side_counter,0);
        Phase_6();
        return;
    }
    if(counter == 0){
        pick_rotation(side_counter,8);
        pick_rotation(side_counter,2);
        pick_rotation(side_counter,9);
        pick_rotation(side_counter,1);
        pick_rotation(side_counter,8);
        pick_rotation(side_counter,3);
        pick_rotation(side_counter,9);
        pick_rotation(side_counter,0);
        Phase_6();
        return;
    }
}

void Cube::Phase_7(){
    int side_counter = 1;
    while (down[0][0] != y || down[2][0] != y || down[0][2] != y || down[2][2] != y){
        while (down[0][0] != y){
            L_();
            U_();
            L();
            U();
        }
        D_();
    }
}