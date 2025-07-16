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
    // Function to get the right side view of a binary tree.
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView; // Stores the right side view elements
        if (!root) {
            return rightView; // If the root is null, return an empty vector
        }

        queue<TreeNode*> nodesQueue; // Queue to perform level order traversal
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {
            // Add the rightmost element of current level to the right view
            rightView.emplace_back(nodesQueue.back()->val);

            // Traverse the current level
            for (int levelSize = nodesQueue.size(); levelSize > 0; --levelSize) {
                TreeNode* currentNode = nodesQueue.front();
                nodesQueue.pop();

                // If left child exists, add it to the queue for next level
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }

                // If right child exists, add it to the queue for next level
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }
        }

        return rightView; // Return the final right side view of the binary tree
    }
};