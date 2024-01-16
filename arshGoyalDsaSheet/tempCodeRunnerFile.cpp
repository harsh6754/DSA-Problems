int main()
{
    int n;
    cin >> n;

    vector<int> cardPoints(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cardPoints[i];
    }

    int k;
    cin >> k;

    Solution solution;
    int result = solution.maxscore(cardPoints, k);
    cout << result << endl;

    return 0;
}