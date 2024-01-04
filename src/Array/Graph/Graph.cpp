//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include "Graph.h"
#include "../DisjointSet.h"
#include "../Queue.h"
#include "../Heap/Heap.h"
#include "../Heap/MinHeap.h"

namespace array{

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount){
        edges = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++){
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }

    void Graph::connectedComponentDisjointSet() {
        DisjointSet sets = DisjointSet(vertexCount);
        for (int fromNode = 0; fromNode < vertexCount; fromNode++){
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (edges[fromNode][toNode] > 0){
                    if (sets.findSetRecursive(fromNode) != sets.findSetRecursive(toNode)){
                        sets.unionOfSets(fromNode, toNode);
                    }
                }
            }
        }
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }
    }

    Path *Graph::bellmanFord(int source) {
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                for (int toNode = 0; toNode < vertexCount; toNode++){
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert( HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }

    int **Graph::floydWarshall() {
        int** distances;
        distances = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            distances[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; j++){
                distances[i][j] = edges[i][j];
            }
        }
        for (int k = 0; k < vertexCount; k++){
            for (int i = 0; i < vertexCount; i++){
                for (int j = 0; j < vertexCount; j++){
                    int newDistance = distances[i][k] + distances[k][j];
                    if (newDistance < distances[i][j]){
                        distances[i][j] = newDistance;
                    }
                }
            }
        }
        return distances;
    }

    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (paths[toNode].getDistance() > edges[fromNode][toNode]){
                    int position = heap.search(toNode);
                    heap.update(position, edges[fromNode][toNode]);
                    paths[toNode].setDistance(edges[fromNode][toNode]);
                    paths[toNode].setPrevious(fromNode);
                }
            }
        }
        void Graph::findShortestPath(std::vector<std::string>& words, const string& start, const string& target) {

            int start_index = -1, target_index = -1;
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == start) start_index = i;
                if (words[i] == target) target_index = i;
            }

            if (start_index == -1 || target_index == -1) {
                std::cout << "Start or target word not found." << std::endl;
                return;
            }


            std::vector<bool> visited(words.size(), false);
            std::vector<int> parent(words.size(), -1);
            std::queue<int> queue;

            visited[start_index] = true;
            queue.push(start_index);

            while (!queue.empty()) {
                int current = queue.front();
                queue.pop();

                if (current == target_index) break;


                for (int i = 0; i < words.size(); ++i) {
                    if (!visited[i] && edges[current][i] == 1) {
                        visited[i] = true;
                        parent[i] = current;
                        queue.push(i);
                    }
                }
            }


            if (!visited[target_index]) {
                std::cout << "No path exists between " << start << " and " << target << std::endl;
                return;
            }

            std::vector<int> path;
            for (int at = target_index; at != -1; at = parent[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());

            std::cout << "Shortest path from " << start << " to " << target << ": ";
            for (int i = 0; i < path.size(); i++) {
                std::cout << words[path[i]];
                if (i < path.size() - 1) std::cout << " -> ";
            }
            std::cout << std::endl;
        }


    }
    class Graph {
    private:
        int vertexCount;
        std::vector<std::vector<int>> edges;

    public:

        void setEdgeWeights() {
            for (int i = 0; i < vertexCount; ++i) {
                for (int j = 0; j < vertexCount; ++j) {
                    if (edges[i][j] > 0) {
                        edges[i][j] = 1;
                    }
                }
            }
        }


        void dijkstra(int start_index, std::vector<int>& distance, std::vector<int>& parent) {
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

            distance[start_index] = 0;
            pq.push({0, start_index});

            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                for (int v = 0; v < vertexCount; ++v) {
                    int weight = edges[u][v];
                    if (weight > 0 && distance[v] > distance[u] + weight) {
                        distance[v] = distance[u] + weight;
                        parent[v] = u;
                        pq.push({distance[v], v});
                    }
                }
            }
        }


        void printShortestPath(std::vector<std::string>& words, int start_index, int target_index) {
            std::cout << "Shortest path from " << words[start_index] << " to " << words[target_index] << ": ";
            std::vector<int> path;
            for (int v = target_index; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            for (int i = path.size() - 1; i >= 0; --i) {
                std::cout << words[path[i]];
                if (i > 0) std::cout << " <-- ";
            }
            std::cout << std::endl;
        }
    };





