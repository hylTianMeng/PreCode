#include<bits/stdc++.h>
#define dd double
#define ld long double
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define N 110
#define M 8
using namespace std;

const int INF=0x3f3f3f3f;

template<typename T> inline void read(T &x) {
    x=0; int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c == '-') f=-f;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}

char s[N];
vector<int> Add[M],Delete[M],Spe[M];

inline int Mapping(char c){
    if(c=='L') return 1;
    else if(c=='I') return 2;
    else if(c=='X') return 3;
    else if(c=='V') return 4;
    else if(c=='=') return 5;
    else if(c=='-') return 6;
    else if(c=='+') return 7;
    assert(0);return 0;
}

inline char InverseMapping(int x){
    if(x==1) return 'L';
    else if(x==2) return 'I';
    else if(x==3) return 'X';
    else if(x==4) return 'V';
    else if(x==5) return '=';
    else if(x==6) return '-';
    else if(x==7) return '+';
    assert(0);return 0;
}

map<string,int> RomanNumber;

string TenDigit[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX"};
string SingleDigit[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};

int len;

inline string RomanNumerals(int x){
    if(x>=90||x<=0) assert(0);
    int ten=x/10,single=x%10;
    return TenDigit[ten]+SingleDigit[single];
}

//这个函数中我们预处理出所有的转移并且把所有的罗马数字映射到阿拉伯数字上。
inline void PreWork(){
    Delete[1].push_back(2);
    Delete[7].push_back(2);Delete[7].push_back(6);
    Delete[5].push_back(6);
    Add[2].push_back(1);Add[2].push_back(7);
    Add[6].push_back(7);Add[6].push_back(5);
    Spe[4].push_back(3);Spe[3].push_back(4);
    Spe[2].push_back(6);Spe[6].push_back(2);
    for(int i=1;i<=80;i++) RomanNumber[RomanNumerals(i)]=i;
}

inline bool Check(){
    string ss;ss.clear();
    int LHS=0,RHS=0;
    bool op=1,op2=0;;
    for(int i=1;i<=len;i++){
        if(s[i]=='='){
            if(op) LHS+=RomanNumber[ss];
            else LHS-=RomanNumber[ss];
            op=1;
            swap(LHS,RHS);if(op2==0) op2=1;else op2=0;
        }
        else if(s[i]=='+'||s[i]=='-'){
            if(RomanNumber.find(ss)==RomanNumber.end()) return 0;
            if(op) LHS+=RomanNumber[ss];
            else LHS-=RomanNumber[ss];
            if(s[i]=='+') op=1;
            if(s[i]=='-') op=0;
            ss.clear();
        }
        else ss+=s[i];
    }
    if(RomanNumber.find(ss)==RomanNumber.end()) return 0;
    if(op) LHS+=RomanNumber[ss];
    else LHS-=RomanNumber[ss];
    return (LHS==RHS)&&op2;
}

inline void Print(){
    for(int i=1;i<=len;i++) putchar(s[i]);puts("");
}

int main(){
    freopen("my.in","r",stdin);
    freopen("my.out","w",stdout);
    PreWork();
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            char lasti=s[i],lastj=s[j];
            for(int k:Delete[Mapping(lasti)]){
                char nowi=InverseMapping(k);
                s[i]=nowi;
                for(int l:Add[Mapping(lastj)]){
                    char nowj=InverseMapping(l);
                    s[j]=nowj;
                    if(Check()) Print();
                }
            }
            if(i==j){
                for(int k:Spe[Mapping(lasti)]){
                    char nowi=InverseMapping(k);
                    s[i]=nowi;
                    if(Check()) Print();
                }
            }
            s[i]=lasti;s[j]=lastj;
        }
    }
    return 0;
}