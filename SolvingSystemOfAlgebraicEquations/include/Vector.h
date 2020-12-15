#ifndef VECTOR_H
#define VECTOR_H

class CVector
{
public:
  CVector(int iRows);
  CVector(CVector& objVector);
  virtual ~CVector();
  void Display();
  double GetElement(int iRow);
  int GetRows();
  double* GetVector();
  void SetElement(int iRow, double dVal);

private:
  int m_iRows;
  double* m_pdVector;
};
#endif//VECTOR_H
