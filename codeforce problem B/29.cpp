#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			reverse(s.begin(), s.begin() + i);
		}
	}
	cout << s << endl;
	
	return 0;
}