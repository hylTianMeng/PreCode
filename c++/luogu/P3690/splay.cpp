#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 3000000
#define M number
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T>  inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct point{
    int size,cnt,val,ch[2],fa;
};
point p[N];

struct Splay{
    int root,tot;
    inline void pushup(int k){
        p[k].size=p[p[k].ch[0]].size+p[p[k].ch[1]].size+p[k].cnt;
    }
    inline void clear(int k){
        p[k].size=p[k].ch[0]=p[k].cnt=p[k].ch[1]=p[k].val=p[k].fa=0;
    }
    inline int get(int k){
        return k==p[p[k].fa].ch[1];
    }
    inline void rotate(int k){
        int y=p[k].fa,z=p[y].fa,which=get(k),which2=get(y);
        p[y].ch[which]=p[k].ch[which^1];
        if(p[y].ch[which]) p[p[y].ch[which]].fa=y;
        p[k].ch[which^1]=y;
        if(z) p[z].ch[which2]=k;
        p[y].fa=k;p[k].fa=z;
        pushup(y);pushup(k);
    }
    inline void splay(int k){
        for(int fa=p[k].fa;fa;rotate(k),fa=p[k].fa){
            if(p[fa].fa) rotate(get(fa)==get(k)?fa:k);
        }
        root=k;
    }
    inline void new_node(int val){
        ++tot;p[tot].val=val;p[tot].size=1;p[tot].cnt=1;
    }
    inline void insert(int val){
        if(!root){
            new_node(val);root=tot;
            return;
        }
        int k=root,fa=0;
        while(1){
            if(p[k].val==val){
                p[k].cnt++;pushup(k);pushup(fa);
                splay(k);break;
            }
            fa=k;k=p[k].ch[p[k].val<val];
            if(!k){
                new_node(val);p[fa].ch[p[fa].val<val]=tot;
                p[tot].fa=fa;pushup(tot);pushup(fa);splay(tot);break;
            }
        }
    }
    inline int getrank(int val){
        int rank=0,k=root;
        while(k)
            if(val<p[k].val) k=p[k].ch[0];
            else{
                rank+=p[p[k].ch[0]].size;
                if(val==p[k].val){
                    splay(k);return rank+1;   
                }
                rank+=p[k].cnt;k=p[k].ch[1];
            }
        return INF;
    }
    inline int getval(int rank){
        int k=root;
        while(k)
            if(rank<=p[p[k].ch[0]].size) k=p[k].ch[0];
            else{
                rank-=p[p[k].ch[0]].size+p[k].cnt;
                if(rank<=0){
                    splay(k);return p[k].val;
                }
                k=p[k].ch[1];
            }
        return INF;
    }
    inline int getpre(){
        int k=p[root].ch[0];
        if(!k) return INF;
        while(p[k].ch[1]) k=p[k].ch[1];
        splay(k);return k;
    }
    inline int getnext(){
        int k=p[root].ch[1];
        if(!k) return INF;
        while(p[k].ch[0]) k=p[k].ch[0];
        splay(k);return k;
    }
    inline void delete_(int k){
        getrank(k);
        if(p[root].cnt>1){
            p[root].cnt--;pushup(root);return;
        }
        if(!p[root].ch[0]&&!p[root].ch[1]){
            clear(root);root=0;return;
        }
        if(p[root].ch[0]==0||p[root].ch[1]==0){
            int which=p[root].ch[0]==0?0:1,now=root;
            root=p[root].ch[which^1];p[root].fa=0;clear(now);return;
        }
        int now=root,pre=getpre();
        p[p[now].ch[1]].fa=pre;
        p[pre].ch[1]=p[now].ch[1];
        clear(now);pushup(root);
    }
};
Splay sp;

int n;

int main(){
    read(n);
    for(int i=1;i<=n;i++){
        int op,x;read(op);read(x);
        if(op==1) sp.insert(x);
        else if(op==2) sp.delete_(x);
        else if(op==3) printf("%d\n",sp.getrank(x));
        else if(op==4) printf("%d\n",sp.getval(x));
        else if(op==5) sp.insert(x),printf("%d\n",p[sp.getpre()].val),sp.delete_(x);
        else if(op==6) sp.insert(x),printf("%d\n",p[sp.getnext()].val),sp.delete_(x);
    }
}
