#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool done (vector<long> diff, long rem) {
	for (unsigned int i = 0; i < diff.size(); i++) {
		if (diff[i] % rem != 0) return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	vector<long> lst;
	ifstream fin{argv[1]};

	for (long n; fin >> n;) {
		lst.push_back(n);
	}

	long min = lst[lst.size()-1];
	vector<long> diff;
	for (unsigned int i = 0; i < lst.size()-1; i++) {
		long d = abs(lst[i+1] - lst[i]);
		min = min < d ? min : d;
		diff.push_back(d);
	}

	long s = 1;
	for (long i = sqrt(min); i > 1; i--) {
		if (done(diff, i)) {
			s *= i;
			break;
		}
	}

	ofstream fout{argv[2]};
	for (long e: lst) fout << e / s << endl;

	return 0;
}
