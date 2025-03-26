#include <iostream>
#include <vector>

using namespace std;

int max_sum(vector <int>&v)
{
    int idx = 0;
    int max_sub_arr_sum = v[0];
    int res = v[0];
    
    for(idx = 1 ; idx < v.size(); idx++)
    {
        max_sub_arr_sum = max(max_sub_arr_sum + v[idx],v[idx]);
	res = max(res,max_sub_arr_sum);
    }

    return res;
}


int main()
{
   vector<int> v = { 2, 4, 5,10 , -2 -4 ,-20 ,1 , 0 };

   cout << "Max subarray"<<endl;
   cout << max_sum(v) << endl;

   return 0;

}
