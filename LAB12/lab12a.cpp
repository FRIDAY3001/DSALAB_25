#include <iostream>
using namespace std;

class Graph {
private:
    int adjmatrix[10][10];
    int V;

public:
    void graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjmatrix[i][j] = 0;
            }
        }
    }

    int (*getMatrix())[10] {
        return adjmatrix;
    }

    void insert(int x, int y, int weight) {
        if (x >= V || y >= V || x < 0 || y < 0) {
            cout << "Invalid Edge.\n";
            return;
        }
        adjmatrix[x][y] = weight; // Directed only
    }

    void Delete(int x, int y) {
        adjmatrix[x][y] = 0;
    }

    void search(int x, int y) {
        if (adjmatrix[x][y] != 0) {
            cout << "Edge found with weight " << adjmatrix[x][y] << "\n";
        } else {
            cout << "Edge does not exist.\n";
        }
    }

    void display() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjmatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int option, A, B, v, weight;
    Graph G;

    cout << "Enter number of vertices: ";
    cin >> v;
    G.graph(v);

    while (option != 5) {
        cout << "\nMenu:\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the edge and weight (from to weight): ";
                cin >> A >> B >> weight;
                G.insert(A, B, weight);
                break;

            case 2:
                cout << "Enter edge to delete (from to): ";
                cin >> A >> B;
                G.Delete(A, B);
                break;

            case 3:
                cout << "Enter edge to search (from to): ";
                cin >> A >> B;
                G.search(A, B);
                break;

            case 4:
                cout << "The adjacency matrix:\n";
                G.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;
        }
    }

    return 0;
}
