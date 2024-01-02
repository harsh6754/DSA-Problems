#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words;
    std::string word;

    // Input words until "####" is encountered
    while (true) {
        std::cin >> word;
        if (word == "####") {
            break;
        }
        words.push_back(word);
    }

    // Print the first word
    std::cout << words[0] << std::endl;

    // Iterate through the words and print the next word in the chain
    for (size_t i = 1; i < words.size(); ++i) {
        // Get the last letter of the previous word
        char lastLetter = words[i - 1].back();

        // Find the next word that starts with the last letter
        bool found = false;
        for (size_t j = i; j < words.size(); ++j) {
            if (words[j][0] == lastLetter) {
                // Print the next word and update the index
                std::cout << words[j] << std::endl;
                std::swap(words[i], words[j]);
                found = true;
                break;
            }
        }

        // If no matching word is found, break the loop
        if (!found) {
            break;
        }
    }

    return 0;
}
