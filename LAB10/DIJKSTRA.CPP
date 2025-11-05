DJIKSTRA'S ALGORITHM 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct MinHeapNode
{
    int v;    
    int dist; 
};

class MinHeap 
{
public:
    int size;      
    int capacity;  
    vector<int> pos;
    vector<MinHeapNode> heap;

    MinHeap(int capacity);
    void build_heap();
    MinHeapNode extract_min();
    void decrease_key(int v, int dist);
    void min_heapify(int idx);
    bool is_empty();
};

MinHeap::MinHeap(int capacity)
{
    size = 0;
    this->capacity = capacity;
    pos.resize(capacity);
    heap.resize(capacity);
}

bool MinHeap::is_empty() 
{
    return size == 0;
}

void MinHeap::build_heap()
{
    int n = size;
    for (int i = (n - 1) / 2; i >= 0; --i) 
    {
        min_heapify(i);
    }
}

void MinHeap::min_heapify(int idx) 
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != idx) 
    {
        MinHeapNode smallestNode = heap[smallest];
        MinHeapNode idxNode = heap[idx];
        pos[smallestNode.v] = idx;
        pos[idxNode.v] = smallest;
        swap(heap[smallest], heap[idx]);
        min_heapify(smallest);
    }
}

MinHeapNode MinHeap::extract_min() 
{
    if (is_empty())
        return {-1, INT_MAX};

    MinHeapNode root = heap[0];
    MinHeapNode last = heap[size - 1];
    heap[0] = last;
    pos[root.v] = size - 1;
    pos[last.v] = 0;
    size--;
    min_heapify(0);
    return root;
}

void MinHeap::decrease_key(int v, int dist)
{
    int i = pos[v];
    heap[i].dist = dist;

    while (i && heap[i].dist < heap[(i - 1) / 2].dist) 
    {
        pos[heap[i].v] = (i - 1) / 2;
        pos[heap[(i - 1) / 2].v] = i;
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void dijkstra(vector<vector<int>>& graph, int src) 
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    MinHeap minHeap(V);
    minHeap.size = V;
    for (int v = 0; v < V; ++v) 
    {
        dist[v] = INT_MAX;
        minHeap.heap[v] = {v, dist[v]};
        minHeap.pos[v] = v;
    }

    dist[src] = 0;
    minHeap.decrease_key(src, 0);
    while (!minHeap.is_empty())
    {
        MinHeapNode minNode = minHeap.extract_min();
        int u = minNode.v;

        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] && minHeap.pos[v] < minHeap.size && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                {
                dist[v] = dist[u] + graph[u][v];
                minHeap.decrease_key(v, dist[v]);
                }
        }
    }
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t " << dist[i] << "\n";
}

int main() 
{
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    int src = 0;
    dijkstra(graph, src);
    return 0;
}
