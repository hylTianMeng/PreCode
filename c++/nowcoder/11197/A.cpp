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

inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int n,a[N],cnt[N],ans;

int main(){
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=1;i<=1000001;i++){
        int tot=0;
        for(int j=i;j<=1000001;j+=i){
            tot+=cnt[j];
            if(i!=1) tot+=cnt[j-1];
        }
        if(tot==n){
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}