# Z函数与Manacher算法

## Z函数

### 定义
Z函数（Z-function）是一个字符串的函数，对于字符串s，Z[i]表示s[i]与s[0]开始的最长公共前缀的长度。

### 应用场景
1. 字符串匹配（类似KMP算法）
2. 查找字符串中的重复子串
3. 计算字符串的最小周期

### 算法实现
```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```

### 时间复杂度
- 时间复杂度：O(n)
- 空间复杂度：O(n)

### 与KMP算法的比较
- Z函数更适合处理多模式匹配
- KMP算法更适合单模式匹配
- Z函数实现更直观，但KMP在某些情况下更高效

## Manacher算法

### 定义
Manacher算法是一种用于在线性时间内查找字符串中最长回文子串的算法。

### 算法思想
通过预处理字符串，在字符间插入特殊字符，将奇数长度和偶数长度的回文统一处理。

### 算法实现
```cpp
string manacher_preprocess(string s) {
    string t = "#";
    for (char c : s) {
        t += c + string("#");
    }
    return t;
}

vector<int> manacher(string s) {
    string t = manacher_preprocess(s);
    int n = t.size();
    vector<int> p(n);
    int center = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }
        
        int a = i + p[i] + 1;
        int b = i - p[i] - 1;
        while (a < n && b >= 0 && t[a] == t[b]) {
            p[i]++;
            a++;
            b--;
        }
        
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
    }
    return p;
}

pair<int, int> longest_palindrome(string s) {
    vector<int> p = manacher(s);
    int max_len = 0, center_index = 0;
    
    for (int i = 0; i < p.size(); i++) {
        if (p[i] > max_len) {
            max_len = p[i];
            center_index = i;
        }
    }
    
    int start = (center_index - max_len) / 2;
    return {start, max_len};
}
```

### 时间复杂度
- 时间复杂度：O(n)
- 空间复杂度：O(n)

### 应用场景
1. 查找最长回文子串
2. 统计回文子串数量
3. 回文相关的问题

### 与其他方法的比较
- 暴力方法：O(n³)
- 动态规划：O(n²)
- 中心扩展法：O(n²)
- Manacher算法：O(n)

## 两种算法的联系与区别

### 相似点
1. 都是线性时间复杂度的字符串处理算法
2. 都利用了已计算的信息来优化后续计算
3. 都使用了"窗口"或"区间"的概念

### 不同点
1. Z函数处理前缀匹配，Manacher处理回文匹配
2. Z函数不需要预处理，Manacher需要预处理
3. Z函数更通用，Manacher专门针对回文问题

## 实际应用示例

### Z函数应用：字符串匹配
```cpp
vector<int> pattern_matching(string text, string pattern) {
    string combined = pattern + "$" + text;
    vector<int> z = z_function(combined);
    vector<int> positions;
    
    for (int i = pattern.size() + 1; i < combined.size(); i++) {
        if (z[i] == pattern.size()) {
            positions.push_back(i - pattern.size() - 1);
        }
    }
    return positions;
}
```

### Manacher应用：回文子串计数
```cpp
int count_palindromic_substrings(string s) {
    vector<int> p = manacher(s);
    int count = 0;
    
    for (int i = 0; i < p.size(); i++) {
        count += (p[i] + 1) / 2;
    }
    return count;
}
```

## 总结

Z函数和Manacher算法都是高效的字符串处理算法，各有其特定的应用场景。Z函数更适合处理前缀匹配相关的问题，而Manacher算法则是处理回文问题的最佳选择。理解这两种算法的原理和实现对于解决复杂的字符串问题非常有帮助。