//
// Created by das31 on 19-06-2024.
//

#include "bits/stdc++.h"
#include "../Model/RubiksCube33.h"
#include "../PatternDB/CornerPatternDatabase.h"

#ifndef RUBIKS_CUBE_SOLVER_IDASTARTSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDASTARTSOLVER_H

template<typename T, typename H>
class  IDAstarSolver{

private:
    CornerPatternDatabase CornerDB;
    vector<RubiksCube33::MOVE>moves;
    unordered_map<T,RubiksCube33::MOVE,H>move_done;
    unordered_map<T,bool,H>visited;

    struct Node{ // creating nodes
        T cube ;
        int depth;
        int estimate;
        Node(T _cube,int _depth, int _estimate):cube(_cube),depth(_depth),estimate(_estimate){};

    };

    struct  compareCube{
        bool operator()(pair<Node,int>const &p1,pair<Node,int>const &p2){
            auto node1 = p1.first , node2= p2.first;
            if(node1.depth + node1.estimate == node2.depth + node2.estimate){
                return node1.estimate > node2.estimate;

        }else return node1.depth+node1.estimate > node2.depth + node2.estimate;

    }

    } ;

   void resetStructure(){

       moves.clear();
       move_done.clear();
       visited.clear();
   }


   // returns {solved cube ,bound} if the cube was solved
   // returnes {rubiks_cube,next_bound} if the cube is not solved;

   pair<T ,int>IDAstar(int bound){
//   priority_queue contains pair(Node, move done to reach that)
       priority_queue<pair<Node,int>,vector<pair<Node,int>>,compareCube>pq;
       auto startNode =Node(rubiksCube,0,CornerDB.getNumMoves(rubiksCube));
       pq.push(startNode,0);
       int next_bound=100;
       while(!pq.empty()){

           auto p=pq.top();
           Node node=p.first;

           pq.pop();

           if(visited[node.cube])continue;

           visited[node.cube]=true;
           move_done[node.cube]=RubiksCube33::MOVE(p.second);

           if(node.cube.isSolved())return {node.cube,bound};
           node.depth++;


           for(int i=0;i<18;i++){
               auto curr_move= RubiksCube33::MOVE(i);
               if(!visited[node.cube]){
                      node.estimate=CornerDB.getNumMoves(node.cube);
                   if(node.depth+node.estimate>bound){
                       next_bound=min(next_bound,node.depth+node.estimate);
                   }else{
                       pq.push(make_pair(node.cube,i));
                   }

               }
               node.cube.invert(curr_move);
           }

       }
       return make_pair(rubiksCube,next_bound);
 }

public:
   T rubiksCube;
IDAstarSolver(T _rubiksCube,string fileName){

    rubiksCube=_rubiksCube;
    CornerDB.fromFile(fileName);

}

vector<RubiksCube33::MOVE>solve(){
    int bound =1;
    auto p= IDAstar(bound);
    while(p.second !=bound){
        resetStructure();
        bound=p.second;
        p= IDAstar(bound);

    }

    T solved_cube=p.first;
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

#endif //RUBIKS_CUBE_SOLVER_IDASTARTSOLVER_H