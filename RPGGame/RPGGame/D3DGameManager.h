#pragma once

#include "header.h"
#include "StructDefine.h"
#include "D3DInput.h"
#include "D3DCamera.h"
#include "D3DSkyBox.h"

class CD3DGameManager
{
public:
	CD3DGameManager(LPDIRECT3DDEVICE9 _direct3dDivece);
	~CD3DGameManager(void);

	HRESULT Init(HWND hWnd,HINSTANCE hInstance);
	HRESULT SetMatrix();
	HRESULT SetItem();

	void Update();
	void Render();

public:
	LPDIRECT3DDEVICE9 m_pDirect3dDevice;

	CD3DInput *m_pInput;
	CD3DCamera *m_pCamera;
	CD3DSkyBox *m_pSkyBox;
};

