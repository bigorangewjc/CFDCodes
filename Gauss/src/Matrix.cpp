#include "Matrix.h"
#include <iostream>

CMatrix::CMatrix(int iRows, int iColumns)
  : m_iRows(iRows)
  , m_iColumns(iColumns)
  , m_pdMatrix(nullptr)
{
  m_pdMatrix = new double* [m_iRows];
  for (int i = 0; i < m_iRows; i++)
  {
    m_pdMatrix[i] = new double [m_iColumns];
    for (int j = 0; j < m_iColumns; j++)
    {
      if (i == j)
      {
        m_pdMatrix[i][j] = 10.0;
      }
      else
      {
        m_pdMatrix[i][j] = 1.0;
      }
    }
  }
}

CMatrix::CMatrix(CMatrix& objMatrix)
{
  m_iRows = objMatrix.GetRows();
  m_iColumns = objMatrix.GetColumns();
  m_pdMatrix = new double* [m_iColumns];
  for (int i = 0; i < m_iRows; i++)
  {
    m_pdMatrix[i] = new double [m_iColumns];
    for (int j = 0; j < m_iColumns; j++)
    {
      m_pdMatrix[i][j] = objMatrix.GetElement(i, j);
    }
  }
}

CMatrix::~CMatrix()
{
  for (int i = 0; i < m_iRows; i++)
  {
    delete[] m_pdMatrix[i];
  }
  delete[] m_pdMatrix;
}

int CMatrix::GetRows()
{
  return m_iRows;
}

int CMatrix::GetColumns()
{
  return m_iColumns;
}

double CMatrix::GetElement(int iRow, int iColumn)
{
  return m_pdMatrix[iRow][iColumn];
}

void CMatrix::SetElement(int iRow, int iColumn, double dVal)
{
  if (nullptr == m_pdMatrix)
  {
    std::cout << "m_pdMatrix has not been initialized!" << std::endl;
    return;
  }
  m_pdMatrix[iRow][iColumn] = dVal;
}

double** CMatrix::GetMat()
{
  return m_pdMatrix; 
}

void CMatrix::Display()
{
  using namespace std;
  if (nullptr == m_pdMatrix)
  {
    std::cout << "Matrix has not been initialized!" << std::endl;
    return;
  }
  std::cout << "m_pdMatrix = " << std::endl;
  for (int iRow = 0; iRow < m_iRows; iRow++)
  {
    if (0 == iRow)
    {
      std::cout << "[";
    }
    else
    {
      std::cout << " ";
    }
    for (int iCol = 0; iCol < m_iColumns; iCol++)
    {
      std::cout << m_pdMatrix[iRow][iCol];
      if (m_iColumns-1 != iCol)
      {
        cout << ", ";
      }
    }
    if (m_iRows-1 != iRow)
    {
      std::cout << std::endl;
    }
    else
    {
      std::cout << "]" << std::endl;
    }
  }
}
