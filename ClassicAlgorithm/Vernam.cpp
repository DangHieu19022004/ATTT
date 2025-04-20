#include <iostream>
#include <string>
using namespace std;

// Ham ma hoa Vernam
string mahoa(string plain, string key) {
    string kq = "";

    for (int i = 0; i < plain.length(); i++) {
        char p = toupper(plain[i]);
        char k = toupper(key[i]);

        if (isalpha(p) && isalpha(k)) {
            int c = (p - 'A' + k - 'A') % 26;
            kq += char(c + 'A');
        } else {
            kq += p; // bo qua dau cach, dau cau
        }
    }

    return kq;
}

// Ham giai ma Vernam
string giaima(string cipher, string key) {
    string kq = "";

    for (int i = 0; i < cipher.length(); i++) {
        char c = toupper(cipher[i]);
        char k = toupper(key[i]);

        if (isalpha(c) && isalpha(k)) {
            int p = (c - k + 26) % 26;
            kq += char(p + 'A');
        } else {
            kq += c;
        }
    }

    return kq;
}

int main() {
    string plain, key;

    cout << "Nhap chuoi plaintext: ";
    getline(cin, plain);

    cout << "Nhap khoa (do dai phai bang plaintext): ";
    getline(cin, key);

    if (key.length() < plain.length()) {
        cout << "Loi: Khoa phai co do dai >= plaintext!" << endl;
        return 0;
    }

    string cipher = mahoa(plain, key);
    cout << "Chuoi ma hoa: " << cipher << endl;

    string goc = giaima(cipher, key);
    cout << "Giai ma lai: " << goc << endl;

    return 0;
}

