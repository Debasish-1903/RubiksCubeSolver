//
// Created by das31 on 17-06-2024.
//

#ifndef RUBIKSCUBESOLVER_IDDFSSOLVER_H
#define RUBIKSCUBESOLVER_IDDFSSOLVER_H

#include "bits/stdc++.h"
#include "../Model/RubiksCube33.h"
#include "DFSSolver.h"


template<typename T, typename H>

class IDDFSsolver{


private:
    int maxSearchDepth;
    vector<RubiksCube33::MOVE>moves;



public:

    T rubiksCube;

//constructor
IDDFSsolver(T rubiks_cube ,int max_search_depth=7){
    rubiksCube=rubiks_cube;
    maxSearchDepth=max_search_depth;

}

//    Used DFSSolver with increasing max_search_depth

vector<RubiksCube33::MOVE>solve(){


    for(int i=0;i<maxSearchDepth;i++){

        IDDFSsolver<T,H>dfsSolver(rubiksCube,i);

        moves=dfsSolver.solve();

        if(dfsSolver.rubiksCube.isSolved()){

            rubiksCube=dfsSolver.rubiksCube;
            break;

        }

    }

return moves;

}

};

#endif //RUBIKSCUBESOLVER_IDDFSSOLVER_H
