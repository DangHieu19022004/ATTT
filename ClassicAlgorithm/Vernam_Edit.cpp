#include<bits/stdc++.h>

using namespace std;

string mahoa(string plain, string key){
	string kq = "";
	for(int i=0; i<plain.size(); i++){
		char p = plain[i];
		char k = key[i];
		if(isalpha(p)){
			kq += ((p - 'A') + (k - 'A')) % 26 + 'A';
		}else{
			kq += p;
		}
	}
	return kq;
}

string giaima(string kqmahoa, string key){
	string kq = "";
	for(int i = 0; i<kqmahoa.length(); i++){
		char p = kqmahoa[i];
		char k = key[i];
		if(isalpha(p)){
			kq += ((p - 'A') - (k - 'A') +26) % 26 + 'A';
		}else{
			kq += p;
		}
	}
	return kq;
}

int main(){
	string plain, key;
	cout << "Nhap chuoi plaintext: " ;
	getline (cin, plain);
	cout << endl << "Nhap khoa key: ";
	getline(cin, key);
	cout << endl << "Chuoi ma hoa: " << mahoa(plain, key);
	cout << endl << "Chuoi giai ma: " << giaima(mahoa(plain, key), key);
}
