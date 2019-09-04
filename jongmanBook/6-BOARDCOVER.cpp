#include <iostream>
using namespace std;
int h, w;
int ans;
char map[21][21];
char block[4][2][2] = {
	{{'.','#'},{'#','#'}},
	{{'#','.'},{'#','#'}},
	{{'#','#'},{'.','#'}},
	{{'#','#'},{'#','.'}}
};
void func(int num) {
	if (num == 0) {
		ans++;
		return;
	}
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w - 1; j++) {
			for (int k = 0; k < 4; k++) {
				bool flag = true;
				for (int x = 0; x < 2; x++) {
					for (int y = 0; y < 2; y++) {
						if (block[k][x][y] == '#'&&map[i + x][j + y] == '#') {
							flag = false;
						}
					}
				}
				if (flag) {
					for (int x = 0; x < 2; x++) {
						for (int y = 0; y < 2; y++) {
							if (block[k][x][y] == '#') {
								map[i + x][j + y] = '#';
							}
						}
					}
					func(num - 3);
					for (int x = 0; x < 2; x++) {
						for (int y = 0; y < 2; y++) {
							if (block[k][x][y] == '#') {
								map[i + x][j + y] = '.';
							}
						}
					}
				}

			}
			if (map[i][j] == '.') {
				return;
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
		func(temp);
		cout << ans << endl;
	}
	return 0;
}