#include <iostream>
#include <vector>
#include <climits>
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

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void getkthSmallest(Node* root, int &k, int &ans) {
    if (!root) return;

    getkthSmallest(root->left, k, ans);

    if (--k == 0) {
        ans = root->data;
        return;
    }

    getkthSmallest(root->right, k, ans);
}

int main() {
    Node* root = NULL;
    vector<int> values = {50, 30, 20, 40, 70, 60, 80};
    for (int val : values) {
        root = insert(root, val);
    }

    int k;
    cout << "Enter the value of K:" << endl;
    cin >> k;
    int ans = INT_MIN;

    getkthSmallest(root, k, ans);

    if (ans == INT_MIN)
        cout << "K is larger than number of nodes in the tree" << endl;
    else
        cout << "The value of kth smallest element is: " << ans << endl;

    return 0;
}
