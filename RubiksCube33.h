//
// Created by Debasish Das on 07-03-2024.
//

#ifndef RUBIKSCUBESOLVER_RUBIKSCUBE33_H
#define RUBIKSCUBESOLVER_RUBIKSCUBE33_H

#include "bits/stdc++.h"
using namespace std;

class RubiksCube33 {

public:
    enum class FACE {

        UP,
        DOWN,
        LEFT,
        RIGHT,
        FRONT,
        BACK


    };

    enum class MOVE {

        U, UPRIME, U2,
        D, DPRIME, D2,
        L, LPRIME, L2,
        R, RPRIME, R2,
        F, FPRIME, F2,
        B, BRIME, B2


    };


    enum class COLOR {

        WHITE,
        YELLOW,
        GREEN,
        BLUE,
        RED,
        ORANGE

    };


    virtual COLOR getcolor(FACE face, unsigned row, unsigned col) const = 0;

    static char getColorLetter(COLOR color);

    virtual bool isSolved() const = 0;

    static string getMove(MOVE idx);


    void print() const;


    vector<MOVE> randomSuffleCube(unsigned int times);


    RubiksCube33 &move(MOVE idx);

    RubiksCube33 &invert(MOVE idx);



    virtual RubiksCube33 &f()=0;
    virtual RubiksCube33 &fprime()=0;
    virtual RubiksCube33 &f2()=0;

    virtual RubiksCube33 &b()=0;
    virtual RubiksCube33 &bprime()=0;
    virtual RubiksCube33 &b2()=0;

    virtual RubiksCube33 &u()=0;
    virtual RubiksCube33 &uprime()=0;
    virtual RubiksCube33 &u2()=0;

    virtual RubiksCube33 &d()=0;
    virtual RubiksCube33 &dprime()=0;
    virtual RubiksCube33 &d2()=0;

    virtual RubiksCube33 &l()=0;
    virtual RubiksCube33 &lprime()=0;
    virtual RubiksCube33 &l2()=0;

    virtual RubiksCube33 &r()=0;
    virtual RubiksCube33 &rprime()=0;
    virtual RubiksCube33 &r2()=0;

    string getCornerColorString(uint8_t idx)const;

    uint8_t getCornerIndex(uint8_t idx);


    uint8_t getCornerOrientation(uint8_t idx) const;
};

#endif //RUBIKSCUBESOLVER_RUBIKSCUBE33_H


