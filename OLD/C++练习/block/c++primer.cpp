#include <iostream>
#include "Sales_item.h"
using namespace std;
int main()
{
    int i,&ri = i;
    i = 5;ri = 10;
    cout<<i<<" " <<ri<<endl;
}
/*
0-201-78345-X 3 20.00
0-201-78345-X 2 25.00
0-201-78346-X 3 20.00
0-201-78346-X 2 25.00
0-201-78346-X 4 20.00
0-201-78346-X 2 25.00
*/
