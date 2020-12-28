#ifndef CFDMATRIX_H
#define CFDMATRIX_H

class CFdMatrix
{
public:
  CFdMatrix(int iRows, int iCols);
  CFdMatrix(const CFdMatrix &objMat);
  virtual ~CFdMatrix();
  void Print() const;

private:
  int m_iCols;
  int m_iRows;
  double **m_pdMat;
};
#endif //CFDMATRIX_H
