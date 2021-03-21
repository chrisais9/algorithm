#include <stdio.h>
 int main()
 {
     int data[6]={0,},j,t,i,mi,mx=0;

     for(i=1;i<=5;i++)
     {
         for(j=0;j<4;j++)
         {
             scanf("%d",&t);
             data[i]+=t;

         }
         if(mx<data[i])
         {
             mi=i;
             mx=data[i];
         }
     }
     printf("%d %d",mi,mx);
 }
