#include <iostream>
#include <ctime>
#include "ISolver.h"
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
  CMatrix& objMat = *(new CMatrix(iRank, iRank));
  CVector& objVecB = *(new CVector(iRank));
  CVector& objVecXGau = *(new CVector(iRank));
  CVector& objVecXLU = *(new CVector(iRank));
  CVector& objVecXJac = *(new CVector(iRank));
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
  // Initialize GaussSolver
  CGaussSolver *pobjGaussSolver = new CGaussSolver(objMat, objVecB);
  // Solve linear equation system by GaussSolver
  clock_t tBegin = clock();
  pobjGaussSolver->Solve(objVecXGau);
  double dInterval = double(clock() - tBegin) / 1000;
  std::cout << "\nGaussSolver solution:" << std::endl;
  objVecXGau.Print();
  std::cout << "\nTime: " << dInterval << "s"<< std::endl;

//   // Initialize LUSolver
//   CLUSolver *pobjLUSolver = new CLUSolver(objMat, objVecB);
//   // Solve linear equation system by LUSolver
//   tBegin = clock();
//   pobjLUSolver->Solve();
//   dInterval = double(clock() - tBegin) / 1000;
//   std::cout << "\nLUSolver solution:" << std::endl;
//   objVecXLU.Print();
//   std::cout << "\nTime: " << dInterval << "s"<< std::endl;

//   tBegin = clock();
//   pobjLUSolver->Solve();
//   dInterval = double(clock() - tBegin) / 1000;
//   std::cout << "\nLUSolver solution of new B:" << std::endl;
//   objVecXLU.Print();
//   std::cout << "\nTime: " << dInterval << "s\n"<< std::endl;

//   // Initialize JacobiSolver
//   CVector& objVecInit = *(new CVector(4));
//   CJacobiSolver *pobjJacobiSolver = new CJacobiSolver(
//     objMat, objVecB, objVecInit, 1.0e-5);
//   // Solve linear equation system by JacobiSolver
//   tBegin = clock();
//   pobjJacobiSolver->Solve();
//   dInterval = double(clock() - tBegin) / 1000;
//   std::cout << "\nJacobiSolver solution:" << std::endl;
//   objVecXJac.Print();
//   std::cout << "\nTime: " << dInterval << "s"<< std::endl;

  return 0;
};
