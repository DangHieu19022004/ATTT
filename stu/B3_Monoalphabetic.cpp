#include<bits/stdc++.h>

using namespace std;

string mahoa(string plain, string key){
	string kq = "";
	for(char c : plain){
		kq += key[c - 'A'];
	}
	return kq;
}

string giaima(string kqmh, string key){
	string kq = "";
	for(char c : kqmh){
		kq += key.find(c) + 'A';
	}
	return kq;
}

int main(){
	string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
	string plain;
	cout << "plain: ";
	getline(cin, plain);
	cout << "Ma hoa: " << mahoa(plain, key);
	cout << endl << "Giai ma: " << giaima(mahoa(plain, key), key);
}
