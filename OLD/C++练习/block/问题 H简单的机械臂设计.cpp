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
bool comp(int x,int y)
{
    return x<=y;
}
void create_Dpmin(){
     int i , j;
     for( i = 1 ; i <= n ; i++ )
          dpmin[i][0] = d[i];
     for( j = 1 ; j <= log((double)(n+1))/log(2.0) ; j++ ){
          for( i = 1 ; i+(1<<j)-1 <= n ; i++ ){
               dpmin[i][j] = mins( dpmin[i][j-1] , dpmin[i+(1<<(j-1))][j-1] );
          }
     }
}
int getmin( int a , int b ){
    int k = (int)(log((double)(b-a+1))/log(2.0));
    return mins( dpmin[a][k] , dpmin[b-(1<<k)+1][k] );
}
void Init()
{
     create_Dpmin();
}

int main
void reverse(vector<int>::iterator a,vector<int>::iterator b)
{
    b--;
    while (a<b)
    {
        swap(*a,*b);
        a++;
        b--;
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        vector<int>v;
        int x;
        for(int i=1; i<=n; i++)
        {
            cin>>x;
            v.push_back(x);
        }
        for(int i=0; i<v.size(); i++)
        {
            auto it=v.begin()+i;
            auto m=min_element(it,v.end(),comp);
            cout<<(m-v.begin()+1)<<" ";
            reverse(it,m+1);


//            for(int j=0; j<v.size(); j++)
//                cout<<v[j]<<" ";
//            cout<<endl;
        }
        cout<<endl;
    }
}
