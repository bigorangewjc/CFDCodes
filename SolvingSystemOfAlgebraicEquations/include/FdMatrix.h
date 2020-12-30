#ifndef CFDMATRIX_H
#define CFDMATRIX_H

#include "Matrix.h"
#include "Field.h"

class CMatrix;
class CVector;
class CFdMatrix
{
public:
  CFdMatrix(const CFdMatrix &objMat);
  virtual ~CFdMatrix();
  inline CMatrix& GetMat();
  inline const CMatrix& GetMat() const;
  inline CVector& GetVec();
  inline const CVector& GetVec() const;
  inline CFdMatrix& operator+(const CFdMatrix& objFdMat);
  inline CFdMatrix& operator==(const CField& objField);
  void Print() const;

private:
    CMatrix& m_objMat;
    CVector& m_objSrc;
};

#include "FdMatrixI.h"

#endif //CFDMATRIX_H
