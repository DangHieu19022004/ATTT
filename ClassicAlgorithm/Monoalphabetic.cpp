#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Khoa hoan vi - phai la 26 chu cai khac nhau, thuong hoac hoa deu duoc
string khoa = "ZXCVBNMASDFGHJKLQWERTYUIOP"; // vi du

// Ham ma hoa: thay the theo vi tri
string mahoa(string p, string key) {
    string c = "";
    for (char ch : p) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int pos = ch - base;
            char ma = key[pos]; // lay ky tu theo bang thay the
            if (islower(ch)) ma = tolower(ma); // giu nguyen chu thuong
            c += ma;
        } else {
            c += ch; // giu nguyen dau cach, dau cau
        }
    }
    return c;
}

// Ham giai ma: tim vi tri trong khoa
string giaima(string c, string key) {
    string p = "";
    for (char ch : c) {
        if (isalpha(ch)) {
            char upper_ch = toupper(ch);
            size_t pos = key.find(upper_ch); // tim vi tri ky tu trong khoa
            char goc = isupper(ch) ? 'A' + pos : 'a' + pos;
            p += goc;
        } else {
            p += ch;
        }
    }
    return p;
}

int main() {
    string plaintext;
    cout << "Nhap chuoi plaintext: ";
    getline(cin, plaintext);

    // Kiem tra khoa co hop le (26 ky tu khac nhau)
    if (khoa.length() != 26 || !all_of(khoa.begin(), khoa.end(), ::isupper)) {
        cout << "Loi: khoa phai la 26 chu cai in hoa!" << endl;
        return 1;
    }

    string ciphertext = mahoa(plaintext, khoa);
    cout << "Chuoi ma hoa: " << ciphertext << endl;

    string giaima_kq = giaima(ciphertext, khoa);
    cout << "Giai ma lai duoc: " << giaima_kq << endl;

    return 0;
}

