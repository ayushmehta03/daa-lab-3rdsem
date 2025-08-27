#include <iostream>
#include <vector>
#include <queue>
#include <chrono>   
using namespace std;
using namespace std::chrono;

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

vector<vector<int>> levelOrder(Node* root, vector<vector<int>>& sol) {
    if (root == NULL) return sol;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> temp;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);

            temp.push_back(curr->data);
        }

        sol.push_back(temp);
    }
    return sol;
}

int main() {
    Node* root = NULL;
    vector<int> values = {50, 30, 20, 40, 70, 60, 80};
    for (int val : values) {
        root = insert(root, val);
    }

    vector<vector<int>> sol;

    auto start = high_resolution_clock::now();

    levelOrder(root, sol);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    for (auto level : sol) {
        for (auto val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nExecution time: " << duration.count() << " microseconds" << endl;
}
