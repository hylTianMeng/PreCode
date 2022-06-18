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

int t,n,a,b,c,cha,d;

inline void Init(){read(n);}
inline void Ask(int l,int r){printf("? %lld %lld\n",l,r);cout.flush();}
inline void Print(int i,int j,int k){printf("! %lld %lld %lld\n",i,j,k);cout.flush();}

inline int F(int a){
    return (1+(int)sqrt(1+8*a))/2;
}

inline bool Check(int mid){
    Ask(1,mid);read(b);
    return b==0;
}

inline void Solve(){
    Ask(1,n);read(a);
    int l=1,r=n,I=l,J,K;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Check(mid)){I=mid;l=mid+1;}else r=mid-1;
    }
    Ask(I+1,n);read(c);
    cha=a-c;J=cha+I+1;
    cha=a-(J-I)*(J-I-1)/2;
    d=F(cha);K=J+d-1;
    Print(I,J,K);

}

signed main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        Init();Solve();
    }
}