#include<stdio.h>
void factnew(int);
int main(void)
{
    int num,fact;   
    scanf("%d",&num);
    while(num-- > 0)
    {
     scanf("%d",&fact);
      factnew(fact);
     }
return 0;
}
 
void factnew(int fact)
{
     int num,ans[1000],i,temp,x,index,zero;
     index=1;
     ans[0]=1;
     temp=0;
     x=0;
     num=1;
     zero=0;
     while(num<=fact)
     {
        for(i=0;i<index;i++)
        {
              x=ans[i]*num+temp;
              ans[i]=x%1000;
              temp=x/1000;              
        }
                   
        while(temp>0)
        {
		i=index;
        ans[i]=temp%1000;
        temp=temp/1000;
        index++;
        }
     num++;
    }
     for(i=index;i>0;i--)
     {
     if(ans[i-1]<100&&i!=index)
     {
     printf("%d",zero);
     if(ans[i-1]<10)
     printf("%d",zero);
     }
     printf("%d",ans[i-1]);
     }
     printf("\n");
}