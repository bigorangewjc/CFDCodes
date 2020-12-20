#ifndef ISOLVER_H
#define ISOLVER_H

class CVector;
class CMatrix;
class ISolver
{
public:
    ISolver(const CMatrix& objMat, const CVector& objVecB);
    virtual ~ISolver();
    void SetNewMat(const CMatrix& objMat);
    void SetNewVecB(const CVector& objVecB);
    virtual void Solve(CVector& objVecX) = 0;

protected:
    int m_iRows;
    int m_iCols;
    const CMatrix& m_objMat;  
    const CVector& m_objVecB;
};
#endif//ISOLVER_H
