//implement 1 to n towers and find number of moves till first tower has maximum no of blocks
#include <iostream>
#include <vector>
using namespace std;


void tower(int n)
{
    int count = 0;
    vector<int> v(n);

    for (int i = 0; i < n;i++)
    {
        cout << "Enter blocks in tower " << i+1 << ":";
        cin >> v[i];
    }
    cout << n << "\nTest Case: ";
    for (int i = 0; i < n;i++)
    {
        cout << v[i] << " ";
    }

    for (int i = 1; i < n;i++)
    {
        if (v[i] > v[0])
        {
            int moves = (v[i]-v[0])+1;
            v[0]+=moves;
            v[i]+=moves;
            count+= moves;
        }
    }

    cout << "\nNumber of moves: " << count << "\n";
}


int main()
{
    int tests;

    cout << "Enter no. of testcases: ";
    cin >> tests;

    for (int i = 0; i < tests;i++)
    {
        int n;
        cout << "Enter no. of towers: ";
        cin >> n;
        tower(n);

    }
    return 0;
}