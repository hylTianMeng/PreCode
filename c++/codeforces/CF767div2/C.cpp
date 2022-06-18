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

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

int cnt[N],n,a[N],t;
int ans[N],tail;
bool vis[N];
int tot,id;

inline int Find(){
    for(int i=0;i<=n;i++) if(!cnt[i]) return i; 
    return INF;
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(t);
    while(t--){
        // printf("t=%d\n",t);
        read(n);for(int i=0;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) read(a[i]),cnt[a[i]]++;
        id=1;
        while(id<=n){
            int now=Find();for(int i=0;i<=now;i++) vis[i]=0;tot=0;
            if(now==0){
                cnt[a[id]]--;ans[++tail]=0;id++;continue;
            }
            while(id<=n&&tot<now){
                cnt[a[id]]--;if(!vis[a[id]]&&a[id]<now) tot++;vis[a[id]]=1;id++;
            }
            ans[++tail]=now;
        }
        printf("%d\n",tail);
        for(int j=1;j<=tail;j++) printf("%d ",ans[j]);puts("");
        tail=0;
    }
    return 0;
}