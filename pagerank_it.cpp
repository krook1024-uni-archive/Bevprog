#include "std_lib_facilities.h"

void print(vector<double> &tomb);
double distance(vector<double> &pagerank, vector<double> &pagerank_temp);

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
	vector< vector<double> >::iterator row; // Iterator for L
	vector<double>::iterator col; // Iterator for L

	for(;;) {
		PR = PRv;

		int i = 0, j = 0;
		for(row = L.begin(); row != L.end(); row++) {
			double tmp = 0.0;
			for(col = row->begin(); col != row->end(); col++) {
				tmp += *col * PR[j];
				PRv[i] = tmp;
				j++;
			}
			if(j % 3) j = 0;
			i++;
		}

		if(distance(PR, PRv) < 0.000001) {
			break;
		}
	}

	print(PR);

	return 0;
}

void print(vector<double> &tomb) {
	vector<double>::iterator i;

	for(i = tomb.begin(); i != tomb.end(); i++) {
		cout << "PageRank [" << distance(tomb.begin(), i) << "]: " << fixed << setprecision(6) << *i << endl;
	}
}


double distance(vector<double> &pr, vector<double> &pr_temp) {
	double tav = 0.0;

	vector<double>::iterator i = pr.begin();
	vector<double>::iterator j = pr_temp.begin();

	for(i = pr.begin(); i != pr.end(); i++) {
		tav += abs((*i) - (*j));
		j++;
	}

	return tav;
}
