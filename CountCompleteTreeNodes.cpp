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
class Solution {
public:
    /**
     * Counts the number of nodes in a complete binary tree.
     *
     * @param root The root node of the binary tree.
     * @return The total number of nodes in the tree.
     */
    int countNodes(TreeNode* root) {
        if (!root) {
            // If the tree is empty, return a count of 0.
            return 0;
        }
      
        // Calculate the depth of the left and right subtrees.
        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);
      
        // If the depths are equal, it means the left subtree is complete and we can use the formula to calculate the number of nodes in a complete subtree, which is 2^height - 1, and add the number of nodes in the right subtree.
        if (leftDepth == rightDepth) {
            return (1 << leftDepth) + countNodes(root->right);
        }
      
        // If the depths are not equal, the right subtree must be complete, and we calculate the number of nodes in the left subtree. We then add the nodes in the right subtree (2^height - 1).
        return (1 << rightDepth) + countNodes(root->left);
    }

    /**
     * Calculates the depth of the tree (distance to the leaf) following the left child.
     *
     * @param node The node to measure the depth from.
     * @return The depth of the subtree.
     */
    int calculateDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            // Move to the left child and increment the depth count.
            node = node->left;
            ++depth;
        }
        return depth;
    }
};