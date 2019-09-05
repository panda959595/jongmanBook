#include <iostream>
#include <string>
#include <vector>
using namespace std;
string func(string str) {
	if (str.length() == 1) {
		return str;
	}
	vector<string> vec;
	string str_temp = "";
	int temp = 0;
	for (int i = 1; i < str.length(); i++) {
		if (i == 0 && str[i] == 'x') {
			continue;
		}
		if (str[i] == 'x') {
			str_temp += 'x';
			temp += 3;
			continue;
		}
		str_temp += str[i];
		if (temp == 0) {
			vec.push_back(str_temp);
			str_temp = "";
			temp = 0;
		}
		else {
			temp--;
		}
	}
	string ret = "x";
	ret += func(vec[2]);
	ret += func(vec[3]);
	ret += func(vec[0]);
	ret += func(vec[1]);
	return ret;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		if (str.length() == 1) {
			cout << str << endl;
		}
		else {
			string ans = func(str);
			cout << ans << endl;
		}
	}
	return 0;
}