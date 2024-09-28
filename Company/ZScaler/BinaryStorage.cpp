#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> sortBinaryNumbers(std::vector<std::vector<int>> bitArrays) {
    std::vector<std::pair<int, int>> decimalIndex;

    for (int i = 0; i < bitArrays.size(); i++) {
        int decimalValue = 0;
        for (int j = 0; j < bitArrays[i].size(); j++) {
            decimalValue += (1 << bitArrays[i][j]);
        }
        decimalIndex.push_back({decimalValue, i});
    }

    std::sort(decimalIndex.rbegin(), decimalIndex.rend());

    std::vector<int> result;
    for (int i = 0; i < decimalIndex.size(); i++) {
        result.push_back(decimalIndex[i].second);
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> bitArrays = {
        {0, 1, 2},
        {1, 3, 4},
        {2, 0, 1}
    };

    std::vector<int> sortedIndices = sortBinaryNumbers(bitArrays);

    std::cout << "Sorted indices: ";
    for (int index : sortedIndices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}