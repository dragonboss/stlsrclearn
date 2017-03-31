/*************************************************************************
	> File Name: _stl_static_template_member.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 01:48:40 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

template<typename T>
class MyClass{
public:
    static int sdata;
};
template<>
int MyClass<char>::sdata = 45;
template<>
int MyClass<int>::sdata = 12;

int main(){

    cout << MyClass<char>::sdata << endl;
    cout << MyClass<int>::sdata << endl;
    MyClass<char> mcharobj;
    MyClass<int> minobj;
    mcharobj.sdata = 778;
    minobj.sdata = 4452;
    cout << mcharobj.sdata << endl;
    cout << minobj.sdata << endl;

    return 0;
}



