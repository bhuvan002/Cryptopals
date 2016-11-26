#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdint>
#include <cctype>
#include <crypto.h>

using namespace std;


int main() {
	string buffer;
	string min_string;
	uint8_t min_byte;
	double min_score = numeric_limits<double>::max();
	while (getline(cin, buffer)) {
		vector<uint8_t> byte_array = hex2byte(buffer);
		double cur_min_score = numeric_limits<double>::max();
		uint8_t cur_min_byte;
		for (uint16_t byte = 0; byte < (1<<8); byte++) {
			vector<long> frequencies(28, 0);	
			vector<uint8_t> result = single_byte_xor(byte_array, byte);
			int len = result.size();
			long total_count = 0;

			bool contains_non_printable = false;

			for (int j = 0; j < len; j++) {

				char c = (char)result[j];
				if (!isprint(c) && !isspace(c)) {
					contains_non_printable = true;
					break;
				}
				if (isalpha(c)) {
					total_count++;
					if (isupper(c)) c = tolower(c);
					frequencies[c - 'a'] += 1;
				}
				else if (c == ' ') {
					total_count++;
					frequencies[26] += 1;
				}
				else {
					total_count++;
					frequencies[27] += 1;
				}
			}	

			if (contains_non_printable) continue;
			if (total_count == 0) continue;
			double score = freq_score(frequencies, total_count);
			if (score < cur_min_score) {
				cur_min_score = score;
				cur_min_byte = byte;
			}
		}


		
		if (cur_min_score < min_score) {
			min_score = cur_min_score;
			min_byte = cur_min_byte;
			min_string = buffer;
		}
	}
	vector<uint8_t> byte_arr = hex2byte(min_string);
	byte_arr = single_byte_xor(byte_arr, min_byte);
	string ans;
	for (int i = 0; i < byte_arr.size(); i++) ans.push_back((char)byte_arr[i]);
	cout << min_string << "\n" << ans << "\n";
}