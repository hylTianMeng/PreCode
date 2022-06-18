#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<queue>
#define ll long long
#define N 110
using namespace std;

bitset<110> v[N];

template<typename T> inline void read(T &x){
	x=0;int flag=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') flag*=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=flag;
}

struct Node{
	ll val;
	bitset<110> bit;
	inline Node(){}
	inline bool operator < (const Node &b)const{
		return val<b.val;
	}
};

multiset<Node> S;

int n,k,a[N],cnt;
char s[N];

inline void Init(){
	read(n);read(k);k--;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			v[i][j]=s[j]-'0';
		}
	}
	for(int i=1;i<=n;i++){
		Node now;now.bit.reset();
		now.bit[i]=1;now.val=a[i];
        S.insert(now);
	}
}

int main(){
	// freopen("my.in","r",stdin);
	// freopen("my.out","w",stdout);
	Init();
	while(S.size()){
		Node Top=(*S.begin());S.erase(S.begin());
        cnt++;
		if(cnt==k){
			printf("%lld",Top.val);return 0;
		}
		int posi=-1;
		for(int i=1;i<=n;i++) if(Top.bit[i]) posi=i+1;
        while(S.size()+cnt>k) S.erase(--S.end());
		for(int j=posi;j<=n;j++){
			if((v[j]&Top.bit)==Top.bit&&(!(S.size()+cnt>k&&Top.val+a[j]>=(*(--S.end())).val))){
				Top.bit[j]=1;Top.val+=a[j];
				S.insert(Top);
				Top.bit[j]=0;Top.val-=a[j];
			}
		}
	}
	puts("-1");
	return 0;
}