#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string solve(int n, vector<int>& a) {
    set<int> s(a.begin(), a.end());
    vector<int> v(s.begin(), s.end());
    sort(v.rbegin(), v.rend());

    long long alex = 0, bob = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        if (i % 2 == 0)
            alex += v[i];
        else
            bob += v[i];
    }

    return alex > bob ? "Alex" : "Bob";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(n, a) << "\n";
    }
    return 0;
}
