//
// Created by pavel on 17.09.17.
//

#ifndef MEPHI_TESTLINKED_H
#define MEPHI_TESTLINKED_H

#include <tgmath.h>
#include "Tests.h"


class TestLinked : public Tests{
public:
    int testAppend() override {
        LinkedList<int> Int;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;

        Int.append(9);
        if (Int.get(0) == 9 && Int.getLength() == 1)
            count++;
        Int.append(4);
        Int.append(7);
        if (Int.getLength() == 3)
            count++;
        if (Int.get(1) == 4 && Int.get(2) == 7)
            count++;

        /////////
        Float.append(9.99);
        if (abs(Float.get(0) - 9.99) < 0.00999 && Float.getLength() == 1)
            count++;
        Float.append(4.44);
        Float.append(7.77);
        if (Float.getLength() == 3)
            count++;
        if (abs(Float.get(1) - 4.44) < 0.00999 && abs(Float.get(2) - 7.77) < 0.00999)
            count++;


        String.append("aaa");
        if (String.get(0) == "aaa" && String.getLength() == 1)
            count++;
        String.append("bbb");
        String.append("ccc");
        if (String.getLength() == 3)
            count++;
        if (String.get(1) == "bbb" && String.get(2) == "ccc")
            count++;

        if (count == 9)
            return 0;
        cout << "Test prepend for LinkedList is failed..." << endl;
        return 1;

    }
    int testPrepend() override {
        LinkedList<int> Int;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;

        Int.prepend(9);
        if (Int.get(0) == 9 && Int.getLength() == 1)
            count++;
        Int.prepend(4);
        Int.prepend(7);
        if (Int.getLength() == 3)
            count++;
        if (Int.get(0) == 7 && Int.get(1) == 4 && Int.get(2) == 9)
            count++;

        /////////
        Float.prepend(9.99);
        if (abs(Float.get(0) - 9.99) < 0.00999 && Float.getLength() == 1)
            count++;
        Float.prepend(4.44);
        Float.prepend(7.77);
        if (Float.getLength() == 3)
            count++;
        if (abs(Float.get(0) - 7.77) < 0.00999 && abs(Float.get(1) - 4.44) < 0.00999 && abs(Float.get(2) - 9.99) < 0.00999)
            count++;

        String.prepend("aaa");
        if (String.get(0) == "aaa" && String.getLength() == 1)
            count++;
        String.prepend("bbb");
        String.prepend("ccc");
        if (String.getLength() == 3)
            count++;
        if (String.get(0) == "ccc" && String.get(1) == "bbb" && String.get(2) == "aaa")
            count++;

        if (count == 9)
            return 0;
        cout << "Test prepend for LinkedList is failed..." << endl;
        return 1;



    }
    int testInsert() override {
        LinkedList<int> Int;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;

        Int.append(9);
        Int.append(7);
        Int.append(9);
        int a[4] = {9, 7, 8, 9};
        Int.insertAt(2, 8);
        int kkk = 0;
        for (int i = 0; i < 4; ++i) {
            if (a[i] == Int.get(i))
                kkk++;
        }
        if (kkk == 4 && Int.getLength() == 4)
            count++;
        /////////////
        Float.append(9.99);
        Float.append(7.77);
        Float.append(9.99);
        float f[4] = {9.99, 7.77, 8.88, 9.99};
        Float.insertAt(2, 8.88);
        int kkkk = 0;
        for (int i = 0; i < 4; ++i) {
            if (abs(f[i] - Float.get(i)) < 0.00999)
                kkkk++;
        }
        if (kkkk == 4 && Float.getLength() == 4)
            count++;
        ////////////
        String.append("aaa");
        String.append("bbb");
        String.append("ccc");
        string s[4] = {"aaa", "bbb", "ddd", "ccc"};
        String.insertAt(2, "ddd");
        int kk = 0;
        for (int i = 0; i < 4; ++i) {
            if (s[i] == String.get(i))
                kk++;
        }
        if (kk == 4 && String.getLength() == 4)
            count++;
        if (count == 3)
            return 0;
        cout << "Test Insert function for LinkedList is failed..." << endl;
        return 1;
    }
    int testRemove() override {

        LinkedList<int> Int, It2;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;

        Int.append(4);
        Int.append(5);
        Int.append(6);
        Int.append(6);
        Int.append(7);
        Int.append(6);
        Int.append(6);
        Int.append(6);
        Int.remove(6);

        int a[3] = {4,5,7};
        int j = 0;
        for (int i = 0; i < 3; ++i) {
            if (a[i] == Int.get(i))
                j++;
        }
        if (j == 3)
            count++;
        Int.remove(7);
        int b[2] = {4,5};
        j = 0;

        for (int i = 0; i < 2; ++i) {
            if (b[i] == Int.get(i))
                j++;
        }
        if (j == 2)
            count++;


        ////////////
        Float.append(1.11);
        Float.append(2.22);
        Float.append(3.33);
        Float.append(1.11);
        Float.append(5.55);
        Float.append(6.66);
        Float.append(1.11);
        Float.append(8.88);
        Float.append(9.99);
        float f[6] = {2.22, 3.33, 5.55, 6.66, 8.88, 9.99};
        Float.remove(1.11);
        int ll = 0;
        for (int k = 0; k < 6; ++k) {
            if (abs(Float.get(k) - f[k]) < 0.0099)
                ll++;
        }
        if (ll == 6)
            count++;
        if (Float.getLength() == 6)
            count++;


        String.append("aaa");
        String.append("bbb");
        String.append("ccc");
        String.append("ddd");
        String.append("eee");
        String.append("fff");
        String.append("ggg");
        String.append("aaa");
        String.append("aaa");
        String.append("aaa");
        string s[6] = {"bbb", "ccc", "ddd", "eee", "fff", "ggg"};
        String.remove("aaa");

        int uuu = 0;
        for (int l = 0; l < 6; ++l) {
            if (s[l] == String.get(l))
                uuu++;
        }
        if (uuu == 6)
            count++;
        if (String.getLength() == 6)
            count++;
        String.remove("ggg");
        string ss[6] = {"bbb", "ccc", "ddd", "eee", "fff"};
        uuu = 0;
        for (int m = 0; m < 5; ++m) {
            if (ss[m] == String.get(m))
                uuu++;
        }
        if (uuu == 5)
            count++;
        if (String.getLength() == 5)
            count++;


        if (count == 8)
            return 0;
        cout << "Test remove function in LinkedList have been failed..." << endl;
        return 1;

    }
    int testSubsequence() override {
        LinkedList<int> Int, Int2;
        LinkedList<float> Float, Float2;
        LinkedList<string> String, String2;
        int count = 0;

        Int.append(9);
        Int.append(5);
        Int.append(6);
        Int.append(7);
        Int.append(8);
        Int.append(1);
        Int.append(15);
        Int2 = Int.getSubsequence(1,5);
        int a1[4] = {5,6,7,8};
        if (Int2.getLength() == 4)
            count++;
        int u = 0;
        for (int i = 0; i < 4; ++i) {
            if (Int2.get(i) == a1[i])
                u++;
        }
        if (u==4)
            count++;
        ///////

        Float.append(9.99);
        Float.append(5.55);
        Float.append(6.66);
        Float.append(7.77);
        Float.append(8.88);
        Float.append(1.11);
        Float.append(15.15);

        Float2 = Float.getSubsequence(2,6);
        float f1[4] = {6.66,7.77,8.88,1.11};
        if (Float2.getLength() == 4)
            count++;
        u = 0;
        for (int i = 0; i < 4; ++i) {
            if (Float2.get(i) == f1[i])
                u++;
        }
        if (u==4)
            count++;
        //////

        String.append("aaa");
        String.append("bbb");
        String.append("ccc");
        String.append("ddd");
        String.append("eee");
        String.append("fff");
        String.append("ggg");

        String2 = String.getSubsequence(0,4);
        if (String2.getLength() == 4)
            count++;
        if (String2.get(0) == "aaa" && String2.get(1) == "bbb" && String.get(2) == "ccc" && String2.get(3) == "ddd")
            count++;

        if (count == 6)
            return 0;
        cout << "Test getSubsequence function in LinkedList have been failed" << endl;



    }
    int testGet() override {
        LinkedList<int> Int;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;
        Int.append(6);
        Int.append(7);
        Int.append(8);
        Int.append(9);
        if (Int.get(2) == 8)
            count++;

        Float.append(6.66);
        Float.append(7.77);
        Float.append(8.88);
        Float.append(9.99);
        if (abs(Float.get(3) - 9.99) < 0.00999)
            count++;

        String.append("aaa");
        String.append("bbb");
        String.append("ccc");
        String.append("sss");

        if (String.get(1) == "bbb")
            count++;
        if (count == 3)
            return 0;
        cout << "Test get function in LinkedList have been failed..." << endl;
        return 1;


    }
    int testGetFirst() override {
        LinkedList<int> Int;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;
        Int.append(6);
        Int.append(7);
        Int.append(8);
        Int.append(9);
        if (Int.getFirst() == 6)
            count++;

        Float.append(6.66);
        Float.append(7.77);
        Float.append(8.88);
        Float.append(9.99);
        if (abs(Float.getFirst() - 6.66) < 0.00999)
            count++;

        String.append("aaa");
        String.append("bbb");
        String.append("ccc");
        String.append("sss");

        if (String.getFirst() == "aaa")
            count++;
        if (count == 3)
            return 0;
        cout << "Test getFirst function in LinkedList have been failed..." << endl;
        return 1;
    }
    int testGetLast() override {
        LinkedList<int> Int;
        LinkedList<float> Float;
        LinkedList<string> String;
        int count = 0;
        Int.append(6);
        Int.append(7);
        Int.append(8);
        Int.append(9);
        if (Int.getLast() == 9)
            count++;

        Float.append(6.66);
        Float.append(7.77);
        Float.append(8.88);
        Float.append(9.99);
        if (abs(Float.getLast() - 9.99) < 0.00999)
            count++;
        String.append("aaa");
        String.append("bbb");
        String.append("ccc");
        String.append("sss");

        if (String.getLast() == "sss")
            count++;
        if (count == 3)
            return 0;
        cout << "Test getLast function in LinkedList have been failed..." << endl;
        return 1;
    }
    int testSort() override{
        LinkedList<int> *Int = new LinkedList<int>;
        Int->append(4);
        Int->append(3);
        Int->append(2);
        Int->append(1);
        Int->append(0);
        Int->append(9);
        int a[6] = {0, 1, 2, 3, 4, 9};
        Int->shellSort();
        int count = 0;
        int l = 0;
        for (int i = 0; i < 6; ++i) {
            if (Int->get(i) == a[i]) l++;
        }
        if (l == 6) count++;
        else
            cout << "Error in ShellSort in LinkedList" << endl;

        Int = new LinkedList<int>;
        Int->append(4);
        Int->append(3);
        Int->append(2);
        Int->append(1);
        Int->append(0);
        Int->append(9);
        Int->shakerSort();
        int ll = 0;
        for (int i = 0; i < 6; ++i) {
            if (Int->get(i) == a[i]) ll++;
        }
        if (ll == 6) count++;
        else
            cout << "Error in ShakerSort in LinkedList" << endl;

        Int = new LinkedList<int>;
        Int->append(4);
        Int->append(3);
        Int->append(2);
        Int->append(1);
        Int->append(0);
        Int->append(9);
        Int->boubbleSort();
        int lll = 0;
        for (int i = 0; i < 6; ++i) {
            if (Int->get(i) == a[i]) lll++;
        }
        if (lll == 6) count++;
        else
            cout << "Error in BoubbleSort in LinkedList" << endl;
        if (count == 3)
            return 0;

        return 1;
    }
    void mainTest() override {
        int m = testGetLast();
        int k = testAppend();
        int y = testGet();
        int w = testGetFirst();
        int a = testPrepend();
        int t = testInsert();
        int l = testRemove();
        int o = testSubsequence();
        int sort = testSort();
        if (k + a + t + l + y + m + w + o + sort == 0)
            cout << "Tests for LinkedList have been passed..." << endl;
    }

};


#endif //MEPHI_TESTLINKED_H
