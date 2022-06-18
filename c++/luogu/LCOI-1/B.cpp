#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 30000100
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

int Prime[N],tail,w[N],Pow[20],f[10],n;
bool NotPrime[N];

inline void PreWork(int n){
    NotPrime[1]=1;
    for(int i=2;i<=n;i++){
        if(!NotPrime[i]) Prime[++tail]=i,w[i]=1;;
        for(int j=1;j<=tail&&1ll*Prime[j]*i<=n;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0){
                w[i*Prime[j]]=w[i];
                break;
            }
            else w[i*Prime[j]]=w[i]+1;
        }
    }
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    PreWork(30000000);
    Pow[0]=1;for(int i=1;i<=10;i++) Pow[i]=Pow[i-1]*3;
    read(n);
    for(int i=1;i<=n;i++){
        f[w[i]%8]+=Pow[w[i]];
    }
    for(int j=0;j<=7;j++) printf("%d\n",f[j]);
    return 0;
}