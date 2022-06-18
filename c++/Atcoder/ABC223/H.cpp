#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define int long long
#define uint unsigned int
#define ull unsigned long long
#define N 66
#define M 400010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct LinearBasis{
    int b[N],ID[N];
    inline void Insert(int val,int id){
        for(int i=60;i>=0;i--){
            if(((val>>i)&1)==0) continue;
            if(!b[i]){b[i]=val;ID[i]=id;return;}
            else{
                if(ID[i]<id){swap(ID[i],id);swap(val,b[i]);}
                val^=b[i];
            }
        }
    }
    inline bool Ask(int val,int l){
        for(int i=60;i>=0;i--){
            if(((val>>i)&1)==0) continue;
            if(!b[i]||ID[i]<l) return 0;
            val^=b[i];
        }
        return 1;
    }
}LB[M];

int n,q;

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(q);
    for(int i=1;i<=n;i++){
        int x;read(x);LB[i]=LB[i-1];LB[i].Insert(x,i);
    }
    for(int i=1;i<=q;i++){
        int l,r,x;read(l);read(r);read(x);
        puts(LB[r].Ask(x,l)?"Yes":"No");
    }
    return 0;
}