//
// Created by das31 on 07-03-2024.
//

#include "RubiksCube33.h"
//
//Given a color return it's first letter
//

char RubiksCube33::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::WHITE:
            return 'W';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::GREEN:
            return 'G';
        case COLOR::BLUE:
            return 'B';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::RED:
            return 'R';

    }
}
/* Describe a move using an index
*/

string RubiksCube33::getMove(MOVE idx) {

    switch (idx) {

        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";


        
    }
}

/*
 * Perform a move operation on using a Move index.
 */
RubiksCube33 &RubiksCube33::move(MOVE idx){
    switch (idx) {

        case MOVE::U:
            return this->u();
        case MOVE::UPRIME:
            return this->uprime();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->d();
        case MOVE::DPRIME:
            return this->dprime();
        case MOVE::D2:
            return this->d2();
        case MOVE::L:
            return this->l();
        case MOVE::LPRIME:
            return this->lprime();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->r();
        case MOVE::RPRIME:
            return this->rprime();
        case MOVE::R2:
            return this->r2();
        case MOVE::F:
            return this->f();
        case MOVE::FPRIME:
            return this->fprime();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->b();
        case MOVE::BPRIME:
            return this->bprime();
        case MOVE::B2:
            return this->b2();


    }


}

/*
 * Invert a move.
 */
RubiksCube33 &RubiksCube33::invert(MOVE idx) {
    switch (idx) {

        case MOVE::U:
            return this->uprime();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::U2:
            return this->u2();
        case MOVE::D:
            return this->dprime();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::D2:
            return this->d2();
        case MOVE::L:
            return this->lprime();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::L2:
            return this->l2();
        case MOVE::R:
            return this->rprime();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::R2:
            return this->r2();
        case MOVE::F:
            return this->fprime();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::F2:
            return this->f2();
        case MOVE::B:
            return this->bprime();
        case MOVE::BPRIME:
            return this->b();
        case MOVE::B2:
            return this->b2();


    }


}

void RubiksCube33::print() const {

    cout<<"Rubik's Cube : \n\n";

    for(int row=0;row<=2;row++){

        for(unsigned i=0;i<7;i++)cout<<" ";
        for(int col=0;col<=2;col++){
            cout<<getColorLetter(getcolor(FACE::UP,row,col))<<" ";
        }
        cout<<"\n";

    }

    cout<<"\n";

    for(int row=0;row<=2;row++){


        for(int col=0;col<=2;col++){
            cout<<getColorLetter(getcolor(FACE::LEFT,row,col))<<" ";
        }
        cout<<" ";

        for(int col=0;col<=2;col++){
            cout<<getColorLetter(getcolor(FACE::FRONT,row,col))<<" ";
        }
        cout<<" ";

        for(int col=0;col<=2;col++){
            cout<<getColorLetter(getcolor(FACE::RIGHT,row,col))<<" ";
        }
        cout<<" ";

        for(int col=0;col<=2;col++){
            cout<<getColorLetter(getcolor(FACE::BACK,row,col))<<" ";
        }

        cout<<"\n";

    }
    for(int row=0;row<=2;row++){

        for(unsigned i=0;i<7;i++)cout<<" ";
        for(int col=0;col<=2;col++){
            cout<<getColorLetter(getcolor(FACE::DOWN,row,col))<<" ";
        }
        cout<<"\n";

    }
    cout<<"\n";
}

vector<RubiksCube33::MOVE>RubiksCube33::randomSuffleCube(unsigned int times) {
    vector<MOVE>moves_performed;
    srand(time(0));
    for(unsigned int i=0;i<times;i++){
        unsigned int selectMove=(rand()%18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }

    return moves_performed;

}


//Helper function returns string of corner
string RubiksCube33::getCornerColorString(uint8_t idx) const {

    string str="";
    switch(idx){

        //UFR
        case 0:
            str+= getColorLetter(getcolor(FACE::UP,2,2));
            str+=getColorLetter(getcolor(FACE::FRONT,0,2));
            str+=getColorLetter(getcolor(FACE::RIGHT,0,0));
        //UFL
        case 1:
            str+= getColorLetter(getcolor(FACE::UP,2,0));
            str+=getColorLetter(getcolor(FACE::FRONT,0,0));
            str+=getColorLetter(getcolor(FACE::LEFT,0,2));


       //UBL
        case 2:
            str+= getColorLetter(getcolor(FACE::UP,0,0));
            str+=getColorLetter(getcolor(FACE::BACK,0,2));
            str+=getColorLetter(getcolor(FACE::LEFT,0,0));
       //UBR
        case 3:
            str+= getColorLetter(getcolor(FACE::UP,0,2));
            str+=getColorLetter(getcolor(FACE::BACK,0,0));
            str+=getColorLetter(getcolor(FACE::RIGHT,0,2));
       //DFR
        case 4:
            str+= getColorLetter(getcolor(FACE::DOWN,0,2));
            str+=getColorLetter(getcolor(FACE::FRONT,2,2));
            str+=getColorLetter(getcolor(FACE::RIGHT,2,0));
       //DFL
        case 5:
            str+= getColorLetter(getcolor(FACE::DOWN,0,0));
            str+=getColorLetter(getcolor(FACE::FRONT,2,0));
            str+=getColorLetter(getcolor(FACE::LEFT,2,2));
       //DBL
        case 6:
            str+= getColorLetter(getcolor(FACE::DOWN,2,0));
            str+=getColorLetter(getcolor(FACE::BACK,2,2));
            str+=getColorLetter(getcolor(FACE::LEFT,2,0));
       //DBR
        case 7:
            str+= getColorLetter(getcolor(FACE::DOWN,2,2));
            str+=getColorLetter(getcolor(FACE::BACK,2,0));
            str+=getColorLetter(getcolor(FACE::RIGHT,2,2));

    }
    return str;
}


uint8_t RubiksCube33::getCornerIndex(uint8_t idx) const {
    string corner = getCornerColorString(idx);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubiksCube33::getCornerOrientation(uint8_t idx) const {
    string corner= getCornerColorString(idx);

    string actual_string="";

    for(auto it:corner){

        if(it!='W'&&it!="Y")continue;
        actual_string.push_back(it);

    }


    if(corner[1]==actual_string[0]){
        return 1;
    }else if(corner[2]==actual_string[0]){
        return 2;

    }else {
        return 0;
    }

}







