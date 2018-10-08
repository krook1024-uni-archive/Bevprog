// [!] This script is under construction...

#include "std_lib_facilities.h"

void kiir(vector<double> tomb);
double tavolsag(vector<double> pagerank, vector<double> pagerank_temp);

int main() {
	// Vectors
	vector<vector<double>> L = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	vector<double> PR = {0.0, 0.0, 0.0, 0.0};
	vector<double> PRv = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

	// Iterators
	vector< vector<double> >::iterator row;
	vector<double>::iterator col;
	vector<double>::iterator vi; // Iterator for PR
	vector<double>::iterator vvi; // Iterator for PRv

	for(;;) {
		PR = PRv;

		for(int i=0; i<PR.size(); i++) {
			double temp = 0.0;

			for(int j=0; j<PRv.size(); j++) {
				temp += L[i][j] * PR[j];
				PRv[i] = temp;
			}
		} //*/

/*		for(row = L.begin(); row != L.end(); row++) {
			vi = PR.begin();
			vvi = PRv.begin();

			for(col = row->begin(); col != row->end(); col++) {
				auto i = distance(PRv.begin(), vvi);
				auto j = distance(PR.begin(), vi);

				vi = (*col) * (*vvi);
				advance(vi, 1);
				advance(vvi, 1);
			}
		} //*/

		if(tavolsag(PR, PRv) < 0.000001) {
			break;
		}
	}

	kiir(PR);

	return 0;
}

void kiir(vector<double> tomb) {
	vector<double>::iterator i;

	for(i = tomb.begin(); i != tomb.end(); i++) {
		cout << "PageRank [" << distance(tomb.begin(), i) << "]: " << fixed << setprecision(6) << *i << endl;
	}
}


double tavolsag(vector<double> pagerank, vector<double> pagerank_temp) {
	double tav = 0.0;

	for(int i=0; i < pagerank.size(); i++) {
		tav += abs(pagerank[i] - pagerank_temp[i]);
	}

	return tav;
}
