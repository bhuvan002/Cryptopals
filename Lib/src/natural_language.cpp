#include <vector>

using namespace std;

// Calculates viability of a frequency array using chi-squared statistic
double freq_score(const vector<long> &frequencies, long len) {
	const static vector<double> english_frequencies = { 
		0.0651738, 0.0124248, 0.0217339, 0.0349835,  //'A', 'B', 'C', 'D',...
		0.1041442, 0.0197881, 0.0158610, 0.0492888, 
		0.0558094, 0.0009033, 0.0050529, 0.0331490,
		0.0202124, 0.0564513, 0.0596302, 0.0137645, 
		0.0008606, 0.0497563, 0.0515760, 0.0729357, 
		0.0225134, 0.0082903, 0.0171272, 0.0013692, 
		0.0145984, 0.0007836, 0.1918182, 0.0000100} ; //'Y', 'Z', ' ', unprintable characters
	double score = 0.0;
	for (int i = 0; i < english_frequencies.size(); i++) {
		double observed = (double)frequencies[i], expected = english_frequencies[i]*len;
		double difference = observed - expected;
		score += difference*difference / expected;
	}
	return score;
}