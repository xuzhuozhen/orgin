#include<bits/stdc++.h>
#include"LinearStruct/linklist.h"
using namespace std;


int main(){

    cout << "--------------linklist----------------" << endl;
    linear::Linklist<int> list;
    auto p = list.get();
    for (int i = 0; i < 10; ++i){
        list.addNode2Head(i);
    }

    while (p){
        cout << "p address = " << p << endl;
        p = p->next;
    }

    cout << "-------------linklist----------------" << endl;

    cout << "-------------stack-------------" << endl;

    linear::stack<int> s;
    for (int i = 0; i < 10; ++i){
        s.push(i);
    }

    int a = s.top();
    cout << "a = " << a << endl;
    s.pop();
    a = s.top();
    cout << "after pop a = " << a << endl;
    cout << "-----------stack---------------" <<endl;
    return 0;

}

