#include <iostream>
#include <string>
using namespace std;

// Ham tinh UCLN
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Ham tinh nghich dao mod 26
int modInverse(int a) {
    a = a % 26;
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1; // khong ton tai
}

// Ham tinh dinh thuc cua ma tran 2x2
int det2x2(int a, int b, int c, int d) {
    return (a * d - b * c) % 26;
}

// Ham ma hoa Hill 2x2
string mahoa(string text, int key[2][2]) {
    string kq = "";
    if (text.length() % 2 == 1) text += 'X'; // them 'X' neu chuoi le

    for (int i = 0; i < text.length(); i += 2) {
        int p1 = toupper(text[i]) - 'A';
        int p2 = toupper(text[i + 1]) - 'A';

        int c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        int c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        kq += char(c1 + 'A');
        kq += char(c2 + 'A');
    }
    return kq;
}

// Ham giai ma Hill 2x2
string giaima(string cipher, int key[2][2]) {
    string kq = "";

    int a = key[0][0], b = key[0][1];
    int c = key[1][0], d = key[1][1];

    int det = det2x2(a, b, c, d);
    if (det < 0) det += 26;

    int invDet = modInverse(det);
    if (invDet == -1) {
        return "Khoa khong kha nghich mod 26!";
    }

    // Tinh nghich dao cua ma tran mod 26
    int invKey[2][2];
    invKey[0][0] =  d * invDet % 26;
    invKey[0][1] = (-b + 26) * invDet % 26;
    invKey[1][0] = (-c + 26) * invDet % 26;
    invKey[1][1] =  a * invDet % 26;

    for (int i = 0; i < cipher.length(); i += 2) {
        int c1 = toupper(cipher[i]) - 'A';
        int c2 = toupper(cipher[i + 1]) - 'A';

        int p1 = (invKey[0][0] * c1 + invKey[0][1] * c2) % 26;
        int p2 = (invKey[1][0] * c1 + invKey[1][1] * c2) % 26;

        kq += char(p1 + 'A');
        kq += char(p2 + 'A');
    }
    return kq;
}

int main() {
    string text;
    cout << "Nhap chuoi can ma hoa (chi chu cai): ";
    getline(cin, text);

    int key[2][2];
    cout << "Nhap khoa ma tran 2x2:\n";
    cin >> key[0][0] >> key[0][1];
    cin >> key[1][0] >> key[1][1];

    // Kiem tra khoa kha nghich
    int det = det2x2(key[0][0], key[0][1], key[1][0], key[1][1]);
    if (gcd(det, 26) != 1) {
        cout << "Ma tran khoa khong kha nghich mod 26, vui long nhap lai!\n";
        return 0;
    }

    string cipher = mahoa(text, key);
    cout << "Chuoi ma hoa: " << cipher << endl;

    string plain = giaima(cipher, key);
    cout << "Giai ma lai: " << plain << endl;

    return 0;
}

