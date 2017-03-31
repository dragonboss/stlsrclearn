/*************************************************************************
	> File Name: _stl_limited_default_templates.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 02:33:29 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
struct B{
    B(){
        data = 33;
        cout << "B\t" << data << endl;
    }
    
    T data;
};

template<typename T,typename V=B<T> >
struct D{
    D(){
        cout << "D" << endl;
    }
    V v;
};

int main(){
    D<int> d;

    return 0;
}
