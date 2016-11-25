#include <vector>
#include <cstdint>

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