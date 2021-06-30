#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

/*
    Given the root of a complete binary tree, return the number of the nodes in the tree.
    According to Wikipedia, every level, except possibly the last, is completely filled
    in a complete binary tree, and all nodes in the last level are as far left as possible.
    It can have between 1 and 2h nodes inclusive at the last level h.
    Design an algorithm that runs in less than O(n) time complexity.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int BFSLevels(TreeNode *root, int levels) {
    queue<TreeNode *> TQ;
    TQ.push(root);
    int existCount{static_cast<int>(pow(2, levels - 1) - 1)}, currentCount{1}, pLevel{1}, newNodes{};
    while (!TQ.empty()) {
        auto *current = TQ.front();
        if (current->left) {
            if (currentCount != existCount) {
                TQ.push(current->left);
                currentCount++;
            } else { newNodes++; }
        } else { pLevel--; }
        if (current->right) {
            if (currentCount != existCount) {
                TQ.push(current->right);
                currentCount++;
            } else { newNodes++; }
        } else { pLevel--; }
        TQ.pop();
    }
    return newNodes;
}


int countNodes(TreeNode *root) {
    if (!root) return 0;
    int levels{1};
    auto *current = root;
    while (current->left) {
        levels++;
        current = current->left;
    }
    int count = static_cast<int>(pow(2, levels - 1) - 1);
    return levels > 1 ? BFSLevels(root, levels) + count : 1;
}
int main() {
    auto *root = new TreeNode(1);
    auto *n2 = new TreeNode(2);
    auto *n3 = new TreeNode(3);
    auto *n4 = new TreeNode(4);
    auto *n5 = new TreeNode(5);
    auto *n6 = new TreeNode(6);
    root->left = n2;
    root->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    cout << "Number of nodes int tree: " << countNodes(root) << endl;

    auto *rootB = new TreeNode(1);
    cout << "Number of nodes int tree: " << countNodes(rootB) << endl;

    return 0;
}
