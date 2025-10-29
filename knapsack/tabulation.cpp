#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int knapSack(vector<int>&weight,vector<int>&value,int capacity){

    // take the size of weight
    int n=weight.size();
    // create 2d vector for tabulation
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));


    // base condition 
    for(int i=weight[0];i<=capacity;i++){
        dp[0][i]=value[0];
    }

    // loop through items
    for(int i=1;i<n;i++){
     // loop through capacity
    for(int c=0;c<=capacity;c++){

    // two conditions either pick or notPick
    int nPick=dp[i-1][c];

    int pick=0;
    // pick only if capicity is equal or greater than the weight
    if(weight[i]<=c){
        pick= value[i]+ dp[i-1][c-weight[i]];
    }
    // take the max from both pick and notpick
         dp[i][c] = max(pick, nPick);


    }


    }

    return dp[n-1][capacity];





}

int main(){

    // given data weight value and the capacity
        vector<int>weight={3,4,9,6};
    vector<int>value={30,40,90,60};
    // capcity
    int capacity=8;

    // logging the answer
    int ans=knapSack(weight,value,capacity);

    cout<<ans;




}