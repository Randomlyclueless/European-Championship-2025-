#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// Huffman Tree Node
struct Node
{
    double freq;
    int index;
    Node *left, *right;

    Node(double f, int idx) : freq(f), index(idx), left(nullptr), right(nullptr) {}
};

// Comparator for Min-Heap
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        if (a->freq == b->freq)
            return a->index > b->index;
        return a->freq > b->freq;
    }
};

void generateCodes(Node *root, string code, unordered_map<int, string> &huffmanCodes)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        huffmanCodes[root->index] = code;
        return;
    }

    generateCodes(root->left, code + "-", huffmanCodes);
    generateCodes(root->right, code + ".", huffmanCodes);
}

void deleteTree(Node *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    int n;
    cin >> n;

    vector<double> frequencies(n);

    for (int i = 0; i < n; i++)
    {
        cin >> frequencies[i];
    }

    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push(new Node(frequencies[i], i));
    }

    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        if (left->freq == right->freq && left->index > right->index)
        {
            swap(left, right);
        }

        Node *merged = new Node(left->freq + right->freq, min(left->index, right->index));
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    unordered_map<int, string> huffmanCodes;
    generateCodes(minHeap.top(), "", huffmanCodes);

    for (int i = 0; i < n; i++)
    {
        cout << huffmanCodes[i] << endl;
    }

    deleteTree(minHeap.top());

    return 0;
}