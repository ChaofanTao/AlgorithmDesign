#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include<bits/stdc++.h> 
using namespace std;

int ans[1000010], n, a;
pair<int, int> g[1000010];

int main() {
    while (scanf("%d", &n) != EOF) {
        memset(ans, 0, sizeof(ans));
        int maxa = -1, tot = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            maxa = max(a, maxa);
            for (int k = 1; k <= sqrt(a) + 0.5; k++) {
                if (a % k == 0) ans[k] += 1;
                if (a % k == 0 and a / k != k) ans[a / k] += 1;
            }
        }
        for (int i = 1; i <= maxa; i++) {
            if (ans[i] != 0) g[tot++] = make_pair(ans[i], i);
        }
        sort(g, g + tot);
        int las = 1;
        for (int i = 0; i < tot; i++) {
            if (i == tot - 1 || g[i].first != g[i + 1].first) {
                while (las <= g[i].first) {
                    ans[las] = g[i].second;
                    las += 1;
                }
            }
        }
        while (las <= n) ans[las++] = 1;
        for (int i = 1; i <= n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}


