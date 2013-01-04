#pragma once

#include "header.h"
#include "StructDefine.h"

#include "D3DGameManager.h"

class CD3DInit
{
public:
	CD3DInit(void);
	~CD3DInit(void);

	BOOL GameInit(HWND hWnd,HINSTANCE hInstance);
	HRESULT InitD3D(HWND hWnd);
	void Render();

private:
	LPDIRECT3D9 g_pDirext3d9;
	LPDIRECT3DDEVICE9 g_pDirect3dDevice9;

	CD3DGameManager *g_pGameManager;
};

