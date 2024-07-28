//
// Created by das31 on 29-07-2024.
//

#ifndef RUBIKSCUBESOLVER_PERMUTATIONINDEXER_H
#define RUBIKSCUBESOLVER_PERMUTATIONINDEXER_H

#include "bits/stdc++.h"
#include "math.h"

using namespace  std;


template<size_t N,size_t k=N>
class PermutationIndexer{

    array<uint32_t,(1<<N)-1>onesCountLookup;
    array<uint32_t,k>factorials;

public:
         // Popluate factorials and ones-count tables.
    PermutationIndexer(){
        for(uint32_t i=0;i<(1<<N)-1;i++){

            bitset<N>bits(i);
            this->onesCountLookup[i]=bits.count();

        }

        for(uint32_t i=0;i<k;i++){
            this->factorials[i]=pick(N-1-i,k-1-i);
        }
    }
    //  Calculate the lexicographic rank (the index) of a permutation in O(n)
uint32_t rank(const array<uint8_t,k>&permutation)const{

   array<int32_t,k>lehmer;

   bitset<N>seen;

   lehmer[0]=permutation[0];

   seen[N-1-permutation[0]]=1;

   for(uint32_t i=0;i<k;i++){
       seen[N-1-permutation[i]]=1;

       uint32_t numOnes =this->onesCountLookup[seen.to_ulong()>>(N-permutation[i])];
       lehmer[i]=permutation[i]-numOnes;
   }

   uint32_t index =0;

   for(uint32_t i=0;i<k;i++){
       index+=lehmer[i]*this->factorials[i];

   }
   return index;

         }

};



#endif //RUBIKSCUBESOLVER_PERMUTATIONINDEXER_H
