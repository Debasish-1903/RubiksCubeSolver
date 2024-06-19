//
// Created by das31 on 16-06-2024.
//

#ifndef RUBIKSCUBESOLVER_BFSSOLVER_H
#define RUBIKSCUBESOLVER_BFSSOLVER_H


#include "bits/stdc++.h"
#include "../Model/RubiksCube33.h"


template<typename T,typename H>
class BFSsolver{

private:

    vector<RubiksCube33::MOVE>moves;
    unordered_map<T,RubiksCube33::MOVE,H>move_done;
    // moves_done : move_done is back pointer which show how we reached to solved state
    unordered_map<T,bool,H>visited;


    T bfs(){
        // bfs will do a breadth-first-search and return solved rubik's cube

        queue<T>q;
        q.push(rubiksCube);
        visited[rubiksCube]=true;

        while(!q.empty()){

            T currNode=q.front();

            q.pop();

            if(currNode.isSolved())return currNode;

            for(int i=0;i<18;i++){

                auto curr_move=RubiksCube33::MOVE(i);
                currNode.move(curr_move);
                if(!visited[currNode]){
                    visited[currNode]=true;
                    move_done[currNode]=curr_move;
                    q.push(currNode);

                }
                currNode.invert(curr_move);
            }

        }
           return rubiksCube;
    }


public:

    T rubiksCube;

    //constructor
    BFSsolver(T rubiks_cube){
        rubiksCube=rubiks_cube;
    }

    vector<RubiksCube33::MOVE>solve(){

        T solved_cube =bfs();
        assert(solved_cube.isSolved());
        T curr_cube=solved_cube;

        while(!(curr_cube==rubiksCube)){
            RubiksCube33::MOVE curr_move=move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.invert(curr_move);

        }
        rubiksCube=solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;

    }

};

#endif //RUBIKSCUBESOLVER_BFSSOLVER_H
