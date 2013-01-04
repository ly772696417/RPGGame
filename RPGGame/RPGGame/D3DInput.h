#pragma once

#include "header.h"
#include "StructDefine.h"


class CD3DInput
{
public:
	CD3DInput(void);
	~CD3DInput(void);

	BOOL InitInput(HWND hWnd,HINSTANCE hInstance);
	BOOL ReadMouse();

public:
	LPDIRECTINPUT8 m_pDI;
	LPDIRECTINPUTDEVICE8 m_pMouse;

	MSTATE m_OldMState;
	MSTATE m_CurMState;

	int MouseX,MouseY;
};

