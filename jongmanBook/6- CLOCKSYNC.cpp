#include <iostream>
#include <vector>
using namespace std;
int cloc[17];
int ans;
vector<int> swc[10];
void check(int temp) {
	for (int i = 0; i < 16; i++) {
		if (cloc[i] != 12) {
			return;
		}
	}
	if (ans > temp) {
		ans = temp;
	}
}
void func(int num, int temp) {
	if (num == 10) {
		check(temp);
		return;
	}
	func(num + 1, temp);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < swc[num].size(); j++) {
			cloc[swc[num][j]] += 3;
			if (cloc[swc[num][j]] == 15) {
				cloc[swc[num][j]] = 3;
			}
		}
		func(num + 1, temp + i + 1);
	}
	for (int j = 0; j < swc[num].size(); j++) {
		cloc[swc[num][j]] += 3;
		if (cloc[swc[num][j]] == 15) {
			cloc[swc[num][j]] = 3;
		}
	}
}
int main() {
	swc[0].push_back(0);
	swc[0].push_back(1);
	swc[0].push_back(2);
	swc[1].push_back(3);
	swc[1].push_back(7);
	swc[1].push_back(9);
	swc[1].push_back(11);
	swc[2].push_back(4);
	swc[2].push_back(10);
	swc[2].push_back(14);
	swc[2].push_back(15);
	swc[3].push_back(0);
	swc[3].push_back(4);
	swc[3].push_back(5);
	swc[3].push_back(6);
	swc[3].push_back(7);
	swc[4].push_back(6);
	swc[4].push_back(7);
	swc[4].push_back(8);
	swc[4].push_back(10);
	swc[4].push_back(12);
	swc[5].push_back(0);
	swc[5].push_back(2);
	swc[5].push_back(14);
	swc[5].push_back(15);
	swc[6].push_back(3);
	swc[6].push_back(14);
	swc[6].push_back(15);
	swc[7].push_back(4);
	swc[7].push_back(5);
	swc[7].push_back(7);
	swc[7].push_back(14);
	swc[7].push_back(15);
	swc[8].push_back(1);
	swc[8].push_back(2);
	swc[8].push_back(3);
	swc[8].push_back(4);
	swc[8].push_back(5);
	swc[9].push_back(3);
	swc[9].push_back(4);
	swc[9].push_back(5);
	swc[9].push_back(9);
	swc[9].push_back(13);
	int T;
	cin >> T;
	while (T--) {
		ans = 100000;
		for (int i = 0; i < 16; i++) {
			cin >> cloc[i];
		}
		func(0, 0);
		if (ans == 100000) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}