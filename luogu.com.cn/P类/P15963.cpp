#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is_leap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return year % 4 == 0;
}

bool is_cute(int year, int month, int day)
{
    string str_date = to_string(year) + to_string(month) + to_string(day);
    vector<int> freq(10, 0);

    for (char ch : str_date) {
        freq[ch - '0']++;
    }

    int target_freq = -1;
    for (int count : freq) {
        if (count > 0) {
            if (target_freq == -1) {
                target_freq = count;
            } else if (target_freq != count) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year = 2239;
    int month = 9;
    int day = 9;
    int total_cute = 0;

    while (true) {
        if (is_cute(year, month, day)) {
            total_cute++;
        }

        if (year == 9876 && month == 1 && day == 1) {
            break;
        }

        day++;
        int max_day = 31;

        if (month == 4 || month == 6 || month == 9 || month == 11) {
            max_day = 30;
        } else if (month == 2) {
            if (is_leap(year)) {
                max_day = 29;
            } else {
                max_day = 28;
            }
        }

        if (day > max_day) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    cout << total_cute << "\n";

    return 0;
}