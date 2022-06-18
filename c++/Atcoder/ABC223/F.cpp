#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 2000100
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

int n,m;
char s[N];

struct Node{
    int lt,rt;
    inline Node(){lt=0;rt=0;}
    inline Node operator + (const Node &b)const{
        Node a;a.lt=a.rt=0;
        a.rt=rt;a.lt=b.lt;
        if(lt<b.rt) a.rt+=b.rt-lt;
        else a.lt+=lt-b.rt;
        return a;
    }
}p[N<<2];

#define ls k<<1
#define rs k<<1|1
struct SegmentTree{
    inline void PushUp(int k){
        // if(p[ls].lt==p[rs].rt){p[k].rt=p[ls].rt;p[k].lt=p[rs].lt;}
        // else if(p[ls].lt<p[rs].rt){p[k].rt=p[ls].rt+p[rs].rt-p[ls].lt;p[k].lt=p[rs].lt;}
        // else{p[k].rt=p[ls].rt;p[k].lt=p[ls].lt-p[rs].rt+p[rs].lt;}
        p[k]=p[ls]+p[rs];
    }
    inline void Build(int k,int l,int r){
        if(l==r){
            if(s[l]=='(') p[k].lt++;
            else p[k].rt++;return;
        }
        int mid=(l+r)>>1;
        Build(ls,l,mid);Build(rs,mid+1,r);
        PushUp(k);
    }
    inline void Change(int k,int l,int r,int w){
        if(l==r){
            p[k].lt^=1;p[k].rt^=1;return;
        }
        int mid=(l+r)>>1;
        if(w<=mid) Change(ls,l,mid,w);
        else Change(rs,mid+1,r,w);
        PushUp(k);
    }
    inline Node Ask(int k,int l,int r,int z,int y){
        if(l==z&&r==y){return p[k];}
        int mid=(l+r)>>1;
        if(y<=mid) return Ask(ls,l,mid,z,y);
        else if(z>mid) return Ask(rs,mid+1,r,z,y);
        else return Ask(ls,l,mid,z,mid)+Ask(rs,mid+1,r,mid+1,y);
    }
}st;

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    read(n);read(m);
    scanf("%s",s+1);
    st.Build(1,1,n);
    for(int i=1;i<=m;i++){
        int op,l,r;read(op);read(l);read(r);
        if(op==1){
            if(s[l]==s[r]) continue;
            swap(s[l],s[r]);
            st.Change(1,1,n,l);st.Change(1,1,n,r);
        }
        else{
            Node ans=st.Ask(1,1,n,l,r);
            if(ans.lt==0&&ans.rt==0){
                puts("Yes");
            }
            else puts("No");
        }
    }
    return 0;
}