#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

using namespace std;

// Function to convert a binary string to decimal
int binaryToDecimal(const string &binary) {
    return stoi(binary, nullptr, 2);
}

// Function to convert a binary string to an IP address format
string binaryToIP(const string &binary) {
    stringstream ss;
    for (size_t i = 0; i < binary.length(); i += 8) {
        string byte = binary.substr(i, 8);
        ss << binaryToDecimal(byte);
        if (i < binary.length() - 8) ss << ".";
    }
    return ss.str();
}

int main() {
    // Input data
    string line1, line2, line3;
    cin >> line1 >> line2 >> line3;

    // Extract the version (bits 0-3)
    string versionBinary = line1.substr(0, 4);
    int version = binaryToDecimal(versionBinary);

    // Extract the protocol (bits 4-12)
    string protocolBinary = line1.substr(4, 8);
    int protocol = binaryToDecimal(protocolBinary);
    string protocolStr = (protocol == 6) ? "TCP" : (protocol == 17) ? "UDP" : "UNKNOWN";

    // Extract the Time to Live (bits 13-20)
    string ttlBinary = line1.substr(12, 8);
    int ttl = binaryToDecimal(ttlBinary);

    // Extract the Packet Length (bits 21-31)
    string packetLengthBinary = line1.substr(20, 12);
    int packetLength = binaryToDecimal(packetLengthBinary);

    // Extract the Source IP Address
    string sourceIPBinary = line2;
    string sourceIP = binaryToIP(sourceIPBinary);

    // Extract the Destination IP Address
    string destinationIPBinary = line3;
    string destinationIP = binaryToIP(destinationIPBinary);

    // Print the results
    cout << version << "," << protocolStr << "," << ttl << "," << packetLength << endl;
    cout << sourceIP << endl;
    cout << destinationIP << endl;

    return 0;
}
