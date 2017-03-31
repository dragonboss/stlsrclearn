/*************************************************************************
	> File Name: vecusemyalloc.cpp
	> Author:lotuswhl 
	> Mail:2857978398@qq.com 
	> Created Time: Wed 29 Mar 2017 05:20:58 AM PDT
 ************************************************************************/

#include<iostream>
#include "myallocator.h"
#include <vector>

using namespace std;

int main(){

    vector<int,mine::allocator<int> >iv(3,9);
    for(auto item:iv){
        cout << item << '\t';
    }
    cout << endl;

    return 0;
}
