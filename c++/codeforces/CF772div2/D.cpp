#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 200010
#define M number
using namespace std;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int n,p,a[N],f[N];
int ans=0;
map<int,bool> Map;

int main(){
    read(n);read(p);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    f[1]=1;f[0]=1;
    for(int i=2;i<=p;i++){
        f[i]=(f[i-2]+f[i-1])%mod;
    }
    for(int i=1;i<=p;i++) f[i]=(f[i]+f[i-1])%mod;
    for(int i=1;i<=n;i++){
        int w=0;
        if(Map[a[i]]) continue;
        Map[a[i]]=1;

        int x=a[i];
        while(x){w++;x>>=1;}

        bool op=0;
        while(1){
            if((a[i]&3)==0&&a[i]>=3){a[i]>>=1;a[i]>>=1;if(Map[a[i]]){op=1;break;}}
            else if(a[i]&1){a[i]>>=1;if(Map[a[i]]){op=1;break;}}
            else break;
        }        
        if(op) continue;

        if(p>=w){
            ans=(ans+f[p-w])%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}