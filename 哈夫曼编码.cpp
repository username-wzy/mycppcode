#include<bits/stdc++.h>
#define ll long long

using namespace std;

// 哈夫曼树节点结构
struct HuffmanNode {
    char ch;      // 字符值，'*'表示内部节点
    int fre;       // 字符出现频率
    HuffmanNode *left, *right;  // 左右子节点指针
};

// 优先队列节点结构，用于构建哈夫曼树
struct pqnode {
    int fre;       // 频率，用于优先队列排序
    HuffmanNode *treeNode;  // 指向哈夫曼树节点的指针
    
    // 重载小于运算符，使优先队列按频率升序排列
    bool operator < (const pqnode other) const {
        return fre > other.fre;
    }
};

// 节点存储数组，避免动态内存分配
HuffmanNode nodePool[int(2e5 + 5)];
vector<bool> Huffmanencode;

// 遍历这个模拟的栈中的Huffmancode
void printHuffmancode() {
    for (auto i : Huffmanencode) {
        cout << i;
    }
}

// 深度优先遍历哈夫曼树，输出每个字符的编码长度
void viewHuffman(HuffmanNode *root, int depth) {
    // 如果是叶子节点（非内部节点标记'*'），输出字符和编码长度
    if (root -> ch != '*') {
        cout << root -> ch << " " << depth << " ";
        printHuffmancode();
        cout << '\n';
    }
    // 递归遍历左子树
    if (root -> left != nullptr) {
        Huffmanencode.push_back(0);
        viewHuffman(root -> left, depth + 1);
        Huffmanencode.pop_back();
    }
    // 递归遍历右子树
    if (root -> right != nullptr) {
        Huffmanencode.push_back(1);
        viewHuffman(root -> right, depth + 1);
        Huffmanencode.pop_back();
    }
}

void solve() {
    string s;
    cin >> s;
    
    int n = 0;
    map<char, int> mp;
    
    // 统计每个字符的出现频率
    for (char ch : s) {
        mp[ch]++;
    }
    
    // 创建优先队列，用于构建哈夫曼树
    priority_queue<pqnode> minHeap;
    
    // 为每个字符创建叶子节点并加入优先队列
    for (auto [ch, fre] : mp) {
        HuffmanNode leafNode = {ch, fre, nullptr, nullptr};
        nodePool[n] = leafNode;
        minHeap.push({leafNode.fre, &nodePool[n]});
        n++;
    }
    
    // 构建哈夫曼树
    while (minHeap.size() > 1) {
        // 取出频率最小的两个节点
        pqnode a = minHeap.top(); minHeap.pop();
        pqnode b = minHeap.top(); minHeap.pop();
        
        // 创建新的内部节点，频率为两个子节点频率之和
        nodePool[n] = {'*', a.fre + b.fre, a.treeNode, b.treeNode};
        minHeap.push({nodePool[n].fre, &nodePool[n]});
        n++;
    }
    
    // 获取哈夫曼树的根节点
    HuffmanNode *huffmanTreeRoot = minHeap.top().treeNode;
    minHeap.pop();
    // 遍历哈夫曼树，输出编码结果
    viewHuffman(huffmanTreeRoot, 0); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("xxx.in", "r", stdin);
    // freopen("xxx.out", "w", stdout);

    int T = 1; // cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}