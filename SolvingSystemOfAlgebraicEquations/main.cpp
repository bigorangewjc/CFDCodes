#include <iostream>
#include <ctime>
#include "GaussSolver.h"
#include "LUSolver.h"
#include "Matrix.h"
#include "Vector.h"

int main()
{
  std::cout << "\nInitial setup:" << std::endl;
  // Initialize matrix A and vector b
  int iRank = 3;
  CMatrix *pobjMatAGauss = new CMatrix(iRank, iRank);
  pobjMatAGauss->SetElement(0, 0, 1.0 /2.0);
  pobjMatAGauss->SetElement(0, 1, 2.0 /3.0);
  pobjMatAGauss->SetElement(0, 2, 3.0 /4.0);
  pobjMatAGauss->SetElement(1, 0, 1.0 /6.0);
  pobjMatAGauss->SetElement(1, 1, 5.0 /12.0);
  pobjMatAGauss->SetElement(1, 2, 11.0/20.0);
  pobjMatAGauss->SetElement(2, 0, 1.0 /12.0);
  pobjMatAGauss->SetElement(2, 1, 3.0 /10.0);
  pobjMatAGauss->SetElement(2, 2, 13.0/30.0);
  pobjMatAGauss->Display();
  CVector *pobjVecBGauss= new CVector(iRank);
  pobjVecBGauss->SetElement(0, 1.0);
  pobjVecBGauss->SetElement(1, 1.0/2.0);
  pobjVecBGauss->SetElement(2, 1.0/3.0);
  pobjVecBGauss->Display();
  // Clone A-Gauss to A-LU and clone b-Guass to b-LU
  CMatrix* pobjMatALU = new CMatrix(*pobjMatAGauss);
  CVector* pobjVecBLU = new CVector(*pobjVecBGauss); 
  // Initialize GaussSolver
  CGaussSolver *pobjGaussSolver = new CGaussSolver(*pobjMatAGauss, *pobjVecBGauss);
  // Solve linear equation system by GaussSolver
  clock_t tBegin = clock();
  pobjGaussSolver->Solve();
  double dInterval = double(clock() - tBegin) / 1000;
  std::cout << "\nAfter Gauss elimination:" << std::endl;
  pobjMatAGauss->Display();
  std::cout << "\nGaussSolver solution:" << std::endl;
  pobjVecBGauss->Display();
  std::cout << "\nTime: " << dInterval << "s"<< std::endl;

  // Initialize LUSolver
  CLUSolver *pobjLUSolver = new CLUSolver(*pobjMatALU, *pobjVecBLU);
  // Solve linear equation system by LUSolver
  tBegin = clock();
  pobjLUSolver->Solve();
  dInterval = double(clock() - tBegin) / 1000;
  std::cout << "\nAfter LU factorization:" << std::endl;
  pobjMatALU->Display();
  std::cout << "\nLUSolver solution:" << std::endl;
  pobjVecBLU->Display();
  std::cout << "\nTime: " << dInterval << "s"<< std::endl;

  pobjVecBLU->SetElement(0, 1.0);
  pobjVecBLU->SetElement(1, 1.0/2.0);
  pobjVecBLU->SetElement(2, 1.0/3.0);
  tBegin = clock();
  pobjLUSolver->SolveNewB(*pobjVecBLU);
  dInterval = double(clock() - tBegin) / 1000;
  std::cout << "\nLUSolver solution of new B:" << std::endl;
  pobjVecBLU->Display();
  std::cout << "\nTime: " << dInterval << "s"<< std::endl;

  return 0;
};
