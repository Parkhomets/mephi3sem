#ifndef MEPHI_SEQUENCE_H
#define MEPHI_SEQUENCE_H

#include <iostream>
using namespace std;

template <typename T> class Sequence {
private:
    int length;
    int tempLength;
    bool isEmpty;


public :
    Sequence(){
        isEmpty = true;
        length = 0;
        tempLength = 0;
    };
    virtual T get(int index) = 0;
    virtual T getFirst() = 0;
    virtual T getLast() = 0;
    virtual Sequence<T>& getSubsequence(int startIndex, int endIndex) = 0;
    virtual void append(T item) = 0;
    virtual void prepend(T item) = 0;
    virtual void insertAt(int index, T item) = 0;
    virtual void remove(T item) = 0;
    virtual void show() = 0;
    virtual void boubbleSort() = 0;
    virtual void shakerSort() = 0;
    virtual void shellSort() = 0;
    bool getIsEmpty(){
        return isEmpty;
    }
    int getLength(){
        return length;
    }
    void lengthPlus(){
        length++;
    }
    void lengthMinus(){
        length--;
    }
    void isNotEmpty(){
        isEmpty = false;
    }
    int getTempLength(){
        return tempLength;
    }
    void tempLengthPlus(){
        tempLength++;
    }
    void setLength(int i){
        length = i;
    }
    void tempLengthMinus(){
        tempLength--;
    }
};



#endif //MEPHI_SEQUENCE_H
