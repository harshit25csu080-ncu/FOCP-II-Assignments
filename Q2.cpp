#include <iostream>
#include <string>
using namespace std;

int countOps(string &bulbs, int n, int l) {
    int ops = 0;
    int i = 0;
    while (i < n) {
        if (bulbs[i] == '1') {
            ops++;
            i += l;
        } else {
            i++;
        }
    }
    return ops;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int lo = 1, hi = n, ans = n;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (countOps(bulbs, n, mid) <= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
