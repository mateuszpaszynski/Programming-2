#include <bits/stdc++.h>
#define MIN(x,y) (((x) < (y)) ? x : y)
int main()
{
    for ( int i = 0;i<100;i++)
    std::cout<<MIN(rand() % 10,5)<<" ";
}