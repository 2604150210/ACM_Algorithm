#include <iostream>
#include <cmath>
using namespace std;
int pri(int y)//ËØÊı
{
    int ret,i;
    for(i=2;i<=sqrt(y);i++)
        if(y%i==0)
        {
            ret=0;
            break;
        }
    if(i>sqrt(y))
        ret=1;
    return ret;

}
int main()
{
    int n;
    while(cin>>n)

    cout<<pri(n)<<endl;
}
