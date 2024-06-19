//
// Created by das31 on 16-06-2024.
//

#ifndef RUBIKSCUBESOLVER_DFSSOLVER_H
#define RUBIKSCUBESOLVER_DFSSOLVER_H



#include "bits/stdc++.h"
#include "../Model/RubiksCube33.h"

template<typename T,typename H>

class DFSsolver{

private:


    vector<RubiksCube33::MOVE>moves;
    int maxSearchDepth;

    bool dfs(int depth){

        //pruning
        if(depth>maxSearchDepth){
            return false;
        }

        // baseCase

        if(rubiksCube.isSolved()){
            return true;
        }

        // computation over all possibilities

        for(int i=0;i<18;i++){

            rubiksCube.move(RubiksCube33::MOVE(i));
            moves.push_back(RubiksCube33::MOVE(i));
            if(dfs(depth+1))return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube33::MOVE(i));

        }

        return false;

    }



public:
    T rubiksCube;

//constructor
DFSsolver(T rubiks_cube, int max_search_depth=8){

    rubiksCube=rubiks_cube;
    maxSearchDepth=max_search_depth;
}


vector<RubiksCube33::MOVE>solve(){

    dfs(1);
    return moves;
}

};

#endif //RUBIKSCUBESOLVER_DFSSOLVER_H