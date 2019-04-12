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
    int n, k;
    bitset<15> bits[101];
    int min = 0x3f3f3f3f;
    int minn;
    while(cin >> n >> k){
        for(int i = 0; i < n; i++) {
            cin >> bits[i];
        }
        for(int i = 0; i < pow(2, k); i++) {
            bitset<15> temp(i);
            int max = 0;
            for(int j = 0; j < n; j++) {
                bitset<15> ans = temp ^ bits[j];
                if(ans.count() > max)
                    max = ans.count();
            }
            if (max < min) {
                min = max;
                minn = i;
            } else if (max == min){
                bitset<15> now(i);
                bitset<15> last(minn);
                if(now.to_string() < last.to_string()) {
                    minn = i;
                }
            }
        }
        bitset<15> ans(minn);
        string s =  ans.to_string();
        for(int i = 15 - k; i < 15; i++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
