//
// Created by das31 on 11-06-2024.

#include "RubiksCube33.h"

class RubiksCubeBitboard : public RubiksCube33{

private:
    uint64_t solved_side_config[6]{};


    int array[3][3]={{0, 1, 2},
                     {7, 8, 3},
                     {6, 5, 4}};

    uint64_t one_8 = (1<<8)-1;
    uint64_t one_24 = (1<<24)-1;

    void rotateFace(int idx){

        uint64_t side= bit_board[idx];

        side=side>>(6*8);
        bit_board[idx]=(bit_board[idx]<<16)|(side);

    }

    void rotateSide(int side1,int s1_1,int s1_2,int s1_3, int side2,int s2_1,int s2_2,int s2_3){

        uint64_t color1= (bit_board[side2]&(one_8 <<(8* s2_1)))>>(8* s2_1);
        uint64_t color2= (bit_board[side2]&(one_8 <<(8* s2_2)))>>(8* s2_2);
        uint64_t color3= (bit_board[side2]&(one_8 <<(8* s2_3)))>>(8* s2_3);

        bit_board[side1]= (bit_board[side1] & ~(one_8 << (8 * s1_1)))|(color1 << (8*s1_1));
        bit_board[side1]= (bit_board[side1] & ~(one_8 << (8 * s1_2)))|(color1 << (8*s1_2));
        bit_board[side1]= (bit_board[side1] & ~(one_8 << (8 * s1_3)))|(color1 << (8*s1_3));

    }

    //helper function to get corners ...
    int get5bitCorner(string corner ){
        int ret=0;
        string actual_str;
        for(auto c :corner){

            if(c!='W'&& c!='Y') continue;
            actual_str.push_back(c);
            if(c=='Y'){
                ret |=(1<<2);
            }
        }

        for(auto c :corner){

            if(c!='R'&& c!='O') continue;

            if(c=='O'){
                ret |=(1<<1);
            }
        }

        for(auto c :corner){

            if(c!='B'&& c!='G') continue;
            actual_str.push_back(c);
            if(c=='G'){
                ret |=(1<<0);
            }
        }

        if(corner[1]==actual_str[0]){
            ret|=(1<<3);
        }else if(corner[2]==actual_str[0]){
            ret |= (1<<4);
        }

     return ret;

    }


    //    This function was used for testing / printing

//    void print5bitbin(int a){
//        for(int i=4; i>=0; i--){
//            if(a & (1 << i)) cout << 1;
//            else cout << 0;
//        }
//    }




public:

    uint64_t bit_board[6]{};


//constructor
    RubiksCubeBitboard() {
        for (int side = 0; side < 6; side++) {
            uint64_t clr = 1 << side;
            bit_board[side] = 0;
            for (int faceIdx = 0; faceIdx < 8; faceIdx++) {
                bit_board[side] |= clr << (8 * faceIdx);
            }
            solved_side_config[side] = bit_board[side];
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        int idx = array[row][col];
        if (idx == 8) return (COLOR)((int) face);

        uint64_t side = bit_board[(int) face];
        uint64_t color = (side >> (8 * idx)) & one_8;

        int bit_pos = 0;
        while (color != 0) {
            color = color >> 1;
            bit_pos++;
        }
        return (COLOR)(bit_pos - 1);
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            if (solved_side_config[i] != bit_board[i]) return false;
        }
        return true;
    }

    RubiksCube33 &u() override {
        this->rotateFace(0);
        uint64_t temp = bit_board[2] & one_24;
        bit_board[2] = (bit_board[2] & ~one_24) | (bit_board[3] & one_24);
        bit_board[3] = (bit_board[3] & ~one_24) | (bit_board[4] & one_24);
        bit_board[4] = (bit_board[4] & ~one_24) | (bit_board[1] & one_24);
        bit_board[1] = (bit_board[1] & ~one_24) | temp;

        return *this;
    }

