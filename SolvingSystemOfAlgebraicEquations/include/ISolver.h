#ifndef ISOLVER_H
#define ISOLVER_H

class CVector;
class CMatrix;
class ISolver
{
public:
    ISolver(){};
    virtual ~ISolver(){};
    virtual void Solve(CVector& objVecX) = 0;
};

#endif//ISOLVER_H
