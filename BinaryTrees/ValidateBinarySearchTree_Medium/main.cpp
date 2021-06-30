#include <iostream>
#include <thread>

using namespace std;
/*
    A valid BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isTree(TreeNode *node, int rootVal) {
    if (!node->left && !node->right) return true;
    if (node->left) {
        if (node->left->val < node->val && node->val >= rootVal ||
            node->left->val < node->val && node->val <= rootVal) { return isTree(node->left, rootVal); }
        else { return false; }
    }
    if (node->right) {
        if (node->right->val > node->val && node->right->val < rootVal ||
            node->right->val > node->val && node->val > rootVal) { return isTree(node->right, rootVal); }
        else { return false; }
    }

    return true;
}

bool isValidBST(TreeNode *root) {
    if (root->right && root->right->val <= root->val) return false;
    if (root->left && root->left->val >= root->val) return false;
    return isTree(root, root->val);
}

int main() {
    cout << boolalpha << endl;

//    auto *n5 = new TreeNode(5);
//    auto *n1 = new TreeNode(1);
//    auto *n4 = new TreeNode(4);
//    auto *n3 = new TreeNode(3);
//    auto *n6 = new TreeNode(6);
//    n5->left = n1;
//    n5->right = n4;
//    n4->left = n3;
//    n4->right = n6;

    auto *n32 = new TreeNode(32);
    auto *n26 = new TreeNode(26);
    auto *n19 = new TreeNode(19);
    auto *n47 = new TreeNode(47);
    auto *n56 = new TreeNode(56);
    auto *n27 = new TreeNode(27);

    n32->left = n26;
    n32->right = n47;
    n26->left = n19;
    n19->right = n27;
    n47->right = n56;
    cout << "Is binary search tree: " << isValidBST(n32) << endl;


    auto *n1 = new TreeNode(1);
    auto *n3 = new TreeNode(3);
    auto *n5 = new TreeNode(5);
    auto *n4 = new TreeNode(4);
    auto *n6 = new TreeNode(6);
    auto *n0 = new TreeNode(0);
    auto *n2 = new TreeNode(2);
    n3->left = n1;
    n3->right = n5;
    n1->left = n0;
    n1->right = n2;
    n5->left = n4;
    n5->right = n6;
    cout << "Is binary search tree: " << isValidBST(n3) << endl;
    auto nA = new TreeNode(34);
    auto nB = new TreeNode(-6);
    auto nC = new TreeNode(-21);
    nA->left = nB;
    nB->left = nC;
    cout << "Is binary search tree: " << isValidBST(nA) << endl;

    return 0;
}
