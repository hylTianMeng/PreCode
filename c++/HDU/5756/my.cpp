#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N number
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

struct Node{
    int val,ls,rs;
    inline Node(){}
    inline Node(int val,int ls,int rs) : val(val),ls(ls),rs(rs) {}
};

int Root[N],tot;

struct SegmentTree{
    inline int NewNode(){return ++tot;}
    inline void Add(int k,int l,int r,int z,int y,int x){

    }
    inline int Ask(int k,int l,int r,int z,int y){
        if(l==z&&r==y) return p[k].val;
        int mid=(l+r)>>1;
        if(y<=mid) return Ask(ls(k),l,mid,z,y);
        else if(z>mid) return Ask(rs(k),mid+1,r,z,y);
        else return A
    }
};

int main(){

}