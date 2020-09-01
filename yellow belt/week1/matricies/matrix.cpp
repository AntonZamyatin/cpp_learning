#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;
    int rows = 0;
    int cols = 0;
public:

    Matrix()
    {
        matrix = vector<vector<int>>(0);
    }

    Matrix(const int& num_rows, const int& num_cols)
    {
        Reset(num_rows, num_cols);
    }

    void Reset(int num_rows, int num_cols)
    {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_cols < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_cols == 0) {
            num_rows = num_cols = 0;
        }
        rows = num_rows;
        cols = num_cols;
        matrix.assign(num_rows, vector<int>(num_cols));
    }

    int& At(const int& row, const int& col)
    {
            return matrix.at(row).at(col);
    }

    int At(const int& row, const int& col) const
    {
            return matrix.at(row).at(col);
    }

    int GetNumRows() const
    {
        return rows;
    }
    
    int GetNumColumns() const
    {
        return cols;
    }

};

istream& operator>>(istream& in, Matrix& m) {
  int num_rows, num_columns;
  in >> num_rows >> num_columns;
  m.Reset(num_rows, num_columns);
  for (int row = 0; row < num_rows; ++row) {
    for (int column = 0; column < num_columns; ++column) {
      in >> m.At(row, column);
    }
  }
  return in;
}

ostream& operator<<(ostream& out, const Matrix& m) {
  out << m.GetNumRows() << ' ' << m.GetNumColumns() << endl;
  for (int row = 0; row < m.GetNumRows(); ++row) {
      out << m.At(row, 0);
    for (int column = 1; column < m.GetNumColumns(); ++column) {
      out << ' ' << m.At(row, column);
    }
    out << endl;
  }
  return out;
}

bool operator==(const Matrix& m, const Matrix& n){
    if ((m.GetNumColumns() != n.GetNumColumns()) || (m.GetNumRows() != n.GetNumRows())){
        return false;
    }
    for (int i=0; i<m.GetNumRows(); i++)
        for (int j=0; j<m.GetNumColumns(); j++)
            if (m.At(i, j) != n.At(i, j))
                return false;
    return true;
}

Matrix operator+(const Matrix& m, const Matrix& n){
    if (m.GetNumRows() != n.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (m.GetNumColumns() != n.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    }
    {
        Matrix answ(m.GetNumRows(), m.GetNumColumns());
        for (int i = 0; i < m.GetNumRows(); i++)
            for (int j = 0; j < m.GetNumColumns(); j++)
                answ.At(i, j) = m.At(i,j) + n.At(i,j);
        return answ;
    }
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
