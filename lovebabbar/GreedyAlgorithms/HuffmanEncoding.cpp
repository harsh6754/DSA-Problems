#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str) {
    if (!root) return;
    if (root->data != '$') cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<char>& data, vector<int>& freq, int size) {
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i) minHeap.push(new MinHeapNode(data[i], freq[i]));
    while (minHeap.size() != 1) {
        MinHeapNode *left = minHeap.top(); minHeap.pop();
        MinHeapNode *right = minHeap.top(); minHeap.pop();
        MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left; top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    vector<char> data(n);
    vector<int> freq(n);
    cout << "Enter characters: ";
    for (int i = 0; i < n; ++i) cin >> data[i];
    cout << "Enter frequencies: ";
    for (int i = 0; i < n; ++i) cin >> freq[i];
    HuffmanCodes(data, freq, n);
    return 0;
}
