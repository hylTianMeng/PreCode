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

int fa[N],n,m,d[N];

vector<int> v[N],c1,c2;
int ad[N],tot;

inline int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}

inline bool PreWork(){
    read(n);read(m);
    for(int i=1;i<=n;i++) read(d[i]);
    for(int i=1;i<=n;i++) fa[i]=i;
    bool op=1;
    tot=n;
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        d[from]--;d[to]--;
        int faf=Find(from),fato=Find(to);
        if(faf==fato){
            op=0;continue;
        }
        fa[faf]=fato;
        tot--;
    }
    return op;
}

typedef pair<int,int> P;
vector<P> Ans;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    if(!PreWork()){
        puts("-1");return 0;
    }
    for(int i=1;i<=n;i++)
        if(d[i]<0){
            // printf("here1\n");
            puts("-1");return 0;
        }
    for(int i=1;i<=n;i++){
        if(d[i]==0) continue;
        v[Find(i)].push_back(i);
        ad[Find(i)]+=d[i];
    }
    for(int i=1;i<=n;i++){
        // printf("i=%d ad[i]=%d\n",i,ad[i]);
        if(ad[i]>1) c2.push_back(i);
        else if(ad[i]>0) c1.push_back(i);
    }
    // printf("tot=%d\n",tot);
    while(c2.size()){
        int s=c2[(int)c2.size()-1];
        // printf("s=%d\n",s);
        for(int j=(int)v[s].size()-1;j>=0;j--){
            // printf("Point: %d\n",v[s][j]);

            while(d[v[s][j]]){
                if(j==0&&d[v[s][j]]==1){
                    c1.push_back(s);break;
                }
                if(c1.empty()){
                    // printf("here2\n");
                    puts("-1");return 0;
                }
                int t=c1[(int)c1.size()-1];
                c1.pop_back();fa[t]=s;
                Ans.push_back(make_pair(v[t][0],v[s][j]));
                d[v[t][0]]--;d[v[s][j]]--;if(d[v[s][j]]==0) v[s].pop_back();
                tot--;
            }


        }
        c2.pop_back();
    }
    // printf("c1=%d\n",c1.size());
    // printf("tot=%d\n",tot);
    if(c1.size()==2&&tot==2){
        int a=c1[0],b=c1[1];
        Ans.push_back(make_pair(v[a][0],v[b][0]));
        for(P now:Ans){
            printf("%d %d\n",now.first,now.second);
        }
    }
    else{
        // printf("here3\n");
        puts("-1");return 0;
    }
    return 0;
}