t s1,int t1,int s2,int t2){
// 	int la=t1-s1+1,lb=t2-s2+1;
// 	fill(f+1,f+1+lb,0),f[0]=1;
// 	for(int i=0;i<26;i++) vector<int>().swap(v[i]);
// 	for(int i=lb;i>=1;i--) v[t[s2+i-1]-'a'].push_back(i);
// 	for(int i=1;i<=la;i++)
// 		for(int j:v[s[s1+i-1]-'a']) f[j]=(f[j]+f[j-1])%mod;
// 	return f[lb];
// }