#include<iostream>
#include<vector>
using namespace std;





vector<int> bellmanFord(vector<vector<int>>&edges,int src,int V){
    vector<int>distance(V,1e8);
    distance[src]=0;

    for(int i=0;i<V-1;i++){
       for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        if(distance[u]!=1e8 &&distance[u]+w<distance[v]){
            distance[v]=distance[u]+w;
        }
       } 

    }

    // last check for negative cycle
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int w=it[2];

        if(distance[u]!=1e8 &&distance[u]+w<distance[v]){
            return {-1};
            }
       } 



       return distance;
    }





int main(){
    
    vector<vector<int>>edges={
        {3,2,6},
        {5,3,1},
        {0,1,5},
        {1,5,-3},
        {1,2,-2},
        {3,4,-2},
        {2,4,3}
    };

    // soruce node

    int src=0;

    // no of vertices / nodes
    int V=5;

    vector<int>ans=bellmanFord(edges,src,V);

    if(ans[0]==-1) cout<<"not possible there is negative cycle ";
    else{
        for(auto it:ans){
            cout<<" "<<it;
        }
    }
    return 0;

}