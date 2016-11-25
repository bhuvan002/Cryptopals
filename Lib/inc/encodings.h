#pragma once

#include <cstdint>
#include <vector>
#include <string>

using namespace std;

char base64char(int n);
vector<uint8_t> hex2byte(string hex);
string byte2base64(const vector<uint8_t> &byte_array);