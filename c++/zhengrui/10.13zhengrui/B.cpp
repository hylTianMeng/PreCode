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

template<typename T> inline T Max(T a,T b){return a<b?b:a;}

struct Trie{
    int ch[N][2],tot;
    inline void Insert(int x){
        int p=0;
        for(int i=20;i>=0;i--){
            int digit=(x>>i)&1;
            if(!ch[p][digit]) ch[p][digit]=++tot;
            p=ch[p][digit];
        }
    }
    inline int Query1(int x){
        int p=0,maxx=0;
        for(int i=20;i>=0;i--){
            int digit=(x>>i)&1;
            if(ch[p][digit^1]){p=ch[p][digit^1];maxx+=(1<<i);}
            else p=ch[p][digit];
        }
        return maxx;
    }
}tr;

int q;
bool vis[N];

inline int Digit(int x){
    int cnt=0;for(;x;x&=(x-1)) cnt++;
    return cnt;
}

inline int lowbit(int x){return x&(-x);}

inline void dfs(int x,int w){
    int now=x;
    for(int i=1;i<=w;i++){
        int val=lowbit(now);now-=val;
        int nowx=x^val;
        if(vis[nowx]) continue;
        vis[nowx]=1;
        dfs(nowx,w-1);
    }
}

inline void Signed(int x){
    // printf("x=%d\n",x);
    if(vis[x]) return;vis[x]=1;
    dfs(x,Digit(x));
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(q);
    for(int i=1;i<=q;i++){
        int op,a;read(op);read(a);
        if(op==1){
            tr.Insert(a);Signed(a);
        }
        else if(op==2){
            int ans1=0,ans2=0,ans3=tr.Query1(a);
            for(int i=20;i>=0;i--){
                if(((a>>i)&1)==0) continue;
                else{
                    if(vis[ans1|(1<<i)]){
                        ans1|=(1<<i);
                    }
                }
            }
            ans1&=a;
            for(int i=20;i>=0;i--){
                if((a>>i)&1) continue;
                else{
                    if(vis[ans2|(1<<i)]){
                        ans2|=(1<<i);
                    }
                }
            }
            // printf("ans2=%d\n",ans2);
            ans2|=a;
            printf("%d %d %d\n",ans3,ans1,ans2);
        }
        else if(op==3){
            printf("%d\n",tr.Query1(a));
        }
    }
}
/*
1026909 201744 1032061
879724 984162 1048062
655316 682376 1043962
649621 683464 1048571
926039 85160 1011199
*/