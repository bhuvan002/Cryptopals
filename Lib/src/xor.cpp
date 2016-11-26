#include <vector>
#include <cstdint>
#include <iostream>

using namespace std;

vector<uint8_t> fixed_xor(const vector<uint8_t> &b1, const vector<uint8_t> &b2) {
	vector<uint8_t> v(b1);
	int len = v.size();
	for (int i = 0; i < len; i++) {
		v[i] ^= b2[i];
	}
	return v;
}

vector<uint8_t> single_byte_xor(const vector<uint8_t> &b, const uint8_t byte) {
	vector<uint8_t> v(b);
	int len = b.size();
	for (int i = 0; i < len; i++) {
		v[i] ^= byte;
	}
	return v;
}

vector<uint8_t> repeating_key_xor(const vector<uint8_t> &msg, const vector<uint8_t> &key) {
	vector<uint8_t> result(msg);
	int n = msg.size();
	int m = key.size();
	for (int i = 0; i < n - (n%m); i+=m) {
		for (int j = 0; j < m; j++) {
			result[i+j] = msg[i+j]^key[j];
		}
	}
	int i = n - (n%m);
	for (int j = 0; i+j < n; j++) {
		result[i+j] = msg[i+j]^key[j];
	}
	return result;
}