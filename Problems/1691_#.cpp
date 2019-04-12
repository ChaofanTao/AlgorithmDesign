#include <iostream>
using namespace std;
#define V 1000
int weight[50 + 1];
int value[50 + 1];
int num[20 + 1];
int f[V + 1];
//有效，但超时间了 
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i] >> num[i];
    }
    int k = n + 1;
    for (int i = 1; i <= n; i++) {
        while (num[i] != 1) {
            weight[k] = weight[i];
            value[k] = value[i];
            k++;
            num[i]--;
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = m; j >= 1; j--) {
            if (weight[i] <= j) f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
    }
    cout<< f[m] << endl;
}
