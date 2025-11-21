 //QUES 1 -> BFS 
 
/*#include <iostream>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[50][50];   // static adjacency matrix
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j] = 0;

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";
    for(int i=0;i<E;i++) {
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    bool visited[50] = {false};
    int q[50];
    int front=0, rear=0;

    visited[start] = true;
    q[rear++] = start;

    cout << "BFS Traversal: ";
    while(front < rear) {
        int node = q[front++];
        cout << node << " ";
        for(int i=0;i<V;i++) {
            if(adj[node][i] && !visited[i]) {
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
    cout << endl;
    return 0;
}*/


// QUES 2 ->

/*#include <iostream>
using namespace std;

void DFSUtil(int node, int V, int adj[50][50], bool visited[50]) {
    visited[node] = true;
    cout << node << " ";
    for(int i=0;i<V;i++) {
        if(adj[node][i] && !visited[i]) {
            DFSUtil(i, V, adj, visited);
        }
    }
}

int main() {
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[50][50];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j] = 0;

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v):\n";
    for(int i=0;i<E;i++) {
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cout << "Enter starting node for DFS: ";
    cin >> start;

    bool visited[50] = {false};
    cout << "DFS Traversal: ";
    DFSUtil(start, V, adj, visited);
    cout << endl;
    return 0;
}*/


// QUES 3 -> MST 

/*#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u,v,w;
};

int find(int parent[], int i) {
    if(parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

int main() {
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];
    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges, edges+E, [](Edge a, Edge b){ return a.w < b.w; });

    int parent[50];
    for(int i=0;i<V;i++) parent[i] = i;

    cout << "Kruskal MST edges:\n";
    for(int i=0;i<E;i++) {
        int pu = find(parent, edges[i].u);
        int pv = find(parent, edges[i].v);
        if(pu != pv) {
            cout << edges[i].u << " - " << edges[i].v << " (weight " << edges[i].w << ")\n";
            parent[pu] = pv;
        }
    }
    return 0;
}*/


//QUES 3 -> PRISM MST

/*#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[50][50];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j] = INF;

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[50], parent[50];
    bool inMST[50];
    for(int i=0;i<V;i++) {
        key[i] = INF;
        inMST[i] = false;
    }
    key[0] = 0; parent[0] = -1;

    for(int count=0; count<V-1; count++) {
        int u=-1;
        for(int i=0;i<V;i++)
            if(!inMST[i] && (u==-1 || key[i]<key[u]))
                u=i;
        inMST[u] = true;

        for(int v=0; v<V; v++) {
            if(adj[u][v] != INF && !inMST[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    cout << "Prim MST edges:\n";
    for(int i=1;i<V;i++)
        cout << parent[i] << " - " << i << " (weight " << adj[i][parent[i]] << ")\n";

    return 0;
}*/


//QUES 4 -> SHORTEST PATH

/*#include <iostream>
using namespace std;

#define INF 9999

int main() {
    int V,E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[50][50];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            adj[i][j] = INF;

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v w):\n";
    for(int i=0;i<E;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int start;
    cout << "Enter starting node for Dijkstra: ";
    cin >> start;

    int dist[50], visited[50];
    for(int i=0;i<V;i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for(int count=0; count<V-1; count++) {
        int u=-1;
        for(int i=0;i<V;i++)
            if(!visited[i] && (u==-1 || dist[i]<dist[u]))
                u=i;
        visited[u] = 1;

        for(int v=0; v<V; v++) {
            if(adj[u][v] != INF && dist[u]+adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "Dijkstra shortest paths from " << start << ":\n";
    for(int i=0;i<V;i++)
        cout << "Node " << i << " : " << dist[i] << endl;

    return 0;
}*/
