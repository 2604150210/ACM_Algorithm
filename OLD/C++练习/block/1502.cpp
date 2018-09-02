#include <iostream>
//#include <vector>
#include <iomanip>
using namespace std;
long long fw(int a,int n)
{
    long long ret;
    if(n==1)
        ret=a;
    else
        ret=fw(a,n-1)*10+ret;
    return ret;
}
int main()
{
    int a,n;
    while(cin>>a>>n)
    {
        long long s=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<fw(a,i)<<endl;
            s+=fw(a,i);
        }

        cout<<s<<endl;
    }


    return 0;
}
