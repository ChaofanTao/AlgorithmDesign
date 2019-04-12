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
    long long n;
    while(cin >> n){
        if(n % 2 == 0) {
            cout << n / 2 << endl;
        } else {
            int mis = 0;
            for(long long i = 3; i * i <= n; i++) {
                if (n % i == 0) {
                    mis = i;
                    break;
                }  
            }
            if(mis == 0) {
                cout << 1 << endl;
            } else {
                cout << (n - mis) / 2 + 1 << endl;
            }
        }
        
    }
    return 0;
}
