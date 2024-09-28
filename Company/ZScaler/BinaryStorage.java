public static int countBalancingElements(int n, int[] arr) {
    if (n <= 1) return 0;
    
    int totalEven = 0, totalOdd = 0, totalCount = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) totalEven += arr[i];
        else totalOdd += arr[i];
    }

    int currentEven = 0, currentOdd = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) totalEven -= arr[i];
        else totalOdd -= arr[i];

        if (currentEven + totalOdd == currentOdd + totalEven) totalCount++;

        if (i % 2 == 0) currentEven += arr[i];
        else currentOdd += arr[i];
    }

    return totalCount;
}