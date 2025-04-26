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
	for(int i = 1; i<26; i++){
		if(a * i % 26 == 1) return i;
	}
	return -1;
}

string giaima(string kqmh, int a, int b){
	string kq = "";
	for(char c : kqmh){
		kq += ((c - 'A') - b) * checka(a) % 26 + 'A';
	}
	return kq;
}

void bekhoa(string kqmh, string plain){
	for(int a = 0; a<26; a++){
		for(int b = 0; b<26; b++){
			string kq = "";
			for(char c : kqmh){
				kq += ((c - 'A') - b) * checka(a) % 26 + 'A';
			}
			if(kq == plain){
				cout << endl << "Ma hoa thanh cong: " << " a = " << a << " b = " << b << " KQ: " << kq;
			}else{
				cout << endl << " a = " << a << " b = " << b << " KQ: " << kq;
			}
		}
	}
}

int main(){
	int a, b;
	string plain;
	cout << "plain: ";
	getline(cin, plain);
	cout << "a: "; cin >> a;
	cout << "b: "; cin >> b;
	cout << "ma hoa: " << mahoa(plain, a, b);
	cout << endl << "giai ma: " << giaima(mahoa(plain, a, b), a, b);
	bekhoa(mahoa(plain, a, b), plain);
}
