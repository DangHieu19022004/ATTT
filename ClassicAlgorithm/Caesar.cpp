#include <iostream>
#include <string>
using namespace std;

// Ham ma hoa Caesar
string ma_hoa(string ban_ro, int khoa) {
    string ban_ma = "";
    for (char c : ban_ro) {
        if (isalpha(c)) {
            // Xac dinh base cho chu hoa hoac thuong
            char base = isupper(c) ? 'A' : 'a';
            char m = (c - base + khoa) % 26 + base;
            m = toupper(m);
            ban_ma += m;
        } else {
            ban_ma += c; // giu nguyen ki tu khac chu cai
        }
    }
    return ban_ma;
}

// Ham giai ma Caesar
string giai_ma(string ban_ma, int khoa) {
    string ban_ro = "";
    for (char c : ban_ma) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char r = (c - base - khoa + 26) % 26 + base;
            ban_ro += r;
        } else {
            ban_ro += c;
        }
    }
    return ban_ro;
}

// Ham be khoa Caesar bang brute-force
void be_khoa(string ban_ma) {
    cout << "\nThu be khoa Caesar:\n";
    for (int k = 1; k < 26; ++k) {
        string thu = giai_ma(ban_ma, k);
        cout << "K = " << k << ": " << thu << endl;
    }
}

int main() {
    string ban_ro = "meet me after the toga party";
    int khoa = 3;

    // Ma hoa
    string ban_ma = ma_hoa(ban_ro, khoa);
    cout << "Ban ro: " << ban_ro << endl;
    cout << "Ban ma: " << ban_ma << endl;

    // Giai ma
    string giai = giai_ma(ban_ma, khoa);
    cout << "Giai ma: " << giai << endl;

    // Be khoa
    be_khoa(ban_ma);

    return 0;
}

