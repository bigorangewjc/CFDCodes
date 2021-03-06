#ifndef MATRIX_H
#define MATRIX_H

class CMatrix
{
public:
  CMatrix(int iRows, int iCols);
  CMatrix(const CMatrix &objMat);
  virtual ~CMatrix();
  // Const object can only call const member functions or const member variables
  inline double** GetMat() const;
  inline int GetNumCols() const;
  inline int GetNumRows() const;
  inline double& operator()(const int iRow, const int iCol);
  inline const double& operator()(const int iRow, const int iCol) const;
  inline CMatrix& operator+(const CMatrix& objMat);
  inline CMatrix& operator+=(const CMatrix& objMat);
  void Print() const;

private:
  int m_iCols;
  int m_iRows;
  double **m_pdMat;
};

#include "MatrixI.h"

#endif //MATRIX_H
