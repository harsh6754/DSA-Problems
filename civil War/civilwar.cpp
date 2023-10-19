#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Function to calculate the factorial
long long factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to generate all legal subsets of the given strings
vector<string> generateSubsets(vector<string> &strings)
{
    int n = strings.size();
    vector<string> subsets;

    // Generate subsets with increasing lengths
    for (int i = 0; i < (1 << n); ++i)
    {
        string subset;
        for (int j = 0; j < n; ++j)
        {
            if (i & (1 << j))
            {
                subset += strings[j] + ",";
            }
        }
        if (!subset.empty())
        {
            subset.pop_back(); // Remove the trailing comma
            subsets.push_back(subset);
        }
    }

    // Create a map to store the original order of input strings
    map<string, int> originalOrder;
    for (int i = 0; i < n; ++i)
    {
        originalOrder[strings[i]] = i;
    }

    // Sort the subsets based on the original order of input strings
    sort(subsets.begin(), subsets.end(), [&](const string &a, const string &b)
         {
        int lenA = a.length();
        int lenB = b.length();
        int len = min(lenA, lenB);
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                return originalOrder[a.substr(i, 1)] < originalOrder[b.substr(i, 1)];
            }
        }
        return lenA < lenB; });

    return subsets;
}

int main()
{
    int N, R;
    cin >> N >> R;

    vector<string> strings(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> strings[i];
    }

    vector<string> subsets = generateSubsets(strings);

    if (R <= subsets.size())
    {
        cout << subsets[R - 1] << endl;
    }
    else
    {
        cout << "Invalid rank." << endl;
    }

    return 0;
}
