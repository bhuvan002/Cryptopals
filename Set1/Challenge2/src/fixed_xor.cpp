#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <crypto.h>

using namespace std;


int main() {
	string buf1, buf2;
	cin >> buf1 >> buf2;
	vector<uint8_t> v1 = hex2byte(buf1);
	vector<uint8_t> v2 = hex2byte(buf2);
	vector<uint8_t> v3 = fixed_xor(v1, v2);
	string buf3 = byte2hex(v3);
	cout << buf3 << "\n";
	return 0;
}