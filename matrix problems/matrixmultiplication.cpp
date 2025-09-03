#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();   
    int m = a[0].size();
    int p = b[0].size();    

    vector<vector<int>> c(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main() {
    vector<vector<int>> a = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> b = {
        {4, 5},
        {6, 7}
    };

    vector<vector<int>> ans = multiply(a, b);

    cout << "Result matrix:" << endl;
    for (auto &row : ans) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
