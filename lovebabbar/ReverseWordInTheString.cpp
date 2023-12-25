// C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(string& s, int begin, int end)
{

	while (begin < end) {
		swap(s[begin++], s[end--]);
	}
}

// C++ program for above approach

void reverseWords(string& s)
{
	int word_begin = -1;

	// /* temp is for word boundary */
	int i = 0;

	/*STEP 1 of the above algorithm */
	while (i < s.size()) {

		/*This condition is to make sure that the
		string start with valid character (not
		space) only*/
		if ((word_begin == -1) && (s[i] != ' ')) {
			word_begin = i;
		}
		if (word_begin != -1
			&& ((s[i + 1] == ' ') || (i + 1 == s.size()))) {
			reverse(s, word_begin, i);
			word_begin = -1;
		}
		i++;
	} /* End of while */

	/*STEP 2 of the above algorithm */
	reverse(s, 0, s.size() - 1);
}

// Driver Code
int main()
{
	string s = "i like this program very much";
    cout<<"before reverse"<<endl;
    cout<<s<<endl;

	// Function call
    cout<<"after reverse"<<endl;
	reverseWords(s);
	cout << s << endl;
	;
	return 0;
}

// This code is contributed by garg28harsh.
