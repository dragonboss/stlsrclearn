/*************************************************************************
	> File Name: _stl_class_partial_specialization.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 02:05:53 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

template<class _T1,class _T2>
class TClass{
public:
    TClass(){
        cout << "_T1,_T2" << endl;
    }
};

template<class _T1>
class TClass<_T1*,_T1>{
public:
    TClass(){
        cout << "_T1*,_T1" << endl;
    }
};

template<class _T1>
class TClass<_T1,_T1>{
public:
    TClass(){
        cout << "_T1,_T1" << endl;
    }
};

int main(){
    
    TClass<char,int> ci;
    TClass<int*,int> ipc;
    TClass<int,int> ii;


    return 0;
}
