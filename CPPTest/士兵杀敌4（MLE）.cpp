#include <bits/stdc++.h>
using namespace std;
const int T = 1000001;
const int M = 1000001;
struct SegTree{
    int left,right,val,add;
}tree[4 * M];

int a[M];
int t,m;

/*
上推
 */
void pushUp(int root) {
    tree[root].val = tree[root << 1].val + tree[root <<1|1].val;
}

/*
建树
 */
void build(int root, int left, int right) {
    tree[root].left = left;
    tree[root].right = right;
    if (left == right){
        tree[root].val = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(root << 1, left, mid);
    build(root << 1 | 1, mid + 1, right);
    pushUp(root);
}


/*
下推
 */
void pushDown(int root) {
    if (tree[root].add!= 0){
        tree[root << 1].add += tree[root].add;
        tree[root << 1 | 1].add += tree[root].add;
        tree[root<<1].val += tree[root<<1].add * (tree[root<<1].right - tree[root<<1].left + 1);
        tree[root<<1|1].val += tree[root<<1|1].add * (tree[root<<1|1].right - tree[root<<1|1].left + 1);
        tree[root].add = 0;
    }
}


/*
单点查询
 */
int query(int root,int index){
    if (tree[root].left == tree[root].right){
        return tree[root].val;
    }
    pushDown(root);
    int mid = (tree[root].left + tree[root].right) >> 1;
    if (index <= mid){
        return query(root << 1, index);
    }else return query(root << 1 |1, index);
}
/*
区间更新：【left, right】+ C
 */
void update(int root, int left, int right, int C){
    if (left <= tree[root].left && tree[root].right <= right){
        tree[root].val += C * (tree[root].right - tree[root].left + 1);
        tree[root].add += C;
        return;
    }
    pushDown(root);
    int mid = (tree[root].left + tree[root].right) >> 1;
    if (left <= mid){
        update(root <<1, left, right,C);
    }
    if (mid < right){
        update(root << 1 | 1, left, right, C);
    }
    pushUp(root);
}

int main(){
    while(~scanf("%d %d",&t,&m)){

        build(1, 1, m);
        for(int i = 1; i <= t; i++){
            char str[10];
            scanf("%s",str);
            if(strcmp(str,"QUERY") == 0){
                int x;
                scanf("%d",&x);
                int sum = query(1,x);
                printf("%d\n",sum);
            }
            if(strcmp(str,"ADD") == 0){
                int left,right,val;
                scanf("%d%d%d",&left,&right,&val);
                update(1,left,right,val);
            }
        }
    }
}
