#ifndef CFDMATRIX_H
#define CFDMATRIX_H

class CField;
class CMatrix;
class CVector;
class CFdMatrix
{
public:
  CFdMatrix(const CFdMatrix &objMat);
  virtual ~CFdMatrix();
  CMatrix& GetMat();
  CVector& GetVec();
  CFdMatrix& operator+(CFdMatrix& objFdMat);
  CFdMatrix& operator==(CField& objField);
  void Print() const;

private:
    CMatrix& m_objMat;
    CVector& m_objSrc;
};
#endif //CFDMATRIX_H
