#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent edges in the graph
struct Edge {
    int from;
    int to;
    int weight;
};

// Function to find the MST using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<Edge> mst;
    vector<int> parent(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        parent[i] = i;
    }

    for (const Edge& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.weight;

        int parentU = parent[u];
        int parentV = parent[v];

        if (parentU != parentV) {
            mst.push_back(edge);
            for (int i = 0; i < numVertices; ++i) {
                if (parent[i] == parentV) {
                    parent[i] = parentU;
                }
            }
        }
    }

    return mst;
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<Edge> edges(numEdges);

    for (int i = 0; i < numEdges; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(edges, numVertices);

    long long minimumCost = 0;
    for (const Edge& edge : mst) {
        minimumCost += edge.weight;
    }

    cout << "Minimum Cost of MST: " << minimumCost << endl;

    return 0;
}
