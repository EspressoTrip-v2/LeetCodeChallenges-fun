#include <iostream>

using namespace std;

/*
   Given the root of a binary tree, return its maximum depth.
   A binary tree's maximum depth is the number of nodes along
   the longest path from the root node down to the farthest leaf node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void DFSPreOrder(TreeNode *root) {
    cout << root->val << endl;
    if (root->left) {
        DFSPreOrder(root->left);
    }
    if (root->right) {
        DFSPreOrder(root->right);
    }
}

void DFSPostOrder(TreeNode *root) {
    if (root->left) {
        DFSPostOrder(root->left);
    }
    if (root->right) {
        DFSPostOrder(root->right);
    }
    cout << root->val << endl;
}

void DFSInOrder(TreeNode *root) {
    if (root->left) {
        DFSInOrder(root->left);
    }
    cout << root->val << endl;
    if (root->right) {
        DFSInOrder(root->right);
    }
}

int main() {
    // Node A
    auto *three = new TreeNode(3);
    auto *nine = new TreeNode(9);
    auto *twenty = new TreeNode(20);
    auto *fifteen = new TreeNode(15);
    auto *seven = new TreeNode(7);
    three->left = nine;
    three->right = twenty;
    twenty->left = fifteen;
    twenty->right = seven;
    // Node B
    auto *one = new TreeNode(1);
    auto *two = new TreeNode(2);
    one->right = two;

    cout << "PreOrder" << endl;
    DFSPreOrder(three);
    cout << endl;
    cout << "PostOrder" << endl;
    DFSPostOrder(three);
    cout << endl;
    cout << "InOrder" << endl;
    DFSInOrder(three);

    return 0;
}