// Assignment6.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Assignment6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static void listObjects()
{
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Get the current space object
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
		pDb->currentSpaceId(),
		AcDb::kForRead);
	// Create a new block iterator that will be used to
	// step through each object in the current space
	AcDbBlockTableRecordIterator* pItr;
	pBlockTableRecord->newIterator(pItr);
	AcDbEntity* pEnt;
	for (pItr->start(); !pItr->done(); pItr->step())
	{   // Get the entity and open it for read
		pItr->getEntity(pEnt, AcDb::kForRead);
		acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
		pEnt->close();
	}
	// Close the current space object
	pBlockTableRecord->close();
	// Remove the block iterator object from memory
	delete pItr;
	// Display the AutoCAD Text Window
	acedTextScr();
}
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
	switch (Msg) {
	case AcRx::kInitAppMsg:
		acrxUnlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		acutPrintf(L"\n Command Loaded");
		//below line for registering new command
		acedRegCmds->addCommand(_T("AUCommands"), _T("ListObjects"),
			_T("ListObjects"), ACRX_CMD_MODAL, listObjects);
		break;
	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\n Command Unloaded"));
		break;
	}
	return AcRx::kRetOK;

}



//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CAssignment6App

BEGIN_MESSAGE_MAP(CAssignment6App, CWinApp)
END_MESSAGE_MAP()


// CAssignment6App construction

CAssignment6App::CAssignment6App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CAssignment6App object

CAssignment6App theApp;


// CAssignment6App initialization

BOOL CAssignment6App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
