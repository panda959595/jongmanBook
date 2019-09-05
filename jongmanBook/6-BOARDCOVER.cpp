#include <iostream>
using namespace std;
int h, w;
int ans;
char map[21][21];
char block[4][3][2] = {
	{{0,0},{0,1},{1,0}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{0,1},{1,1}}
};
void func() {
	int x, y;
	x = y = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '.') {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) {
			break;
		}
	}
	if (x == -1) {
		ans++;
		return;
	}
	for (int k = 0; k < 4; k++) {
		bool flag = true;
		for (int i = 0; i < 3; i++) {
			if ((x + block[k][i][0] >= h || y + block[k][i][1] >= w) || map[x + block[k][i][0]][y + block[k][i][1]] == '#') {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int i = 0; i < 3; i++) {
				map[x + block[k][i][0]][y + block[k][i][1]] = '#';
			}
			func();
			for (int i = 0; i < 3; i++) {
				map[x + block[k][i][0]][y + block[k][i][1]] = '.';
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> h >> w;
		int temp = 0;
		ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.') {
					temp++;
				}
			}
		}
		if (temp % 3 != 0) {
			cout << 0 << endl;
			continue;
		}
		if (temp == 0) {
			cout << 1 << endl;
			continue;
		}
		func();
		cout << ans << endl;
	}
	return 0;
}