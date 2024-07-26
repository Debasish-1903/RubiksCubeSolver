//
// Created by das31 on 25-06-2024.
//

#include "NibbleArray.h"
using namespace  std;

NibbleArray::NibbleArray(const size_t size, const uint8_t val): size(size),arr(size/2,val) {

}

uint8_t NibbleArray ::get(const uint8_t pos) const {
     size_t i=pos/2;
    assert(pos<= this->size);
     uint8_t value=arr.at(i);

     if(pos%2){

         return value & 0x0F;
     }else{
         return value >>4;
     }

}

void NibbleArray ::set(const size_t pos, const uint8_t val) {

    size_t i =pos/2;
    assert(pos<=this->size);
    uint8_t curr_val=arr.at(i);

    //lower nibble
    if(pos%2){

        this->arr.at(i)=(curr_val & 0xF0)|(val & 0x0F);

    }else{
        //upper nibble
        this->arr.at(i)=(curr_val & 0x0F)|(val << 4);
    }

}

uint8_t *NibbleArray :: data() {
    return this->arr.data();
}


const uint8_t *NibbleArray :: data() const {
    return this->arr.data();
}



// Move all the moves to a vector. This doubles the size, but is faster to access,
// since there is no bitwise operation needed.

void NibbleArray ::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);

    for(unsigned i=0 ; i< this->size;i++){
        dest.push_back(this->get(i));
    }

}

void NibbleArray ::reset(const uint8_t val) {
    fill(this->arr.begin(),this->arr.end(),val);
}