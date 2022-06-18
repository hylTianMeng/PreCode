#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 20000100
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

uint seed,a[N],ans;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}

int n,Prime[N],tail;
bool NotPrime[N];

inline void GetPrime(){
    for(int i=2;i<=n;i++){
        if(!NotPrime[i]) Prime[++tail]=i;
        for(int j=1;j<=tail&&1ll*Prime[j]*i<=n;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0) break;
        }
    }
}

int main(){
    read(n);read(seed);GetPrime();
    for(int i=1;i<=n;i++){
        a[i]=getnext();
    }
    for(int i=1;i<=tail;i++){
        for(int j=1;1ll*j*Prime[i]<=n;j++){
            a[j*Prime[i]]+=a[j];
        }
    }
    for(int i=1;i<=n;i++) ans^=a[i];
    printf("%u",ans);
    return 0;
}