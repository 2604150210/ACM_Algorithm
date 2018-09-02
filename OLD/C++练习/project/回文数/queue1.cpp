#include "queue1.h"
cirqueue::cirqueue()  //构造函数
{
  front = rear = count = 0;
}

int cirqueue::queueempty()  //判断队满
{
  return count == 0;
}

int cirqueue::queuefull()  //队空
{
  return count == queuesize;
}

void cirqueue::enqueue(datatype x)  //入队
{
  if (queuefull()) {
    printf("queue is full\n");
    exit(1);
  }
  count++;
  data[rear] = x;
  rear = (rear + 1) % queuesize;  // rear 指针后移
}

datatype cirqueue::dequeue()  //出队
{  //若队列不空则删除队列头部元素并用e返回其值
  datatype temp;
  if (queueempty()) {
    printf("queue is full\n");
    exit(1);
  }
  temp = data[front];
  count--;
  // front指针后移
  front = (front + 1) % queuesize;
  return temp;
}

datatype cirqueue::queuefront()  //取队列的头元素
{
  if (queueempty()) {
    printf("queue is full\n");
    exit(1);
  }
        return data[front];
}

int cirqueue::queuelength()//求队列元素的个数
{return count;}