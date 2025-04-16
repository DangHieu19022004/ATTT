#include <bits/stdc++.h>

using namespace std;

string mahoa(string p, int k){
	string c = "";
	for(char s : p){
		if(isalpha(s)){
			char base = isupper(s) ? 'A' : 'a';
			c += (s - base + k) % 26 + base;
		}else{
			c += s;
		}
	}
	return c;
}

void phakhoa(string mahoa){
	for(int k = 1; k<26; k++){
		string c = "";
		for(char s : mahoa){
			if(isalpha(s)){
				char base = isupper(s) ? 'A' : 'a';
				c += (s - base - k + 26) % 26 + base;
			}else{
				c += s;
			}
		}
		cout << endl << "k = " << k << " KQ: " << c << endl;
	}
}

int main(){
	string p;
	int k;
	cout << "Nhap chuoi plaintext: ";
//	cin.ignore();
	getline(cin,p);
	cout << endl << "Nhap khoa k = ";
	cin >> k;
	
	string mahoakq = mahoa(p,k);
	cout << endl<< "Chuoi ciphertext sau ma hoa: " << mahoakq;
	
	phakhoa(mahoakq);
}
