#include <iostream>
#include <fstream>

#define start 20997837
#define end 20997842
#define len end - start

using namespace std;
int main() {
    char* e = new char[] {(char)0x90, (char)0x90, (char)0x90, (char)0x90, (char)0xEB};
    char* d = new char[] {(char)0x83, (char)0x78, (char)0x74, (char)0x01, (char)0x75};
    char* s = new char[1];
    ifstream inf("GameAssembly.dll");
    inf.seekg(start);
    inf.read(s, 1);
    inf.close();
    if (s[0] == d[0]) cout << "Patch disabled "; else cout << "Patch enabled ";
    ofstream outf("GameAssembly.dll");
    char c;
    cout << "(e/d):" << endl;
    cin >> c;
    if (c == 'e') {
        outf.seekp(start);
        outf.write(e, len);
        outf.close();
        cout << "Patch enabled" << endl;
    } else {
        outf.seekp(start);
        outf.write(d, len);
        outf.close();
        cout << "Patch disabled" << endl;
    }
}
