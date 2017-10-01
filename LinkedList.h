#ifndef MEPHI_LINKEDLIST_H
#define MEPHI_LINKEDLIST_H
#include "Sequence.h"

template <typename T> class LinkedList : public Sequence<T> {
public:
    LinkedList():Head(NULL){} ;
    struct  Node{
        T element;
        Node *Next, *Back;
    };
    Node *Head;

    void append(T item) {
        this->lengthPlus();
        Node *node = new Node;
        node->element = item;
        node->Next = NULL;
        node->Back = NULL;
        if (this->getIsEmpty()) {
            Head = node;
            this->isNotEmpty();
        }
        else{
            Node *temp = Head;
            while (temp->Next != NULL) {
                temp = temp->Next;
            }
            temp->Next = node;
            node->Back = temp;
        }
    };
    void show(){
        Node *tempHead = Head;
        int temp = this->getLength(); //correct it
        int counter = 1;
        while (tempHead!= NULL){
            cout << counter << " : " << tempHead->element << endl;
            tempHead = tempHead->Next;
            temp--; counter++;
        }
        cout << endl;
    };
    T get(int index) override {
        if (index < 0)
            return NULL;
        if (index >= this->getLength())
            return NULL;
        int count = 0;
        Node *tempHead =
                Head;
        while (count < index) {
            tempHead = tempHead->Next;
            count++;
        }
        return tempHead->element;
    }
    T getFirst() override {
        return get(0);
    }
    T getLast() override {
        Node *tempHead = Head;
        while (tempHead->Next != NULL){
            tempHead=tempHead->Next;
        }
        return tempHead->element;
    }
    LinkedList<T>& getSubsequence(int startIndex, int endIndex) { // correct it
        Node *var = Head;
        if (startIndex > endIndex){
            int k = startIndex;
            startIndex = endIndex;
            endIndex = k;
        }
        if (startIndex < 0)
            startIndex = 0;
        if (endIndex > this->getLength())
            endIndex = this->getLength();

        for (int i = 0; i < startIndex; ++i) {
            var = var->Next;
        }
        LinkedList<T> *list = new LinkedList<T>;
        for (int j = 0; j < endIndex-startIndex; ++j) {
            list->append(var->element);
            var = var->Next;
            //list->lengthPlus();
        }
        list->setLength(endIndex - startIndex);

        return *list;
    }
    /*void getSubsequence(int startIndex, int endIndex, Sequence<T> *list) override {
        Node *var = Head;
        for (int i = 0; i < startIndex; ++i) {
            var = var->Next;
        }
        for (int j = 0; j < endIndex-1; ++j) {
            list->append(var->element);
            var = var->Next;
            list->lengthPlus();
        }
    }*/
    void prepend(T item) override {
        this->lengthPlus();
        Node *tempHead = new Node;
        tempHead->element = item;
        tempHead->Next = NULL;
        tempHead->Back = NULL;
        if (this->getIsEmpty()) {
            Head = tempHead;
            this->isNotEmpty();
        }else {
            tempHead->Next = Head;
            Head->Back = tempHead;
            Head = tempHead;
        }

    }
    void insertAt(int index, T item) override {
        if (index < 0 || index > this->getLength())
            return;
        Node *tempHead = new Node;
        tempHead->element = item;
        Node *var = Head;
        if (index == 0){
            Head = tempHead;
        }
        else {
            for (int i = 0; i < index - 1; ++i) {
                var = var->Next;
            }
            tempHead->Next = var->Next;
            tempHead->Back = var;
            var->Next->Back = tempHead;
            var->Next = tempHead;
        }
        this->lengthPlus();
    }
    void remove(T item) override {
        Node *node = Head;
        int var = this->getLength();
        while (node != NULL) {
            if (node->element == item) {
                if (node->Back) {
                    node->Back->Next = node->Next;
                    if(node->Next != NULL )
                        node->Next->Back = node->Back;
                    node = node->Back;

                    this->lengthMinus();
                }
                else{
                    node->Next->Back = NULL;
                    node = node->Next;
                    Head = node;
                    this->lengthMinus();
                }
            }else {
                node = node->Next;
            }
        }

    }
    void boubbleSort() override {
        Node *temp1, *temp2;
        if (this->getLength() == 1 || this->getLength() == 0)
            return;
        for (int i = 0; i < this->getLength(); ++i) {
            temp1 = Head;
            temp2 = Head->Next;
            for (int j = 0; j < this->getLength(); j++) {
                if (temp1->element > temp2->element) {
                    swap(temp1->element, temp2->element);
                }
                temp1 = temp1->Next;
                temp2 = temp2->Next;
                if (temp2 == nullptr)
                    break;
            }
        }

    }
    void shakerSort() override{
        Node *temp1, *temp2;
        for (int i = 0; i < this->getLength(); ++i) {
            int c = 0;
            if (this->getLength() == 0 || this->getLength() == 1)
                return;
            temp1 = Head;
            temp2 = Head->Next;
            for (int j = 0; j < this->getLength() - 2; ++j) {
                if (temp1->element > temp2->element) {
                    swap(temp1->element, temp2->element);
                    c++;
                }
                temp1 = temp1->Next;
                temp2 = temp2->Next;
            }
            for (int k = 0; k < this->getLength() - 1; ++k) {
                if (temp1->element > temp2->element) {
                    swap(temp1->element, temp2->element);
                    c++;
                }
                temp1 = temp1->Back;
                temp2 = temp2->Back;
            }
            if (c == 0)
                break;



        }
    };
    void shellSort() override {
        for (int d = this->getLength() / 2; d > 0; d /= 2) {
            Node *temp1, *temp2;
            for (int i = 0; i < this->getLength(); ++i) {
                if (d != 0) {
                    for (int j = 0; j < (this->getLength() / d) - 1; ++j) {
                        temp1=Head;
                        temp2=Head;
                        for (int k = 0; k < j * d; ++k) {
                            temp1= temp1->Next;
                        }
                        for (int l = 0; l < (j+1) * d ; ++l) {
                            temp2 = temp2->Next;
                        }
                        if (temp1->element > temp2->element)
                            swap(temp1->element, temp2->element);
                    }
                }


            }
        }
    };
};

#endif //MEPHI_ARRAYLIST_H
