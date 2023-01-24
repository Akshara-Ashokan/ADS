#include<stdio.h>
void main()
{
        int a[10],i,n,val,f=0,loc;
        printf("number of element to be entered:");
        scanf("%d",&n);
        printf("enter elements:");
        for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
        printf("enter value to be searched:");
        scanf("%d",&val);
        for(i=0;i<n;i++)
        {
        if(a[i]==val)
        {
        loc=i;
        f=1;
        break;
        }
        }
        if(f==0)
        {
        printf("item can not found");
        }
        else
        {
        printf("item found at location %d",loc);
        }
}

