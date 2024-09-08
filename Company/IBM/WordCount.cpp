#include <bits/stdc++.h>
using namespace std;

int getLastAnimalNameLength(string animal_sequence) {
    vector<string> animals;
    string delimiter = "-";

    size_t pos = 0;
    std::string token;
    while ((pos = animal_sequence.find(delimiter)) != std::string::npos) {
        token = animal_sequence.substr(0, pos);
        if (!token.empty()) {
            animals.push_back(token);
        }
        animal_sequence.erase(0, pos + delimiter.length());
    }
    if (!animal_sequence.empty()) {
        animals.push_back(animal_sequence);
    }

    if (animals.empty()) {
        return 0; // If there are no animals in the sequence
    }

    string lastAnimal = animals.back();
    return lastAnimal.length();
}

int main() {
    string animalSequence = "";
    int lastAnimalNameLength = getLastAnimalNameLength(animalSequence);
    cout << lastAnimalNameLength << endl; 

    return 0;
}