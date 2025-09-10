#include<iostream>
#include<vector>
using namespace std;

int kadaneAlgo(vector<int>&nums){
    int n=nums.size();
    int sum=0;
    int maxSum=-1e9;
    for(int i=0;i<n;i++){
    sum+=nums[i];
    if(sum<0) sum=0;
    maxSum=max(maxSum,sum);


    

    }
    return maxSum;
}

int main(){
    vector<int>nums= {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans=kadaneAlgo(nums);
    cout<<"The maximum sub-array sum is:"<<" "<<ans;
    return 0;
}