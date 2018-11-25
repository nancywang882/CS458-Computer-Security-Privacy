#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool cmp (long i, long j) { return (i<j); }

bool done (vector<long> diff, long rem) {
	for (unsigned int i = 0; i < diff.size(); i++) {
		if (diff[i] % rem != 0) return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	vector<long> lst;
	ifstream fin{argv[1]};
	ofstream fout{argv[2]};

	for (long n; fin >> n;) {
		lst.push_back(n);
	}

	sort(lst.begin(), lst.end(), cmp);

	long max = lst[lst.size()-1];
	vector<long> diff;
	for (unsigned int i = 0; i < lst.size()-1; i++) {
		long d = lst[i+1] - lst[i];
		max = max < d ? d : max;
		diff.push_back(d);
	}

	long ans = 1;
	for (long i = 2; i < sqrt(max); i++) {
		if (done(diff, i)) {
			ans *= i;
			max /= i;
			for (auto &e : diff) e /= i;
			i = 2;
		}
	}

	fout << ans << endl;

	return 0;
}
