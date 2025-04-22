#include<bits/stdc++.h>

using namespace std;

int key[2][2];

string mahoa(string text, int key[2][2]){
	string kq = "";
	if(text.length()%2==1) text += 'X';
	for(int i = 0; i<text.length(); i+=2){
		int p1 = text[i] - 'A';
		int p2 = text[i+1] - 'A';
		kq += (p1 * key[0][0] + p2 * key[0][1]) % 26 + 'A';
		kq += (p1 * key[1][0] + p2 * key[1][1]) % 26 + 'A';
	}
	return kq;
}

string giaima(string cipher, int key[2][2]){
	string kq = "";
	for(int i = 0; i < cipher.length(); i+=2){
		int p1 = cipher[i] - 'A';
		int p1 = cipher[i+1] - 'A';
		kq += ()
	}
}

int main(){
	string plain;
	cout << "Nhap plaintext: ";
	getline(cin, plain);
	cin >> key[0][0] >> key[0][1];
	cin >> key[1][0] >> key[1][1];
	string cipher = mahoa(plain, key);
    cout << "Chuoi ma hoa: " << cipher << endl;

    string plain = giaima(cipher, key);
    cout << "Giai ma lai: " << plain << endl;

}
