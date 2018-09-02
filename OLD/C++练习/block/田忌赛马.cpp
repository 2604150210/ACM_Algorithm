
/************************田忌赛马*****************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
/*
  1、
  当然要对马的速度进行一个排序，让田忌与齐王的马都从大到小进行排序（当然你也可以从小到大）

  2、 然后将齐王的马与田忌的进行比较，有以下几种情况：

        (1)田忌最快的马，比齐王最快的马还快，当然这种情况直接就用田忌最快的马来赢齐王的最快的马

        (2)田忌最快的马，比齐王最快的马慢，这种情况用田忌最慢的马去与齐王最快的马比赛，以达到最优解

        (3)田忌最快的马与齐王最快的马一样快

            此时，拿最慢的马进行比较：

            如果田忌最慢的马比齐王最慢的马速度快，那就直接赢了它。
  否则就用田忌最慢的马与齐王最快的马进行比较
*/
int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }
int main()  //田忌赛马
{
  int n;
  while (cin >> n && n) {
    int tian[1000], king[1000], num[1000];
    for (int i = 0; i < n; i++) cin >> tian[i];
    for (int i = 0; i < n; i++) cin >> king[i];
    qsort(tian, n, sizeof(tian[0]), cmp);
    qsort(king, n, sizeof(king[0]), cmp);
    int head, front, tail, rear, count(0);
    head = front = 0;
    tail = rear = n - 1;
    while (front <= rear) {
      if (tian[front] > king[head]) {
        num[front] = head;
        front++;
        head++;
      } else if (tian[front] < king[head]) {
        num[rear] = head;
        rear--;
        head++;
      } else if (tian[rear] > king[tail]) {
        num[rear] = tail;
        tail--;
        rear--;
      } else {
        num[rear] = head;
        rear--;
        head++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (tian[i] > king[num[i]])
        count++;
      else if (tian[i] < king[num[i]])
        count--;
    }
    cout << 200*count << endl;
  }
}
/*

*/