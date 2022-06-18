#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1000100
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

int n,a[N],b[N];
ld Ans;
bool Sub1=1;

inline void Init(){
    read(n);
    for(int i=1;i<=n;i++){
        read(a[i]);if(a[i]!=i) Sub1=0;
    }
    for(int i=1;i<=n;i++){
        read(b[i]);if(b[i]!=i) Sub1=0;
    }
}

inline void BruteForce(){
    for(int i=1;i<=n;i++){
        Ans=0.0;
        for(int j=1;j<=n;j++){
            Ans+=(ld)b[i]/((ld)a[j]+(ld)b[i]);
        }
        printf("%0.10Lf ",Ans);
    }
}

inline void BruteForce2(){
    for(int i=2;i<=n+1;i++) Ans+=1.0/(ld)i;
    printf("%0.10Lf ",Ans);
    int r=n+1;
    for(int i=2;i<=n;i++){
        Ans-=1.0/(ld)i;Ans+=1.0/(ld)(r+1);r++;
        printf("%0.10Lf ",i*Ans);
    }
}

inline void Solve(){
    if(n<=5000){
        BruteForce();return;
    }
    else if(Sub1){
        BruteForce2();return;
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Solve();
    return 0;
}