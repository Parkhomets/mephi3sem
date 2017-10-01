//
// Created by pavel on 17.09.17.
//

#ifndef MEPHI_TESTARRAY_H
#define MEPHI_TESTARRAY_H

#include <cmath>
#include "Tests.h"

class TestArray : public Tests{
public:
    TestArray(){};

    int testSort() override {
        ArrayList<int> *Int = new ArrayList<int>;
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
            if (Int->array[i] == a[i]) l++;
        }
        if (l == 6) count++;
        else
            cout << "Error in ShellSort in ArrayList" << endl;

        Int = new ArrayList<int>;
        Int->append(4);
        Int->append(3);
        Int->append(2);
        Int->append(1);
        Int->append(0);
        Int->append(9);
        Int->shakerSort();
        int ll = 0;
        for (int i = 0; i < 6; ++i) {
            if (Int->array[i] == a[i]) ll++;
        }
        if (ll == 6) count++;
        else
            cout << "Error in ShakerSort in ArrayList" << endl;

        Int = new ArrayList<int>;
        Int->append(4);
        Int->append(3);
        Int->append(2);
        Int->append(1);
        Int->append(0);
        Int->append(9);
        Int->boubbleSort();
        int lll = 0;
        for (int i = 0; i < 6; ++i) {
            if (Int->array[i] == a[i]) lll++;
        }
        if (lll == 6) count++;
        else
            cout << "Error in BoubbleSort in ArrayList" << endl;
        if (count == 3)
            return 0;
        else
            return 1;
    }
    int testAppend() override{
        ArrayList<int> arrInt;
        ArrayList<float> arrFloat;
        ArrayList<string> arrString;
        int count = 0;

        if (arrInt.getTempLength() == 0) {
            arrInt.append(4);
            if (arrInt.getTempLength() == 1)
                count++;
        }
        arrInt.append(6);
        arrInt.append(7);
        arrInt.append(8);
        arrInt.append(9);
        if (arrInt.getTempLength() == 5)
            count++;
        int a[5] = {4, 6, 7, 8, 9};
        int k = 0;
        for (int i = 0; i < 5; ++i) {
            if (a[i] == arrInt.array[i])
                k++;
        }
        if (k == 5)
            count++;

        if (arrFloat.getTempLength() == 0) {
            arrFloat.append(4.22);
            if (arrFloat.getTempLength() == 1)
                count++;
        }
        arrFloat.append(6.66);
        arrFloat.append(7.77);
        arrFloat.append(8.88);
        arrFloat.append(9.99);
        if (arrInt.getTempLength() == 5)
            count++;
        float f[5] = {4.22, 6.66, 7.77, 8.88, 9.99};
        int l = 0;
        for (int i = 0; i < 5; ++i) {
            if (f[i] == arrFloat.array[i])
                l++;
        }
        if (l == 5)
            count++;


        if (arrString.getTempLength() == 0) {
            arrString.append("pop");
            if (arrString.getTempLength() == 1)
                count++;
        }
        arrString.append("aaa");
        arrString.append("bbb");
        arrString.append("ccc");
        arrString.append("ddd");
        if (arrInt.getTempLength() == 5)
            count++;
        string s[5] = {"pop", "aaa", "bbb", "ccc", "ddd"};
        int e = 0;
        for (int i = 0; i < 5; ++i) {
            if (s[i] == arrString.array[i])
                e++;
        }
        if (e == 5)
            count++;

        if (count != 9) {
            cout << "Test append function in ArrayList is failed..." << endl;
            return 1;
        }
        return 0;








    }
    int testGet() override {
        ArrayList <int> arrInt;
        int count = 0;
        for (int i = 0; i < 10; ++i) {
            arrInt.append(i);
        }
        int k = 0;
        for (int j = 0; j < 10; ++j) {
            if(j == arrInt.get(j))
                k++;
        }
        if (k == 10)
            count++;

        if (count == 1)
            return 0;
        cout << "Test get function in ArrayList is failed..." << endl;
        return 1;

    }
    int testPrepend() override{
        ArrayList<int> arrInt;
        ArrayList<float> arrFloat;
        ArrayList<string> arrString;
        int count = 0;

        if (arrInt.getTempLength() == 0) {
            arrInt.prepend(4);
            if (arrInt.getTempLength() == 1)
                count++;
        }
        arrInt.prepend(6);
        arrInt.prepend(7);
        arrInt.prepend(8);
        arrInt.prepend(9);
        if (arrInt.getTempLength() == 5)
            count++;
        int a[5] = {9, 8, 7, 6, 4};
        int k = 0;
        for (int i = 0; i < 5; ++i) {
            if (a[i] == arrInt.array[i])
                k++;
        }
        if (k == 5)
            count++;

        if (arrFloat.getTempLength() == 0) {
            arrFloat.prepend(4.22);
            if (arrFloat.getTempLength() == 1)
                count++;
        }
        arrFloat.prepend(6.66);
        arrFloat.prepend(7.77);
        arrFloat.prepend(8.88);
        arrFloat.prepend(9.99);
        if (arrInt.getTempLength() == 5)
            count++;
        float f[5] = {9.99, 8.88, 7.77, 6.66, 4.22};
        int l = 0;
        for (int i = 0; i < 5; ++i) {
            if (f[i] == arrFloat.array[i])
                l++;
        }
        if (l == 5)
            count++;


        if (arrString.getTempLength() == 0) {
            arrString.prepend("pop");
            if (arrString.getTempLength() == 1)
                count++;
        }
        arrString.prepend("aaa");
        arrString.prepend("bbb");
        arrString.prepend("ccc");
        arrString.prepend("ddd");
        if (arrInt.getTempLength() == 5)
            count++;
        string s[5] = {"ddd", "ccc", "bbb", "aaa", "pop"};
        int e = 0;
        for (int i = 0; i < 5; ++i) {
            if (s[i] == arrString.array[i])
                e++;
        }
        if (e == 5)
            count++;

        if (count != 9) {
            cout << "Test prepend function in ArrayList is failed..." << endl;
            return 1;
        }
        return 0;
    }
    int testInsert() override{
        ArrayList<int> arrInt;
        ArrayList<float> arrFloat;
        ArrayList<string> arrString;
        int count = 0;

        arrInt.insertAt(1, 3);
        if (arrInt.array[0] == 3 && arrInt.getTempLength() == 1)
            count++;
        arrInt.insertAt(1, 5);
        arrInt.insertAt(1, 9);
        arrInt.insertAt(2, 14);
        arrInt.insertAt(-6, 59);
        if (arrInt.getTempLength() == 5)
            count++;
        int l = 0;
        int a[5] = {59, 3, 9, 14, 5};
        for (int i = 0; i < 5; ++i) {
            if (a[i] == arrInt.array[i])
                l++;
        }
        if (l == 5)
            count++;


        arrFloat.insertAt(1, 3.33);
        if (abs(arrFloat.array[0] - 3.33) < 0.01 && arrFloat.getTempLength() == 1)
            count++;
        arrFloat.insertAt(1, 5.55);
        arrFloat.insertAt(1, 9.99);
        arrFloat.insertAt(2, 14.14);
        arrFloat.insertAt(-6, 59.59);
        if (arrFloat.getTempLength() == 5)
            count++;
        int ll = 0;
        float f[5] = {59.59, 3.33, 9.99, 14.14, 5.55};
        for (int i = 0; i < 5; ++i) {
            if (abs(a[i] - arrInt.array[i]) < 0.01)
                ll++;
        }
        if (ll == 5)
            count++;


        arrString.insertAt(1, "pop");
        if (arrString.array[0] == "pop" && arrString.getTempLength() == 1)
            count++;
        arrString.insertAt(1, "ggg");
        arrString.insertAt(1, "aaa");
        arrString.insertAt(2, "kkk");
        arrString.insertAt(-6, "ooo");
        if (arrString.getTempLength() == 5)
            count++;
        int lll = 0;
        string s[5] = {"ooo", "pop", "aaa", "kkk", "ggg"};
        for (int i = 0; i < 5; ++i) {
            if (s[i] == arrString.array[i])
                lll++;
        }
        if (lll == 5)
            count++;

        if (count != 9) {
            cout << "Test prepend function in ArrayList is failed..." << endl;
            return 1;
        }
        return 0;

    }
    int testRemove() override{
        ArrayList<int> arrInt;
        ArrayList<float> arrFloat;
        ArrayList<string> arrString;
        int count = 0;

        arrInt.append(6);
        arrInt.append(8);
        arrInt.append(13);
        arrInt.append(17);
        arrInt.append(6);
        int a[4] {6, 8, 13, 6};
        int l = 0;
        arrInt.remove(17);
        for (int i = 0; i < 4; ++i) {
            if (arrInt.array[i] == a[i] && arrInt.getTempLength() == 4)
                l++;
        }
        if (l == 4)
            count++;

        int aa[2] = {8, 13};
        int ll =0;
        arrInt.remove(6);
        for (int j = 0; j < 2; ++j) {
            if (arrInt.array[j] == aa[j] && arrInt.getTempLength() == 2)
                ll++;
        }
        if(ll == 2)
            count++;
        int aaa = 8;
        arrInt.remove(13);
        if (arrInt.getTempLength() == 1 && arrInt.array[0] == aaa)
            count++;
        ////////////////
        arrFloat.append(6.66);
        arrFloat.append(8.88);
        arrFloat.append(13.13);
        arrFloat.append(17.17);
        arrFloat.append(6.66);
        float f[4] {6.66, 8.88, 13.13, 6.66};
        int g = 0;
        arrFloat.remove(17.17);
        for (int i = 0; i < 4; ++i) {
            if (abs(arrFloat.array[i] - f[i]) < 0.00999 && arrFloat.getTempLength() == 4)
                g++;
        }
        if (g == 4)
            count++;

        float ff[2] = {8.88, 13.13};
        int gg =0;
        arrFloat.remove(6.66);
        for (int j = 0; j < 2; ++j) {
            if (fabs(arrFloat.array[j] - ff[j]) < 0.00999 && arrFloat.getTempLength() == 2)
                gg++;
        }
        if(gg == 2)
            count++;
        float fff = 8.88;
        arrFloat.remove(13.13);
        if (arrFloat.getTempLength() == 1 && fabs(arrFloat.array[0] - fff) < 0.00999)
            count++;

        ////////////////

        arrString.append("aaa");
        arrString.append("bbb");
        arrString.append("ccc");
        arrString.append("ddd");
        arrString.append("aaa");
        string s[4] {"aaa", "bbb", "ddd", "aaa"};
        int k = 0;
        arrString.remove("ccc");
        for (int i = 0; i < 4; ++i) {
            if (arrString.array[i] == s[i] && arrString.getTempLength() == 4)
                k++;
        }
        if (k == 4)
            count++;

        //
        string ss[2] = {"bbb", "ddd"};
        int kk =0;
        arrString.remove("aaa");
        for (int j = 0; j < 2; ++j) {
            if (arrString.array[j] == ss[j] && arrString.getTempLength() == 2)
                kk++;
        }
        if(kk == 2)
            count++;
        string kkk = "bbb";
        arrString.remove("ddd");
        if (arrString.getTempLength() == 1 && arrString.array[0] == kkk)
            count++;

        if (count != 9) {
            cout << "Test remove function in ArrayList is failed..." << endl;
            return 1;
        }
        return 0;
    }
    int testSubsequence() override{
        ArrayList<int> arrInt;
        ArrayList<float> arrFloat;
        ArrayList<string> arrString;
        int count = 0;

        arrInt.append(6);
        arrInt.append(8);
        arrInt.append(13);
        arrInt.append(17);
        arrInt.append(6);
        arrInt.append(93);
        int a[4] {6, 8, 13, 17};
        ArrayList<int> array1 = arrInt.getSubsequence(0, 4);
        int po = 0;
        if (array1.getTempLength() == 4)
            count++;
        for (int l = 0; l < array1.getTempLength(); ++l) {
            if (a[l] == array1.array[l])
                po++;
        }
        if (po == 4)
            count++;

        ////////////////
        arrFloat.append(6.66);
        arrFloat.append(8.88);
        arrFloat.append(13.13);
        arrFloat.append(17.17);
        arrFloat.append(6.66);
        arrFloat.append(93.93);
        float b[4] {8.88, 13.13, 17.17, 6.66};
        ArrayList<float> array2 = arrFloat.getSubsequence(1,5);
        int pop = 0;
        if (array2.getTempLength() == 4)
            count++;

        for (int l = 0; l < array2.getTempLength(); ++l) {
            if (abs(b[l] - array2.array[l]) < 0.00999) {
                pop++;
            }
        }
        if (pop == 4)
            count++;
        ////////////////

        arrString.append("aaa");
        arrString.append("bbb");
        arrString.append("ccc");
        arrString.append("ddd");
        arrString.append("eee");
        arrString.append("fff");
        string s[4] {"bbb", "ccc", "ddd", "eee"};
        ArrayList<string> array4 = arrString.getSubsequence(1,5);
        int popo = 0;
        if (array4.getTempLength() == 4)
            count++;
        for (int l = 0; l < array4.getTempLength(); ++l) {
            if (s[l] == array4.array[l])
                popo++;
        }
        if (popo == 4)
            count++;
        if (count != 6) {
            cout << "Test subSequence function in ArrayList is failed..." << endl;
            return 1;
        }
        return 0;
    }
    int testGetFirst() override {
        ArrayList<int> arrInt;
        ArrayList<float> arrFloat;
        ArrayList<string> arrString;
        int count = 0;

        arrInt.append(3);
        arrInt.append(4);
        if (arrInt.getFirst() == 3)
            count++;

        arrFloat.append(4.44);
        arrFloat.append(5.55);
        if (abs(arrFloat.getFirst() - 4.44) < 0.00999)
            count++;

        arrString.append("aaa");
        arrString.append("bbb");
        if (arrString.getFirst() == "aaa")
            count++;

        if (count == 3)
            return 0;
        cout << "Test getFirst function in ArrayList is failed..." << endl;
        return 1;
    }
    int testGetLast() override {
        ArrayList<int> ArrInt;
        ArrayList<float> ArrFloat;
        ArrayList<string> ArrString;
        int count = 0;
        ArrInt.append(9);
        ArrInt.append(10);
        if (ArrInt.getLast() == 10)
            count++;

        ArrFloat.append(4.44);
        ArrFloat.append(6.66);
        if (abs(ArrFloat.getLast() - 6.66) < 0.009999)
            count++;

        ArrString.append("aaa");
        ArrString.append("bbb");
        if (ArrString.getLast() == "bbb")
            count++;

        if (count == 3)
            return 0;
        cout << "Test getLast function in ArrayList is failed..." << endl;
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
        if (k + a + t + l + y + m + w + o + sort== 0)
            cout << "Tests for ArrayList have been passed..." << endl;
    }
};


#endif //MEPHI_TESTARRAY_H
