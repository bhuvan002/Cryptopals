#include <vector>
#include <cstdint>
#include <string>

using namespace std;

/*
	Value	|	Char
	-----------------
	00-25		A-Z
	26-51		a-z
	52-61		0-9
	62			+
	63			-
*/
char base64char(int n) {
	//printf("%d\n", n);
	if (n < 26) {
		return 'A' + n;
	}
	if (n < 52) {
		return 'a' + n - 26;
	}
	if (n < 62) {
		return '0' + n - 52;
	}
	if (n == 62) return '+';
	return '/';
}

vector<uint8_t> hex2byte(string hex) {
	if (hex.size() % 2 == 1) hex = "0" + hex;
	const char *buf = hex.c_str();
	int len = hex.size();
	uint8_t byte;
	vector<uint8_t> byte_array;
	for (int i = 0; i < len-1; i+=2) {
		sscanf(buf+i, "%2hhx", &byte);
		byte_array.push_back(byte);
	}
	return byte_array;
}

string byte2base64(const vector<uint8_t> &byte_array) {
	uint8_t base64it = 0;
	int i = 0;
	int bits = 0;
	string result;
	int len = byte_array.size();
	for (i = 0; i < len-2; i+=3) {
		base64it = byte_array[i]>>2;
		result.push_back(base64char(base64it));
		base64it = ((byte_array[i] & 0x3) << 4) | (byte_array[i+1] >> 4);
		result.push_back(base64char(base64it));
		base64it = ((byte_array[i+1] & 0xF) << 2) | (byte_array[i+2] >> 6);
		result.push_back(base64char(base64it));
		base64it = byte_array[i+2] & 0x3F;
		result.push_back(base64char(base64it));
	}
	if (i == len-2) {
		base64it = byte_array[i]>>2;
		result.push_back(base64char(base64it));
		base64it = ((byte_array[i] & 0x3) << 4) | (byte_array[i+1] >> 4);
		result.push_back(base64char(base64it));
		base64it = ((byte_array[i+1] & 0xF) << 2);
		result.push_back(base64char(base64it));
		result.push_back('=');
	}
	else if (i == len-1) {
		base64it = byte_array[i]>>2;
		result.push_back(base64char(base64it));
		base64it = ((byte_array[i] & 0x3) << 4);
		result.push_back(base64char(base64it));
		result.push_back('=');
		result.push_back('=');
	}
	return result;
}

string byte2hex(const vector<uint8_t> &byte_array) {
    int len = byte_array.size();
	char hex_str[2*len + 1];
    for (int i = 0; i < len; i++) {
        sprintf(hex_str + 2*i, "%.2hhx", byte_array[i]);
    }
    hex_str[2*len+1] = '\0';
    return string(hex_str);
}
