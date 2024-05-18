//
// Created by Debasish Das on 07-03-2024.
//

#ifndef RUBIKSCUBESOLVER_RUBIKSCUBE33_H
#define RUBIKSCUBESOLVER_RUBIKSCUBE33_H

#include "bits/stdc++.h"
using namespace std;

/**
 * A base class for all Rubik's Cube Model. There are various representation for Rubik's Cube.
 * Each one has it's own special ways of definitions. This class provides a shared functionality
 * between all models.
 * We'll benchmark all models and observe which one is better for performance.
 */

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
        B, BPRIME, B2


    };


    enum class COLOR {

        WHITE,
        YELLOW,
        GREEN,
        BLUE,
        RED,
        ORANGE

    };

    /*
   * Returns the color of the cell at (row, col) in face.
   * If Rubik's Cube face is pointing at you, then the row numbering starts from the
   * top to bottom, and column numbering starts from the left to right.
   * The rows and columns are 0-indexed.
   * @param Face, row, and column index
   */

    virtual COLOR getcolor(FACE face, unsigned row, unsigned col) const = 0;

    /*
  * Returns the first letter of the given COLOR
  * Eg: For COLOR::GREEN, it returns 'G'
  */

    static char getColorLetter(COLOR color);


    /*
    * Returns true if the Rubik's Cube is solved, otherwise returns false.
    */
    virtual bool isSolved() const = 0;



    /*
     * Returns the move in the string format.
     */

    static string getMove(MOVE idx);

    /*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */


    void print() const;




    /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */

    vector<MOVE> randomSuffleCube(unsigned int times);

    /*
   * Perform moves on the Rubik's Cube
   */
    RubiksCube33 &move(MOVE idx);


    /*
    * Invert a move
    */

    RubiksCube33 &invert(MOVE idx);


    /*
     * Rotational Moves on the Rubik's Cubes
     *

     * U, U’, U2,
     * D, D’, D2,
     * L, L’, L2,
     * R, R’, R2,
     * F, F’, F2,
     * B, B’, B2
     */


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

    virtual RubiksCube33 &f()=0;
    virtual RubiksCube33 &fprime()=0;
    virtual RubiksCube33 &f2()=0;

    virtual RubiksCube33 &b()=0;
    virtual RubiksCube33 &bprime()=0;
    virtual RubiksCube33 &b2()=0;


    string getCornerColorString(uint8_t idx)const;

    uint8_t getCornerIndex(uint8_t idx)const;


    uint8_t getCornerOrientation(uint8_t idx) const;
};

#endif //RUBIKSCUBESOLVER_RUBIKSCUBE33_H


