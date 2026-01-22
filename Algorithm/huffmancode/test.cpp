#include "huffmancode.h"

using namespace std;

void HuffmanCode :: wzy() {
    cout << "yusiwen is a good man" << '\n';
}

int main() {
    string str = "classmycls";
    HuffmanCode hc(int(str.size()), str);
    hc.view();
    cout << "\n\n\n\n\n\n\n\n\n\n";
    hc.wzy();
}