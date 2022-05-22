#include <bits/stdc++.h>
#define cout out
using namespace std;
map <string, int> bin;
string entry[9] = { "000", "SN", "SN", "SN", "SN", "SN", "SN", "SN", "SN" };
ofstream out("test.txt", ios::out);
void build() {
	bin["000"] = 1, bin["001"] = 2;
	bin["010"] = 3, bin["011"] = 4;
	bin["100"] = 5, bin["101"] = 6;
	bin["110"] = 7, bin["111"] = 8;
}
string change_state(string pre, char now) {
	string buf[4] = { "SN","WN","WT","ST" };
	for (int i = 0; i < 4; i++) {
		if (buf[i] == pre) {
			if (now == 'N') {
				if (i == 0) return buf[i];
				else return buf[i - 1];
			}
			else {
				if (i == 3) return buf[i];
				else return buf[i + 1];
			}
		}
	}
}
int main() {
	build();
	string goal = "TTTTNNTNTNTNTNTNT";
	cout << "Initial State: ";
	for (auto& i: entry) cout << i << " ";
	cout << "\n==================start==================\n\n";
	for (int i = 0; i < goal.size(); i++) {
		cout << "=================times " << setw(2) << i+1 << "================\n";
		cout << "Predict: " << entry[bin[entry[0]]][1] << endl;
		cout << "Actual: " << goal[i] << endl;
		cout << "State: ";
		for (int j = 1; j < 9; j++)cout << entry[j] << " ";
		cout << endl;
		cout << "History: " << entry[0] << endl;
		entry[bin[entry[0]]] = change_state(entry[bin[entry[0]]], goal[i]);
		entry[0].erase(entry[0].begin());
		entry[0] += (goal[i] == 'N' ? "0" : "1");
		
	}
	cout << "\n===================end===================\n";
	cout << "Predictor State: ";
	for (auto& i : entry) cout << i << " ";
	cout << endl;
	return 0;
}
