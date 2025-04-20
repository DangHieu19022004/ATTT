#include<bits/stdc++.h>

using namespace std;

string morongkhoa(string key, int dodai){
	string khoa = "";
	int j = 0;
	for(int i=0; i<dodai; i++){
		khoa += key[j];
		j = (j+1) % key.length();
	}
	return khoa;
}

string mahoa(string plain, string khoa){
	string kq = "";
	for(int i = 0; i<plain.length(); i++){
		char p = plain[i];
		char k = khoa[i];
		if(isalpha(p)){
			kq += ((p - 'A') + (k - 'A')) % 26 + 'A';
		}else{
			kq += p;
		}
	}
	return kq;
}

string giaima(string mahoakq, string khoa){
	string kq = "";
	for(int i = 0; i<mahoakq.length(); i++){
		char p = mahoakq[i];
		char k = khoa[i];
		if(isalpha(p)){
			kq += ((p - 'A') - (k - 'A') + 26) % 26 + 'A';
		}else{
			kq += p;
		}
	}
	return kq;
}

int main(){
	string key, plain;
	cout << "Nhap chuoi plaintext: ";
	getline(cin, plain);
	cout << "Nhap key: ";
	getline(cin, key);
	string khoa = morongkhoa(key, plain.length());
	string mahoakq = mahoa(plain, khoa);
	cout << "Chuoi ma hoa: " << mahoakq;
	cout << endl << "Giai ma: " << giaima(mahoakq, khoa);
}
