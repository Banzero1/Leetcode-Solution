class Solution
{
public:
    bool kahnAlgo(vector<vector<int>> &adj, int n, vector<int> &indegree, vector<int> &ans)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            // will push all the nodes with the indegree 0 in the queue as we have completed all the prerequisites for it.
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty())
        {
            // one by one we will take every element of the queue and will traverse the adjacency list of it 
            // and will remove that node and will reduce the indegree of the adjacent nodes which are
            // prerequisites for it.
            int curr = q.front();
            q.pop();

            for (auto a : adj[curr])
            {
                indegree[a] -= 1;
                // and will push the node having 0 indegree in the queue.
                if (indegree[a] == 0)
                    q.push(a);
            }
            // and after processing current node, will push it in the ans.
            ans.push_back(curr);
            count++;
        }

        // checking for DAG.
        if (count != n)
            return false;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses); // Adjacency matrix.
        vector<int> indegree(numCourses, 0); // indegree array.

        // traversing all the nodes of the graph.
        for (int i = 0; i < n; i++)
        {
            // filling adjacency matrix for all the nodes of the graph.
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            // also filling indegree value for all nodes.
            indegree[prerequisites[i][0]] += 1;
        }

        vector<int> ans;

        // if graph is DAG and Kahn's algo is applied then return the ans.
        if (kahnAlgo(adj, numCourses, indegree, ans))
            return ans;

        // otherwise return the empty vector.
        return {};
    }
};