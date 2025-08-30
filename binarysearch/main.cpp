// core binary search logic

#include<iostream>
#include<vector>
using namespace std;


int binarySearch(vector<int>&nums,int k){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){

        int mid=low+(high-low)/2;


        if(nums[mid]==k) return mid;

        else if(nums[mid]<k) low=mid+1;

        else high=mid-1;

    }

    // no target found
    return -1;


}


int main(){
    int n;
    cout<<"Enter the number of elements:"<<" ";
    cin>>n;


    vector<int>nums(n);

    cout<<"Enter the arr elements: "<<" ";

    for(int i=0;i<n;i++) cin>>nums[i];

    // for bs array/vector must be sorted
    sort(nums.begin(),nums.end());

    int k;
    cout<<"Enter the target element:"<<" ";
    cin>>k;

    int ans=binarySearch(nums,k);
    if(ans!=-1){
        cout<<"Target found at index:"<<" "<<ans;
    }
    else{
        cout<<"No target found in the vector";
    }
    return 0;


}