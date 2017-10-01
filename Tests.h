//
// Created by pavel on 17.09.17.
//

#ifndef MEPHI_TESTS_H
#define MEPHI_TESTS_H
#include "ArrayList.h"
#include "LinkedList.h"

class Tests {
public:
    Tests(){}
    virtual int testAppend()= 0;
    virtual int testGet() = 0;
    virtual int testGetFirst() = 0;
    virtual int testPrepend() = 0;
    virtual int testInsert() = 0;
    virtual int testRemove() = 0;
    virtual int testSubsequence() = 0;
    virtual int testGetLast() = 0;
    virtual int testSort() = 0;
    virtual void mainTest(){
        int m = testGetLast();
        int k = testAppend();
        int y = testGet();
        int w = testGetFirst();
        int a = testPrepend();
        int t = testInsert();
        int l = testRemove();
        int o = testSubsequence();
        if (k + a + t + l + y + m + w + o == 0)
            cout << "Tests for ArrayList have been passed..." << endl;
    }

};


#endif //MEPHI_TESTS_H
