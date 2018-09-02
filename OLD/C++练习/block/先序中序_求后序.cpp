#include <iostream>
#include <malloc.h>
#include <cstring>
using namespace std;
typedef struct Node
{
    Node *lchild, *rchild;
    char value;
} Tree;

void ReBuild(char* PreOrder,char* InOrder, int TreeLen, Tree** root){
  Tree * p;
  char *LeftEnd;
  if(PreOrder == NULL || InOrder == NULL || root == NULL)//检查边界条件
  {
    return;
  }
  p = (Tree *)malloc(sizeof(Tree));//获得前序遍历的第一个结点
  p -> value = * PreOrder;
  p -> lchild = p -> rchild = NULL;
  *root = p;
  if(TreeLen == 1)return;//一个结点直接结束
  LeftEnd = InOrder;//LeftEnd得到先序遍历根结点的值
  while(*LeftEnd != *PreOrder)//在中序遍历中查找该点的位置
    LeftEnd++;
  int LeftLen = 0,RightLen=0;
  //寻找左子树长度
  LeftLen = (int)(LeftEnd - InOrder);
  //寻找右子树长度
  RightLen = TreeLen - LeftLen - 1;
  //重建左子树， 递归
  if(LeftLen>0)
    ReBuild(PreOrder+1,InOrder,LeftLen,&(p->lchild));
  //重建右子树，递归
  if(RightLen > 0)
    ReBuild(PreOrder+LeftLen+1,InOrder+LeftLen +1,RightLen,&(p->rchild));
}

void PostOrder(Tree *p){//二叉树建完后进行后序遍历
    if(p!=NULL){
      PostOrder(p->lchild);
      PostOrder(p->rchild);
      cout << p->value;
    }
}
int main(){
    char a[110],b[110];
    Tree *p;
    while(cin>>a>>b){
        int len = strlen(a);
        ReBuild(a, b, len, &p);
        PostOrder(p);
        cout << endl;
    }
}
