#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std; 

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2);
vector<double> selectionSortedDistances(vector<double> distances); 

int main() {
	ifstream fin("input.txt"); 
	ofstream fout("mattsOutput.txt"); 
	ofstream sortedFout("mattsSortedOutput.txt"); 
	double x1, x2, y1, y2, z1, z2, dist;
	vector<double> distances; 


	while (fin.good()) {
		fin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
		dist = calcDistance(x1, x2, y1, y2, z1, z2);
		distances.push_back(dist);
	}
	if (fout.good()) {
		for (int i = 0; i < distances.size(); ++i) {
			fout << distances.at(i) << endl;
		}
	}
	else { cout << "Unable to open file" << endl; }

	distances = selectionSortedDistances(distances); 

	if (sortedFout.good()) {
		for (int i = 0; i < distances.size(); ++i) {
			sortedFout << distances.at(i) << endl;
		}
	}
	else { cout << "Unable to open file" << endl; }
	
}

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
	double distance;

	distance = pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2);
	distance = sqrt(distance); 


	return distance; 
}

vector<double> selectionSortedDistances(vector<double> distances) {
	//selection Sort
	for (int i = 0; i < distances.size(); ++i) {
		int small = i; 
		for (int j = i + 1; j < distances.size() - 1; ++j) {
			if (distances.at(j) < distances.at(small)) {
				small = j;
			}
		}
		//Swap
		double temp = distances.at(i);
		distances.at(i) = distances.at(small);
		distances.at(small) = temp; 
	}
	return distances; 
}
