#include <iostream>
#include "Tests.h"
#include "TestArray.h"
#include "TestLinked.h"


class error : public exception{};
void manual() {
    cout << "#        #       #       #      #  #    #       #       #"  << endl;
    cout << "# #    # #      # #      ##     #  #    #      # #      #" << endl;
    cout << "#  #  #  #     #   #     #  #   #  #    #     #   #     #" << endl;
    cout << "#    #   #    # # # #    #   #  #  #    #    # # # #    #" << endl;
    cout << "#        #   #       #   #    # #  #    #   #       #   #" << endl;
    cout << "#        #  #         #  #      #   ####   #         #  #####" << endl;
    cout << "Hello, you are working with sequences" << endl
         << "You can use this functions: " << endl
         << "create" << endl
         << "append" <<endl
         << "prepend" <<endl
         << "insert" <<endl
         << "remove" <<endl
         << "show" <<endl
         << "subSequence" <<endl
         << "get" <<endl
         << "getFirst" <<endl
         << "getLast" <<endl
         << "test" << endl
         << "sort" << endl;
    cout << "For more information about any function print \"man -function\"" << endl
         << "print \"exit\" for exit from program" << endl;

}
void manualSort(){
    cout << "This function is needed fo sorting your sequence"
         << "use some keys fo different sorts" << endl
         << "\"sort() -shaker\" for ShakerSort" << endl
         << "\"sort() -shell\" for ShellSort" << endl
         << "\"sort() -boubble\" for BoubbleSort" << endl;
}
void manualCreate(){
    cout << "This function is needed for creating ArrayList or LinkedList" << endl
         << "print create -ArrayList -type for creating ArrayList" << endl
         << "print create -LinkedList -type for creating LinkedList" << endl
         << "type - it is type of your data (string, float, int)" << endl;
}
void manualAppend(){
    cout << "This function is needed for adding elements to end of your sequence" << endl
         << "print \"append(element)\", elements - it is thing which you want to add" << endl
         << "ensure that the element type match the data type" << endl;
}
void manualPrepend(){
    cout << "This function is needed for adding elements to beginning of your sequence" << endl
         << "print \"prepend(element)\", elements - it is thing which you want to add" << endl
         << "ensure that the element type match the data type" << endl;
}
void manualInsert(){
    cout << "This function is needed for adding elements to your position" << endl
         << "print \"insert(index, element)\", elements - it is thing which you want to add" << endl
         << "index - the place where you want to place your element" << endl
         << "ensure that the element type match the data type" << endl;
}
void manualRemove(){
    cout << "This function is needed for removing elements from your sequence" << endl
         << "print \"remove(element)\", elements - it is thing which you want to add" << endl;
}
void manualGet() {
    cout << "This function is needed for getting elements from your position" << endl
         << "print \"get(index)\", elements - it is thing which you want to add" << endl
         << "ensure that the index doesn't go beyong of your sequence" << endl;
}
void manualGetFirst(){
    cout << "This function is needed for getting the first elements from your sequence" << endl
         << "print \"getFirst()\", if you want to use it" << endl
         << "ensure that the index doesn't go beyong of your sequence" << endl;
}
void manualGetLast(){
    cout << "This function is needed for getting last elements from your sequence" << endl
        << "print \"getLast()\", if you want to use it" << endl
        << "ensure that the index doesn't go beyong of your sequence" << endl;
}
void manualSubSequence(){
    cout << "This function is needed for getting subsequence from your sequence" << endl
         << "print \"subSequence(index1, index2)\", if you want to get subsequence" << endl
         << "index1 and index2 are bounds of your subsequence" << endl
         << "ensure that the index doesn't go beyong of your sequence" << endl;
}
void manualTest(){
    cout << "This function is needed for testing functions for working with sequences" << endl
         << "tests includes two modules for every sequence (for ArrayList and for LinkedList)" << endl
         << "if something will be wrong tests will be failed" << endl
         << "else tests will be passed" << endl;
    cout << "print test() for test" << endl;
}
void manualShow(){
    cout << "Show() function is needed for looking your sequence" << endl;
}

