#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    for (int i = 0; i < t; i++) 
    {
        int n;
        cout << "Enter no. of integers in the sequence: ";
        cin >> n;

        int arr[n];
        unordered_set<int> s;

        for (int j = 0; j < n; j++) 
        {
            cout << "Enter a number: ";
            cin >> arr[j];
        }

        int pop = 0;
        for (int j = n - 1; j >= 0; j--) 
        {
            if (s.count(arr[j])) {
                pop = j + 1;
                break;
            } else {
                s.insert(arr[j]);
            }
        }

        cout << "Mininum number of moves: " << pop << "\n";
    }

    return 0;
}
