//
// Created by das31 on 19-05-2024.
#include "RubiksCube33.h"

class RubiksCube3dArray: public RubiksCube33{

private:
    void rotateTheFace(int idx){

         char temp_arr[3][3]={};
         for(int i=0;i<3;i++){

             for(int j=0;j<3;j++){

                 temp_arr[i][j]=cube[idx][i][j];

             }
         }
         for(int i=0;i<3;i++) cube[idx][0][i]=temp_arr[2-i][0];
         for(int i=0;i<3;i++) cube[idx][i][2]=temp_arr[0][i];
         for(int i=0;i<3;i++) cube[idx][2][2-i]=temp_arr[i][2];
         for(int i=0;i<3;i++) cube[idx][2-i][0]=temp_arr[2][2-i];


    }

public:
    char cube[6][3][3]{};

    //constructor
    RubiksCube3dArray() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {

                    cube[i][j][k] = getColorLetter(COLOR(i));

                }
            }
        }

    }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override{

        char color=cube[int(face)][row][col];

        switch (color) {

            case 'G':
                return COLOR::GREEN;

            case 'R':
                 return COLOR::RED;

            case 'B':
                return COLOR::BLUE;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }

    }

    bool isSolved() const override{
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if(this->cube[i][j][k]== getColorLetter(COLOR(i)))continue;
                    return false;
                }
            }
        }

        return true;
    }

    RubiksCube33 &u() override{
        this->rotateTheFace(0);

        char temp_arr[3]={};

        for(int i=0;i<3;i++) temp_arr[i]=cube[4][0][2-i];
        for(int i=0;i<3;i++) cube[4][0][2-i]=cube[1][0][2-i];
        for(int i=0;i<3;i++) cube[1][0][2-i]=cube[2][0][2-i];
        for(int i=0;i<3;i++) cube[2][0][2-i]=cube[3][0][2-i];
        for(int i=0;i<3;i++) cube[3][0][2-i]=temp_arr[i];

         return *this;

    }


    RubiksCube33 &uPrime() override{

        this->u();
        this->u();
        this->u();
        return *this;
    }

    RubiksCube33 &u2() override{

        this->u();
        this->u();

        return *this;
    }

    RubiksCube33 &l() override{
        this->rotateTheFace(1);

        char temp_arr[3]={};

        for(int i=0;i<3;i++) temp_arr[i]=cube[0][i][0];
        for(int i=0;i<3;i++) cube[0][i][0]=cube[4][2-i][2];
        for(int i=0;i<3;i++) cube[4][2-i][2]=cube[5][i][0];
        for(int i=0;i<3;i++) cube[5][i][0]=cube[2][i][0];
        for(int i=0;i<3;i++) cube[2][i][0]=temp_arr[i];

        return *this;


    }

    RubiksCube33 &lPrime() override{

        this->l();
        this->l();
        this->l();
        return *this;
    }

    RubiksCube33 &l2() override{

        this->l();
        this->l();

        return *this;
    }


    RubiksCube33 &f() override{
        this->rotateTheFace(2);

        char temp_arr[3]={};

        for(int i=0;i<3;i++) temp_arr[i]=cube[0][2][i];
        for(int i=0;i<3;i++) cube[0][2][i]=cube[1][2-i][2];
        for(int i=0;i<3;i++) cube[1][2-i][2]=cube[5][0][2-i];
        for(int i=0;i<3;i++) cube[5][0][2-i]=cube[3][i][0];
        for(int i=0;i<3;i++) cube[3][i][0]=temp_arr[i];

        return *this;


    }

    RubiksCube33 &fPrime() override{

        this->f();
        this->f();
        this->f();
        return *this;
    }

    RubiksCube33 &f2() override{

        this->f();
        this->f();

        return *this;
    }

    RubiksCube33 &r() override{
        this->rotateTheFace(3);

        char temp_arr[3]={};

        for(int i=0;i<3;i++) temp_arr[i]=cube[0][2-i][2];
        for(int i=0;i<3;i++) cube[0][2-i][2]=cube[2][2-i][2];
        for(int i=0;i<3;i++) cube[2][2-i][2]=cube[5][2-i][0];
        for(int i=0;i<3;i++) cube[5][2-i][0]=cube[4][i][0];
        for(int i=0;i<3;i++) cube[4][i][0]=temp_arr[i];

        return *this;


    }

    RubiksCube33 &rPrime() override{

        this->r();
        this->r();
        this->r();
        return *this;
    }

    RubiksCube33 &r2() override{

        this->r();
        this->r();

        return *this;
    }


    RubiksCube33 &b() override{
        this->rotateTheFace(4);

        char temp_arr[3]={};

        for(int i=0;i<3;i++) temp_arr[i]=cube[0][0][2-i];
        for(int i=0;i<3;i++) cube[0][0][2-i]=cube[3][2-i][2];
        for(int i=0;i<3;i++) cube[3][2-i][2]=cube[5][2][i];
        for(int i=0;i<3;i++) cube[5][2][i]=cube[1][i][0];
        for(int i=0;i<3;i++) cube[1][i][0]=temp_arr[i];

        return *this;


    }

    RubiksCube33 &bPrime() override{

        this->b();
        this->b();
        this->b();
        return *this;
    }

    RubiksCube33 &b2() override{

        this->b();
        this->b();

        return *this;
    }


    RubiksCube33 &d() override{
        this->rotateTheFace(5);

        char temp_arr[3]={};

        for(int i=0;i<3;i++) temp_arr[i]=cube[2][2][i];
        for(int i=0;i<3;i++) cube[2][2][i]=cube[1][2][i];
        for(int i=0;i<3;i++) cube[1][2][i]=cube[4][2][i];
        for(int i=0;i<3;i++) cube[4][2][i]=cube[3][2][i];
        for(int i=0;i<3;i++) cube[3][2][i]=temp_arr[i];

        return *this;


    }

    RubiksCube33 &dPrime() override{

        this->d();
        this->d();
        this->d();
        return *this;
    }

    RubiksCube33 &d2() override{

        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCube3dArray &R1)const{

        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(R1.cube[i][j][k]!=cube[i][j][k])return false;
                }
            }
        }
        return true;
    }


    RubiksCube3dArray &operator=(const RubiksCube3dArray &R1){

        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    cube[i][j][k] = R1.cube[i][j][k];
                }
            }
        }
        return *this;
    }


};
struct Hash3d{

        size_t operator()(const RubiksCube3dArray &R1)const {
              string str="";
              for(int i=0;i<6;i++){
                  for(int j=0;j<3;j++){
                      for(int k=0;k<3;k++){
                          str+=R1.cube[i][j][k];
                      }
                  }
              }
            return hash<string>()(str);
        }

};



//
