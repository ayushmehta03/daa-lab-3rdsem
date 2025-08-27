#include <iostream>
#include<vector>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



Node *insert(Node*root,int val){
      if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


void inOrder(Node*root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<" "<<root->data;
    inOrder(root->right);
}

void preOrder(Node*root){
    if(root==NULL) return;
     cout<<" "<<root->data;

    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(Node*root){
    if(root==NULL) return;

    inOrder(root->left);
    inOrder(root->right);
         cout<<" "<<root->data;

}




int main(){
    Node*root=NULL;
    vector<int>values={50,30,20,40,70,60,80};
    for(int val:values){
        root=insert(root,val);
    }

    cout<<"Inorder Traversalof BST:";
    cout<<endl;
    inOrder(root);
    cout<<endl;
    
    cout<<"Pre order traversal:"<<endl;
    preOrder(root);
    cout<<endl;
    
    
    cout<<"PostOrder Traversal:"<<endl;
    postOrder(root);
    cout<<endl;

}