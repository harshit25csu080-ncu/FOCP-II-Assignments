#include <stdio.h>
#include <string.h>

// For a given window size l, count minimum operations needed
int countOps(char *bulbs, int n, int l) {
    int ops = 0;
    int i = 0;
    while (i < n) {
        if (bulbs[i] == '1') {
            ops++;
            i += l;  // skip the whole window we just turned off
        } else {
            i++;
        }
    }
    return ops;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char bulbs[100005];
    scanf("%s", bulbs);

    // Binary search on l
    int lo = 1, hi = n, ans = n;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (countOps(bulbs, n, mid) <= k) {
            ans = mid;
            hi = mid - 1;  // try smaller l
        } else {
            lo = mid + 1;  // need bigger l
        }
    }

    printf("%d\n", ans);
    return 0;
}
