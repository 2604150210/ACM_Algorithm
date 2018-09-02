
/********数字反转******************/
#include<iostream>
using namespace std;
int rev(int x)//·´×ªÊý×Ö
{
    int ret;
    for(ret=0;x;x/=10)
        ret=ret*10+x%10;
    return ret;
}
int main()
{
    int n;
    while(cin>>n)
        cout<<rev(n)<<endl;
    return 0;
}
