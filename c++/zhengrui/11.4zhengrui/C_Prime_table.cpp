#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100100
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

int Prime[N],tail;
bool NotPrime[N];

inline void GetPrime(int n){
    NotPrime[1]=1;
    for(int i=2;i<=n;i++){
        if(!NotPrime[i]) Prime[++tail]=i;
        for(int j=1;j<=tail&&Prime[j]*i<=n;j++){
            NotPrime[Prime[j]*i]=1;
            if(i%Prime[j]==0) break;
        }
    }
}

int main(){
    
}