#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t ;
    printf("enter the number of test cases \n") ;
    scanf("%d",&t) ;
    while(t-->0)
    {
        int n ;
        printf("enter the number of elements \n") ;
        scanf("%d",&n) ;
        int arr[n] ;
        printf("enter the elements \n") ;
        for(int x=0;x<n;x++)
        {
            scanf("%d",&arr[x]) ;
        }
        int temp=0 ;
        for (int gap = n/2; gap > 0; gap /= 2) 
        { 
            for (int i = gap; i < n; i += 1) 
            { 
                if(arr[i-gap]>arr[i])
                {
                    temp=arr[i-gap] ;
                    arr[i-gap]=arr[i] ;
                    arr[i]=temp ;
                }
                    
            } 
        } 
        for(int x=0;x<n-2;x++)
        {
            printf("%d ",arr[x]) ;
        }
        printf("\n") ;
    }
    


}
