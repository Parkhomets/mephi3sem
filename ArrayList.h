//
// Created by pavel on 17.09.17.
//

#ifndef MEPHI_ARRAYLIST_H
#define MEPHI_ARRAYLIST_H
#include "Sequence.h"
#include <alloca.h>


template <typename T> class ArrayList : public Sequence <T>{
public:
    T *array = (T*)malloc(0 * sizeof(T));
    ArrayList(){};
    T get(int index) {
        T elem;
        try{
            elem = array[index];
        } catch(...) {
            cout << "Incorrect index..." << endl;
        }
        return elem;
    }
    T getFirst() {
        return array[0];
    }
    T getLast() override {
        return array[this->getTempLength()-1];
    }
    void show() override {
        cout << "[";
        for (int i = 0; i < this->getTempLength(); ++i) {
            cout << array[i];
            if (i < this->getTempLength() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    void append(T item) override {
        if (this->getLength() == 0) {
            array = (T*)realloc(array, 1 * sizeof(T));
            array[0] = item;
            this->lengthPlus();
            this->tempLengthPlus();
        }else{
            if (this->getLength() == this->getTempLength()){
                array = (T*)realloc(array, this->getLength() * 2 * sizeof(T));
                array[this->getTempLength()] = item;
                this->setLength(this->getLength() * 2);
                this->tempLengthPlus();
            }
            else{
                array[this->getTempLength()] = item;
                this->tempLengthPlus();
            }
        }

    }
    void prepend(T item) override {
        if (this->getLength() == 0){
            array = (T*)realloc(array, 1 * sizeof(T));
            array[0] = item;
            this->lengthPlus();
            this->tempLengthPlus();
        }else{
            if (this->getLength() == this->getTempLength()){
                T *array1 = (T*)malloc(this->getLength() * 2 * sizeof(T));
                array1[0] = item;
                for (int i = 0; i < this->getTempLength(); ++i) {
                    array1[i+1] = array[i];
                }
                array = (T*)realloc(array1,this->getLength() * 2 * sizeof(T));
                this->setLength(this->getLength()*2);
                this->tempLengthPlus();
            }
            else {
                T *array1 = (T *) malloc(this->getLength() * sizeof(T));
                array1[0] = item;
                for (int j = 0; j < this->getTempLength(); ++j) {
                    array1[j + 1] = array[j];
                }
                array = array1;
                this->tempLengthPlus();
            }

        }
    }
    void insertAt(int index, T item) override {
        if (index >= this->getTempLength()){
            append(item);
        }else if (index <= 0) {
            prepend(item);
        }else{
            if (this->getLength() == this->getTempLength()){
                T *array1 = (T*)malloc(this->getLength() * 2 * sizeof(T));
                for (int i = 0; i < index; ++i) {
                    array1[i] = array[i];
                }
                array1[index] = item;
                for (int j = index; j < this->getTempLength(); ++j) {
                    array1[j+1] = array[j];
                }
                this->setLength(this->getLength()*2);
                this->tempLengthPlus();
                array = array1;
            }else{
                T *array1 = (T*)malloc(this->getLength() * sizeof(T));
                for (int i = 0; i < index; ++i) {
                    array1[i] = array[i];
                }
                array1[index] = item;
                for (int j = index; j < this->getTempLength(); ++j) {
                    array1[j+1] = array[j];
                }
                this->tempLengthPlus();
                array = array1;
            }

        }

    }
    /*void remove(T item) override {
        ArrayList <T> array1;
        int var = this->getTempLength();
        for (int i = 0; i < var; ++i) {
            if (array[i] == item) {
                cout << this->getTempLength();
                this->tempLengthMinus();
                cout << "found!!" << endl;

            }else{
                array1.append(array[i]);
            }
        }
        cout << this->getTempLength()<<endl;
        array = array1.array;

    }*/
    void remove(T item) override {
        T *array1 = (T*)malloc(this->getLength() * sizeof(T));
        int var = this->getTempLength();
        int count = 0;
        for (int i = 0; i < var; ++i) {
            if (array[i] != item){
                array1[i-count] = array[i];
            } else{
                this->tempLengthMinus();
                count++;
            }
        }
        array = array1;
    }
    ArrayList<T> & getSubsequence(int startIndex, int endIndex) override {
        if (startIndex > endIndex){
            int k = startIndex;
            startIndex = endIndex;
            endIndex = k;
        }
        if (startIndex < 0)
            startIndex = 0;
        if (endIndex > this->getTempLength())
            endIndex = this->getTempLength();
        int count = 0;
        T *array1 = (T*)malloc(this->getLength() * sizeof(T));
        ArrayList <T> *arr = new ArrayList<T>;

        for (int i = startIndex; i < endIndex; ++i) {
            array1[count] = array[i];
            count++;
            arr->tempLengthPlus();
        }
        arr->array = array1;
        return *arr;

    }
    void boubbleSort() override {
        for (int i = 0; i < this->getTempLength(); ++i) {
            for (int j = 0; j < this->getTempLength() - 1; ++j) {
                if (array[j] > array[j+1])
                    swap(array[j], array[j+1]);
            }
        }
    };
    void shellSort() override{
        for (int d = this->getTempLength() / 2; d > 0; d /= 2) {
            for (int i = 0; i < this->getTempLength(); ++i) {
                if (d != 0) {
                    for (int j = 0; j < (this->getTempLength() / d) - 1; ++j) {
                        if (array[j * d] > array[(j + 1) * d])
                            swap(array[j * d], array[(j + 1) * d]);
                    }
                }


            }
        }


    };
    void shakerSort() override{
        for (int i = 0; i < this->getTempLength(); ++i) {
            int c = 0;
            for (int j = 0; j < this->getTempLength() - 1; ++j) {
                if (array[j] > array[j+1]) {
                    swap(array[j], array[j + 1]);
                    c++;
                }
            }

            for (int k = this->getTempLength() - 1; k > 1 ; --k) {
                if (array[k] < array[k-1]) {
                    swap(array[k], array[k - 1]);
                    c++;
                }
            }
            if (c == 0)
                break;
        }
    };
};


#endif //MEPHI_ARRAYLIST_H
