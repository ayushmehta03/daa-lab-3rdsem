#include<iostream>
#include<vector>
#include<algorithm>


// 0/1 knapsack 
using namespace std;

int f(int idx,vector<int>&value,vector<int>&weight,int capacity){
    if(idx==0){
        if(weight[0]<=capacity){
          return value[0];
        }
        return 0;
    }

    int nPick=f(idx-1,value,weight,capacity);
    int pick=0;
    if(weight[idx]<=capacity){
        pick=value[idx]+f(idx-1,value,weight,capacity-weight[idx]);
    }

    return max(pick,nPick);

}

int main(){
    vector<int>weight={3,4,5,6};
    vector<int>value={20,30,10,40};
    int capacity=8;
    int n=weight.size();

    int ans=f(n-1,value,weight,capacity);
    cout<<ans;

}