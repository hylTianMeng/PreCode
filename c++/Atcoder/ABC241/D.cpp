#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N number
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

multiset<int> S;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        int op,x,k;
        read(op);read(x);
        if(op==1){
            S.insert(x);
        }
        else if(op==2){
            read(k);
            auto now=S.upper_bound(x);
            if(now==S.begin()){
                puts("-1");continue;
            }
            now--;
            k--;
            while(k&&now!=S.begin()){
                now--;k--;
            }
            if(k){
                puts("-1");
            }
            else printf("%lld\n",(*now));
        }
        else{
            read(k);
            auto now=S.lower_bound(x);
            if(now==S.end()){
                puts("-1");continue;
            }
            k--;
            while(k&&(now)!=(--S.end())){
                k--;now++;
            }
            if(k){
                puts("-1");
            }
            else printf("%lld\n",(*now));
        }
    }
}