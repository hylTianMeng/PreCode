// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005,P=998244353;
// struct mat{
// 	int d[2][2];
// 	void print(){
// 		for(int i=0;i<2;i++)
// 			for(int j=0;j<2;j++)
// 				cout<<d[i][j]<<" \n"[j];
// 	}
// }m[N],I={1,0,0,1};
// mat operator*(mat x,mat y){
// 	mat z={};
// 	for(int i=0;i<2;i++)
// 		for(int j=0;j<2;j++)
// 			for(int k=0;k<2;k++)
// 				z.d[i][j]=(z.d[i][j]+1ll*x.d[i][k]*y.d[k][j])%P;
// 	return z;
// }
//这里规定了N个矩阵，其中 I 是单位矩阵。矩阵的大小为2
//竟然是矩阵。
//frac 计算 x/y 的逆元。
// int frac(int x,int y){
// 	for(int z=P-2;z;z>>=1){
// 		if(z&1)x=1ll*x*y%P;
// 		y=1ll*y*y%P;
// 	}
// 	return x;
// }
// int read(){
// 	int x,y;
// 	scanf("%d%d",&x,&y);
// 	return frac(x,y);
// }
// int v[N];
//表示在不在环上。
// int n,p[N],q[N],r[N],e[N];
//前三个是基本信息，后两个是入度和边。
// queue<int>Q;
mat dfs(int x,mat a){
	if(v[x])return I;v[x]=1;
	mat k=m[x]*dfs(e[x],a*m[x]);
	p[x]=(k*a).d[1][0];
	return k;
}
// int main(){
	// cin>>n;
	// for(int i=1;i<=n;i++)p[i]=read();
	// for(int i=1;i<=n;i++)
		// scanf("%d",&e[i]),r[e[i]]++;
    //存边，存入度。//
	// for(int i=1;i<=n;i++)q[i]=read();
	// for(int i=1;i<=n;i++)
		// if(!r[i])Q.push(i);
	// while(!Q.empty()){
	// 	int k=Q.front();Q.pop();v[k]=1;
	// 	if(!--r[e[k]])Q.push(e[k]);
	// 	p[e[k]]=(1-(1-p[e[k]])*(1-1ll*p[k]*q[k]%P))%P;
	// }
    //按照拓扑序进行 dp，然后计算每个点（只考虑树）被感染的概率。
    //进行完后，p[k] 里面放的是上面的值。
	for(int i=1;i<=n;i++)
		m[i]={(1ll-p[e[i]])*q[i]%P,0,p[e[i]],1};
    //
// 	for(int i=1;i<=n;i++)
// 		if(!v[i])dfs(i,I);
// 	for(int i=1;i<=n;i++)
// 		cout<<(p[i]+P)%P<<' ';
// 	return 0;
// }
