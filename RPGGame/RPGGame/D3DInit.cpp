#include "D3DInit.h"


CD3DInit::CD3DInit(void)
{
	g_pDirext3d9 = NULL;
	g_pDirect3dDevice9 = NULL;
}

CD3DInit::~CD3DInit(void)
{
	Release(g_pDirext3d9);
	Release(g_pDirect3dDevice9);
}

BOOL CD3DInit::GameInit(HWND hWnd,HINSTANCE hInstance){
	
	if (SUCCEEDED(this->InitD3D(hWnd)))
	{
		g_pGameManager = new CD3DGameManager(g_pDirect3dDevice9);
		g_pGameManager->Init(hWnd,hInstance);

		return TRUE;
	}
	else
	{
		return FALSE;
	}
	return TRUE;
}

HRESULT CD3DInit::InitD3D(HWND hWnd){
	if (!(g_pDirext3d9= Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	D3DDISPLAYMODE d3ddm;
	if (FAILED(g_pDirext3d9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,&d3ddm)))
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp,sizeof(d3dpp));
	//d3dpp.AutoDepthStencilFormat = D3DFMT_D32;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.BackBufferFormat = d3ddm.Format;
	d3dpp.BackBufferHeight = d3ddm.Height;
	d3dpp.BackBufferWidth = d3ddm.Width;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	//d3dpp.Windowed = false;
	d3dpp.Windowed = true;

	if (FAILED(g_pDirext3d9->CreateDevice(D3DADAPTER_DEFAULT,
																 D3DDEVTYPE_HAL,
																 hWnd,
																 D3DCREATE_HARDWARE_VERTEXPROCESSING,
															     &d3dpp,
																 &g_pDirect3dDevice9
																 )
					)
		)
	{
		return E_FAIL;
	}

	return S_OK;
}

void CD3DInit::Render(){
	if (NULL == g_pDirect3dDevice9)
	{
		return;
	}

	g_pDirect3dDevice9->Clear(0,NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0,0,0),1.0f,0);
	g_pDirect3dDevice9->BeginScene();

	g_pGameManager->Update();
	g_pGameManager->Render();

	g_pDirect3dDevice9->EndScene();
	g_pDirect3dDevice9->Present(NULL,NULL,NULL,NULL);
}
