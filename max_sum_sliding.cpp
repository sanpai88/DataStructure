#include <iostream>
#include <vector>

using namespace std;


vector<int> subArrayContainingSum( int arr[],int num_ele , int max_sum)
{
   int low = 0 , high = 0;
   int sum = 0;
   vector<int> res;

   while( high < num_ele  )
   {
       while(high < num_ele && sum < max_sum)
           sum += arr[high++];
       
       if(high == num_ele && sum != max_sum)
       {
          cout<<"The sum could not be obtained"<<endl;
	  return res;
       }

       if( sum >= max_sum ){

	   if(sum == max_sum)
	       break;

           while(low < high && sum > max_sum)
              sum-=arr[low++];
       }
    }
    
    while(low < high)
    {
        res.push_back(arr[low]);
	low++;
    }

    return res;
}

/*
 * minimum size containing sum  
 */

int windowsizeContainingSum(int arr[],int num_ele,int max_sum)
{

   int low = 0 , high = 0;
   int windowsize = num_ele * num_ele;
   int sum = 0;
   while( high < num_ele  )
   {
       while(high < num_ele && sum != max_sum)
           sum += arr[high++];
       
       if(high == num_ele && sum <= max_sum)
           break;

       while(low < high && sum-arr[low] > max_sum)
           sum-=arr[low++];

       windowsize = min(windowsize, high -low );

       sum-=arr[low];
       low++;
    }

    if (windowsize  == num_ele * num_ele)
    {
       cout<<"Sum not found"<<endl;
       return -1;
    }

    return windowsize;
}


/*
 * find the maximum sum of all subarrays of size K
 */

int maxsum(int arr[],int num_ele , int win_size)
{
   int start = 0 ,end = 0;
   int max_sum = 0 , win_sum = 0;
   if(num_ele <= win_size)
   {
       cout<<"Array size is small"<<endl;
       return -1;
   }

   for(int idx = 0 ; idx < win_size ; idx++)
       win_sum = win_sum + arr[idx];

   max_sum = win_sum;

   for( int idx = win_size; idx < num_ele ; idx++  )
   {
       win_sum +=arr[idx] - arr[idx-win_size];
       max_sum = max(max_sum,win_sum);
   }

   return max_sum;
}

int main()
{

    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res;
    cout<<maxsum(arr,n,4)<<endl;
    cout<<windowsizeContainingSum(arr,n,50);
    cout <<endl;
    res = subArrayContainingSum(arr,n,15);
    
    for( auto iter : res )
       cout << iter << " ";
    return 0;
}
