#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 100010
#define M 200010
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
template<typename T> inline T Min(T a,T b){return a<b?a:b;}

struct edge{
    int to,next;
    inline void Init(int to_,int ne_){
        to=to_;next=ne_;
    }
}li[M];
int head[N],tail;

inline void Add(int from,int to){
    li[++tail].Init(to,head[from]);
    head[from]=tail;
}

struct Node{
    int val,id;
    inline Node(){}
    inline Node(int val,int id) : val(val),id(id) {}
};
vector<Node> P[N];

int n,m,Q,Len;

inline void Init(){
    read(n);read(m);read(Q);
    for(int i=1;i<=m;i++){
        int from,to;read(from);read(to);
        Add(to,from);
    }
    Len=100;
//    printf("%d\n",ques[Q].T);
//    printf("Len=%d\n",Len);

}

bool Vis[N];

inline vector<Node> Merge(int a,int b){
//    printf("a=%d b=%d\n",a,b);
    vector<Node> res;vector<Node>().swap(res);
    int ia=0,ib=0,cnt=0;
//    printf("ia=%d ib=%d\n",ia,ib);
    while(cnt<Len&&(ia!=(int)P[a].size()||ib!=(int)P[b].size())){
        Node nowa(-INF,-INF),nowb(-INF,-INF);
        if(ia!=(int)P[a].size()){nowa=P[a][ia];nowa.val++;}if(ib!=(int)P[b].size()){nowb=P[b][ib];}
//        printf("nowa.id=%d nowa.val=%d nowb.id=%d nowb.val=%d\n",nowa.id,nowa.val,nowb.id,nowb.val);
        if(ia!=(int)P[a].size()&&Vis[nowa.id]){ia++;continue;}if(ib!=(int)P[b].size()&&Vis[nowb.id]){ib++;continue;}
        if(nowa.val<nowb.val){res.push_back(nowb);ib++;Vis[nowb.id]=1;}
        else{res.push_back(nowa);ia++;Vis[nowa.id]=1;}cnt++;
    }
    for(Node x:res) Vis[x.id]=0;
	return res;
}

inline void Print(int i){
	printf("i=%d:\n",i);for(Node x:P[i]) printf("id=%d val=%d\n",x.id,x.val);puts("");
}

inline void PreWork(){
    for(int i=1;i<=n;i++){
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;P[i]=Merge(to,i);
        }
        int now=P[i].size();
        if(now<Len){P[i].push_back(Node(0,i));}
    }
//    for(int i=1;i<=n;i++){
//        printf("i=%d:\n",i);for(Node x:P[i]) printf("id=%d val=%d\n",x.id,x.val);puts("");
//    }
//	Print(17861);
}

int f[N],T;
vector<int> Y;

inline void Dp(){
    fill(f+1,f+n+1,-1);int k=T;f[k]=0;
    for(int x:Y) Vis[x]=1;
    for(int i=k;i>=1;i--){
        if(f[i]==-1) continue;
        for(int x=head[i];x;x=li[x].next){
            int to=li[x].to;f[to]=Max(f[to],f[i]+1);
        }
    }
    int Ans=-1;for(int i=1;i<=n;i++) if(!Vis[i]) Ans=Max(Ans,f[i]);
    for(int x:Y) Vis[x]=0;
    printf("%d\n",Ans);
}

inline void GetAns(){
    int k=T;
    for(int x:Y) Vis[x]=1;
    int Ans=-1;
    for(int i=0;i<(int)P[k].size();i++) if(!Vis[P[k][i].id]){Ans=P[k][i].val;break;}
    for(int x:Y) Vis[x]=0;printf("%d\n",Ans);
}

inline void Solve(){
    for(int i=1;i<=Q;i++){
    	read(T);vector<int>().swap(Y);int y;read(y);
		for(int i=1;i<=y;i++){int x;read(x);Y.push_back(x);}
        if((int)Y.size()>=Len){/*printf("Enter 1\n");*/Dp();}
        else{/*printf("Enter 2\n");*/GetAns();}
    }
}

int main(){
//    freopen("my.in","r",stdin);
//    freopen("my.out","w",stdout);
    Init();PreWork();Solve();return 0;
}