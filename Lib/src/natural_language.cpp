#include <vector>

using namespace std;

// Calculates viability of a frequency array using chi-squared statistic
double freq_score(const vector<double> &frequencies) {
	const static vector<double> english_frequencies = {
		8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, // a,b,c,d,e,f,g,h
		6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, // i,j,k,l,m,n,o,p
		0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, // q,r,s,t,u,v,w,x
		1.974, 0.074											// y,z
	};
	double score = 0.0;
	for (int i = 0; i < 26; i++) {
		score += ((frequencies[i]-english_frequencies[i])*(frequencies[i] - english_frequencies[i]))/english_frequencies[i];
	}
	return score;
}