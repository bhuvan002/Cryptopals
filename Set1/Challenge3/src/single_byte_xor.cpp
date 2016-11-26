#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <crypto.h>

using namespace std;


int main() {
	string buf1;
	cin >> buf1;
	vector<uint8_t> byte_arr = hex2byte(buf1);

	double min_score = numeric_limits<double>::max();
	double min_byte = 0;

	/*
	string test_string("Far far away, behind the word mountains, \
	far from the countries Vokalia and Consonantia, there live the blind texts. \
	Separated they live in Bookmarksgrove right at the coast of the Semantics, \
	a large language ocean. A small river named Duden flows by their place and supplies \
	it with the necessary regelialia. It is a paradisematic country, \
	in which roasted parts of sentences fly into your mouth. \
	Even the all-powerful Pointing has no control about the blind texts it is an almost \
	unorthographic life One day however a small line of blind text by the name of Lorem \
	Ipsum decided to leave for the far World of Grammar. The Big Oxmox advised her not \
	to do so, because there were thousands of bad Commas, wild Question Marks and devious \
	Semikoli, but the Little Blind Text didn’t listen. She packed her seven versalia, put \
	her initial into the belt and made herself on the way. When she reached the first hills of \
	the Italic Mountains, she had a last view back on the skyline of her hometown Bookmarksgrove, \
	the headline of Alphabet Village and the subline of her own road, the Line Lane. Pityful a \
	rethoric question ran over her cheek, then");

	vector<uint8_t> test_byte_arr;
	for (int i = 0; i < test_string.size(); i++) {
		test_byte_arr.push_back(test_string[i]);
	}
	uint8_t test_byte = 136;
	*/

	
	// Using uint16_t so that this loop doesnt go into an infinite loop
	for (uint16_t byte = 0; byte < (1<<8); byte++) {  
		vector<long> frequencies(28, 0.0);
		vector<uint8_t> result = single_byte_xor(byte_arr, (uint8_t)byte);
		int len = result.size();
		long total_count = 0;
		for (int j = 0; j < len; j++) {
			char c = (char)result[j];
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
		if (total_count == 0) continue;
		// cout << "\n";
		double score = freq_score(frequencies, total_count);
		// cout << "Cur byte = " << byte << " Cur score = " << score << "\n";
		if (score < min_score) {
			min_score = score;
			min_byte = (uint8_t)byte;
		}

	}
	
	
	string ans;
	vector<uint8_t> result = single_byte_xor(byte_arr, min_byte);
	for (int i = 0; i < result.size(); i++) ans.push_back((char)result[i]);
	cout << ans << "\n";
	
	return 0;
}