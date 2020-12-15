#ifndef MATRIX_H
#define MATRIX_H

class CMatrix
{
public:
  CMatrix(int iRows, int iColumns);
  CMatrix(CMatrix &objMatrix);
  virtual ~CMatrix();
  void Display();
  int GetColumns();
  double GetElement(int iRow, int iColumn);
  double **GetMat();
  int GetRows();
  void SetElement(int iRow, int iColumn, double dVal);

private:
  int m_iColumns;
  int m_iRows;
  double **m_pdMatrix;
};
#endif //MATRIX_H
