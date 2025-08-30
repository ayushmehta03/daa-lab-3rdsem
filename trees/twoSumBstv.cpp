#include<iostream>
#include<vector>
using namespace std;

struct Node
{
int data;
Node*left;
Node*right;

Node(int val){
    data=val;
    left=right=NULL;
}
};


Node*insert(Node*root,int val){
    if(!root) return new Node(val);
      if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// inorder traversal for sorted vector

void inOrder(Node*root,vector<int>&nums){
   if(!root) return;
    inOrder(root->left,nums);
    nums.push_back(root->data);
    inOrder(root->right,nums);

}

// classic two Sum approach
bool tSum(vector<int>&nums, int target){
    int low=0;
    int high=nums.size()-1;
    while(low<high){
     int sum=nums[low]+nums[high];
     if(sum==target) return true;
     else if(sum<target) low++;
     else high--;
    }
    return false;
}

// check point
bool findTarget(Node*root,int target){
    vector<int>nums;
    inOrder(root,nums);
    return tSum(nums,target);

}
 

int main(){
    int n;
    cout<<"Enter the no of nodes:"<<" ";
    cin>>n;
        vector<int>values(n);

    cout<<"Enter the values of nodes:"<<" ";
for (int i = 0; i < n; i++) cin >> values[i];

    Node*root=NULL;
    for(auto it:values) {
    root=insert(root,it);
    }

    int k;
    cout<<"Enter the target value:"<<" ";
    cin>>k;


    if(findTarget(root,k)){
        cout<<"Yes target is avilable ";
    }
    else{
        cout<<"No target found";
    }
    return 0;
}



