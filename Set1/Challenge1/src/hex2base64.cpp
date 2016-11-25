#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <encodings.h>

using namespace std;


int main() {
	string buffer;
	cin >> buffer;
	vector<uint8_t> byte_array = hex2byte(buffer);
	string b64str = byte2base64(byte_array);
	cout << b64str << "\n";
	return 0;
}