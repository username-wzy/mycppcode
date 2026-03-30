    #include<bits/stdc++.h>

    using namespace std;
    typedef long long ll;

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;
        cout << (s.size() % 5 == 0 ? "Yes" : "No");

        return 0;
    }