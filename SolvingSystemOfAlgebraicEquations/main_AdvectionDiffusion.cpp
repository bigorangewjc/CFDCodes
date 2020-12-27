#ifdef JCWANG
#include <iostream>
#include "Field.h"
#include "LoadConfig.h"
#include "ThomasSolverFactory.h"
#include "ThomasSolver.h"

int main(int argc, char* argv[])
{
   // Load configuration
   CLoadConfig* pCLoadConfig = new CLoadConfig();
   std::string sFileName("config.ini");
   pCLoadConfig->ParseFile(sFileName);
   // Assign parameters to local variables
   double dD, dU, dLength, dDeltaT;
   int iNumPoints, iNumTimeSteps;
   pCLoadConfig->GetParam(std::string("D"), dD) ;
   pCLoadConfig->GetParam(std::string("U"), dU) ;
   pCLoadConfig->GetParam(std::string("Length"), dLength) ;
   pCLoadConfig->GetParam(std::string("DeltaT"), dDeltaT) ;
   pCLoadConfig->GetParam(std::string("NumPoints"), iNumPoints);
   pCLoadConfig->GetParam(std::string("NumTimeSteps"), iNumTimeSteps);
   // Create field
   CField* pCField = new CField();
   std::string sInitStrategy("sin");
   pCField->Initialize(iNumPoints, dLength, sInitStrategy);
   pCField->PrintField();
   // Create solver
   ISolverFactory* pThomasFactory = new CThomasSolverFactory();
   ISolver* pThomasSolver = pThomasFactory->CreateSolver();
   pThomasSolver->Solve();
   // Delete objects
   delete pThomasFactory;
   delete pThomasSolver;
   delete pCLoadConfig;
   return 0;
}
#endif
