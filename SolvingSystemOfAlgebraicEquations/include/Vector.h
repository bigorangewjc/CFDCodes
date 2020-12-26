#ifndef VECTOR_H
#define VECTOR_H

class CVector
{
public:
  CVector(int iRows);
  CVector(const CVector& objVec);
  virtual ~CVector();
  inline double* GetVec() const;
  inline int GetNumRows() const;
  inline double& operator()(const int iRow);
  inline const double& operator()(const int iRow) const;
  void Print() const;

private:
  int m_iRows;
  double* m_pdVec;
};

#include "VectorI.h"

#endif//VECTOR_H
