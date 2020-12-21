#include "LUSolver.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CLUSolver::CLUSolver(const CMatrix &objMatA, const CVector &objVecB)
    : ISolver::ISolver(objMatA, objVecB)
    , m_sMethod("Crout")
{
}

CLUSolver::~CLUSolver()
{
}


void CLUSolver::SetDecomposeMethod(std::string sMethod)
{
    if ("Crout" != sMethod && "Gauss" != sMethod)
    {
        std::cout << "Unrecognized sMethod: " << sMethod << std::endl;
        abort();
    }
    m_sMethod = sMethod;
}

void CLUSolver::Solve(CVector &objVecX)
{
    if ("Crout" == m_sMethod)
    {
        LUFactorization();
    }
    else if ("Gauss" == m_sMethod)
    {
        LUFactorizationByGaussElimination();
    }
    ForwardSubstitution();
    BackwardSubstitution(objVecX);
}

void CLUSolver::SolveNewB(CVector &objVecX, const CVector &objVecB)
{
    if (m_iCols != objVecB.GetNumRows())
    {
        std::cout << "A's column number " << m_iCols
                  << " is not equal to new B's row number "
                  << objVecB.GetNumRows() << std::endl;
        abort();
    }
    for (int iRow = 0; iRow < m_iRows; iRow++)
    {
        m_objVecB(iRow) = objVecB(iRow);
        std::cout << objVecB(iRow) << std::endl;
    }
    ForwardSubstitution();
    BackwardSubstitution(objVecX);
}

void CLUSolver::LUFactorization()
{
    // The first row of U equals to that of A
    // Calculate the first column of L
    for (int iM = 1; iM < m_iRows; iM++)
    {
        m_objMat(iM, 0) /= m_objMat(0, 0);
    }
    // Calculate the rest of U and L
    for (int iI = 1; iI < m_iRows; iI++)
    {
        // Calcute iI-th row of U
        for (int iJ = iI; iJ < m_iCols; iJ++)
        {
            // iI is the real index minus one, so iK < iI
            for (int iK = 0; iK < iI; iK++)
            {
                m_objMat(iI, iJ) -= m_objMat(iI, iK) * m_objMat(iK, iJ);
            }
        }
        // Calculate iI-th column of L
        // The for loop will just return when iI = m_iRows-1, because of
        //   the loop condition is iM = iI+1 < m_iRows
        for (int iM = iI + 1; iM < m_iRows; iM++)
        {
            // iI is the real index minus one, so iK < iI
            for (int iK = 0; iK < iI; iK++)
            {
                m_objMat(iM, iI) -= m_objMat(iM, iK) * m_objMat(iK, iI);
            }
            m_objMat(iM, iI) /= m_objMat(iI, iI);
        }
    }
}

void CLUSolver::LUFactorizationByGaussElimination()
{
    for (int iElim = 0; iElim < m_iRows - 1; iElim++)
    {
        for (int iI = iElim + 1; iI < m_iRows; iI++)
        {
            // The elements in column iElim of U is zero, so we replace the zero
            //    in U by element of L at the same position
            m_objMat(iI, iElim) /= m_objMat(iElim, iElim);
            for (int iJ = iElim + 1; iJ < m_iCols; iJ++)
            {
                m_objMat(iI, iJ) -= m_objMat(iI, iElim) * m_objMat(iElim, iJ);
            }
        }
    }
}

void CLUSolver::ForwardSubstitution()
{
    // Calculate solution vector y in system of L y = b
    // The first element in vector y is equals to that in vector b
    // Calculate the rest elements in vector y
    for (int iI = 1; iI < m_iRows; iI++)
    {
        // iI is the real index minus one, so iJ < iI
        for (int iJ = 0; iJ < iI; iJ++)
        {
            // m_objMat is lower triangular matrix
            m_objVecB(iI) -= m_objMat(iI, iJ) * m_objVecB(iJ);
        }
    }
}

void CLUSolver::BackwardSubstitution(CVector &objVecX)
{
    // Calculate solution vector x in system of U x = y
    // Calculate the last element in vector x
    objVecX(m_iRows - 1) =
        m_objVecB(m_iRows - 1) / m_objMat(m_iRows - 1, m_iRows - 1);
    // Calculate the rest elements in vector x
    double dSum = 0;
    for (int iI = m_iRows - 2; iI >= 0; iI--)
    {
        dSum = 0;
        for (int iJ = iI + 1; iJ < m_iCols; iJ++)
        {
            // m_objMat is upper triangular matrix
            dSum += m_objMat(iI, iJ) * objVecX(iJ);
        }
        objVecX(iI) = (m_objVecB(iI) - dSum) / m_objMat(iI, iI);
    }
}