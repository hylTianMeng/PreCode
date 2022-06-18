#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solve(int N, vector<int> A) {
	int lans = 0;
	for(int i = 0; i < N; ++i) {
		lans = max(lans, A[i] + A[i + N]);
	}
	int rans = *max_element(A.begin(), A.end()) * 2;
	int l = lans - 1, r = rans;
	while(r - l > 1) {
		int m = (l + r) >> 1;
		vector<int> L(N), R(N);
		for(int i = 0; i < N; ++i) {
			L[i] = A[i];
			R[i] = m - A[i + N];
		}
		int lsub = L[0], rsub = R[0] + 1;
		while(rsub - lsub > 1) {
			int msub = (lsub + rsub) / 2;
			long long lcur = 0, rcur = msub;
			for(int i = 1; i < N; ++i) {
				rcur = max(rcur, lcur + L[i]);
				lcur = max(lcur, rcur - R[i]);
			}
			if(rcur <= m) lsub = msub;
			else rsub = msub;
		}
		long long plcur = 0, prcur = lsub;
		for(int i = 1; i < N; ++i) {
			prcur = max(prcur, plcur + L[i]);
			plcur = max(plcur, prcur - R[i]);
		}
		if(plcur <= lsub && prcur <= m) r = m;
		else l = m;
	}
	return r;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(2 * N);
	for(int i = 0; i < 2 * N; ++i) {
		cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}