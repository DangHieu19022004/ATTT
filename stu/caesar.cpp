#include<bits/stdc++.h>

using namespace std;

string mahoa(string plain, int k){
	string kq = "";
	for(char c : plain){
		kq += (c - 'A' + k) % 26 + 'A';
	}
	return kq;
}

string giaima(string mhkq, int k){
	string kq = "";
	for(char c : mhkq){
		kq += (c - 'A' - k + 26) % 26 + 'A';
	}
	return kq;
}

int main(){
	int k;
	string plain;
	cout << "nhap k: ";
	cin >> k;
	cout << "Nhap plain: ";
	cin.ignore();
	getline(cin, plain);
	cout << "ma hoa: " << mahoa(plain, k) << endl;
	cout << "giai ma: " << giaima(mahoa(plain, k), k);
}
