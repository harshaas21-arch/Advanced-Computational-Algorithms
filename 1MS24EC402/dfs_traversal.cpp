#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
       int n, edges;
       cout << "Enter number of vertices: ";
       cin >> n;
       vector<int> vertex(n);
       cout << "Enter the vertex values:\n";
       for (int i = 0; i < n; i++)
       {
              cin >> vertex[i];
       }
       // Adjacency matrix initialized completely to 0
       vector<vector<int>> adj(n, vector<int>(n, 0));
       cout << "Enter number of edges: ";
       cin >> edges;
       cout << "Enter the edges (u v):\n";
       for (int i = 0; i < edges; i++)
       {
              int u, v;
              cin >> u >> v;
              int x = -1, y = -1;
              // Find positions of the vertices
              for (int j = 0; j < n; j++)
              {
                     if (vertex[j] == u)
                            x = j;
                     if (vertex[j] == v)
                            y = j;
              }
              if (x != -1 && y != -1)
              {
                     adj[x][y] = 1;
                     adj[y][x] = 1;
              }
       }
       cout << "\nAdjacency Matrix:\n";
       for (int i = 0; i < n; i++)
       {
              for (int j = 0; j < n; j++)
              {
                     cout << adj[i][j] << " ";
              }
              cout << endl;
       }
       int start;
       cout << "\nEnter starting vertex for DFS: ";
       cin >> start;
       int startIndex = -1;
       for (int i = 0; i < n; i++)
       {
              if (vertex[i] == start)
              {
                     startIndex = i;
                     break;
              }
       }
       if (startIndex == -1)
       {
              cout << "Starting vertex not found!";
              return 0;
       }
       vector<bool> visited(n, false);
       stack<int> s;
       s.push(startIndex);
       visited[startIndex] = true;
       cout << "\nDFS Traversal: ";
       while (!s.empty())
       {
              int current = s.top();
              s.pop();
              cout << vertex[current] << " ";
              // Visit adjacent vertices
              for (int i = n - 1; i >= 0; i--)
              {
                     if (adj[current][i] == 1 && !visited[i])
                     {
                            s.push(i);
                            visited[i] = true;
                     }
              }
       }
       cout << endl;
       return 0;
}