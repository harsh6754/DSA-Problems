// #include<bits/stdc++.h>
// using namespace std;

// int maxOverlappingIntervals(vector<pair<int, int>>& intervals) {
//     map<int, int> timeline;
    
//     // Construct the timeline
//     for (const auto& interval : intervals) {
//         timeline[interval.first]++;
//         timeline[interval.second]--;
//     }

//     int maxOverlap = 0;
//     int currentOverlap = 0;

//     // Iterate through the timeline
//     for (const auto& entry : timeline) {
//         currentOverlap += entry.second;
//         maxOverlap = max(maxOverlap, currentOverlap);
//     }

//     return maxOverlap;
// }

// int main() {
//     vector<pair<int, int>> intervals = {{5, 10}, {7, 12}, {11, 15}, {13, 18}, {14, 16}};

//     int result = maxOverlappingIntervals(intervals);

//     cout << "Maximum number of intervals overlapping at any time: " << result << endl;

//     return 0;
// }

// Program to find maximum guest at any time in a party
#include<iostream>
#include<algorithm>
using namespace std;
 
void findMaxGuests(int arrl[], int exit[], int n)
{
   // Sort arrival and exit arrays
   sort(arrl, arrl+n);
   sort(exit, exit+n);
 
   // guests_in indicates number of guests at a time
   int guests_in = 1, max_guests = 1, time = arrl[0];
   int i = 1, j = 0;
 
   // Similar to merge in merge sort to process
   // all events in sorted order
   while (i < n && j < n)
   {
      // If next event in sorted order is arrival,
      // increment count of guests
      if (arrl[i] <= exit[j])
      {
          guests_in++;
 
          // Update max_guests if needed
          if (guests_in > max_guests)
          {
              max_guests = guests_in;
              time = arrl[i];
          }
          i++;  //increment index of arrival array
      }
      else // If event is exit, decrement count
      {    // of guests.
          guests_in--;
          j++;
      }
   }
 
   cout << "Maximum Number of Guests = " << max_guests;
}
 
// Driver program to test above function
int main()
{
    int arrl[] = {5, 7, 11, 13, 14};
    int exit[] = {10, 12, 15, 18, 16};
    int n = sizeof(arrl)/sizeof(arrl[0]);
    findMaxGuests(arrl, exit, n);
    return 0;
}