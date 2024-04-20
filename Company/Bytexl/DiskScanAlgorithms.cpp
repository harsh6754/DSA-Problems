#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> scan_disk_schedule(int head_position, vector<int> requests) {
    // sort the requests
    sort(requests.begin(), requests.end());

    // initialize the serviced requests vector
    vector<int> serviced_requests;

    // add the initial head position to the serviced requests
    serviced_requests.push_back(head_position);

    // initialize the direction to true (moving to the right)
    bool direction = true;

    // continue servicing requests until all have been processed
    while (serviced_requests.size() < requests.size() + 1) {
        // find the next request in the current direction
        int next_request = -1;
        if (direction) {
            for (int i = 0; i < requests.size(); ++i) {
                if (requests[i] > serviced_requests.back()) {
                    next_request = requests[i];
                    break;
                }
            }
        } else {
            for (int i = requests.size() - 1; i >= 0; --i) {
                if (requests[i] < serviced_requests.back()) {
                    next_request = requests[i];
                    break;
                }
            }
        }

        // if no more requests in this direction, reverse direction
        if (next_request == -1) {
            direction = !direction;
        } else {
            // add the next request to the serviced requests
            serviced_requests.push_back(next_request);

            // remove the next request from the list of requests
            if (direction) {
                requests.erase(remove(requests.begin(), requests.end(), next_request), requests.end());
            } else {
                reverse(requests.begin(), requests.end());
                requests.erase(remove(requests.begin(), requests.end(), next_request), requests.end());
                reverse(requests.begin(), requests.end());
            }
        }
    }

    return serviced_requests;
}

int main() {
    int head_position = 50;
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};

    vector<int> serviced_requests = scan_disk_schedule(head_position, requests);

    cout << "Order of serviced requests: ";
    for (int i = 0; i < serviced_requests.size(); ++i) {
        cout << serviced_requests[i] << " ";
    }
    cout << endl;

    return 0;
}