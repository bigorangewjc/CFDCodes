#include <iostream>
#include <ctime>
#include "ISolver.h"
#include "GaussSeidelSolver.h"
#include "GaussSolver.h"
#include "JacobiSolver.h"
#include "LUSolver.h"
#include "Matrix.h"
#include "Vector.h"

int main()
{
    std::cout << "\nInitial setup:" << std::endl;
    // Initialize matrix A and vector b
    int iRank = 4;
    CMatrix objMat(iRank, iRank);
    CVector objVecB(iRank);
    CVector objVecInit(iRank);
    CVector objVecNewB(iRank);
    CVector objVecXGau(iRank);
    CVector objVecXLU(iRank);
    CVector objVecXJac(iRank);
    CVector objVecXGS(iRank);
    objMat(0, 0) = 3;
    objMat(0, 1) = -1;
    objMat(0, 2) = 0;
    objMat(0, 3) = 0;
    objMat(1, 0) = -2;
    objMat(1, 1) = 6;
    objMat(1, 2) = -1;
    objMat(1, 3) = 0;
    objMat(2, 0) = 0;
    objMat(2, 1) = -2;
    objMat(2, 2) = 6;
    objMat(2, 3) = -1;
    objMat(3, 0) = 0;
    objMat(3, 1) = 0;
    objMat(3, 2) = -2;
    objMat(3, 3) = 7;
    objVecB(0) = 3;
    objVecB(1) = 4;
    objVecB(2) = 5;
    objVecB(3) = -3;
    objVecNewB(0) = 3;
    objVecNewB(1) = 4;
    objVecNewB(2) = 5;
    objVecNewB(3) = -3;
    // Initialize GaussSolver
    ISolver *pobjGaussSolver = new CGaussSolver(objMat, objVecB);
    // Solve linear equation system by GaussSolver
    clock_t tBegin = clock();
    pobjGaussSolver->Solve(objVecXGau);
    double dInterval = double(clock() - tBegin) / 1000;
    std::cout << "\nGaussSolver solution:" << std::endl;
    objVecXGau.Print();
    std::cout << "\nTime: " << dInterval << "s" << std::endl;

    // Initialize LUSolver
    ISolver *pobjLUSolver = new CLUSolver(objMat, objVecB);
    pobjLUSolver->SetDecomposeMethod("Gauss");
    // Solve linear equation system by LUSolver
    tBegin = clock();
    pobjLUSolver->Solve(objVecXLU);
    dInterval = double(clock() - tBegin) / 1000;
    std::cout << "\nLUSolver solution:" << std::endl;
    objVecXLU.Print();
    std::cout << "\nTime: " << dInterval << "s" << std::endl;

    tBegin = clock();
    pobjLUSolver->SolveNewB(objVecXLU, objVecB);
    dInterval = double(clock() - tBegin) / 1000;
    std::cout << "\nLUSolver solution of new B:" << std::endl;
    objVecXLU.Print();
    std::cout << "\nTime: " << dInterval << "s\n"
              << std::endl;

    // Initialize JacobiSolver
    ISolver *pobjJacobiSolver = new CJacobiSolver(objMat, objVecB);
    pobjJacobiSolver->SetTol(1.0e-7);
    pobjJacobiSolver->SetInitVec(objVecInit);
    // Solve linear equation system by JacobiSolver
    tBegin = clock();
    pobjJacobiSolver->Solve(objVecXJac);
    dInterval = double(clock() - tBegin) / 1000;
    std::cout << "\nJacobiSolver solution:" << std::endl;
    objVecXJac.Print();
    std::cout << "\nTime: " << dInterval << "s\n" << std::endl;

    // Initialize GaussSeidelSolver
    ISolver *pobjGaussSeidelSolver =
        new CGaussSeidelSolver(objMat, objVecB);
    pobjGaussSeidelSolver->SetTol(1.0e-5);
    pobjGaussSeidelSolver->SetInitVec(objVecInit);
    // Solve linear equation system by GaussSeidelSolver
    tBegin = clock();
    pobjGaussSeidelSolver->Solve(objVecXGS);
    dInterval = double(clock() - tBegin) / 1000;
    std::cout << "\nGaussSeidelSolver solution:" << std::endl;
    objVecXGS.Print();
    std::cout << "\nTime: " << dInterval << "s\n" << std::endl;

    return 0;
};
