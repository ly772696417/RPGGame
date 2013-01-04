#include "D3DGameManager.h"


CD3DGameManager::CD3DGameManager(LPDIRECT3DDEVICE9 _direct3dDivece)
{
	m_pDirect3dDevice = _direct3dDivece;
	m_pInput = new CD3DInput();
	m_pCamera = new CD3DCamera();
	m_pSkyBox = new CD3DSkyBox(m_pDirect3dDevice);
}


CD3DGameManager::~CD3DGameManager(void)
{
	m_pInput->~CD3DInput();
	m_pCamera->~CD3DCamera();
}

HRESULT CD3DGameManager::Init(HWND hWnd,HINSTANCE hInstance){
	m_pInput->InitInput(hWnd,hInstance);
	m_pSkyBox->Init();

	return S_OK;
}

void CD3DGameManager::Update(){
	m_pDirect3dDevice->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
	m_pDirect3dDevice->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);
	
	m_pInput->ReadMouse();
	m_pCamera->ProcInput(m_pInput);

	SetItem();
}

void CD3DGameManager::Render(){
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	SetMatrix();
	
	m_pSkyBox->Render(m_pCamera->getPosition());

	m_pDirect3dDevice->SetTransform(D3DTS_WORLD,&matWorld);

}

HRESULT CD3DGameManager::SetMatrix(){
	D3DXMATRIX matView;
	m_pCamera->getViewMatrix(&matView);
	m_pDirect3dDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIX matProjection;
	D3DXMatrixPerspectiveFovLH(&matProjection, D3DX_PI/3, (GetSystemMetrics(SM_CXSCREEN)*1.0f)/GetSystemMetrics(SM_CYSCREEN), 
		0.001f, 100000.0f );
	m_pDirect3dDevice->SetTransform(D3DTS_PROJECTION, &matProjection);

	return S_OK;
}

HRESULT CD3DGameManager::SetItem(){
	if(KEYDOWN('1')){
		m_pDirect3dDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_WIREFRAME);
	}
	if(KEYDOWN('2')){
		m_pDirect3dDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
	}
	if(KEYDOWN('3')){
		m_pDirect3dDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_POINT);
	}

	return S_OK;
}