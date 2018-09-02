#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<algorithm>
//#define LOCAL
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=100010;
struct Node{
    int l,r,ma,mi;
};
Node tree[MAXN<<2];
int ax,ai;
void build(int root,int l,int r){
    tree[root].l=l;
    tree[root].r=r;
    if(l==r){
        scanf("%d",&tree[root].ma);
        tree[root].mi=tree[root].ma;
    }
    else{
        int mid=(l+r)>>1;
        build(root<<1,l,mid);
        build(root<<1|1,mid+1,r);
        tree[root].ma=max(tree[root<<1].ma,tree[root<<1|1].ma);
        tree[root].mi=min(tree[root<<1].mi,tree[root<<1|1].mi);
    }
}
void query(int root,int x,int y){
    if(tree[root].l>=x&&tree[root].r<=y){
        ax=max(ax,tree[root].ma);
        ai=min(ai,tree[root].mi);
    }
    else{
        int mid=(tree[root].l+tree[root].r)>>1;
        if(mid>=x)query(root<<1,x,y);
        if(mid<y)query(root<<1|1,x,y);
    }
}
int main(){
    #ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    #endif
    int N,Q;
    scanf("%d%d",&N,&Q);
    build(1,1,N);
    while(Q--){
        int x,y;
        ax=-INF;ai=INF;
        scanf("%d%d",&x,&y);
        query(1,x,y);
        printf("%d\n",ax-ai);
    }
    return 0;
}
