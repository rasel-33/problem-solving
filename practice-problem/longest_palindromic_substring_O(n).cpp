#include <bits/stdc++.h>
using namespace std;

#define EPS          1E-9
#define PI           acos(-1)
#define N            1000006
#define M            1000000007
#define fast         ios::sync_with_stdio();cin.tie(0)
#define all(v)       (v).begin(), (v).end()
#define ll           long long
#define f0(i, n)     for(int (i) = 0; i <  (n); i++)
#define f1(i, n)     for(int (i) = 1; i <= (n); i++)
#define endl         "\n"
#define pb           push_back
#define base         179
#define UNIQUE(v)    (v).erase(unique(all(v)), (v).end())

int dx[] = { -1,+0,+1,+0,-1,-1,+1,+1};
int dy[] = { +0,-1,+0,+1,+1,-1,+1,-1};

// longest palindromic substring
// O(n) time and O(n) space

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";
    string t = "$#";
    for (int i = 0; i < n; i++) {
        t += s[i];
        t += '#';
    }
    n = t.size();
    t += '!';
    vector<int> p(n, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n; i++) {
        int i_mirror = 2 * c - i;
        p[i] = (r > i) ? min(r - i, p[i_mirror]) : 0;
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
}
