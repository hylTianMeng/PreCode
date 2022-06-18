#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

int a[N],n;

bool vis[N];

inline int GetMex(){
    for(int i=0;i<=n;i++) vis[i]=0;
    for(int i=0;i<n;i++) vis[a[i]]=1;
    for(int j=0;j<=n;j++){
        if(!vis[j]) return j;
    }
    assert(0);
}

int ans[N<<1],tail,t;

inline bool Check(){
    for(int i=0;i<n;i++) if(a[i]!=i) return 0;
    return 1;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        read(n);for(int i=0;i<n;i++) read(a[i]);
        tail=0;
        while(!Check()){
            int now=GetMex();
            // printf("now=%d\n",now);
            if(now==n){
                for(int i=0;i<n;i++) if(a[i]!=i){ans[++tail]=i;a[i]=n;break;}
            }
            else{
                ans[++tail]=now;a[now]=now;
            }
            // for(int i=0;i<n;i++) printf("%d ",a[i]);puts("");
            // cin.get();
        }
        printf("%d\n",tail);
        for(int i=1;i<=tail;i++) printf("%d ",ans[i]+1);
        puts("");
    }
    return 0;
}