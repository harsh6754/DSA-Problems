#include <bits/stdc++.h>
using namespace std;

int findNotes(int totalShaneMoney, int totalNotes, vector<int> &noteOrder)
{
    for (int i = 0; i < totalNotes - 1; ++i)
    {
        for (int j = i + 1; j < totalNotes; ++j)
        {
            if (noteOrder[i] + noteOrder[j] == totalShaneMoney)
                return 2;
        }
    }

    for (int i = 0; i < totalNotes - 2; ++i)
    {
        for (int j = i + 1; j < totalNotes - 1; ++j)
        {
            for (int k = j + 1; k < totalNotes; ++k)
            {
                if (noteOrder[i] + noteOrder[j] + noteOrder[k] == totalShaneMoney)
                    return 3;
            }
        }
    }

    return 0;
}

int main()
{
    int totalShaneMoney;
    cin >> totalShaneMoney;

    int totalNotes;
    cin >> totalNotes;

    vector<int> noteOrder(totalNotes);
    for (int i = 0; i < totalNotes; i++)
    {
        cin >> noteOrder[i];
    }

    int result = findNotes(totalShaneMoney, totalNotes, noteOrder);

    cout << result << endl;

    return 0;
}
