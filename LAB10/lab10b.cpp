#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    for (int x = 0;x < t;x++)
    {
        int n;
        cout << "Enter number of words: ";
        cin >> n;
        vector<vector<string>> words(3, vector<string>(n));
        unordered_map<string,int> frequency;

        for (int i = 0; i < 3;i++) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cout << "Enter a 3 letter word: ";
                cin >> words[i][j];
                frequency[words[i][j]]++;
            }
        }

        vector<int> scores(3, 0);
        for (int i = 0; i < 3;i++) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (frequency[words[i][j]] == 1) scores[i] += 3;
                else if (frequency[words[i][j]] == 2) scores[i] += 1;
            }
        }

        cout << "player 1:"<< scores[0] << "\n" << "player 2:" << scores[1] << "\n" << "player 3:" << scores[2] << "\n";

    }


    return 0;
}