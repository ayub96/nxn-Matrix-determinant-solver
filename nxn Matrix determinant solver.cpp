#include <vector>

#include <iostream>

#include <sstream>

#include <string>

#include <cstdlib>

#include <ctime>

#include <cmath>

#include <iomanip>

using namespace std;

void detMat(vector < vector < double > > & D, int n, double & det); // pass in 2d vector which contains our matrix, pass in the order of the matrix, receive determinant

int main() {

  int order;
  double detIn;
  string reply;

  srand(time(0)); // this value changes with time

  cout << "enter the order of the matrix: " << endl;
  cin >> order;

  vector < vector < double > > A(order);

  cout << "generate random matrix with element values 0-9? (y/n): " << endl;
  cin >> reply;

  for (int i = 0; i < order; i++) {
    A[i].resize(order);
  }

  if (reply == "n") { // user inputs their matrix
    int row = 1;
    for (int i = 0; i < order; i++) {
      int column = 1;
      for (int j = 0; j < order; j++) {
        cout << "enter element of matrix [" << row << "][" << column << "]:";
        cin >> A[i][j];
        column++;
      }
      row++;
    }
    cout << "you entered the following matrix: " << endl;
  } else if (reply == "y") { // generate a random matrix
    for (int i = 0; i < order; i++) {
      for (int j = 0; j < order; j++) {
        A[i][j] = (rand() % 10);
      }
    }
    cout << "random matrix: " << endl;
  } else {
    cout << "bye";

    return 0;
  }

  for (unsigned int i = 0; i < A.size(); i++) { // print the matrix
    for (unsigned int j = 0; j < A[i].size(); j++) {
      cout << A[i][j] << "\t";
    }
    cout << endl;
  }

  detMat(A, order, detIn); // return the triangular matrix and the determinant
  cout << endl << "triangular form: " << endl; // print the triangular matrix
  for (unsigned int i = 0; i < A.size(); i++) {
    for (unsigned int j = 0; j < A[i].size(); j++) {
      cout << setprecision(2) << fixed << A[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl << "determinant = " << detIn; // print determinant

  return 0;
}

void detMat(vector < vector < double > > & D, int n, double & det) {
  for (int i = 0; i < n; i++) {
    for (int k = i + 1; k < n; k++) {

      double t = 0; // the multiplier for the row operations will be zero (ie no further operations will take place) unless its numerator and denominator are
      // both non-zero
      if (!((D[k][i] == 0) || (D[i][i] == 0))) {
        t = D[k][i] / D[i][i];
      }
      for (int j = 0; j < n; j++) {
        D[k][j] = D[k][j] - t * D[i][j]; // going across the row, take away from each element a factor (t) of the element directly above it
      }
    }
  }
  det = 1;
  for (int y = 0; y < n; y++) {
    det = det * D[y][y]; // after matrix has been converted to a triangular matrix, determinant is simply the multiplication of the diagonal elements
  }
}