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
    vector<vector<int>> levelOrder(TreeNode* root) {
      
      vector<vector<int>> levels;  // Stores the values of nodes at each level
        if (!root) return levels;   // If the tree is empty, return an empty vector

        // Initialize a queue to assist in BFS traversal
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {
            int levelSize = nodesQueue.size(); // Number of nodes at the current level
            vector<int> currentLevel;          // Vector to store values of node at current level
          
            while (levelSize > 0) {
                TreeNode* currentNode = nodesQueue.front(); // Take the front node in the queue
                nodesQueue.pop();                           // Remove that node from the queue

                // Add current node's value to current level vector
                currentLevel.push_back(currentNode->val);

                // If the current node has a left child, add it to the queue
                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }
                // If the current node has a right child, add it to the queue
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }

                levelSize--; // Decrement the counter for nodes remaining at current level
            }

            // After processing all nodes at the current level, add the current level vector to the results
            levels.push_back(currentLevel);
        }

        return levels; // Return the 2D vector with all the levels' values
    }
};