#include<bits/stdc++.h>

using namespace std;


class DirectedGraph
{
    typedef vector< vector < pair<int, long long> > > AdjList;

    int V;    // Number of vertices
  
    AdjList adjList;
public:
    DirectedGraph(int V);

    void addEdge(int u, int v, long long w);

    // Finds the shortest path from source to destination
    long long shortestPathDijkstra(int source, int destination, vector<int>& path);
};

DirectedGraph::DirectedGraph(int n) : adjList(n), V(n)
{
}
 
void DirectedGraph::addEdge(int u, int v, long long w)
{
    adjList[u].emplace_back(v, w);
}
  
long long DirectedGraph::shortestPathDijkstra(int source, int destination, vector<int>& path)
{
    vector< int > parent(V, -1);
    vector< long long > minCost(V, LLONG_MAX);
    set< pair<long long, int> > pq;

    minCost[source] = 0LL;
    pq.insert( make_pair(0LL, source) );

    while(!pq.empty())
    {
        set< pair<long long, int> >::iterator it = pq.begin();
        int u = it->second;
        pq.erase(it);

        if(u == destination)
            break;

        for(int i=0; i < adjList[u].size(); ++i)
        {
            int v = adjList[u][i].first;
            long long w = adjList[u][i].second;
            if(minCost[v] > minCost[u] + w)
            {
                pq.erase( make_pair(minCost[v], v) );
                minCost[v] = minCost[u] + w;
                pq.insert( make_pair(minCost[v], v) );
                parent[v] = u;
            }
        }
    }

    int tmp = destination;
    while(tmp != -1)
    {
        path.push_back(tmp);
        tmp = parent[tmp];
    }
    reverse(path.begin(), path.end());

    return minCost[destination];
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    DirectedGraph g(5);
    g.addEdge(0, 1, 3LL);
    g.addEdge(1, 3, 6LL);
    g.addEdge(3, 4, 2LL);
    g.addEdge(1, 2, 4LL);
    g.addEdge(2, 3, 1LL);

    vector<int> path;
    long long cost = g.shortestPathDijkstra(0, 4, path);
    cout << "Shortest path from vertex 0 to vertex 4 costs " << cost << " and follows the vertices:" << endl;
    for(int i = 0; i < path.size(); ++i)
    {
        cout << path[i] << endl;
    }

    return 0;
}