int main() {
    Sequence<string> *Str = NULL;
    Sequence<int> *Int = NULL;
    Sequence<float> *Float = NULL;

    manual();
    string input = "";
    while (input != "exit" || "Exit" != input) {
        getline(cin, input);
        string inputAp = input.substr(0, 6);
        string inputPrep = input.substr(0,7);
        if (input == "exit"){
            cout << "Goodbye" << endl;
            break;
        }
        if (input == "man -create")
            manualCreate();
        else if (input == "man -sort")
            manualSort();
        else if (input == "man -append")
            manualAppend();
        else if (input == "man -prepend")
            manualPrepend();
        else if (input == "man -insert")
            manualInsert();
        else if (input == "man - remove")
            manualRemove();
        else if (input == "man -get")
            manualGet();
        else if (input == "man -getFirst")
            manualGetFirst();
        else if (input == "man -show")
            manualShow();
        else if (input == "man - getLast")
            manualGetLast();
        else if (input == "man -subSequence")
            manualSubSequence();
        else if (input == "man -test")
            manualTest();
        else if (input == "create -ArrayList -int") {
            Int = new ArrayList<int>;
            cout << "ArrayList for int was created" << endl;
            Float = NULL;
            Str = NULL;
        }
        else if (input == "create -LinkedList -int"){
            Int = new LinkedList<int>;
            cout << "LinkedList for int was created" << endl;
            Float = NULL;
            Str = NULL;
        }
        else if (input == "create -ArrayList -float") {
            Int = NULL;
            Float = new ArrayList<float>;
            cout << "ArrayList for float was created" << endl;
            Str = NULL;
        }
        else if (input == "create -LinkedList -float") {
            Int = NULL;
            Float = new LinkedList<float>;
            cout << "LinkedList for float was created" << endl;
            Str = NULL;
        }
        else if (input == "create -ArrayList -string") {
            Int = NULL;
            Float = NULL;
            Str = new ArrayList<string>;
            cout << "ArrayList for string was created" << endl;
        }
        else if (input == "create -LinkedList -string") {
            Int = NULL;
            Float = NULL;
            Str = new LinkedList<string>;
            cout << "LinkedList for string was created" << endl;
        }
        else if (input == "sort() -shell"){
            if (Int != NULL)
                Int->shellSort();
            if (Float != NULL)
                Float->shellSort();
            if (Str != NULL)
                Str->shellSort();
        }
        else if (input == "sort() -shaker"){
            if (Int != NULL)
                Int->shellSort();
            if (Float != NULL)
                Float->shellSort();
            if (Str != NULL)
                Str->shellSort();
        }
        else if (input == "sort() -boubble"){
            if (Int != NULL)
                Int->boubbleSort();
            if (Float != NULL)
                Float->boubbleSort();
            if (Str != NULL)
                Str->boubbleSort();
        }
        else if (input.substr(0, 6) == "append"){
            string arg = input.substr(7, input.size());
            arg.pop_back();
            string ok = "";
            if (arg == "0")
                ok = "ok";
            try{
                if (Int != NULL) {
                    istringstream iss(arg, istringstream::in);
                    int n;
                    iss >> n;
                    if (n == 0 && ok != "ok")
                        throw error();
                    Int->append(n);
                }
            }catch(...){}
            try{
                if (Float != NULL) {
                    istringstream iss(arg, istringstream::in);
                    float n;
                    iss >> n;
                    if (n == 0 && ok != "ok")
                        throw error();
                    Float->append(n);
                }
            }
            catch(...){}
            try{
                if (Str != NULL) {
                    Str->append(arg);
                }
            }
            catch(...){}
        }
        else if (input.substr(0,7) == "prepend") {
            input.pop_back();
            cout << "prepend" << "" << input << endl;
            string arg = input;
            string ok = "";
            arg = arg.substr(8, arg.size());
            if (arg == "0")
                ok = "ok";
            try{
                if (Int != NULL) {
                    istringstream iss(arg, istringstream::in);
                    int n;
                    iss >> n;
                    if (n == 0 && ok != "ok")
                        throw error();
                    Int->prepend(n);
                }
            }catch(...){}
            try{
                if (Float != NULL) {
                    istringstream iss(arg, istringstream::in);
                    float n;
                    iss >> n;
                    if (n == 0 && ok != "ok")
                        throw error();
                    Float->prepend(n);
                }
            }
            catch(...){}
            try{
                if (Str != NULL) {
                    Str->prepend(arg);
                }
            }
            catch(...){}
        }else if (input.substr(0, 6) == "insert"){
            string arg = input;
            int st1 = input.find('(');
            int st2 = input.find(",");
            int st3 = input.find(")");
            if (st1 != -1 && st2 != -1 && st3 != -1){
                string arg1 = input.substr(st1 + 1, st2-st1);
                arg1.pop_back();
                string arg2 =  input.substr(st2 + 2, st3-1);
                arg2.pop_back();
                string ok = "";
                if (arg2 == "0")
                    ok = "ok";
                try{
                    if (Int != NULL) {
                        istringstream iss1(arg1, istringstream::in);
                        istringstream iss2(arg2, istringstream::in);
                        int n1, n2;
                        iss1 >> n1;
                        iss2 >> n2;
                        if (n2 == 0 && ok != "ok")
                            throw error();
                        Int->insertAt(n1, n2);
                    }
                }catch(...){}
                try{
                    if (Float != NULL) {
                        istringstream iss1(arg1, istringstream::in);
                        istringstream iss2(arg2, istringstream::in);
                        int n1;
                        float n2;
                        iss1 >> n1;
                        iss2 >> n2;
                        if (n2 == 0 && ok != "ok")
                            throw error();
                        Float->insertAt(n1, n2);
                    }
                }
                catch(...){}
                try{
                    if (Str != NULL) {
                        istringstream iss1(arg1, istringstream::in);
                        int n1;
                        iss1 >> n1;
                        Str->insertAt(n1, arg2);
                    }
                }
                catch(...){}
            }

        }
        else if (input.substr(0,4) == "get("){
            string arg = input.substr(4,1);
            try{
                if (Int != NULL) {
                    istringstream iss1(arg, istringstream::in);
                    int n1;
                    iss1 >> n1;
                    cout << Int->get(n1) << endl;
                }
            }catch(...){}
            try{
                if (Float != NULL) {
                    istringstream iss1(arg, istringstream::in);
                    int n1;
                    iss1 >> n1;
                    cout << Float->get(n1) << endl;
                }
            }
            catch(...){}
            try{
                if (Str != NULL) {
                    istringstream iss1(arg, istringstream::in);
                    int n1;
                    iss1 >> n1;
                    cout << Str->get(n1) << endl;
                }
            }
            catch(...){}

        }
        else if(input == "getFirst()"){
            if (Int != NULL)
                cout << Int->getFirst() << endl;
            else if (Float != NULL)
                cout << Float->getFirst() << endl;
            else if (Str != NULL)
                cout << Str->getFirst() << endl;
        }
        else if (input == "getLast()") {
            if (Int != NULL)
                cout << Int->getLast() << endl;
            else if (Float != NULL)
                cout << Float->getLast() << endl;
            else if (Str != NULL)
                cout << Str->getLast() << endl;
        }
        else if (input == "test()"){
            TestArray test1;
            TestLinked test2;
            test1.mainTest();
            test2.mainTest();
        }
        else if (input.substr(0,11) == "subSequence"){
            int tk1 = input.find("(");
            int tk2 = input.find(",");
            int tk3 = input.find(")");
            if (tk1 != -1 && tk2 != -1 && tk3 != -1) {
                string arg1 = input.substr(tk1 + 1, tk2 - tk1);
                arg1.pop_back();
                string arg2 = input.substr(tk2 + 2, tk3 - 1);
                arg2.pop_back();
                try{
                    if (Int != NULL) {
                        istringstream iss1(arg1, istringstream::in);
                        istringstream iss2(arg2, istringstream::in);
                        int n1, n2;
                        iss1 >> n1;
                        iss2 >> n2;
                        Sequence<int> *seq2 = &Int->getSubsequence(n1, n2);
                        seq2->show();
                    }
                }catch(...){}
                try{
                    if (Float != NULL) {
                        istringstream iss1(arg1, istringstream::in);
                        istringstream iss2(arg2, istringstream::in);
                        int n1;
                        int n2;
                        iss1 >> n1;
                        iss2 >> n2;
                        Sequence<float> *seq2 = &Float->getSubsequence(n1, n2);
                        seq2->show();
                    }
                }
                catch(...){}
                try{
                    if (Str != NULL) {
                        istringstream iss1(arg1, istringstream::in);
                        istringstream iss2(arg2, istringstream::in);
                        int n1;
                        iss1 >> n1;
                        int n2;
                        iss2 >> n2;
                        Sequence<string> *seq2 = &Str->getSubsequence(n1, n2);
                        seq2->show();
                    }
                }
                catch(...){}
            }
        }
        else if (input == "show()"){
            if (Int != NULL)
                Int->show();
            if (Float != NULL)
                Float->show();
            if (Str != NULL)
                Str->show();
        }
        else if (input.substr(0, 6) == "remove"){
            string arg = input.substr(7, input.size());
            arg.pop_back();
            string ok = "";
            if (arg == "0")
                ok = "ok";
            try{
                if (Int != NULL) {
                    istringstream iss1(arg, istringstream::in);
                    int n1;
                    iss1 >> n1;
                    if (n1 == 0 && ok != "ok")
                        throw error();
                    Int->remove(n1);
                }
            }catch(...){}
            try{
                if (Float != NULL) {
                    istringstream iss1(arg, istringstream::in);
                    float n1;
                    iss1 >> n1;
                    if (n1 == 0 && ok != "ok")
                        throw error();
                    Float->remove(n1);
                }
            }
            catch(...){}
            try{
                if (Str != NULL) {
                    Str->remove(arg);
                }
            }
            catch(...){}

        }
        else {
            cout << "you are doing something wrong..." << endl
                 << "Try to use the manual functions." << endl
                 << "For example, manual -create" << endl;
        }

    }

    return 0;
}


