#include <iostream>
#include <algorithm>
using namespace std;
int wood[20005];
int n;
int func(int left, int right) {
	if (left == right) {
		return wood[left];
	}
	int mid = (left + right) / 2;
	int ret = 0;
	ret = max(ret, func(left, mid));
	ret = max(ret, func(mid + 1, right));
	int temp = min(wood[mid], wood[mid + 1]);
	ret = max(ret, temp * 2);
	int l = mid;
	int r = mid + 1;
	while (l != left || r != right) {
		if (l != left && r != right) {
			if (wood[l - 1] < wood[r + 1]) {
				r++;
				temp = min(temp, wood[r]);
			}
			else {
				l--;
				temp = min(temp, wood[l]);
			}
		}
		else if (l != left) {
			l--;
			temp = min(temp, wood[l]);
		}
		else {
			r++;
			temp = min(temp, wood[r]);
		}
		ret = max(ret, temp*(r - l + 1));
	}
	return ret;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> wood[i];
		}
		int ans = func(0, n - 1);
		cout << ans << endl;
	}
	return 0;
}