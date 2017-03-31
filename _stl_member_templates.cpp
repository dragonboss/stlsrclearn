/*************************************************************************
	> File Name: _stl_member_templates.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 02:19:47 AM PDT
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

template <typename T>
struct MyClass{
    MyClass(){
        num = 4545;
    }
    
    template<typename V>
    void showNum(const V& v){
        cout << num << "\t" << v << endl;
    }


    T num;
};


int main(){
    MyClass<int> mi;
    mi.showNum(string("tta.."));

    return 0;
}
