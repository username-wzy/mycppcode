#include <bits/stdc++.h>
using namespace std;

/*
核心：
- 每个诱饵存活时间 = 最近僵尸的距离。
- 候选时间来源：
  1. 左端到第一个僵尸的距离。
  2. 右端到最后一个僵尸的距离。
  3. 相邻僵尸之间的间隔的一半。
- 收集所有候选时间，排序，取前 K 个。
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        long long K, L;
        cin >> N >> K >> L;
        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        sort(A.begin(), A.end());

        vector<long long> candidates;

        // 左端
        candidates.push_back(A[0]);
        // 右端
        candidates.push_back(L - A.back());

        // 相邻僵尸间隔
        for (int i = 0; i < N - 1; i++) {
            long long gap = A[i + 1] - A[i];
            candidates.push_back(gap / 2);
        }

        sort(candidates.rbegin(), candidates.rend());

        long long result = 0;
        for (int i = 0; i < (int)candidates.size() && i < K; i++) {
            result += candidates[i];
        }

        cout << result << "\n";
    }
    return 0;
}