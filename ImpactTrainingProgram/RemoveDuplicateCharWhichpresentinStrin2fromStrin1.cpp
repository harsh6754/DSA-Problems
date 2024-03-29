//  ===
// #include <bits/stdc++.h>
// #define NO_OF_CHAR 256
// using namespace std;

// int* getcountarray(string str2)
// {
// 	int* count = (int*)calloc(sizeof(int), NO_OF_CHAR);

// 	for (int i = 0; i < str2.size(); i++) 
// 	{
// 		count[str2[i]]++;
// 	}

// 	return count;
// }

// /* removeDirtyChars takes two 
// string as arguments: First
// string (str1) is the one from
// where function removes dirty
// characters. Second string(str2) 
// is the string which contain
// all dirty characters which need 
// to be removed from first
// string */
// string removeDirtyChars(string str1, string str2)
// {
// 	// str2 is the string 
// 	// which is to be removed
// 	int* count = getcountarray(str2);
// 	string res;
	
// 	// ip_idx helps to keep 
// 	// track of the first string
// 	int ip_idx = 0;

// 	while (ip_idx < str1.size()) 
// 	{
// 		char temp = str1[ip_idx];
// 		if (count[temp] == 0) 
// 		{
// 			res.push_back(temp);
// 		}
// 		ip_idx++;
// 	}

// 	return res;
// }

// // Driver Code
// int main()
// {
// 	string str1;
//     cin>>str1;
// 	string str2;
//     cin>>str2;
// 	// Function call
// 	cout << removeDirtyChars(str1, str2) << endl;
// }
// #include <iostream>
// #include <string>
// using namespace std;

// void removeChars(string& first,string& second) {
//     for (size_t i = 0; i < second.length(); ++i) {
//         if (first.find(second[i]) != string::npos) {
//             second.erase(i, 1);
//             --i;  // Decrement i to recheck the current position after erasing a character
//         }
//     }
// }

// int main() {
//     string firstString;
// 	cin>>firstString;
//     string secondString;
// 	cin>>secondString

//     removeChars(firstString, secondString);

//     cout << "Result: " << secondString << endl;

//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

void removeChars(string& first, string& second) {
    for (size_t i = 0; i < second.length(); ++i) {
        if (first.find(second[i]) != string::npos) {
            second.erase(i, 1);
            --i;  // Decrement i to recheck the current position after erasing a character
        }
    }
}

int main() {
    string firstString;
    cin >> firstString;

    string secondString;
    cin >> secondString;

    removeChars(firstString, secondString);

    cout << secondString << endl;

    return 0;
}
