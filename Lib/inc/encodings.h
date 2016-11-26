#pragma once

#include <cstdint>
#include <vector>
#include <string>

using namespace std;

char base64char(int n);
vector<uint8_t> hex2byte(string hex);
string byte2base64(const vector<uint8_t> &byte_array);
string byte2hex(const vector<uint8_t> &byte_array);
string byte2str(const vector<uint8_t> &byte_array);
vector<uint8_t> str2byte(const string &str);