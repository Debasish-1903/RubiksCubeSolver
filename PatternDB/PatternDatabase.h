//
// Created by das31 on 25-07-2024.
//

#ifndef RUBIKSCUBESOLVER_PATTERNDATABASE_H
#define RUBIKSCUBESOLVER_PATTERNDATABASE_H


#include "bits/stdc++.h"
#include "../Model/RubiksCube33.h"
#include "NibbleArray.h"
using namespace std;

class PatternDatabase {

    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabase();
public:
    PatternDatabase(const size_t size);

// Testing for init_val

PatternDatabase(const size_t size, uint8_t init_val);

virtual  uint32_t getDatabaseIndex(const RubiksCube33 &cube)const =0;
virtual bool setNumMoves(const RubiksCube33 &cube , const uint8_t numMoves);
virtual bool setNumMoves(const uint32_t idx,const uint8_t numMoves);
virtual uint8_t getNumMoves(const RubiksCube33 && cube)const;
virtual uint8_t  getNumMoves(const uint32_t idx)const;

virtual size_t getSize() const;
virtual size_t getNumItems() const;
virtual bool isFull() const;
virtual void toFile(const string &filePath)const;
virtual bool fromFile(const string &filePath);
virtual  vector<uint8_t>inflate() const;

virtual void reset();

};


#endif //RUBIKSCUBESOLVER_PATTERNDATABASE_H
