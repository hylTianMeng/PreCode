#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 110
#define M 1010
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

struct BigNum{
    int num[N],Size;
    inline BigNum(){memset(num,0,sizeof(num));Size=1;}
    inline void Clear(){
        memset(num,0,sizeof(num));Size=1;
    }
    inline BigNum operator * (const int &val)const{
        BigNum c;c.Clear();c.Size=Size;
        for(int i=1;i<=Size;i++) c.num[i]=num[i]*val;
        for(int i=1;i<=Size;i++){
            c.num[i+1]+=c.num[i]/10;c.num[i]%=10;
        }
        while(c.num[c.Size+1]){
            c.Size++;
            c.num[c.Size+1]+=c.num[c.Size]/10;
            c.num[c.Size]%=10;
        }
        return c;
    }
    inline BigNum operator * (const BigNum &b)const{
        BigNum c;c.Clear();c.Size=Size+b.Size;
        for(int i=1;i<=Size;i++)
            for(int j=1;j<=b.Size;j++){
                c.num[i+j-1]+=(num[i]*b.num[j]);
                c.num[i+j]+=c.num[i+j-1]/10;c.num[i+j-1]%=10;
            }
        while(!c.num[c.Size]&&c.Size>1) c.Size--;
        return c; 
    }
    inline BigNum operator - (const BigNum &b)const{
        BigNum c;c.Clear();c.Size=Size;
        for(int i=1;i<=Size;i++){
            c.num[i]+=num[i]-b.num[i];
            if(c.num[i]<0){c.num[i]+=10,c.num[i+1]--;}
        }
        while(!c.num[c.Size]&&c.Size>1) c.Size--;
        return c;
    }
    inline void ry(){
        for(int i=Size;i>=1;i--){
            if(num[i]&1) num[i-1]+=10;
            num[i]>>=1;
        }
        while(!num[Size]&&Size>1) Size--;
    }
    inline int Mod2(){return num[1]&1;}
    inline bool operator > (const BigNum &b)const{
        if(Size!=b.Size) return Size>b.Size;
        for(int i=Size;i>=1;i--){
            if(num[i]!=b.num[i]) return num[i]>b.num[i];
        }
        return 0;
    }
    inline bool operator <= (const BigNum &b)const{
        return !((*this)>b);
    }
    inline void Init(string s){
        Size=s.length();
        for(int i=1;i<=Size;i++){
            num[i]=s[Size-i]-'0';
        }
    }
    inline bool Empty(){
        return Size==1&&num[1]==0;
    }
    inline void Print(){
        for(int i=Size;i>=1;i--) putchar(num[i]+'0');putchar(' ');
        // puts("");
    }
}ans[M],Basic,n;

int tail;
string s;

inline void Init(){
    cin>>s;n.Init(s);Basic.num[1]=1;
}

inline BigNum FindMax(){
    BigNum res;res.Clear();BigNum nxt;nxt.Clear();
    res.num[1]=1;nxt=res*3;
    while(nxt<=n){
        res=nxt;nxt=res*3;
    }
    return res;
}

inline void Solve(){
    while(!n.Empty()){
        while(n.Mod2()==0){
            Basic=Basic*2;n.ry();
        }
        BigNum now=FindMax();
        n=n-now;
        now=now*Basic;
        ans[++tail]=now;
    }
}

inline void Print(){
    printf("%d\n",tail);
    for(int i=1;i<=tail;i++) ans[i].Print();
}

int main(){
    // freopen("my.in","r",stdin);
    // freopen("my.out","w",stdout);
    Init();
    // printf("Finished Initing\n");
    Solve();Print();
    return 0;
}