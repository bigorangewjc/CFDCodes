#include "Matrix.h"
#include <iostream>

CMatrix::CMatrix(int iRows, int iCols)
    : m_iRows(iRows)
    , m_iCols(iCols)
    , m_pdMat(nullptr)
{
    m_pdMat = new double *[m_iRows];
    for (int i = 0; i < m_iRows; i++)
    {
        m_pdMat[i] = new double[m_iCols];
        for (int j = 0; j < m_iCols; j++)
        {
            if (i == j)
            {
                m_pdMat[i][j] = 10.0;
            }
            else
            {
                m_pdMat[i][j] = 1.0;
            }
        }
    }
}

CMatrix::CMatrix(const CMatrix& objMat)
{
    if (nullptr == objMat.GetMat())
    {
        std::cout << "objMat is nullptr!" << std::endl;
        abort();
    }
    m_iRows = objMat.GetNumRows();
    m_iCols = objMat.GetNumCols();
    m_pdMat = new double *[m_iRows];
    for (int i = 0; i < m_iRows; i++)
    {
        m_pdMat[i] = new double[m_iCols];
        for (int j = 0; j < m_iCols; j++)
        {
            m_pdMat[i][j] = objMat(i, j);
        }
    }
}

CMatrix::~CMatrix()
{
    for (int i = 0; i < m_iRows; i++)
    {
        delete[] m_pdMat[i];
    }
    delete[] m_pdMat;
}

inline double** CMatrix::GetMat() const
{
    return m_pdMat;
}

inline int CMatrix::GetNumRows() const
{
    return m_iRows;
}

inline int CMatrix::GetNumCols() const
{
    return m_iCols;
}

inline double &CMatrix::operator()(const int iRow, const int iCol) const
{
    if (nullptr == m_pdMat)
    {
        std::cout << "m_pdMat is nullptr!" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows-1
                  << std::endl;
        abort();
    }
    if (iCol < 0 || iCol >= m_iCols)
    {
        std::cout << "iCol = " << iCol << " is out of range 0..." << m_iCols-1
                  << std::endl;
        abort();
    }
    return m_pdMat[iRow][iCol];
}

void CMatrix::Print() const
{
    using namespace std;
    if (nullptr == m_pdMat)
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
        for (int iCol = 0; iCol < m_iCols; iCol++)
        {
            std::cout << m_pdMat[iRow][iCol];
            if (m_iCols - 1 != iCol)
            {
                cout << ", ";
            }
        }
        if (m_iRows - 1 != iRow)
        {
            std::cout << std::endl;
        }
        else
        {
            std::cout << "]" << std::endl;
        }
    }
}