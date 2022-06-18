#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 300010
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

int n,q;

typedef pair<int,int> P;

struct Node{
    P a,b;
}a[N];

int cnt[N];
int vis[N];

inline void Cover(int l,int r){
    for(int i=l;i<=r;i++) vis[i]=1;
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    read(n);read(q);
    for(int i=1;i<=n;i++){
        read(a[i].a.first);read(a[i].a.second);
        read(a[i].b.first);read(a[i].b.second);
    }
    for(int i=1;i<=q;i++){
        int l,r;read(l);read(r);
        for(int i=1;i<=1000;i++) cnt[i]=0;
        for(int j=l;j<=r;j++){
            Cover(a[j].a.first,a[j].a.second);
            Cover(a[j].b.first,a[j].b.second);
            for(int i=min(a[j].a.first,a[j].b.first);i<=max(a[j].a.second,a[j].b.second);i++){
                if(vis[i]) cnt[i]++;
                vis[i]=0;
            }
        }
        // printf("cnt=%d\n",cnt[8]);
        int w=-1;
        for(int i=1;i<=1000;i++) if(cnt[i]==r-l+1){w=i;break;}
        if(w==-1) puts("NO");
        else printf("%d\n",w);
    }
    return 0;
}