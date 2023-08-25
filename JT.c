#include<stdio.h>
#define RIGHT_TO_LEFT 0
#define LEFT_TO_RIGHT 1
int searchArr(int a[],int n,int mobile)
{
    int i;
    for(i=0;i<n;i++)
    {

        if(a[i]==mobile)
            return i+1;
    }
    return -1;
}
int getMobile(int a[],int dir[],int n)
{

    int i,mobile_prev=0,mobile=0;
    for(i=0;i<n;i++)
    {

        if(dir[a[i]-1]==RIGHT_TO_LEFT && i!=0)
        {

            if(a[i]>a[i-1] && a[i]>mobile_prev)
            {
                mobile=a[i];
                mobile_prev=mobile;
            }
        }
        if(dir[a[i]-1]==LEFT_TO_RIGHT && i!=n-1)
        {

            if(a[i]>a[i+1] && a[i]>mobile_prev)
            {
                mobile=a[i];
                mobile_prev=mobile;
            }
        }
        
	}
        return mobile;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void printOnePerm(int a[],int dir[],int n)
{
    int i;
    int mobile=getMobile(a,dir,n);
    int pos=searchArr(a,n,mobile);
    if(dir[a[pos-1]-1]==RIGHT_TO_LEFT)
        swap(&a[pos-1],&a[pos-2]);
    else if(dir[a[pos-1]-1]==LEFT_TO_RIGHT)
        swap(&a[pos],&a[pos-1]);
    for(i=0;i<n;i++)
    {

        if(a[i]>mobile)
        {

            if(dir[a[i]-1]==LEFT_TO_RIGHT)
                dir[a[i]-1]=RIGHT_TO_LEFT;
            else if(dir[a[i]-1]==RIGHT_TO_LEFT)
                dir[a[i]-1]=LEFT_TO_RIGHT;
        }
    }
    for(i=0;i<n;i++)
    {

        printf("%d",a[i]);

    }
    printf(" ");
}
int fact(int n)
{

    int i, res=1;
    for(i=1;i<=n;i++)
        res*=i;
    return res;
}
void printPermutations(int n)
{
    int i, a[n];
    int dir[n];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
        printf("%d",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        dir[i]=RIGHT_TO_LEFT;
    }
    for(i=1;i<fact(n);i++)
    {
        printOnePerm(a,dir,n);
    }

}
int  main()
{
    int n;
    printf("Enter the number of digits\n");
    scanf("%d",&n);
    printf("Permutations of the seqeuence :");
    printPermutations(n);
	return 0;
}
