//find stregnth of each participant compared to strongest

#include <iostream>
using namespace std;

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >>t;

    for (int i = 0;i<t;i++)
    {
        int n;
        cout << "Enter number of participants: ";
        cin >> n;
        int arr[n];
        for (int i = 0;i < n;i++)
        {
            cout << "Enter strength:";
            cin >> arr[i];
        }


        for (int k = 0;k < n;k++)
        {
            int s = arr[k];
            int max = arr[0];
            for (int j = 0;j < n;j++)
            {
                if (j != k)
                {
                    if (arr[j] > max)
                    {
                        max = arr[j];
                    }
                }
            }

            cout << (s-max) << " ";

        }

        cout << "\n";
    }
}