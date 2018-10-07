// [!] This script is under construction...

#include "std_lib_facilities.h"

void kiir(vector<double> tomb);
double tavolsag(vector<double> pagerank, vector<double> pagerank_temp);

int main() {
	// Vektorok
	vector<vector<double>> L = {
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	vector<double> PR = {0.0, 0.0, 0.0, 0.0};
	vector<double> PRv = {1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0, 1.0 / 4.0};

	// Iterátorok
	vector< vector<double> >::iterator row;
	vector<double>::iterator col;
	vector<double>::iterator vi;
	vector<double>::iterator viv;

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
	vector<double>::iterator i;

	for(i = tomb.begin(); i != tomb.end(); i++) {
		cout << "PageRank: " << *i << endl;
	}
}


double tavolsag(vector<double> pagerank, vector<double> pagerank_temp) {
	double tav = 0.0;

	for(int i=0; i < pagerank.size(); i++) {
		tav += abs(pagerank[i] - pagerank_temp[i]);
	}

	return tav;
}
