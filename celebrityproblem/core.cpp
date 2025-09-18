#include<iostream>
#include<vector>
using namespace std;

int celebrityP(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int>knowMe(n),iKnow(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                knowMe[j]++;
                iKnow[i]++;
            }
        }

    }

    for(int i=0;i<n;i++){
        if(knowMe[i]==n-1 &&iKnow[i]==0){
            return i;
        }
    }
    return -1;


}


int main(){
    vector<vector<int>>mat={{1,1,0},{0,1,0},{0,1,1}};

    int ans=celebrityP(mat);

    cout<<ans;


}