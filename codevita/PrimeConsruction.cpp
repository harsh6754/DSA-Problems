#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    string firstName, familyName, birthFamilyName, gender, fatherName, spouseName;
    int age;

    // Constructor
    Person(string fName, string fFamily, string bFamily, string g, string fName2, string sName, int a) : 
        firstName(fName), familyName(fFamily), birthFamilyName(bFamily), gender(g), fatherName(fName2), spouseName(sName), age(a) {}
};

map<string, Person> people;  // Store people by their name
map<string, string> leaders;  // Store family leaders

bool comparePeople(const Person &a, const Person &b) {
    if (a.age == b.age) {
        if (a.familyName == b.familyName) {
            return a.firstName < b.firstName;
        }
        return a.familyName < b.familyName;
    }
    return a.age < b.age;
}

void selectLeaders() {
    for (auto it = leaders.begin(); it != leaders.end(); it++) {
        vector<Person> familyMembers;
        string leaderName = it->first;
        string leaderFamily = it->second;

        for (auto it2 = people.begin(); it2 != people.end(); it2++) {
            if (it2->second.familyName == leaderFamily) {
                familyMembers.push_back(it2->second);
            }
        }

        sort(familyMembers.begin(), familyMembers.end(), comparePeople);
        leaders[leaderName] = familyMembers.back().firstName;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string fName, fFamily, bFamily, g, fName2, sName;
        int a;
        cin >> fName >> fFamily >> bFamily >> g >> fName2 >> sName >> a;
        Person person(fName, fFamily, bFamily, g, fName2, sName, a);
        people[fName] = person;

        if (leaders.find(fFamily) == leaders.end()) {
            leaders[fFamily] = fName;
        } else {
            if (person.age > people[leaders[fFamily]].age) {
                leaders[fFamily] = fName;
            }
        }
    }

    int E;
    cin >> E;

    for (int i = 0; i < E; i++) {
        string event;
        cin >> event;
        if (event == "MA") {
            // Handle marriage event
            string person1, person2;
            cin >> person1 >> person2;

            // Update spouse names
            people[person1].spouseName = person2;
            people[person2].spouseName = person1;

            // Update family leaders
            string family1 = people[person1].familyName;
            string family2 = people[person2].familyName;

            if (leaders[family1] != person1 && leaders[family2] != person2) {
                // Choose the older person as the leader
                if (people[person1].age > people[person2].age) {
                    leaders[family2] = person2;
                } else {
                    leaders[family1] = person1;
                }
            }
        } else if (event == "DI") {
            // Handle divorce event
            string person1, person2;
            cin >> person1 >> person2;

            // Update spouse names
            people[person1].spouseName = "NA";
            people[person2].spouseName = "NA";

            // Update family leaders if needed
            string family1 = people[person1].familyName;
            string family2 = people[person2].familyName;

            if (leaders[family1] == person1) {
                selectLeaders();
            }
            if (leaders[family2] == person2) {
                selectLeaders();
            }
        } else if (event == "BI") {
            // Handle birth event
            string nameOfTheNewBorn, gender, father, mother;
            cin >> nameOfTheNewBorn >> gender >> father >> mother;

            // Update family name of the new born
            people[nameOfTheNewBorn].familyName = people[father].familyName;

            // Update family leaders if needed
            string family = people[father].familyName;
            if (leaders[family] == father) {
                selectLeaders();
            }
        } else if (event == "DE") {
            // Handle death event
            string person;
            cin >> person;

            // Remove the person from the records
            people.erase(person);

            // Update family leaders if needed
            string family = people[person].familyName;
            if (leaders[family] == person) {
                selectLeaders();
            }
        } else if (event == "YP") {
            // Handle Year Passed event
            int years;
            cin >> years;

            // Update ages of all people
            for (auto it = people.begin(); it != people.end(); it++) {
                it->second.age += years;
            }
        } else if (event == "PO") {
            // Handle Print One event
            string person;
            cin >> person;
            if (people.find(person) != people.end()) {
                Person p = people[person];
                cout << p.firstName << " " << p.familyName << " " << p.birthFamilyName << " " << p.gender << " " << p.fatherName << " " << p.spouseName << " " << p.age << " " << leaders[p.familyName] << endl;
            }
        } else if (event == "PA") {
            // Handle Print All event
            vector<string> alivePeople;
            for (auto it = people.begin(); it != people.end(); it++) {
                alivePeople.push_back(it->first);
            }
            sort(alivePeople.begin(), alivePeople.end());
            for (string name : alivePeople) {
                Person p = people[name];
                cout << p.firstName << " " << p.familyName << " " << p.birthFamilyName << " " << p.gender << " " << p.fatherName << " " << p.spouseName << " " << p.age << " " << leaders[p.familyName] << endl;
            }
        }
    }

    return 0;
}
