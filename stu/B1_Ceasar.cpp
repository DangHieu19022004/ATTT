 #include<bits/stdc++.h>
 
 using namespace std;
 
 string mahoa(string plain, int k){
 	string kq = "";
 	for(char c : plain){
 		kq += (c - 'A' + k) % 26 + 'A';
	}
	return kq;
 }
 
 string giaima(string kqmh, int k){
 	string kq = "";
 	for(char c : kqmh){
 		kq += (c - 'A' - k + 26) % 26 + 'A';
	 }
	 return kq;
 }
 
 int main(){
 	string plain;
 	int k;
 	cout << "Nhap plain: ";
 	getline(cin, plain);
 	cout << "Nhap k: ";
 	cin >> k;
 	cout << "ma hoa: " << mahoa(plain, k);
 	cout << endl << "giai ma: " << giaima(mahoa(plain, k), k);
 }
