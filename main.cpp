#include <bits/stdc++.h>
#include "Model/RubiksCube3dArrayRep.cpp"

using namespace std;
int main() {

RubiksCube3dArray obj3DArray;



//obj3DArray.l();

//    obj3DArray.u();
//   if(obj3DArray.isSolved()) {
//       cout<<"YES \n";
//   }else{
//       cout<<"No\n";
//
//   }
//
//    obj3DArray.print();
//
//    obj3DArray.uPrime();
//    if(obj3DArray.isSolved()) {
//        cout<<"YES \n";
//    }else{
//        cout<<"No\n";
//
//    }
//
//
//    obj3DArray.print();
//

vector<RubiksCube33::MOVE>movesForSuffeling =obj3DArray.randomSuffleCube(5);

for(auto move:movesForSuffeling){ // getting idx of MOVE
    cout<<obj3DArray.getMove(move)<<" "; // return  actual what idx of MOVE is performed
}
cout<<endl;
    if(obj3DArray.isSolved()) {
        cout<<"YES \n";
    }else{
        cout<<"No\n";

    }

    obj3DArray.print();





    return 0;
}
