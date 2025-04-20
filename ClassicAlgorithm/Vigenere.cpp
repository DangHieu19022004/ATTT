#include <iostream>
#include <string>
using namespace std;

// Ham mo rong khoa cho bang do dai plaintext
string moRongKhoa(string key, int dodai) {
    string khoa = "";
    int j = 0;
    for (int i = 0; i < dodai; i++) {
        khoa += key[j];
        j = (j + 1) % key.length();
    }
    return khoa;
}

// Ham ma hoa Vigenere
string mahoa(string plain, string key) {
    string kq = "";
    string khoa = moRongKhoa(key, plain.length());

    for (int i = 0; i < plain.length(); i++) {
        char p = toupper(plain[i]);
        char k = toupper(khoa[i]);

        if (isalpha(p)) {
            char c = (p - 'A' + (k - 'A')) % 26 + 'A';
            kq += c;
        } else {
            kq += p; // bo qua ky tu khac chu cai
        }
    }
    return kq;
}

// Ham giai ma Vigenere
string giaima(string cipher, string key) {
    string kq = "";
    string khoa = moRongKhoa(key, cipher.length());

    for (int i = 0; i < cipher.length(); i++) {
        char c = toupper(cipher[i]);
        char k = toupper(khoa[i]);

        if (isalpha(c)) {
            char p = (c - k + 26) % 26 + 'A';
            kq += p;
        } else {
            kq += c;
        }
    }
    return kq;
}

int main() {
    string plain, key;
    cout << "Nhap chuoi can ma hoa (chi chu cai): ";
    getline(cin, plain);
    cout << "Nhap khoa (vi du: LEMON): ";
    cin >> key;

    string c = mahoa(plain, key);
    cout << "Chuoi ma hoa: " << c << endl;

    string g = giaima(c, key);
    cout << "Giai ma lai: " << g << endl;

    return 0;
}

