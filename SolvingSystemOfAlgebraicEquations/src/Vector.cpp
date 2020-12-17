#include "Vector.h"
#include <iostream>

CVector::CVector(int iRows)
  : m_iRows(iRows)
  , m_pdVector(nullptr)
{
  m_pdVector = new double [m_iRows]; 
  for (int i = 0; i < m_iRows; i++)
  {
    m_pdVector[i] = 0.0;
  }
}

CVector::CVector(CVector& objVector)
{
  m_iRows = objVector.GetRows();
  m_pdVector = new double [m_iRows];
  for (int i = 0; i < m_iRows; i++)
  {
    m_pdVector[i] = objVector.GetElement(i);
  }
}

CVector::~CVector()
{
  delete[] m_pdVector;
}

int CVector::GetRows()
{
  return m_iRows;
}

double CVector::GetElement(int iRow)
{
  return m_pdVector[iRow];
}

void CVector::SetElement(int iRow, double dVal)
{
  if (nullptr == m_pdVector)
  {
    std::cout << "m_pdVector has not been initialized!" << std::endl;
    return;
  }
  m_pdVector[iRow] = dVal;
}

double* CVector::GetVector()
{
  return m_pdVector;
}

void CVector::Display()
{
  std::cout << "m_pdVector = " << std::endl;
  std::cout << "[" << m_pdVector[0] << std::endl;
  for (int iRow = 1; iRow < m_iRows-1; iRow++)
  {
    std::cout << " " << m_pdVector[iRow] << std::endl;;
  }
  std::cout << " " << m_pdVector[m_iRows-1] << "]" << std::endl;
}
