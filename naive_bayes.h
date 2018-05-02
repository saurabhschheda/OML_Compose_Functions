#ifndef NAIVE_BAYES_H
#define NAIVE_BAYES_H

#include <vector>
#include <set>

using namespace std;

vector< vector<double> > getVector(const int rows, const int columns, const double *data)
{
  vector< vector<double> > graph(rows);
  for (int i = 0; i < rows; ++i)
  {
    vector<double> row(columns);
    for (int j = 0; j < columns; ++j)
    {
      row[j] = *(data + (i * columns) + j);
    }
    graph[i].assign(row.begin(), row.end());
  }
  return graph;
}

double _getProbability(vector< vector<double> > data, int attribute, double value, double classNo)
{
  double positiveCount = 0;
  double classCount = 0;

  for (vector< vector<double> >::iterator i = data.begin(); i != data.end(); ++i)
  {
    vector<double> instance = *i;
    if (instance.back() == classNo)
    {
      classCount++;
      if (instance[attribute] == value)
        positiveCount++;
    }
  }
  return positiveCount / classCount;
}

set<double> _getClasses(vector< vector<double> > data)
{
  set<double> classes;
  for (vector< vector<double> >::iterator i = data.begin(); i != data.end(); ++i)
  {
    vector<double> instance = *i;
    const double classNo = instance.back();
    classes.insert(classNo);
  }
  return classes;
}

vector<double> _getProbabilities(vector< vector<double> > trainingData, vector<double> testData)
{
  set<double> classes = _getClasses(trainingData);
  vector<double> probabilities(classes.size());
  int classNo = 0;

  for (set<double>::iterator j = classes.begin(); j != classes.end(); ++j)
  {
    probabilities[classNo] = 1;
    int attribute = 0;
    for (vector<double>::iterator i = testData.begin(); i != testData.end(); ++i)
    {
      probabilities[classNo] *= _getProbability(trainingData, attribute, *i, *j);
      ++attribute;
    }
    ++classNo;
  }

  return probabilities;
}

int naiveBayes(vector< vector<double> > trainingData, vector<double> testData, double *&output)
{
  vector<double> probabilities = _getProbabilities(trainingData, testData);
  double sum = 0;

  for (int i = 0; i < probabilities.size(); ++i)
  {
    sum += probabilities[i];
  }

  output = new double[probabilities.size()];
  for (int i = 0; i < probabilities.size(); ++i)
  {
    *(output + i) = probabilities[i] / sum;
  }
  return probabilities.size();
}

#endif
