#ifndef FUNC_CPP_INCLUDED
#define FUNC_CPP_INCLUDED
#include <iostream>
#include "Func.h"//����ͷ�ļ��������嶨���Ѿ������ĺ���
using namespace std;
int max(int a,int b)//�Ƚ����������Ĵ�С
{
    return a>b?a:b;
}
//�����ͺ���֮��Ԥ��һ�У����ں�������
int add(int a,int b)//ʵ����ӹ���
{
    return a+b;
}

void printf(int a)
{
    cout<<"ֵ�ǣ�"<<a<<endl;
}


#endif // FUNC_CPP_INCLUDED
