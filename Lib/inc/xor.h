#pragma once

#include <vector>
#include <cstdint>

using namespace std;

vector<uint8_t> fixed_xor(const vector<uint8_t> &, const vector<uint8_t> &);
vector<uint8_t> single_byte_xor(const vector<uint8_t> &, const uint8_t );
vector<uint8_t> repeating_key_xor(const vector<uint8_t> &, const vector<uint8_t> &);