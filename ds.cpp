#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll factor_sum(ll a){
    ll sum = 0;
    for(ll i = 1; i <= sqrt(a); i++){
        sum += i * (a / i - (i - 1));
        sum += (((a / i) * (a / i + 1) / 2) - ((i * (i + 1)) / 2));
    }
    return sum;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << factor_sum(b) - factor_sum(a-1);
    return 0;
}
