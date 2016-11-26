#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <crypto.h>

using namespace std;


int main() {
	stringstream bufin;
	bufin << cin.rdbuf();
	string buffer = bufin.str();
	vector<uint8_t> msg = str2byte(buffer);
	string key_str = "ICE";
	vector<uint8_t> key = str2byte(key_str);
	vector<uint8_t> result = repeating_key_xor(msg, key);
	cout << byte2hex(result);
	return 0;
}