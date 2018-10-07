#include "std_lib_facilities.h"

void kiir(vector<double> tomb);
double tavolsag(vector<double> pagerank, vector<double> pagerank_temp);

int main() {

	vector<vector<double>> L = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	vector<double> PR;
	for(int i=0; i<4; i++) {
		PR.push_back(0.0);
	}

	vector<double> PRv;
	for(int i=0; i<4; i++) {
		PRv.push_back(1.0 / 4.0);
	}

	for(;;) {
		PR = PRv;

		for(int i=0; i<PR.size(); i++) {
			double temp = 0.0;

			for(int j=0; j<PRv.size(); j++) {
				temp += L[i][j] * PR[j];
				PRv[i] = temp;
			}
		}

		if(tavolsag(PR, PRv) < 0.00001) {
			break;
		}
	}

	kiir(PR);

	return 0;
}

void kiir(vector<double> tomb) {
	for(int i=0; i<tomb.size(); i++) {
		cout << "PageRank [" << i << "]: " << tomb[i] << endl;
	}
}


double tavolsag(vector<double> pagerank, vector<double> pagerank_temp) {
	double tav = 0.0;

	for(int i=0; i < pagerank.size(); i++) {
		tav += abs(pagerank[i] - pagerank_temp[i]);
	}

	return tav;
}
