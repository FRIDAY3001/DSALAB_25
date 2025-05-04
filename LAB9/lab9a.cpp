#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cases;

    cout << "Enter number of test cases: ";
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int k, q;
        cout << "Enter numbers in sequence: ";
        cin >> k;
        cout << "Enter number of players: ";
        cin >> q;

        vector<int> seq(k);
        vector<int> values(q);

        for (int j = 0; j < k; j++)
        {
            cout << "Enter the element of sequence: ";
            cin >> seq[j];
        }

        
        for (int j = 0; j < q; j++)
        {
            cout << "Enter a number: ";
            cin >> values[j];
        }

       
        for (int j = 0; j < k; j++)
        {
            int player = seq[j];
            for (int i = 1; i < values.size()+1; i++)
            {
                if (i == player)
                {
                    values.erase(values.begin() + (i-1));
                    i--; 
                }
            }
        }

  
        int count = values.size();
        if (count == 0)
        {
            cout << "0";
        }
        else
        {
            for (int j = 0; j < count; j++)
            {
                cout << count << " ";
            }
        }
        cout << "\n";
    }
} 