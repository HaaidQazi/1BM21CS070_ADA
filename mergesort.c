#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int arr[],int l,int r,int m)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int left[n1], right[n2];
    for(i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    int mid;
    if(l<r)
    {
        mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,r,mid);
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void main()
{
    int arr[2000],n,i;
    clock_t st,et;
    double ts;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    // printf("enter the elements of the array\n");
    // for(i=0;i<n;i++)
    // {
    //     scanf("%d",&arr[i]);
    // }
    printf("Providing random numbers");
    for(i=0;i<n;i++)
    {
        arr[i] = rand();
    }
    // printf("before sorting \n");
    st = clock();
    print(arr,n);
    mergesort(arr,0,n-1);
    et = clock();
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    printf("\nafter sorting using mergesort\n");
    print(arr,n);
    printf("\n");
    printf("the time taken is %f",ts);


}
