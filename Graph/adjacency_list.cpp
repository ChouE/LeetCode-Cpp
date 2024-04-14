#include <list>
#include <print>
#include <vector>

class Vertex {
 public:
  int id;
  Vertex(int id) : id(id) {}
};

class Graph {
  int V;
  std::vector<std::list<Vertex*>> adj;

 public:
  Graph(int V) : V(V), adj(V) {}
  void addEdge(int src, int dest) {
    Vertex* destination = new Vertex(dest);
    adj[src].push_back(destination);
    // 无向图，需要添加反向
    // Vertex* source = new Vertex(src);
    // adj[dest].push_back(source);
  }

  void printGraph() {
    for (int i = 0; i < V; i++) {
      std::print("Adjacency List of Vertex {}", i);
      for (auto vertex : adj[i]) {
        std::print(" -> {} ", vertex->id);
      }
      std::print("\n");
    }
  }

  ~Graph() {
    for (int i = 0; i < V; i++) {
      for (auto vertex : adj[i]) {
        delete vertex;
      }
    }
  }
};

int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(1, 4);
  // g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.printGraph();
  return 0;
}