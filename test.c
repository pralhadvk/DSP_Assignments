#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
    int x,res;
    scanf("%d",&x);
    x%2==0 ? res = (x/2): res = (x/2)+1;
    printf("%d\n",x/2);
}