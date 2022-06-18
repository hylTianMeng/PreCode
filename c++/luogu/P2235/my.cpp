#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 1010
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

struct Bignum{
    int num[N],size;
    inline void Carry(int k){num[k+1]+=num[k]/10;num[k]%=10;}
    inline Bignum(){memset(num,0,sizeof(num));size=1;}
    inline Bignum operator + (const Bignum &b)const{
        Bignum c;c.size=Max(size,b.size);
        for(int i=1;i<=c.size;i++){
            c.num[i]+=num[i]+b.num[i];c.Carry(i);
        }if(c.num[c.size+1]) c.size++;
        return c;
    }
    inline void operator += (const Bignum &b){(*this)=(*this)+b;}
    inline void Ry(){
        for(int i=size;i>=1;i--){
            if(num[i]&1) num[i-1]+=10;num[i]>>=1;
        }
        num[0]=1;
        if(!num[size]&&size>1) size--;
    }
    inline void Ly(){
        for(int i=size;i>=1;i--){
            num[i]<<=1;(*this).Carry(i);
        }
        if(num[size+1]) size++;
    }
    inline bool Parity(){return num[1]&1;}
    inline void Init(char *s,int len){
        for(int i=1;i<=len;i++) num[i]=s[len-i+1]-'0';
        size=len;
    }
    inline bool Empty(){return num[1]==0&&size==1;}
    inline void Print(){
        for(int i=size;i>=1;i--) printf("%d",num[i]);
        puts("");
    }
}m,f[N][2],I,now,Ans;

int b[N],lenb,len,up,upp,c[N];
char s[N];
bool op,pd;

inline void Init(){
    scanf("%s",s+1);len=strlen(s+1);m.Init(s,len);
    if(m.size==1&&m.num[1]==1) pd=1;
    while(!m.Empty()){
        if(m.Parity()) b[++lenb]=1;else b[++lenb]=0;
        m.Ry();
    }
    I.size=1;I.num[1]=1;
    // for(int i=lenb;i>=1;i--) printf("%d",b[i]);puts("");
}

inline void Dp(){
    f[lenb][1]=I;upp=lenb/2+1;
    for(int i=lenb-1;i>=upp;i--){
        for(int j=0;j<=1;j++){
            if(f[i+1][j].Empty()) continue;
            up=(j)?b[i]:(1);
            // printf("up=%d\n",up);
            for(int k=0;k<=up;k++){
                f[i][j&&(k==up)]+=f[i+1][j];
                // printf("i=%d j=%d k=%d\n",i,j,k);
                // printf("f[%d][%d]=",i,j&&(k==up));f[i][j&&(k==up)].Print();
            }
        }
    }
    Ans+=f[upp][0];
    for(int i=1;i<=upp-1;i++) c[i]=b[lenb-i+1];
    // for(int i=upp-1;i>=1;i--){
        // printf("c[%d]=%d\n",i,c[i]);
    // }
    for(int i=upp-1;i>=1;i--) if(c[i]!=b[i]){if(c[i]>b[i]) op=1;break;}
    // printf("op=%d\n",op);
    if(!op) Ans+=f[upp][1];
    // printf("nowAns=");Ans.Print();
}

inline void GetAns(){
    now=I;
    for(int i=2;i<=lenb-1;i++){
        if(i&1) now.Ly();
        Ans+=now;
        // printf("i=%d\n",i);Ans.Print();
    }
    if(!pd) Ans+=I;
}

inline void Print(){Ans.Print();}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();Dp();GetAns();Print();return 0;
}