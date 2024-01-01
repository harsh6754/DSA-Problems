#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int size;
    std::cin >> size;

    std::vector<int> array(size);

    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    std::unordered_set<int> uniqueElements;
    std::vector<int> result;

    for (int i = 0; i < size; ++i) {
        // If the element is not in the set, add it to the result array and the set
        if (uniqueElements.find(array[i]) == uniqueElements.end()) {
            result.push_back(array[i]);
            uniqueElements.insert(array[i]);
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}
