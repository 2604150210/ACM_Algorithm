#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int f[2000];
int primer(int n)
{
    int ret, i;
    int sq;
    if (n == 1)
        ret = 1;
    else
    {
        sq = sqrt(n);  //Ê±¼äÓÅ»¯£¬²»ÓÃÃ¿´ÎÑ­»·¶¼ÅÐ¶Ïsqrt£¨n£©
        for (i = 2; i <= sq; i++)
            if (n % i == 0)
            {
                ret = 0;
                break;
            }
        if (i > sq) ret = 1;
    }
    return ret;
}
void Do(int x, int y)
{
    int t = 0;
    f[t++]=2;
    for (int i = 3; i <= 10000; i+=2)
    {
        if (primer(i)==1) f[t++] = i;
    }
}

int main()
{
    memset(f,1,sizeof(f));
    int a, b;
    cin >> a >> b;
    Do(a,b);

    for (int j = a; j <= b; j++)
    {
        int t=j;
        vector<int> v;
        int x = 0;
        if(primer(t)==1)
            cout<<t<<"="<<t<<endl;
        else
        {
            while (!primer(t))
            {
                //cout<<f[x]<<"*"<<t<<endl;
                while (t % f[x] == 0)
                {
                    v.push_back(f[x]);
                    t /= f[x];
                    if(t<f[x])break;
                }
                if(t<f[x])break;

                x++;
            }
            if(t!=1)
            v.push_back(t);
            cout << j << "=" << v[0];
            for (int i = 1; i < v.size(); i++)
            {
                cout << "*" << v[i];
            }
            cout << endl;
        }
    }
    return 0;
}
