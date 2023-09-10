#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    int u, v, w; // Source node, target node, weight
};

int main() {
    // Define the filename of the DIMACS file
    string filename = "USA-road-d.FLA.gr";

    // Open the DIMACS file for reading
    ifstream dimacsFile(filename);

    if (!dimacsFile.is_open()) {
        cerr << "Error: Unable to open the DIMACS file." << endl;
        return 1;
    }

    int n, m;
    vector<Edge> graph; // Assuming you use a vector to store edges

    string line;
    while (getline(dimacsFile, line)) {
        // Split the line into words
        stringstream ss(line);
        string word;

        ss >> word;

        if (word == "p") {
            // Parse the "p" line to get the number of nodes (n) and edges (m)
            ss >> word; // Expect "sp" (shortest path)
            ss >> n >> m;
        } else if (word == "a") {
            // Parse the "a" lines and add edges to the graph vector
            int u, v, w;
            ss >> u >> v >> w;

            // Assuming you use 0-based indexing, decrement node IDs by 1
            u--;
            v--;

            // Create an edge and add it to the graph vector
            graph.push_back({u, v, w});
        }
    }

    // Close the DIMACS file
    dimacsFile.close();

    // Now you have read the graph information from the DIMACS file
    // You can use the 'graph' vector to work with the graph data

    // For example, you can iterate through the edges:
    for (const Edge& edge : graph) {
        cout << "Edge: " << edge.u << " -> " << edge.v << " Weight: " << edge.w << endl;
    }

    return 0;
}

