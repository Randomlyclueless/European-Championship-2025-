#include <iostream>

using namespace std;

const int MAX_NODES = 200001; 
const int MAX_EDGES = 200001; 
const int INF = 1e9;          

int head[MAX_NODES], to[MAX_EDGES * 2], next_edge[MAX_EDGES * 2]; 
int dist[MAX_NODES]; 
int queue[MAX_NODES];    
int front, rear;
int edge_count = 0;     


void addEdge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count++;
    
    to[edge_count] = u; 
    next_edge[edge_count] = head[v];
    head[v] = edge_count++;
}


int bfs(int start, int end, int n) {
    front = rear = 0; 
    queue[rear++] = start; 
    dist[start] = 0;   

    while (front < rear) {
        int node = queue[front++]; 

        for (int edge = head[node]; edge != -1; edge = next_edge[edge]) {
            int neighbor = to[edge];
            if (dist[neighbor] == INF) { 
                dist[neighbor] = dist[node] + 1;
                queue[rear++] = neighbor; 
            }
        }
    }

    return (dist[end] == INF) ? -1 : dist[end];  
}

int main() {
    int n, m;
    cin >> n >> m;

   
    for (int i = 1; i <= n; i++) {
        head[i] = -1; 
        dist[i] = INF; 
    }

    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    int shortestPath = bfs(1, n, n);  
    
    cout << shortestPath << endl;

    return 0;
}
