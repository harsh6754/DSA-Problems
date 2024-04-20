#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfTwo(int x) {
    return x != 0 && (x & (x - 1)) == 0;
}

int main() {

    int page_size_kb;
    cin>> page_size_kb;
    
    int physical_memory_kb;
    cin>>physical_memory_kb;
    
    int address_space_bits;
    cin>>address_space_bits;

    if (!isPowerOfTwo(page_size_kb) || !isPowerOfTwo(physical_memory_kb)) {
        cout << "Both page size and physical memory size must be powers of two." << endl;
        return 0;
    }

    int page_size_bits = static_cast<int>(log2(page_size_kb * 1024));
    int physical_memory_bits = static_cast<int>(log2(physical_memory_kb * 1024));
    int page_table_index_bits = address_space_bits - page_size_bits;

    cout << "\"VPN\":" << page_table_index_bits <<" bits"<< endl;
    cout << "\"Page Offset\":" << page_size_bits<<" bits" << endl;
    cout << "\"Page Table Index\":" << page_table_index_bits <<" bits"<< endl;
    cout << "\"Frame Number\":" << physical_memory_bits - page_size_bits <<" bits"<< endl;
    cout << "\"Offset within a Frame\":" << page_size_bits<<" bits" << endl;

    return 0;
}