#include <bits/stdc++.h>
#define cout out
using namespace std;
int reg[32];
vector<vector<string>> program;
map <string, int>loop, bin;
int doing = 0, oridoing = 0;
ofstream out("./Pro/project2_proOutput2.txt", ios::out);
bool NorT = false;
void build() {
	bin["000"] = 1, bin["001"] = 2;
	bin["010"] = 3, bin["011"] = 4;
	bin["100"] = 5, bin["101"] = 6;
	bin["110"] = 7, bin["111"] = 8;
}
void do_ins(string inst, string doins) {	
	string buf[3] = {}, s;
	int i = 0;
	while (doins.find(',') != string::npos)
		doins[doins.find(',')] = ' ';
	stringstream ss(doins);
	while (ss >> s)
		buf[i++] = s;
	oridoing = doing;
	if (inst == "addi") {
		int a = buf[0][1] - '0', b = buf[1][1] - '0', c = atoi(buf[2].c_str());
		reg[a] = reg[b] + c;
		doing++;		
	}
	if (inst == "add") {
		int a = buf[0][1] - '0', b = buf[1][1] - '0', c = buf[2][1] - '0';
		reg[a] = reg[b] + reg[c];
		doing++;		
	}
	if (inst == "andi") {
		int a = buf[0][1] - '0', b = buf[1][1] - '0', c = atoi(buf[2].c_str());
		reg[a] = reg[b] & c;
		doing++;		
	}
	if (inst == "bne") {
		int a = buf[0][1] - '0', b = buf[1][1] - '0';		
		if (reg[a] != reg[b]){
			doing = loop[buf[2]];
			NorT = true;
		}
		else
			doing++;
	}
	if (inst == "beq") {
		int a = buf[0][1] - '0', b = buf[1][1] - '0';		
		if (reg[a] == reg[b]){
			doing = loop[buf[2]];
			NorT = true;
		}					
		else
			doing++;
	}
	
}
string change_state(string pre, bool now) {
	string buf[4] = { "SN","WN","WT","ST" };
	for (int i = 0; i < 4; i++) {
		if (buf[i] == pre) {
			if (!now) {
				
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
	fstream in("./testData/test2.txt", ios::in);
	memset(reg, sizeof(reg), 0);
	string s,t;
	int times = 0;
	build();
	int entryNum;
	cout << "Enter entry number: ";
	cin >> entryNum;
	cout << entryNum << endl;
	cout << "Input File: \n";
	cout << "============================================\n";
	while (getline(in, s)) {		
		vector<string> ins;
		string buf = "";
		cout << s << endl;
		if (s.find(';') != string::npos)
			s.erase(s.find(';'), s.size() - s.find(';'));
		
		stringstream ss(s);
		while (ss >> t) {			
			ins.push_back(t);
		}			
		ss.clear();
		if (ins.size() == 1) {			
			ins[0].pop_back();
			loop[ins[0]] = times;
			ins.erase(ins.begin());
			continue;
		}			
		ins.erase(ins.begin());				
		program.push_back(ins);
		times++;
	}
	cout << "============================================\n\n";
	vector<vector<string>> Entrys;
	for (int i = 0; i < entryNum;i++) {
		vector<string> buf = { "000", "SN", "SN", "SN", "SN", "SN", "SN", "SN", "SN", "0" };
		Entrys.push_back(buf);
	}
	
	while (doing < program.size()) {
		NorT = false;
		cout << "============================================\n";
		cout << "Inst. : ";
		for (auto i : program[doing])cout << i << " ";
		cout << "\nUse Entry: " << (doing % entryNum) << "\n";
		for (int i = 0; i < entryNum; i++) {
			cout << "Entry " << i << " : (";
			for (int j = 0; j < 9;j++) {
				if (j < 8)
					cout << Entrys[i][j] << ", ";
				else
					cout << Entrys[i][j] << ")\n";
			}
		}
		do_ins(program[doing][0], program[doing][1]);	
		cout << Entrys[(oridoing % entryNum)][bin[Entrys[(oridoing % entryNum)][0]]][1] << " " << (NorT ? "T " : "N ");
		if (Entrys[(oridoing % entryNum)][bin[Entrys[(oridoing % entryNum)][0]]][1] == 'T'){
			if (NorT) 
				cout << "Predict Success\n";			
			else {
				Entrys[(oridoing % entryNum)][9] = to_string(atoi(Entrys[(oridoing % entryNum)][9].c_str()) + 1);
				cout << "Predict Fail\n";
			}
		}
		else{
			if (!NorT)
				cout << "Predict Success\n";			
			else {
				Entrys[(oridoing % entryNum)][9] = to_string(atoi(Entrys[(oridoing % entryNum)][9].c_str()) + 1);
				cout << "Predict Fail\n";
			}
		}
		cout << "Misprediction: " << Entrys[(oridoing % entryNum)][9] << endl;
		Entrys[(oridoing % entryNum)][bin[Entrys[(oridoing % entryNum)][0]]] = change_state(Entrys[(oridoing % entryNum)][bin[Entrys[(oridoing % entryNum)][0]]], NorT);
		Entrys[(oridoing % entryNum)][0].erase(Entrys[(oridoing % entryNum)][0].begin());	
		Entrys[(oridoing % entryNum)][0] += (NorT ? "1" : "0");			
	}
	cout << "====================Done====================\n";
	cout << "Predictors:\n";
	for (int i = 0; i < entryNum; i++) {
		cout << "Entry " << i << " : (";
		for (int j = 0; j < 9; j++) {
			if (j < 8)
				cout << Entrys[i][j] << ", ";
			else
				cout << Entrys[i][j] << ")" << "Misprediction: " << Entrys[i][9] << endl;
		}
	}
	return 0;
}
