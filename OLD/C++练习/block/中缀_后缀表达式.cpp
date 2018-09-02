/*表达式求值
时间限制：3000 ms  |  内存限制：65535 KB
难度：4
描述
ACM队的mdd想做一个计算器，但是，他要做的不仅仅是一计算一个A+B的计算器，他想实现随便输入一个表达式都能求出它的值的计算器，
现在请你帮助他来实现这个计算器吧。
比如输入：“1+2/4=”，程序就输出1.50（结果保留两位小数）
输入
第一行输入一个整数n，共有n组测试数据（n<10)。
每组测试数据只有一行，是一个长度不超过1000的字符串，表示这个运算式，每个运算式都是以“=”结束。这个表达式里只包含+-*//*
与小括号这几种符号。其中小括号可以嵌套使用。数据保证输入的操作数中不会出现负数。
数据保证除数不会为0
输出
每组都输出该组运算式的运算结果，输出结果保留两位小数。
样例输入
2
1.000+2/4=
((1+2)*5+1)/4=
样例输出
1.50
4.00
来源
数据结构课本例题改进
上传者
张云聪
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int main(){
    char s[1010], out[1010],stack[1010];//s输入数组,out后缀数组，stack临时存放操作符数组
    int i, j, k, m, n, bol, l2, l1;//bol比较关键，主要来分割后缀表达式中两个相邻的数字， 如果不分开的话用sscanf会出错
    float ans[1010];//结果数组
    scanf("%d", &n);
    getchar();
    while(n--){
        gets(s);
        m = strlen(s);
        l2 = 0;
        bol = 0;
        l1 = 0;
        for(i = 0; i < m -1; i++){//对操作符和数字进行处理
            if(s[i] >= 48 && s[i] <= 57 || s[i]=='.')//如果是数字直接存放后缀数组中
            {
                if(bol){
                    out[l2++]=' ';
                    bol = 0;
                }
                out[l2++] = s[i];
            }
            else if( s[i] == '+' || s[i] == '-')//如果是加减，将stack中加减之前的操作符全部弹出放入后缀数组中，再将该符号存入stack中
            {
                for(j = l1 -1; j >= 0; j--){
                    if(stack[j] != '(')//遇到左括号直接停止
                    {
                        out[l2++] = stack[j];
                        l1--;
                    }
                    else break;
                }
                stack[l1++] = s[i];
                bol = 1;
            }
            else if(s[i] == '(')//左括号直接放入
            {
                stack[l1++] = s[i];
                bol = 1;
            }
            else if( s[i] == ')')//遇到右括号，将左括号前的操作符全部弹出放入out
            {
                for(j = l1 - 1; j >= 0; j--){
                    if(stack[j] != '('){
                        out[l2++] = stack[j];
                        l1--;
                       }
                       else{
                        l1--;
                        break;
                       }
                }
                bol = 1;
            }
            else if (s[i] == '*' || s[i] == '/')//遇到乘除，将stack中栈顶前的乘除全部弹出放入out中
            {
                for(j = l1 -1;j >=0 ;j--){
                    if(stack[j] == '*' || stack[j] == '/')
                    {
                        out[l2++] = stack[j];
                        l1 --;
                    }
                    else break;
                }
                stack[l1++] = s[i];
                bol = 1;
            }
        }
        while(l1)//如果操作栈中还有剩余全部弹出放入out中
        {
            out[l2++] = stack[l1-1];
            l1--;
        }
        k = 0;
        float a;
        int b;
        for( i = 0; i < l2; i++){
            if(out[i] >= 48 && out[i] <= 57 || out[i] == '.')//如果是数字用sscanf读取存入ans中
            {
                sscanf(out + i, "%f%n", &a,&b);
                i = i + b - 1;
                ans[k++] = a;
            }
            else if(out[i] == ' ')
                continue;
            else if(out[i] == '+')
            {
                ans[k-2] += ans[k-1];
                k--;
            }
            else if(out[i] == '*')
            {
                ans[k -2] *= ans[k-1];
                k--;
            }
            else if(out[i] == '/')
            {
                ans[k-2] /= ans[k-1];
                k--;
            }
            else if(out[i] == '-'){
                ans[k - 2] -= ans[k-1];
                k--;
            }
        }
        printf("%.2f\n",ans[0]);
    }
    return 0;
}
