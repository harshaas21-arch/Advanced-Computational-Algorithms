#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
       int n, edges;
       // Number of vertices
       cout << "Enter number of vertices: ";
       cin >> n;
       // Vertex values
       vector<int> vertex(n);
       cout << "Enter the vertex values:\n";
       for (int i = 0; i < n; i++)
       {
              cin >> vertex[i];
       }
       // Adjacency matrix
       // 0 means there is no edge
       vector<vector<int>> graph(n, vector<int>(n, 0));
       // Number of edges
       cout << "Enter number of edges: ";
       cin >> edges;
       cout << "Enter the edges (u v weight):\n";
       for (int i = 0; i < edges; i++)
       {
              int u, v, weight;
              cin >> u >> v >> weight;
              int x = -1, y = -1;
              // Find indices of the vertices
              for (int j = 0; j < n; j++)
              {
                     if (vertex[j] == u)
                            x = j;
                     if (vertex[j] == v)
                            y = j;
              }
              if (x != -1 && y != -1)
              {
                     graph[x][y] = weight;
                     graph[y][x] = weight; // Undirected graph
              }
       }
       // Display adjacency matrix
       cout << "\nWeighted Adjacency Matrix:\n";
       for (int i = 0; i < n; i++)
       {
              for (int j = 0; j < n; j++)
              {
                     cout << graph[i][j] << " ";
              }
              cout << endl;
       }
       // Source and destination
       int source, destination;
       cout << "\nEnter source vertex: ";
       cin >> source;
       cout << "Enter destination vertex: ";
       cin >> destination;
       int sourceIndex = -1;
       int destinationIndex = -1;
       // Find indices
       for (int i = 0; i < n; i++)
       {
              if (vertex[i] == source)
                     sourceIndex = i;

              if (vertex[i] == destination)
                     destinationIndex = i;
       }
       if (sourceIndex == -1 || destinationIndex == -1)
       {
              cout << "Invalid vertex!";
              return 0;
       }
       // Distance array
       vector<int> distance(n, INT_MAX);
       // Visited array
       vector<bool> visited(n, false);
       // Previous vertex array to reconstruct path
       vector<int> parent(n, -1);
       distance[sourceIndex] = 0;
       // Dijkstra's algorithm
       for (int count = 0; count < n; count++)
       {
              // Find unvisited vertex with minimum distance
              int u = -1;
              int minDistance = INT_MAX;
              for (int i = 0; i < n; i++)
              {
                     if (!visited[i] && distance[i] < minDistance)
                     {
                            minDistance = distance[i];
                            u = i;
                     }
              }
              // No more reachable vertices
              if (u == -1)
                     break;
              visited[u] = true;
              // Update distances of adjacent vertices
              for (int v = 0; v < n; v++)
              {
                     if (graph[u][v] != 0 && !visited[v])
                     {
                            if (distance[u] + graph[u][v] < distance[v])
                            {
                                   distance[v] = distance[u] + graph[u][v];
                                   parent[v] = u;
                            }
                     }
              }
       }
       // Check if destination is reachable
       if (distance[destinationIndex] == INT_MAX)
       {
              cout << "\nNo path exists between "
                   << source << " and " << destination << endl;
              return 0;
       }
       // Display shortest distance
       cout << "\nShortest distance: "
            << distance[destinationIndex] << endl;
       // Construct shortest path
       vector<int> path;
       int current = destinationIndex;
       while (current != -1)
       {
              path.push_back(vertex[current]);
              current = parent[current];
       }
       reverse(path.begin(), path.end());
       // Display path
       cout << "Shortest Path: ";
       for (int i = 0; i < path.size(); i++)
       {
              cout << path[i];
              if (i != path.size() - 1)
                     cout << " -> ";
       }
       cout << endl;
       return 0;
}