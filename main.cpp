#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

vl calc(const vl& dat) {
	auto ret = vl(dat.size() - 1);
	for (auto i = 0; i < ret.size(); ++i) {
		ret[i] = dat[i + 1] - dat[i];
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	auto dat = vl{};
	auto iss = istringstream{ s };
	while (getline(iss, s, ',')) {
		dat.push_back(stoll(s));
	}

	for (auto i = 0; i < k; ++i) {
		dat = calc(dat);
	}

	for (auto i = 0; i < dat.size() - 1; ++i) {
		cout << dat[i] << ',';
	}
	cout << dat[dat.size() - 1];

	return 0;
}