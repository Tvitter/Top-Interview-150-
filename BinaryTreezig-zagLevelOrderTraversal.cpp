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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
             // The result will be stored in this vector of integer vectors.
        vector<vector<int>> result;
      
        // Base case: if the root is null, return an empty vector.
        if (!root) return result;
      
        // Queue to store tree nodes during level order traversal.
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root); // Initialize the queue with the root node.
      
        // Variable to keep track of the current zigzag direction.
        bool isLeftToRight = true;
      
        // While there are nodes to process in the queue...
        while (!nodesQueue.empty()) {
            // Temporary vector to store one level's nodes' values.
            vector<int> level;
          
            // For all nodes at the current level...
            for (int n = nodesQueue.size(); n > 0; --n) {
                // Retrieve the next node.
                TreeNode* node = nodesQueue.front(); 
                nodesQueue.pop();
              
                // Add the node's value to the current level vector.
                level.push_back(node->val);
              
                // Add the node's left child to the queue if it exists.
                if (node->left) nodesQueue.push(node->left);
              
                // Add the node's right child to the queue if it exists.
                if (node->right) nodesQueue.push(node->right);
            }
          
            // If the current direction is right to left, reverse the level vector.
            if (!isLeftToRight) {
                reverse(level.begin(), level.end());
            }
          
            // Append the current level to the result vector.
            result.push_back(level);
          
            // Toggle the direction for the next level.
            isLeftToRight = !isLeftToRight;
        }

        // Return the zigzag level order traversal.
        return result;
    }
};
    