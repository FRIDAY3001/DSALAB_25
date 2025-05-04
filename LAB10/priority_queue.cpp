//priority queue adt
#include <iostream>
#include <vector>
using namespace std;


class Heap 
{
    private:

    vector<int> heap;

    int parent(int i)
    {
        return (i - 1) / 2; 
    }
    int leftChild(int i) 
    { 
        return 2 * i + 1; 
    }
    int rightChild(int i) 
    { 
        return 2 * i + 2; 
    }


    void heapifyUp(int index) 
    {
        while (index != 0 && heap[parent(index)] < heap[index]) 
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }


    void heapifyDown(int index) 
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) 
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }
    
    
    public:

    void insert(int val) 
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << val << "\n";
    }



    void deleteRoot() 
    {
        if (heap.empty()) 
        {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Deleted: " << heap[0] <<"\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }


    void display() 
    {
        cout << "Heap elements: ";
        for (int i : heap)
            cout << i << " ";
        cout << "\n";
    }


    void search(int val) 
    {
        for (int i = 0; i < heap.size(); i++) 
        {
            if (heap[i] == val) 
            {
                cout << val << " found at index " << i << "\n";
                return;
            }
        }
        cout << "Element not found.\n";
    }


    void heapSort() 
    {
        vector<int> temp = heap;
        vector<int> sorted;

        while (!temp.empty()) 
        {
            sorted.push_back(temp[0]);
            temp[0] = temp.back();
            temp.pop_back();
            heapifyDownForSort(temp, 0);
        }

        cout << "Sorted elements: ";
        for (int x : sorted)
            cout << x << " ";
        cout << endl;
    }


    void heapifyDownForSort(vector<int>& h, int index) 
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < h.size() && h[left] > h[largest])
            largest = left;
        if (right < h.size() && h[right] > h[largest])
            largest = right;

        if (largest != index) 
        {
            swap(h[index], h[largest]);
            heapifyDownForSort(h, largest);
        }
    }
};


int main() 
{
    Heap h;
    int choice, value;

    while (choice != 6) {
        cout << "1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort (Heap Sort)\n6.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            h.insert(value);
            break;

        case 2:
            h.deleteRoot();
            break;

        case 3:
            h.display();
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            h.search(value);
            break;

        case 5:
            h.heapSort();
            break;

        case 6:
            cout << "Exiting.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}





