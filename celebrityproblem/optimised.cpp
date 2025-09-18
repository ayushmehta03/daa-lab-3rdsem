#include<iostream>
#include<vector>
using namespace std;

int celebrityP(vector<vector<int>>&mat){
    int top=0;
    int down=mat.size()-1;
    while(top<down){
        if(mat[top][down]==1) top=top+1;
        else down=down-1;

    }


    int c=top;
    for(int i=0;i<mat.size();i++){
        if(i==c) continue;
        if(mat[c][i] || !mat[i][c]) return -1;
    }

    return c;


}


int main(){
    vector<vector<int>>mat={{1,1,0},{0,1,0},{0,1,1}};

    int ans=celebrityP(mat);

    cout<<ans;


}