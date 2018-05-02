#include <iostream>
#include "naive_bayes.h"

using namespace std;

void print(int size, double *data)
{
	for (int i = 0; i < size; ++i) {
		cout << *(data + i) << " ";
	}
}

int main()
{

	const double trainingData[] = {
		3, 1, 1, 0, 0,
		3, 1, 1, 1, 0,
		2, 1, 1, 0, 1, 
		1, 2, 1, 0, 1, 
		1, 3, 0, 0, 1,
		1, 3, 0, 1, 0,
		2, 3, 0, 1, 1, 
		3, 2, 1, 0, 0,
		3, 3, 0, 0, 1,
		1, 2, 0, 0, 1,
		3, 2, 0, 1, 1,
		2, 2, 1, 1, 1, 
		2, 1, 0, 0, 1,
		1, 2, 1, 1, 0
	};

	const double testData[] = {1, 1, 0, 0};
	vector<double> test(testData, testData + 4);
	vector< vector<double> > train = getVector(14, 5, trainingData);

	double* output;
	int size = naiveBayes(train, test, output);
	print(size, output);

  return 0;

}