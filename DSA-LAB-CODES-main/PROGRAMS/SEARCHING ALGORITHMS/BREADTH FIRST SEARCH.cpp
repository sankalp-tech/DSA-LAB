#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph {
    private:
        int vertices;
        list<int> *adjlist;
        vector<bool> visited;
    public:
        Graph () {
        }
        Graph (int nodes) { 
            adjlist = new list<int> [nodes];
            visited.resize(nodes, false);  
            vertices = nodes;
        }
        ~Graph () { 
            delete [] adjlist;
        }
        void AddEdge (int src, int dst) {
            adjlist[src].push_back(dst);
            adjlist[dst].push_back(src);
        }
        void BFS (int source) {
            queue<int> Q;
            visited[source] = true;
            Q.push(source);
            while (!Q.empty()) {
                int node = Q.front();
                Q.pop();
                cout << node << " ";
                for (auto& adj_node : adjlist[node]) {
                    if (!visited[adj_node]) {
                        visited[adj_node] = true;
                        Q.push(adj_node);
                    }
                }
            }
            fill (visited.begin(), visited.end(), false);
        }
};
int main(){ 
    Graph g(7); 
    g.AddEdge(0,1); 
    g.AddEdge(0,2); 
    g.AddEdge(1,3); 
    g.AddEdge(1,4); 
    g.AddEdge(2,3);
    g.AddEdge(3,5); 
    g.AddEdge(4,6); 
    g.AddEdge(5,6); 
    cout << "BFS Graph Traversal" << endl;
    cout << "Source Node(0): "; g.BFS(0); cout << endl;
    cout << "Source Node(3): "; g.BFS(3); cout << endl;
    Graph t(10); 
    t.AddEdge(0,1); 
    t.AddEdge(0,2); 
    t.AddEdge(0,3); 
    t.AddEdge(1,4); 
    t.AddEdge(1,5); 
    t.AddEdge(1,6);
    t.AddEdge(3,7); 
    t.AddEdge(3,8); 
    t.AddEdge(4,9); 
    cout << "BFS Tree Traversal" << endl;
    cout << "Root Node (0): "; t.BFS(0); cout << endl;
    cout << "Root Node (9): "; t.BFS(9); cout << endl;
    return 0;
}
