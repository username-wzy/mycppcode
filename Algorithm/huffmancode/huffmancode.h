#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;

class HuffmanCode {
    protected:
        struct HuffmanNode {
            char ch;
            int fre;
            HuffmanNode *left, *right;
        };
        struct forpq_node {
            int fre;
            HuffmanNode *treeNode;
            bool operator< (const forpq_node other) const {
                return fre > other.fre;
            }
        };
        HuffmanNode *nodePool;
        bool *code;
        int codesize;
        HuffmanNode *root;
        void printHuffmancode();
        void viewHuffman(HuffmanNode *root, int depth);
    public:
        HuffmanCode(int cap, string str);
        ~HuffmanCode();
        void view() { viewHuffman(root, 0); }
        void wzy();
};

HuffmanCode :: HuffmanCode(int cap, string str) {
    nodePool = new HuffmanNode[cap + 5];
    code = new bool [cap + 5];
    int size = 0;
    codesize = 0;
    map<char, int> count;
    for (char ch : str) {
        count[ch]++;
    }

    priority_queue<forpq_node> minHeap;
    for (auto [ch, fre] : count) {
        HuffmanNode leaf = {ch, fre, nullptr, nullptr};
        nodePool[++size] = leaf;
        minHeap.push({fre, &nodePool[size]});
    }

    while (minHeap.size() > 1) {
        auto a = minHeap.top(); minHeap.pop();
        auto b = minHeap.top(); minHeap.pop();
        nodePool[++size] = {
            '*', a.fre + b.fre, a.treeNode, b.treeNode
        };
        minHeap.push({a.fre + b.fre, &nodePool[size]});
    }
    root = minHeap.top().treeNode;
    minHeap.pop();
}

HuffmanCode :: ~HuffmanCode() {
    delete[] nodePool;
    delete[] code;
}

inline void HuffmanCode :: printHuffmancode() {
    for (int i = 0; i < codesize; i++) {
        cout << code[i];
    }
}

void HuffmanCode :: viewHuffman(HuffmanNode *root, int depth) {
    if (root -> ch != '*') {
        cout << root -> ch << ' ' << depth << ' ';
        printHuffmancode();
        cout << '\n';
    }
    if (root -> left != nullptr) {
        code[codesize++] = 0;
        viewHuffman(root -> left, depth + 1);
        codesize--;
    }
    if (root -> right != nullptr) {
        code[codesize++] = 1;
        viewHuffman(root -> right, depth + 1);
        codesize--;
    }
}