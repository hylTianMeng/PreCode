#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define int long long
#define ull unsigned long long
#define N 3000100
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

int n,q,a[N];

inline int F(int c,int x){
    return ((x+c-1)/c+1)*c;
}

namespace Subtask1{
    inline void Solve(){
        for(int i=1;i<=n;i++) a[i]=i;
        for(int i=1;i<=q;i++){
            int op,l,r;read(op);read(l);read(r);
            if(op==1){
                reverse(a+l,a+r+1);
            }
            else{
                for(int k=l;k<=n;k++){
                    r=F(a[k],r);
                    // printf("r=%lld\n",r);
                }
                printf("%lld\n",r);
            }
        }
    }
}

namespace Subtask2{
    inline void Solve(){
        int c=0;
        for(int i=1;i<=n;i++) c=F(a[i],c);
        for(int i=1;i<=q;i++) printf("%lld\n",c);
    }
}

signed main(){
    freopen("machine.in","r",stdin);
    freopen("machine.out","w",stdout);
    read(n);read(q);
    if(n<=5000){
        Subtask1::Solve();
        return 0;
    }
    Subtask2::Solve();
}