#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void BFSLevel(TreeNode *root, vector<int> &result) {
    queue<TreeNode *> tQ;
    vector<int> items;
    tQ.push(root);
    int level{2};
    while (!tQ.empty()) {
        auto *current = tQ.front();
        if (current->left) {
            tQ.push(current->left);
            items.push_back(current->left->val);
        } else { level--; }
        if (current->right) {
            tQ.push(current->right);
            items.push_back(current->right->val);
        } else { level--; }

        if (level == items.size() && level != 0) {
            result.push_back(items.back());
            items.clear();
            level *= 2;
        }
        tQ.pop();
    }
}

vector<int> rightSideView(TreeNode *root) {
    if (!root) return {};
    vector<int> result;
    result.push_back(root->val);
    BFSLevel(root, result);
    return result;
}

void print(vector<int> &v) {
    cout << "[ ";
    for (auto &i: v)
        cout << i << " ";
    cout << "]" << endl;
}
int main() {
    // Node A
    auto *root = new TreeNode(1);
    auto *two = new TreeNode(2);
    auto *three = new TreeNode(3);
    auto *four = new TreeNode(4);
    auto *five = new TreeNode(5);
    root->left = two;
    root->right = three;
    two->right = five;
    three->right = four;

    auto v = rightSideView(root);
    print(v);

    // Node B
    auto *rootB = new TreeNode(10);
    auto *n20 = new TreeNode(20);
    auto *n30 = new TreeNode(30);
    auto *n40 = new TreeNode(40);
    auto *n50 = new TreeNode(50);
    auto *n60 = new TreeNode(60);
    rootB->left = n20;
    rootB->right = n30;
    n20->left = n40;
    n20->right = n50;
    n50->left = n60;

    auto v2 = rightSideView(rootB);
    print(v2);
    return 0;
}
