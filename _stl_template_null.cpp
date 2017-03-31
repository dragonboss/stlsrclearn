/*************************************************************************
	> File Name: _stl_template_null.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 03:00:44 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T>
struct B{
    void operator()(){
        cout << "B" << endl;
    }
};

template<>
struct B<char>{
    void operator()(){
        cout << "B char" << endl;
    }
};

int main(){


    B<char> b;
    B<int> b2;
    b();
    b2();

    return 0;
}
