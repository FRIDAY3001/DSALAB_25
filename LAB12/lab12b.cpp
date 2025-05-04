#include <iostream>
using namespace std;

class Graph {
private:
    class Node {
    public:
        int vertex;
        int weight;
        Node* next;
        Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    };

    int V;
    Node** adjlist;

public:
    Graph(int vertices) {
        V = vertices;
        adjlist = new Node*[V];
        for (int i = 0; i < V; i++) {
            adjlist[i] = nullptr;
        }
    }

    Node** getAdjList() {
        return adjlist;
    }

    void insert(int x, int y, int weight) {
        Node* newNode = new Node(y, weight);
        newNode->next = adjlist[x];
        adjlist[x] = newNode;
    }

    void Delete(int x, int y) {
        Node* temp = adjlist[x];
        Node* prev = nullptr;

        while (temp != nullptr && temp->vertex != y) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Edge not found.\n";
            return;
        }

        if (prev == nullptr) {
            adjlist[x] = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Edge deleted.\n";
    }

    void search(int x, int y) {
        Node* temp = adjlist[x];
        while (temp != nullptr) {
            if (temp->vertex == y) {
                cout << "Edge found with weight " << temp->weight << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Edge does not exist.\n";
    }

    void display() {
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            Node* temp = adjlist[i];
            while (temp != nullptr) {
                cout << "(" << temp->vertex << "," << temp->weight << ") -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }
};

int main() {
    int option = 0, A, B, v, weight;

    cout << "Enter number of vertices: ";
    cin >> v;
    Graph G(v);

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
                cout << "The adjacency list:\n";
                G.display();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
