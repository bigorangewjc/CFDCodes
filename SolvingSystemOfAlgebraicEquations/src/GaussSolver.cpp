#include "GaussSolver.h"
#include <iostream>
#include "Matrix.h"
#include "Vector.h"

CGaussSolver::CGaussSolver(const CMatrix &objMatA, const CVector &objVecB)
    : ISolver::ISolver(objMatA, objVecB)
{
}

CGaussSolver::~CGaussSolver()
{
}

void CGaussSolver::Solve(CVector &objVecX)
{
    m_objMat.Print();
    // Forward elimination
    // Complexity: (N-1)*(N-i)*(N-i+1), i = 1,...,N-1
    // Elimilate the iColElim-th variable of X for rows below row iColElim of matrix A
    for (int iColElim = 0; iColElim < m_iCols - 1; iColElim++)
    {
        for (int iRow = iColElim + 1; iRow < m_iRows; iRow++)
        {
            // The element located in lower triangle of matrix will be eliminated
            //   to be zero, so the ratio of the element in lower triangle of matrix
            //   and the diagonal element is zero after eliminating. As a result,
            //   we need to store the quotient in a new variable dRatio.
            double dRatio = m_objMat(iRow, iColElim) / m_objMat(iColElim, iColElim);
            // In fact, there's no need to calculate elements aligned in column iColElim
            for (int iCol = iColElim; iCol < m_iCols; iCol++)
            {
                m_objMat(iRow, iCol) -= dRatio * m_objMat(iColElim, iCol);
            }
            m_objVecB(iRow) -= dRatio * m_objVecB(iColElim);
        }
    }
    m_objMat.Print();
    // Backward substitution
    objVecX(m_iRows - 1) =
        m_objVecB(m_iRows - 1) / m_objMat(m_iRows - 1, m_iCols - 1);
    for (int iRow = m_iRows - 2; iRow >= 0; iRow--)
    {
        double dSum = 0;
        for (int iCol = iRow + 1; iCol < m_iCols; iCol++)
        {
            dSum += m_objMat(iRow, iCol) * objVecX(iCol);
        }
        objVecX(iRow) = (m_objVecB(iRow) - dSum) / m_objMat(iRow, iRow);
    }
}