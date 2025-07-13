/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <stack>

// Definition for a binary tree node.

class BSTIterator {
private:
    std::stack<TreeNode*> nodeStack; // Use std namespace and CamelCase for variables.

public:
    // Constructor initializes the iterator using the root of a binary search tree.
    BSTIterator(TreeNode* root) {
        // Go all the way to the left-most node, simulating an in-order traversal.
        while (root != nullptr) {
            nodeStack.push(root);
            root = root->left;
        }
    }

    // Returns the next smallest number in the BST.
    int next() {
        // The top element of the stack is the next smallest element.
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();
      
        // If there is a right subtree, push all the left-most nodes of that subtree to the stack.
        TreeNode* node = currentNode->right;
        while (node != nullptr) {
            nodeStack.push(node);
            node = node->left;
        }
      
        // Return the value of the next smallest element.
        return currentNode->val;
    }

    // Returns whether we have a next smallest number.
    bool hasNext() {
        // If the stack is not empty, there is a next element.
        return !nodeStack.empty();
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */