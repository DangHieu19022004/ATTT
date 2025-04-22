#include<bits/stdc++.h>

using namespace std;

string mahoa(string plain, int a, int b){
	string kq = "";
	for(char c : plain){
		kq += ((c - 'A') * a + b) % 26 + 'A';
	}
	return kq;
}

int checka(int a){
	for(int i=1; i<26; i++){
		if(a*i % 26 == 1) return i;
	}
	return -1;
}

string giaima(string mhkq, int a, int b){
	string kq = "";
	for(char c : mhkq){
		kq += (c - 'A' - b)*checka(a) % 26 + 'A';
	}
	return kq;
}

int main(){
	int a, b;
	string plain;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cin.ignore();
	cout << "plain: ";
	getline(cin, plain);
	cout << "Ma hoa: " << mahoa(plain, a, b);
	cout << endl << "Giai ma: " << giaima(mahoa(plain, a, b), a, b);
}
