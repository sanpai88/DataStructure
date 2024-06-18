#include <stdio.h>

int partition(int arr[] , int low , int high)
{
 
   int pivot = arr[high];
   int j = low -1;
   int temp;
    
   for(int i = low ; i < high  ; i++)
   {
        if (arr[i] < pivot )
        {
            j++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;        
        }
   }
   
   temp = arr[j+1];
   arr[j+1] = arr[high];
   arr[high] = temp;

   return j+1;       

}


void quicksort(int arr[],int low , int high)
{
    if (low < high )
    {
          int pi = partition(arr,low,high) ;
          
          quicksort(arr,low,pi-1);
          quicksort(arr,pi+1,high);    
    }
}


int main()
{
    int arr[] = {6,1,8,10,2,3,0,-1,5,4,-2,-6,7,9,15};
    int len = sizeof(arr)/sizeof(int);
    quicksort(arr,0,len - 1);

    for(int i = 0 ; i < 7 ; i++)
        printf("%d \n",arr[i]);

    return 0;
}
