#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
    Given the root of a binary tree, return the level order traversal of its nodes' values.
    (i.e., from left to right, level by level).
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> result;
    vector<int> v;
    queue<TreeNode *> tQue;
    tQue.push(root);
    result.push_back({root->val});
    int level{2};
    while (!tQue.empty()) {
        auto current = tQue.front();
        if (current->left) {
            v.push_back(current->left->val);
            tQue.push(current->left);
        } else { level--; }
        if (current->right) {
            v.push_back(current->right->val);
            tQue.push(current->right);
        } else { level--; }
        if (!v.empty() && v.size() == level) {
            result.push_back(v);
            v.clear();
            level *= 2;
        }
        tQue.pop();
    }
    return result;
}
void print(vector<vector<int>> &v) {
    cout << "[ ";
    for (auto &i: v) {
        cout << "[ ";
        for (auto &j: i) {
            cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
}

int main() {
    // Node Test A
    auto *root = new TreeNode(3);
    auto *nine = new TreeNode(9);
    auto *twenty = new TreeNode(20);
    auto *fifteen = new TreeNode(15);
    auto *seven = new TreeNode(7);
    root->left = nine;
    root->right = twenty;
    twenty->left = fifteen;
    twenty->right = seven;
    // Node Test B
    auto *rootB = new TreeNode(1);
    auto *two = new TreeNode(2);
    auto *three = new TreeNode(3);
    auto *four = new TreeNode(4);
    auto *five = new TreeNode(5);
    rootB->left = two;
    rootB->right = three;
    two->left = four;
    three->right = five;
    auto v1 = levelOrder(root);
    print(v1);
    cout << endl;
    auto v2 = levelOrder(rootB);
    print(v2);
    return 0;
}