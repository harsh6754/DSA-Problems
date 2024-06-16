#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> generateLargestNumber(vector<int> &idDigitList, vector<int> &enRollDigitList, int P)
{

    int totalLength = idDigitList.size() + enRollDigitList.size();

    stack<int> stk;

    for (int i = 0, idIndex = 0, enIndex = 0; i < totalLength; ++i)
    {

        int current = -1;
        if (idIndex < idDigitList.size() && (enIndex >= enRollDigitList.size() || idDigitList[idIndex] >= enRollDigitList[enIndex]))
        {
            current = idDigitList[idIndex++];
        }
        else if (enIndex < enRollDigitList.size())
        {
            current = enRollDigitList[enIndex++];
        }

        while (!stk.empty() && stk.size() + (totalLength - i - 1) >= P && stk.top() < current)
        {
            stk.pop();
        }

        if (stk.size() < P)
        {
            stk.push(current);
        }
    }

    vector<int> result(stk.size());
    for (int i = stk.size() - 1; i >= 0; --i)
    {
        result[i] = stk.top();
        stk.pop();
    }

    return result;
}

void processInput()
{

    int idDigitListSize;
    cin >> idDigitListSize;
    vector<int> idDigitList(idDigitListSize);
    for (int i = 0; i < idDigitListSize; ++i)
    {
        cin >> idDigitList[i];
    }

    int enRollDigitListSize;
    cin >> enRollDigitListSize;
    vector<int> enRollDigitList(enRollDigitListSize);
    for (int i = 0; i < enRollDigitListSize; ++i)
    {
        cin >> enRollDigitList[i];
    }

    int P;
    cin >> P;

    vector<int> result = generateLargestNumber(idDigitList, enRollDigitList, P);

    for (int digit : result)
    {
        cout << digit << " ";
    }
    cout << endl;
}

int main()
{
    processInput();
    return 0;
}
