#include <iostream>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int DFSmx(TreeNode *node, int count) {
    count++;
    int left{}, right{};
    if (node->left) {
        left = DFSmx(node->left, count);
    }
    if (node->right) {
        right = DFSmx(node->right, count);
    }
    if (!node->left && !node->right) {
        return count;
    }
    return std::max(left, right);
}


int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return DFSmx(root, 0);
}

int main() {
    // Node A
    auto *three = new TreeNode(3);
    auto *nine = new TreeNode(9);
    auto *twenty = new TreeNode(20);
    auto *fifteen = new TreeNode(15);
    auto *seven = new TreeNode(7);
    auto *eight = new TreeNode(8);
    auto *ten = new TreeNode(10);
    three->left = nine;
    three->right = twenty;
    twenty->left = fifteen;
    twenty->right = seven;
    seven->left = eight;
    eight->left = ten;

    auto r = maxDepth(three);
    cout << "Max depth: " << r << endl;
    return 0;
}
