#include<bits/stdc++.h>

using namespace std;

string mahoa(string P, string key){
	string C = "";
	for(char s : P){
		if(isalpha(s)){
			char base = isupper(s) ? 'A' : 'a';
			C += key[s - base];
		}else{
			C += s;
		}
	}
	return C;
}

string giaima(string kq, string key){
	string C = "";
	for(char s : kq){
		if(isalpha(s)){
			char base = isupper(s) ? 'A' : 'a';
			int pos = key.find(s);
			C += base + pos;
		}else{
			C += s;
		}
	}
	return C;
}

int main(){
	string key = "ZXCVBNMASDFGHJKLQWERTYUIOP";
	string P;
	cout << "Chuoi plaintext: ";
	getline(cin, P);
	cout << endl << "Ma hoa: " << mahoa(P, key);
	
	cout << endl << "Giai ma: " << giaima(mahoa(P, key), key);
}
