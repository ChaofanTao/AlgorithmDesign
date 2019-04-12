#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<cstring>
#include<bitset>
#include<cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n >> m >> k >> t){
        if(k >= n) {
            cout << m * t << endl;
        } else {
            int tot = n * m * t;
            if(tot % k== 0) {
                cout << tot / k << endl;
            } else {
                cout << tot / k + t << endl;
            }
        }
    }
    return 0;
}
