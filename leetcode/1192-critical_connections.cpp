
// tag
// tag graphs
// tag bridges

// diff:
// hard

// url:
// https://leetcode.com/problems/critical-connections-in-a-network/description/

#include <iostream>
#include <vector>
using std::cout, std::endl, std::vector, std::string;

class Solution {
  private:
	int timer;

  public:
	void dfs(int node, int parent, vector<int> &visited,
	         vector<vector<int>> &adj, vector<int> &time_in, vector<int> &low,
	         vector<vector<int>> &bridges)
	{
		if (!visited[node])
		{
			visited[node] = 1;
			time_in[node] = low[node] = timer++;

			for (auto neigh : adj[node])
			{
				if (neigh == parent)
					continue;
				if (!visited[neigh])
				{
					dfs(neigh, node, visited, adj, time_in, low, bridges);

					low[node] = std::min(low[node], low[neigh]);

					if (low[neigh] > time_in[node])
						bridges.push_back({node, neigh});
				}
				else
				{
					low[node] = std::min(low[node], time_in[neigh]);
				}
			}
		}
	}

	vector<vector<int>> criticalConnections(int n,
	                                        vector<vector<int>> &connections)
	{
		vector<vector<int>> adj(n);
		for (auto conn : connections)
		{
			adj[conn[0]].push_back(conn[1]);
			adj[conn[1]].push_back(conn[0]);
		}

		vector<int> time_in(n), low(n);
		vector<int> visited(n, 0);
		vector<vector<int>> bridges;

		dfs(0, -1, visited, adj, time_in, low, bridges);

		return bridges;
	}
};

int main()
{
	Solution soln;
	return 0;
}
