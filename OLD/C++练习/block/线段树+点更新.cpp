#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 +10;
int a[maxn];
int index[maxn];
struct node{
    int l, r;
    int min, val;
}T[maxn<<2];
void build(int id, int l, int r){
    T[id].l = l;
    T[id].r = r;
    if(l == r){
        T[id].min = T[id].val = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(id<<1, l , m);
    build(id<<1 | 1, m + 1, r);
    T[id].min = min(T[id<<1].min,T[id<< 1 | 1].min);
}
int query(int id, int l, int r){
    if(T[id].l == l && T[id].r == r){
        return T[id].min;
    }
    int m = (T[id].l + T[id].r)>>1;
    if(m >= r) return query(id<<1, l, r);
    if(m < l) return query(id<<1 | 1, l ,r);
    return min(query(id<<1,l, m), query(id<<1 | 1,m+1,r));
}

void update(int id, int l, int r, int val){
    if(T[id].l == l && T[id].r == r){
        T[id].min = T[id].val = val;
        return ;
    }
    int m = (T[id].l + T[id].r)>>1;
    if(m >= r)update(id <<1 , l, r, val);
    if(m < l)update(id<<1 | 1,l, r, val);
    T[id].min = min(T[id<<1].min,T[id<<1 | 1].min);
}
int main(){
    int n, q, l, r;
    char str[100];
    scanf("%d%d", &n,&q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    for(int i = 0; i < q; i ++){
        scanf("%s",str);
        if(str[0] == 'q'){
            sscanf(str + 5, "(%d,%d)",&l,&r);
            printf("%d\n",query(1,l,r));
        }
        else{
            int k, l = 0,t = 0;
            for(k = 0; str[k];k++)
                if(str[k] == '(')break;
            for(int j = k + 1; str[j]; j++){
                while(str[j]!=',' && str[j] !=')'){
                    t = t* 10+str[j] - '0';
                    j++;
                }
                index[l++] = t;
                t = 0;
            }
            t = a[index[0]];
            for(int k = 0; k < l;k++){
                if(k == 0)update(1,index[l -1],index
                                 [l-1], a[index[0]]);
                else{
                    update(1, index[k - 1], index[k -1], a[index[k]]);
                }
            }
            for(int k = 0; k < l - 1; k ++){
                a[index[k]] = a[index[k+1]];
            }
            a[index[l -1]] = t;
        }
    }
}





