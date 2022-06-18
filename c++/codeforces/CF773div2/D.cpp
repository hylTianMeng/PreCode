#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 510
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

int t,n,a[N];
map<int,int> Map;
int v[N*N];

typedef pair<int,int> P;
P ans[N*N];
int tail;
int Ans[N],at;

inline void Clear(){
    Map.clear();
    // v.clear();
    // memset(ans,0,sizeof(ans));
    // memset(Ans,0,sizeof(Ans));
    tail=0;at=0;
    for(int i=0;i<=n;i++) v[i]=0;
}

inline void Insert(int k,int x){
    ans[++tail].first=k;
    ans[tail].second=x;
    // v.insert(v.begin()+k,x);
    // v.insert(v.begin()+k,x);
    n++;
    for(int i=n;i>=k+1;i--) v[i]=v[i-1];
    v[k]=x;
    n++;
    for(int i=n;i>=k+1;i--) v[i]=v[i-1];
    v[k]=x;
}

int main(){
    // freopen("my.in","r",stdin);
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++) read(a[i]);
        for(int i=1;i<=n;i++) v[i-1]=a[i];
        for(int i=1;i<=n;i++) Map[a[i]]++;
        bool op=0;
        for(int i=1;i<=n;i++){
            if(Map[a[i]]&1){op=1;break;}
        }
        if(op){
            puts("-1");
            Clear();continue;
        }
        int w=0;
        while(w<n){
            int val=v[w];
            int p=-1;
            for(int i=w+1;i<n;i++){
                if(v[i]==val){p=i;break;}
            }
            int now=p;
            at++;Ans[at]=1;
            while(w<now-1){
                if(p<n&&v[w+1]==v[p+1]){
                    Ans[at]++;
                    w++;p++;continue;
                }
                // printf("p=%d x=%d\n",p+1,v[w+1]);
                Insert(p+1,v[w+1]);
                assert(v[w+1]==v[p+1]);
                w++;p++;
                Ans[at]++;
                // for(int i=0;i<=n;i++) printf("%d ",v[i]);puts("");
            }
            Ans[at]*=2;
            w=p+1;
        }
        printf("%d\n",tail);
        for(int i=1;i<=tail;i++){
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
        printf("%d\n",at);
        for(int i=1;i<=at;i++){
            // printf("i=%d\n",i);
            printf("%d ",Ans[i]);
        }
        puts("");
        Clear();
    }
}