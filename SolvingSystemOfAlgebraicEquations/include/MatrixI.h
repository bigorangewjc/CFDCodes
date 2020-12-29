#include <iostream>

inline double **CMatrix::GetMat() const
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

inline double &CMatrix::operator()(const int iRow, const int iCol)
{
    if (nullptr == m_pdMat)
    {
        std::cout << "m_pdMat is nullptr!" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows - 1
                  << std::endl;
        abort();
    }
    if (iCol < 0 || iCol >= m_iCols)
    {
        std::cout << "iCol = " << iCol << " is out of range 0..." << m_iCols - 1
                  << std::endl;
        abort();
    }
    return m_pdMat[iRow][iCol];
}

inline const double &CMatrix::operator()(const int iRow, const int iCol) const
{
    if (nullptr == m_pdMat)
    {
        std::cout << "m_pdMat is nullptr!" << std::endl;
        abort();
    }
    if (iRow < 0 || iRow >= m_iRows)
    {
        std::cout << "iRow = " << iRow << " is out of range 0..." << m_iRows - 1
                  << std::endl;
        abort();
    }
    if (iCol < 0 || iCol >= m_iCols)
    {
        std::cout << "iCol = " << iCol << " is out of range 0..." << m_iCols - 1
                  << std::endl;
        abort();
    }
    return m_pdMat[iRow][iCol];
}

inline CMatrix &CMatrix::operator+(const CMatrix &objMat)
{
    if (m_iRows != objMat.GetNumRows())
    {
        std::cout << "ERROR: m_iRows = " << m_iRows << " is not equal to objMat.GetNumRows() = "
                  << objMat.GetNumRows() << std::endl;
        abort();
    }
    if (m_iCols != objMat.GetNumCols())
    {
        std::cout << "ERROR: m_iCols = " << m_iCols << " is not equal to objMat.GetNumCols() = "
                  << objMat.GetNumCols() << std::endl;
        abort();
    }
    for (int iI = 0; iI < m_iRows; iI++)
    {
        for (int iJ = 0; iJ < m_iCols; iJ++)
        {
            m_pdMat[iI][iJ] += objMat(iI, iJ);
        }
    }
    return *this;
}