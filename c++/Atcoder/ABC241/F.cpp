#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 400010
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

int n,m,k;
vector<int> v[N],v2[N];
typedef pair<int,int> P;
int sx,sy,tx,ty,xx[N],yy[N],xxx[N],yyy[N];;
map<P,int> Map;

queue<P> q;

inline void bfs(){
    q.push(make_pair(sx,sy));
    Map[make_pair(sx,sy)]=1;

    while(q.size()){
        P now=q.front();q.pop();
        int a=now.first,b=now.second;
        // printf("%d %d\n",now.first,now.second);
        if(v[a].size()){
            auto l=upper_bound(v[a].begin(),v[a].end(),b);
            if(l==v[a].begin()){
                if(!Map[make_pair(a,*l-1)]){
                    Map[make_pair(a,*l-1)]=Map[now]+1;
                    q.push(make_pair(a,*l-1));
                }

            }
            else{
                auto r=l;l--;
                if(r!=v[a].end()){
                    // dfs(a,*r-1,tot+1);
                    if(!Map[make_pair(a,*r-1)]){
                        Map[make_pair(a,*r-1)]=Map[now]+1;
                        q.push(make_pair(a,*r-1));
                    }
                }
                // dfs(a,*l+1,tot+1);
                if(!Map[make_pair(a,*l+1)]){
                    Map[make_pair(a,*l+1)]=Map[now]+1;
                    q.push(make_pair(a,*l+1));
                }

            }
        }
        if(v2[b].size()){
            auto l=upper_bound(v2[b].begin(),v2[b].end(),a);
            if(l==v2[b].begin()){
                // dfs(*l-1,b,tot+1);
                if(!Map[make_pair(*l-1,b)]){
                    Map[make_pair(*l-1,b)]=Map[now]+1;
                    q.push(make_pair(*l-1,b));
                }
            }
            else{
                auto r=l;l--;
                if(r!=v2[b].end()){
                    // dfs(*r-1,b,tot+1);
                    if(!Map[make_pair(*r-1,b)]){
                        Map[make_pair(*r-1,b)]=Map[now]+1;
                        q.push(make_pair(*r-1,b));
                    }

                }
                // dfs(*l+1,b,tot+1);
                if(!Map[make_pair(*l+1,b)]){
                    Map[make_pair(*l+1,b)]=Map[now]+1;
                    q.push(make_pair(*l+1,b));
                }
            }
        }
    }    
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    // puts("-1");
    read(n);read(m);read(k);
    read(sx);read(sy);read(tx);read(ty);
    for(int i=1;i<=k;i++){
        int x,y;read(x);read(y);
        // v[x].push_back(y);v2[y].push_back(x);
        xx[i]=x;yy[i]=y;xxx[i]=x;yyy[i]=y;
    }
    int nowk=k;
    k++;xxx[k]=sx;yyy[k]=sy;
    k++;xxx[k]=tx;yyy[k]=ty;
    for(int i=1;i<=nowk;i++){
        ++k;
        xxx[k]=xx[i]-1;
        yyy[k]=yy[i]-1;
        ++k;
        xxx[k]=xx[i]+1;
        yyy[k]=yy[i]+1;
    }
    sort(xxx+1,xxx+1+k);sort(yyy+1,yyy+k+1);
    int len1=unique(xxx+1,xxx+1+k)-xxx-1;
    int len2=unique(yyy+1,yyy+k+1)-yyy-1;
    for(int i=1;i<=nowk;i++){
        xx[i]=lower_bound(xxx+1,xxx+len1+1,xx[i])-xxx;
        yy[i]=lower_bound(yyy+1,yyy+len2+1,yy[i])-yyy;
        // printf("%d %d\n",xx[i],yy[i]);
        v[xx[i]].push_back(yy[i]);
        v2[yy[i]].push_back(xx[i]);
    }
    sx=lower_bound(xxx+1,xxx+len1+1,sx)-xxx;
    sy=lower_bound(yyy+1,yyy+len2+1,sy)-yyy;
    tx=lower_bound(xxx+1,xxx+len1+1,tx)-xxx;
    ty=lower_bound(yyy+1,yyy+len2+1,ty)-yyy;
    // v[sx].push_back(sy);v2[sy].push_back(sx);
    // printf("sx=%d sy=%d tx=%d ty=%d\n",sx,sy,tx,ty);

    for(int i=1;i<=k;i++){
        sort(v[i].begin(),v[i].end());
    }
    for(int i=1;i<=k;i++){
        sort(v2[i].begin(),v2[i].end());
    }
    bfs();
    if(Map[make_pair(tx,ty)]){
        assert(Map[make_pair(tx,ty)]>=0);
        printf("%d\n",Map[make_pair(tx,ty)]-1);
    } 
    else puts("-1");
    return 0;
}