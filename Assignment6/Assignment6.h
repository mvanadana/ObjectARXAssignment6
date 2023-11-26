// Assignment6.h : main header file for the Assignment6 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CAssignment6App
// See Assignment6.cpp for the implementation of this class
//

class CAssignment6App : public CWinApp
{
public:
	CAssignment6App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
