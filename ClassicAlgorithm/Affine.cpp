#include <iostream>
#include <string>
using namespace std;

// Ham tinh nghich dao modulo a^-1 mod 26 (dung brute-force)
int mod_inverse(int a, int m = 26) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1)
            return i;
    }
    return -1; // khong ton tai nghich dao
}

// Ham ma hoa Affine
string mahoa_affine(string ban_ro, int a, int b) {
    string ban_ma = "";
    for (char c : ban_ro) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            int ma = (a * x + b) % 26;
            ban_ma += char(ma + base);
        } else {
            ban_ma += c;
        }
    }
    return ban_ma;
}

// Ham giai ma Affine
string giaima_affine(string ban_ma, int a, int b) {
    string ban_ro = "";
    int a_inv = mod_inverse(a); // nghich dao cua a
    if (a_inv == -1) {
        return "Khong the giai ma vi a khong co nghich dao";
    }

    for (char c : ban_ma) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int y = c - base;
            int ro = (a_inv * (y - b + 26)) % 26;
            ban_ro += char(ro + base);
        } else {
            ban_ro += c;
        }
    }
    return ban_ro;
}

int main() {
    string p;
    int a, b;
    cout << "Nhap chuoi plaintext: ";
    getline(cin, p);

    cout << "Nhap a (nguyen to cung nhau voi 26): ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    string ban_ma = mahoa_affine(p, a, b);
    cout << "Chuoi da ma hoa: " << ban_ma << endl;

    string giai = giaima_affine(ban_ma, a, b);
    cout << "Giai ma lai duoc: " << giai << endl;

    return 0;
}

