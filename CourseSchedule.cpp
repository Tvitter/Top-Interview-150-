class Solution {
public:
    // Function to determine if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); // A graph where each node is a course
        vector<int> inDegree(numCourses); // Indegree array to keep track of prerequisites
      
        // Process prerequisites to build the graph and update indegrees
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];
            graph[prereq].push_back(course); // Add an edge from prereq to course
            ++inDegree[course]; // Increment indegree of the course
        }
      
        queue<int> noPrereqCourses; // Queue to store courses with no prerequisites
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                noPrereqCourses.push(i); // Enqueue if no prerequisites
            }
        }
      
        int finishedCount = 0; // Counter for finished courses
        while (!noPrereqCourses.empty()) {
            int current = noPrereqCourses.front();
            noPrereqCourses.pop();
            ++finishedCount; // Increment finished courses whenever one is completed
          
            // Reduce indegree for all neighbors, if it drops to 0, enqueue
            for (int neighbor : graph[current]) {
                if (--inDegree[neighbor] == 0) {
                    noPrereqCourses.push(neighbor);
                }
            }
        }
      
        // If we have not finished all courses, return false; otherwise, true
        return finishedCount == numCourses;
    }
};