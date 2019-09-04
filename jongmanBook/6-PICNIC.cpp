#include <iostream>
#include <vector>
using namespace std;
int n, m, ans;
bool fr[11][11];
bool check[11];
void make_friend(int num) {
	if (num == n) {
		ans++;
		return;
	}
	if (check[num]) {
		make_friend(num + 1);
		return;
	}
	for (int i = num + 1; i < n; i++) {
		if (fr[num][i] && !check[i]) {
			check[num] = true;
			check[i] = true;
			make_friend(num + 1);
			check[num] = false;
			check[i] = false;
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		ans = 0;
		for (int i = 0; i < n; i++) {
			check[i] = false;
			for (int j = 0; j < n; j++) {
				fr[i][j] = false;
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			fr[a][b] = true;
			fr[b][a] = true;
		}
		make_friend(0);
		cout << ans << endl;
	}
	return 0;
}