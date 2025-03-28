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

vector<int> max_sub_array(vector<int> &v)
{

     int max_sum = v[0];
     int start_idx = 0;
     int inter_idx = 0;
     int max_sub_array = v[0];
     int end_idx = 0;
     vector<int> res;

     for(int idx = 1;idx < v.size();idx++ )
     {
            if( max_sub_array + v[idx] > v[idx] )
	    {
                 max_sub_array = max_sub_array + v[idx];
	    }else  {
                 max_sub_array = v[idx];
		 inter_idx = idx;
	    }

	    if( max_sub_array > max_sum )
	    {
                 max_sum = max_sub_array;
		 start_idx = inter_idx;
                 end_idx = idx;
	    }
     }

     for(int idx = start_idx ; idx <= end_idx ;idx++){
        res.push_back(v[idx]);
     }

     return res;
}

int main()
{
   vector<int> v = { 2, 4, 5,10 , -2 -4 ,-20 ,1 , 0 };

   cout << "Max subarray"<<endl;
   vector<int> res = max_sub_array(v);

   for(int idx = 0 ; idx < res.size();idx++)
       cout<<v[idx]<<"   ";

   cout <<endl;
   cout << max_sum(v) << endl;

   return 0;

}
