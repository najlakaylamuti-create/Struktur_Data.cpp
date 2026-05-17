#include <iostream>
using namespace std;

// Define the structure of each node in the binary tree
struct TreeNode {
    int val;          // Value stored in the node
    TreeNode* left;   // Pointer to left child
    TreeNode* right;  // Pointer to right child

    // Constructor: initialize node with value x, and set children to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum depth of the binary tree
// Uses recursion: depth = 1 + max(left depth, right depth)
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0; // Base case: empty node has depth 0

    int leftDepth  = maxDepth(root->left);  // Recursively get left subtree depth
    int rightDepth = maxDepth(root->right); // Recursively get right subtree depth

    return 1 + max(leftDepth, rightDepth); // Return the deeper side + 1 (current node)
}

// Helper function: print the tree structure visually in the console
void printTree(TreeNode* root, string prefix = "", bool isLeft = true) {
    if (root == nullptr) return; // Stop if node is empty

    cout << prefix;
    cout << (isLeft ? "|-- " : "\\-- "); // Show branch direction
    cout << root->val << endl;

    // Recursively print left and right children with updated prefix
    printTree(root->left,  prefix + (isLeft ? "|   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

int main() {
    cout << "=== Maximum Depth of Binary Tree ===" << endl;
    cout << endl;

    // Test case: root = [3, 9, 20, null, null, 15, 7]
    // Tree structure:
    //        3
    //       / \
    //      9  20
    //         / \
    //        15   7
    TreeNode* root = new TreeNode(3);
    root->left          = new TreeNode(9);
    root->right         = new TreeNode(20);
    root->right->left   = new TreeNode(15);
    root->right->right  = new TreeNode(7);

    // Display the tree visually
    cout << "Tree structure:" << endl;
    printTree(root, "", false);
    cout << endl;

    // Calculate and display the maximum depth
    cout << "maxDepth = " << maxDepth(root) << endl;

    return 0;
}