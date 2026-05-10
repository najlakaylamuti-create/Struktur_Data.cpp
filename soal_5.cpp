#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftDepth  = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// Helper: cetak tree secara visual (sederhana)
void printTree(TreeNode* root, string prefix = "", bool isLeft = true) {
    if (root == nullptr) return;
    cout << prefix;
    cout << (isLeft ? "|-- " : "\\-- ");
    cout << root->val << endl;
    printTree(root->left,  prefix + (isLeft ? "|   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

int main() {
    cout << "=== Maximum Depth of Binary Tree ===" << endl;
    cout << endl;

    // Test case 1: [3,9,20,null,null,15,7]  -> depth = 3
    TreeNode* root1 = new TreeNode(3);
    root1->left          = new TreeNode(9);
    root1->right         = new TreeNode(20);
    root1->right->left   = new TreeNode(15);
    root1->right->right  = new TreeNode(7);

    cout << "Test 1 - Tree:" << endl;
    printTree(root1, "", false);
    cout << "maxDepth = " << maxDepth(root1) << endl;
    cout << endl;

    // Test case 2: [1,null,2]  -> depth = 2
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);

    cout << "Test 2 - Tree:" << endl;
    printTree(root2, "", false);
    cout << "maxDepth = " << maxDepth(root2) << endl;

    return 0;
}