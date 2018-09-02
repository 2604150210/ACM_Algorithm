#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
const int M = 100001;
struct SegTree{
    int left,right,val;
}tree[4 * N];

int a[N];
int n,m;
void build(int root, int left, int right){
    tree[root].left = left;
    tree[root].right = right;
    if(left == right){
        tree[root].val = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(root << 1, left, mid);
    build(root << 1 | 1, mid+1, right);
    tree[root].val = tree[root<<1].val + tree[root<<1|1].val;
}
int query(int root, int left, int right){
    if(left <= tree[root].left && tree[root].right <= right){
        return tree[root].val;
    }
    int mid = (tree[root].left + tree[root].right) >> 1;
    if(right <= mid){
        return query(root << 1, left, right);
    }
    if(left > mid){
        return query(root << 1 |1, left, right);
    }
    return query(root << 1, left, mid) + query(root << 1 | 1, mid+1, right);
}
void add(int root, int index, int val){
    if(tree[root].left == tree[root].right){
        tree[root].val += val;
        return;
    }
    int mid = (tree[root].left + tree[root].right) >> 1;
    if(index <= mid){
        add(root << 1, index, val);
    }
    else{
        add(root <<1 |1, index, val);
    }
    tree[root].val = tree[root<<1].val + tree[root<<1|1].val;
}
int main(){
    while(~scanf("%d %d",&n,&m)){
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }
        build(1, 1, n);
        for(int i = 1; i <= m; i++){
            char str[10];
            int x,y;
            scanf("%s%d%d",str,&x,&y);
            if(strcmp(str,"QUERY") == 0){
                int sum = query(1,x,y);
                printf("%d\n",sum);
            }
            if(strcmp(str,"ADD") == 0){
                add(1,x,y);
            }
        }
    }
}
