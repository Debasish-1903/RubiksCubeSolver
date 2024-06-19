//
// Created by das31 on 6-6-2024.
#include "RubiksCube33.h"

class RubiksCube1dArray: public RubiksCube33{


private :
    /*
     * Given a face index, row and col, return it's flattened index
     */

    static inline int getIndex(int idx,int row, int col){

        return (idx*9)+(row*3)+col;
    }

    void rotateTheFace(int idx){

        // anti clock wise rotaion of the face :
         char temp_arr[9]={};
        for(int i=0;i<3;i++){

            for(int j=0;j<3;j++){

                temp_arr[3*i + j]=cube[getIndex(idx,i,j)];
            }
        }

        for(int i=0;i<3;i++)cube[getIndex(idx,0,i)]=temp_arr[getIndex(idx,2-i,0)];
        for(int i=0;i<3;i++)cube[getIndex(idx,i,2)]=temp_arr[getIndex(idx,0,i)];
        for(int i=0;i<3;i++)cube[getIndex(idx,2,2-i)]=temp_arr[getIndex(idx,i,2)];
        for(int i=0;i<3;i++)cube[getIndex(idx,2-i,0)]=temp_arr[getIndex(idx,2,2-i)];

    }

public:
    char cube[54]{};


    //constructor
    RubiksCube1dArray(){

        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){

                    cube[i*9+j*3+k]= getColorLetter(COLOR(i));
                }
            }

        }

    }

    COLOR getColor(FACE face,unsigned row,unsigned col)const override{

        char color = cube[getIndex((int)face,(int)row,(int)col)];

        switch(color){

            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;

            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR:: YELLOW;

            default:
                return COLOR::WHITE;

        }

    }

     bool isSolved() const override{

        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){

                for(int k=0;k<3;k++){

                    if(this -> cube[getIndex(i,j,k)]== getColorLetter(COLOR(i)))continue;
                    return false;
                }
            }
        }
        return true;
    }

    RubiksCube1dArray &u() override{

        this->rotateTheFace(0);

        char temp_arr[3] ={};

        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];
        return *this;

    }

    RubiksCube33 &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube33 &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube33 &l() override {
        this->rotateTheFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }


    RubiksCube33 &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube33 &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube33 &f() override {
        this->rotateTheFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube33 &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube33 &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube33 &r() override {
        this->rotateTheFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube33 &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube33 &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube33 &b() override {
        this->rotateTheFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    RubiksCube33 &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube33 &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube33 &d() override {
        this->rotateTheFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    RubiksCube33 &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube33 &d2() override {
        this->d();
        this->d();

        return *this;
    }


    bool operator==(const RubiksCube1dArray &R1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != R1.cube[i]) return false;
        }
        return true;
    }

    RubiksCube1dArray &operator=(const RubiksCube1dArray &R1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = R1.cube[i];
        }
        return *this;
    }
};


struct Hash1d {
    size_t operator()(const RubiksCube1dArray &R1) const {
        string str = "";
        for (int i = 0; i < 54; i++) str += R1.cube[i];
        return hash<string>()(str);
    }
};


//