    RubiksCube33 &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    };

    RubiksCube33 &u2() override {
        this->u();
        this->u();

        return *this;
    };

    RubiksCube33 &l() override {
        this->rotateFace(1);
        uint64_t clr1 = (bit_board[2] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bit_board[2] & (one_8 << (8 * 6))) >> (8 * 6);
        uint64_t clr3 = (bit_board[2] & (one_8 << (8 * 7))) >> (8 * 7);

        this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);

        bit_board[5] = (bit_board[5] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));
        bit_board[5] = (bit_board[5] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bit_board[5] = (bit_board[5] & ~(one_8 << (8 * 7))) | (clr3 << (8 * 7));

        return *this;

    };

    RubiksCube33 &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    };

    RubiksCube33 &l2() override {
        this->l();
        this->l();

        return *this;
    };

    RubiksCube33 &f() override {
        this->rotateFace(2);

        uint64_t clr1 = (bit_board[0] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bit_board[0] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bit_board[0] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(0, 4, 5, 6, 1, 2, 3, 4);
        this->rotateSide(1, 2, 3, 4, 5, 0, 1, 2);
        this->rotateSide(5, 0, 1, 2, 3, 6, 7, 0);

        bit_board[3] = (bit_board[3] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bit_board[3] = (bit_board[3] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bit_board[3] = (bit_board[3] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube33 &fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    };

    RubiksCube33 &f2() override {
        this->f();
        this->f();

        return *this;
    };

    RubiksCube33 &r() override {
        this->rotateFace(3);
        uint64_t clr1 = (bit_board[0] & (one_8 << (8 * 2))) >> (8 * 2);
        uint64_t clr2 = (bit_board[0] & (one_8 << (8 * 3))) >> (8 * 3);
        uint64_t clr3 = (bit_board[0] & (one_8 << (8 * 4))) >> (8 * 4);

        this->rotateSide(0, 2, 3, 4, 2, 2, 3, 4);
        this->rotateSide(2, 2, 3, 4, 5, 2, 3, 4);
        this->rotateSide(5, 2, 3, 4, 4, 7, 6, 0);

        bit_board[4] = (bit_board[4] & ~(one_8 << (8 * 7))) | (clr1 << (8 * 7));
        bit_board[4] = (bit_board[4] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bit_board[4] = (bit_board[4] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube33 &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    };

    RubiksCube33 &r2() override {
        this->r();
        this->r();

        return *this;
    };

    RubiksCube33 &b() override {
        this->rotateFace(4);

        uint64_t clr1 = (bit_board[0] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bit_board[0] & (one_8 << (8 * 1))) >> (8 * 1);
        uint64_t clr3 = (bit_board[0] & (one_8 << (8 * 2))) >> (8 * 2);

        this->rotateSide(0, 0, 1, 2, 3, 2, 3, 4);
        this->rotateSide(3, 2, 3, 4, 5, 4, 5, 6);
        this->rotateSide(5, 4, 5, 6, 1, 6, 7, 0);

        bit_board[1] = (bit_board[1] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bit_board[1] = (bit_board[1] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bit_board[1] = (bit_board[1] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube33 &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    };

    RubiksCube33 &b2() override {
        this->b();
        this->b();

        return *this;
    };

    RubiksCube33 &d() override {
        this->rotateFace(5);

        uint64_t clr1 = (bit_board[2] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bit_board[2] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bit_board[2] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(2, 4, 5, 6, 1, 4, 5, 6);
        this->rotateSide(1, 4, 5, 6, 4, 4, 5, 6);
        this->rotateSide(4, 4, 5, 6, 3, 4, 5, 6);

        bit_board[3] = (bit_board[3] & ~(one_8 << (8 * 4))) | (clr1 << (8 * 4));
        bit_board[3] = (bit_board[3] & ~(one_8 << (8 * 5))) | (clr2 << (8 * 5));
        bit_board[3] = (bit_board[3] & ~(one_8 << (8 * 6))) | (clr3 << (8 * 6));

        return *this;
    };

    RubiksCube33 &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    };

    RubiksCube33 &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCubeBitboard &r1) const {
        for (int i = 0; i < 6; i++) {
            if (bit_board[i] != r1.bit_board[i]) return false;
        }
        return true;
    }

    RubiksCubeBitboard &operator=(const RubiksCubeBitboard &r1) {
        for (int i = 0; i < 6; i++) {
            bit_board[i] = r1.bit_board[i];
        }
        return *this;
    }


    uint64_t getCorners() {
        uint64_t ret = 0;
        string top_front_right = "";
        top_front_right += getColorLetter(getColor(FACE::UP, 2, 2));
        top_front_right += getColorLetter(getColor(FACE::FRONT, 0, 2));
        top_front_right += getColorLetter(getColor(FACE::RIGHT, 0, 0));

        string top_front_left = "";
        top_front_left += getColorLetter(getColor(FACE::UP, 2, 0));
        top_front_left += getColorLetter(getColor(FACE::FRONT, 0, 0));
        top_front_left += getColorLetter(getColor(FACE::LEFT, 0, 2));

        string top_back_left = "";
        top_back_left += getColorLetter(getColor(FACE::UP, 0, 0));
        top_back_left += getColorLetter(getColor(FACE::BACK, 0, 2));
        top_back_left += getColorLetter(getColor(FACE::LEFT, 0, 0));

        string top_back_right = "";
        top_back_right += getColorLetter(getColor(FACE::UP, 0, 2));
        top_back_right += getColorLetter(getColor(FACE::BACK, 0, 0));
        top_back_right += getColorLetter(getColor(FACE::RIGHT, 0, 2));

        string bottom_front_right = "";
        bottom_front_right += getColorLetter(getColor(FACE::DOWN, 0, 2));
        bottom_front_right += getColorLetter(getColor(FACE::FRONT, 2, 2));
        bottom_front_right += getColorLetter(getColor(FACE::RIGHT, 2, 0));

        string bottom_front_left = "";
        bottom_front_left += getColorLetter(getColor(FACE::DOWN, 0, 0));
        bottom_front_left += getColorLetter(getColor(FACE::FRONT, 2, 0));
        bottom_front_left += getColorLetter(getColor(FACE::LEFT, 2, 2));

        string bottom_back_right = "";
        bottom_back_right += getColorLetter(getColor(FACE::DOWN, 2, 2));
        bottom_back_right += getColorLetter(getColor(FACE::BACK, 2, 0));
        bottom_back_right += getColorLetter(getColor(FACE::RIGHT, 2, 2));

        string bottom_back_left = "";
        bottom_back_left += getColorLetter(getColor(FACE::DOWN, 2, 0));
        bottom_back_left += getColorLetter(getColor(FACE::BACK, 2, 2));
        bottom_back_left += getColorLetter(getColor(FACE::LEFT, 2, 0));

        ret |= get5bitCorner(top_front_right);
        ret = ret << 5;

        ret |= get5bitCorner(top_front_left);
        ret = ret << 5;

        ret |= get5bitCorner(top_back_right);
        ret = ret << 5;

        ret |= get5bitCorner(top_back_left);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_front_right);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_front_left);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_back_right);
        ret = ret << 5;

        ret |= get5bitCorner(bottom_back_left);
        ret = ret << 5;

//        Following was used for Testing / Printing

//        cout << top_front_right << " "; print5bitbin(get5bitCorner(top_front_right )); cout  << "\n";
//        cout << top_front_left << " "; print5bitbin(get5bitCorner(top_front_left )); cout << "\n";
//        cout << top_back_right << " "; print5bitbin(get5bitCorner(top_back_right )); cout << "\n";
//        cout << top_back_left  << " "; print5bitbin(get5bitCorner(top_back_left  )); cout << "\n";
//        cout << bottom_front_right  << " "; print5bitbin(get5bitCorner(bottom_front_right  )); cout << "\n";
//        cout << bottom_front_left << " "; print5bitbin(get5bitCorner(bottom_front_left )); cout << "\n";
//        cout << bottom_back_right << " "; print5bitbin(get5bitCorner(bottom_back_right )); cout << "\n";
//        cout << bottom_back_left << " "; print5bitbin(get5bitCorner(bottom_back_left )); cout << "\n";

        return ret;
    }

};

struct HashBitboard {
    size_t operator()(const RubiksCubeBitboard &r1) const {
        uint64_t final_hash = r1.bit_board[0];
        for (int i = 1; i < 6; i++) final_hash ^= r1.bit_board[i];
        return (size_t) final_hash;
    }



};