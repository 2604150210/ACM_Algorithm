#ifndef FUNC_CPP_INCLUDED
#define FUNC_CPP_INCLUDED
#include <iostream>
#include "Func.h"//包含头文件，来具体定义已经声明的函数
using namespace std;
int max(int a,int b)//比较两个整数的大小
{
    return a>b?a:b;
}
//函数和函数之间预留一行，便于函数管理
int add(int a,int b)//实现相加功能
{
    return a+b;
}

void printf(int a)
{
    cout<<"值是："<<a<<endl;
}


#endif // FUNC_CPP_INCLUDED
