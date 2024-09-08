#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void convertToIpv6(const string& ipv4address) {
    vector<string> octets;
    stringstream ss(ipv4address);
    string token;

    while (getline(ss, token, '.')) {
        octets.push_back(token);
    }

    if (octets.size() != 4) {
        cout << "Invalid input\n";
        return;
    }

    if (octets[0] == "127") {
        cout << "::1\n";
        return;
    }

    string ipv6 = "::FFFF:";

    for (int i = 0; i < 4; i++) {
        int octet = stoi(octets[i]);
        if (octet < 0 || octet > 255) {
            cout << "Invalid input\n";
            return;
        }

        char hex[3];
        snprintf(hex, sizeof(hex), "%02X", octet);
        
        ipv6 += hex;
        if (i == 1) {
            ipv6 += ":";
        }
    }

    cout << ipv6 << endl;
}

int main() {
    string ipv4address;
    cout << "Enter IPv4 address: ";
    cin >> ipv4address;
    convertToIpv6(ipv4address);
    return 0;
}
