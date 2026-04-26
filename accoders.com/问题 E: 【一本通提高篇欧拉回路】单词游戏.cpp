    #include <bits/stdc++.h>

    using namespace std;
    typedef long long ll;

    int in[200], out[200];
    bool vis[200];

    int fa[200];

    int find(int u)
    {
        int root = u;
        while (fa[root] != root)
            root = fa[root];
        while (fa[u] != root) {
            int next = fa[u];
            fa[u] = root;
            u = next;
        }
        return root;
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            memset(vis, 0, sizeof vis);
            memset(in, 0, sizeof in);
            memset(out, 0, sizeof out);
            int n;
            cin >> n;
            for (int i = 0; i < 200; i++)
                fa[i] = i;
            for (int i = 0; i < n; i++) {
                string s;
                cin >> s;
                int a = s[0], b = s.back();
                in[b]++;
                out[a]++;
                vis[a] = true;
                vis[b] = true;
                fa[find(a)] = find(b);
            }
            // 1.连通
            int liantongkuai = 0;
            for (int i = 'a'; i <= 'z'; i++)
                if (fa[i] == i && vis[i])
                    liantongkuai++;
            if (liantongkuai > 1) {
                cout << "The door cannot be opened.\n";
                continue;
            }
            // 2.一笔画判断(有向图)
            int st = 0, ed = 0, other = 0;
            for (int i = 'a'; i <= 'z'; i++) {
                if (in[i] == out[i])
                    continue;
                if (in[i] - out[i] == 1)
                    ed++;
                else if (out[i] - in[i] == 1)
                    st++;
                else
                    other++;
            }
            if (other == 0 && (st == 0 && ed == 0 || st == 1 && ed == 1)) {
                // 不能存在度的差大于1，例如(1, 3)(3, 1)，例如1，你要回来两次，2，你要回去两次，不可能构成一笔画（无论回路还是通路），第二个就是如果都是相同的，就是欧拉回路，要么就是有一起点和一个终点
                cout << "Ordering is possible.\n";
            } else
                cout << "The door cannot be opened.\n";
        }
        return 0;
    }