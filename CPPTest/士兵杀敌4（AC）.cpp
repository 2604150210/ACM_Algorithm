
#include <stdio.h>
//using namespace std;
const int M = 1000001;
struct SegTree
{
    int left,right,val;
} tree[ M << 2];

int a[M];
int t,m;
void build(int root, int left, int right)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].val = 0;
    if(left < right)
    {

    int mid = (left + right) >> 1;
    build(root << 1, left, mid);
    build(root << 1 | 1, mid+1, right);
    }
}
int query(int root,int index)
{
    if (tree[root].left == tree[root].right)
    {
        return tree[root].val;
    }
    int mid = (tree[root].left + tree[root].right) >> 1;
    if (index <= mid)
    {
        return tree[root].val+query(root << 1, index);
    }
    else return tree[root].val+query(root << 1 |1, index);
}
void add(int root, int left, int right, int val)
{
    if (left ==tree[root].left && tree[root].right == right)
    {
        tree[root].val += val;
        return;
    }
    int mid = (tree[root].left + tree[root].right) >> 1;
    if (right <= mid)
    {
        add(root << 1, left, right, val);
        return;
    }
    if (left > mid)
    {
        add(root << 1 | 1, left, right, val);
        return;
    }
    add(root << 1, left, mid, val);
    add(root << 1 | 1, mid+1, right, val);
}
char str[10];
int left,right,val,x;
int main()
{
    scanf("%d %d",&t,&m);
    build(1, 1, m);
    for(int i = 1; i <= t; i++)
    {
        scanf("%s",str);
        if(str[0] == 'Q')
        {
            scanf("%d",&x);
            printf("%d\n",query(1,x));
        }
        if(str[0] == 'A')
        {
            scanf("%d%d%d",&left,&right,&val);
            add(1,left,right,val);
        }
    }

}
