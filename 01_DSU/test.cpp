#include <iostream>
#include <vector>
using namespace std;

class DisjointUnionSets {
    vector<int> rank, parent;

public:
    // Constructor to initialize sets
    DisjointUnionSets(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        // Initially, each element is in its own set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of the set that x belongs to
    int find(int i) {
        int root = parent[i];

        if (parent[root] != root) {
            return parent[i] = find(root);
        }

        return root;
    }

    // Union of sets containing x and y
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        // If they are in the same set, no need to union
        // if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[xRoot] = yRoot;
            rank[yRoot]++;
        }
    }

    // Method to print parent and rank information
    void printSets() {
        cout << "Element -> Parent -> Rank" << endl;
        for (size_t i = 0; i < parent.size(); i++) {
            cout << i << " -> " << parent[i] << " -> " << rank[i] << endl;
        }
    }
};

int main() {
    // Let there be 9 elements with ids 0 to 8
    int n = 9;
    DisjointUnionSets dus(n);

    // Perform union operations
    dus.unionSets(1, 2);
    dus.unionSets(2, 3);
    dus.unionSets(4, 5);
    dus.unionSets(6, 7);
    dus.unionSets(4, 7);
    dus.unionSets(7, 8);
    dus.unionSets(5, 8);

    // Print the parent and rank information
    dus.printSets();

    return 0;
}