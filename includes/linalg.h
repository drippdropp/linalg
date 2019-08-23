#include <cmath>
#include <cstdlib>
#include <cstring>
#include <tuple>

#ifndef LINALG_H
#define LINALG_H

template <typename T>
class ColumnVector {
 private:
  T* values;
  int vector_length;
  const char* vector_type = "column";
 public:
  ColumnVector<T>(T* _values, int length) {
    values = new T[length];
    std::memcpy(values, _values, length);
    vector_length = length;
  }

  ~ColumnVector<T>() {
    delete[] values;
  }

  long L2Norm() {
    long sum = 0;
    for (size_t i = 0; i < vector_length; i++) {
      sum += values[i] * values[i];
    }
    return sum;
  }
};

template <typename T>
class RowVector {
 private:
  T* values;
  int vector_length;
  const char* vector_type = "row";
 public:
  RowVector<T>(T* _values, int length) {
    values = new T[length];
    std::memcpy(values, _values, length);
    vector_length = length;
  }

  ~RowVector<T>() {
    delete[] values;
  }

  long L2Norm() {
    long sum = 0;
    for (size_t i = 0; i < vector_length; i++) {
      sum += values[i] * values[i];
    }
    return sum;
  }
};

template <typename T>
class Matrix {
 private:
  std::tuple<int, int> dimensions;
  ColumnVector<T>* columns;
  RowVector<T>* rows;
  char* mat_type;
 public:
  Matrix<T>(int row_dim, int col_dim, ColumnVector<T>* _columns) {
    dimensions = std::tuple<int, int>{row_dim, col_dim};
    columns = new ColumnVector<T>[col_dim];
    for (int i = 0; i < col_dim; i++) {
      columns[i] = _columns[i];
    }
    mat_type = "columns";
  }
  Matrix<T>(int row_dim, int col_dim, RowVector<T>* _rows) {
    dimensions = std::tuple<int, int>{row_dim, col_dim};
    rows = new RowVector<T>[row_dim];
    for (int i = 0; i < row_dim; i++) {
      rows[i] = _rows[i];
    }
    mat_type = "rows";
  }
  std::tuple<int, int> Dimensions() {
    return dimensions;
  }

  ~Matrix<T>() {

    if (strcmp(mat_type, "rows") == 0)
      delete[] rows;

    if (strcmp(mat_type, "columns") == 0)
      delete[] columns;
  }

  ColumnVector<T> GetColumn(int col) {
    return columns[col];
  }

  Matrix<T> operator+(const Matrix<T> &other) {
    if (this->dimensions != other.Dimensions()) {
      throw std::exception();
    }
  }
};

#endif //LINALG_H
