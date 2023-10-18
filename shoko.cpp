#include <bits/stdc++.h>
using namespace std;

bool hg_break(int hg, int wd, int rem){
    for(int i=1; i<=rem/hg; i++){
        if((rem-hg*i)%(wd-i)==0 || rem%(wd-i)==0){
            return true;
        }
    }
  
    int mid = (int)ceil((float)wd/2);
    if(rem/hg<mid){
        for(int i=rem/hg+1; i<=mid; i++){
            if(rem%i==0 || rem%(wd-i)==0){
                return true;
            }
        }
    }
  
    return false;
}

bool wd_break(int hg, int wd, int rem){
    for(int i=1; i<=rem/wd; i++){
        if((rem-wd*i)%(hg-i)==0 || rem%(hg-i)==0){
            return true;
        }
    }
  
    int mid = (int)ceil((float)hg/2);
    if(rem/wd<mid){
        for(int i=rem/wd+1; i<=mid; i++){
            if(rem%i==0 || rem%(hg-i)==0){
                return true;
            }
        }
    }
  
    return false;
}


int main(){
    int hg, wd, rem;
    cin >> hg >> wd >> rem;
  
    if(hg*wd == rem) cout << 0;
    else if(rem%wd==0 || rem%hg==0) cout << 1;
    else if(rem<hg || rem<wd) cout << 2;
    else if(hg_break(hg, wd, rem)) cout << 2;
    else if(wd_break(hg, wd, rem)) cout << 2;
    else cout << 3;
    return 0;
}
