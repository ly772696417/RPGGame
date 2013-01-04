#include "D3DSkyBox.h"

const DWORD	SkyboxVertices::FVF = (D3DFVF_XYZ|D3DFVF_TEX1);

CD3DSkyBox::CD3DSkyBox(LPDIRECT3DDEVICE9 _pDirext3dDevice9)
{
	m_pDirect3dDevice = _pDirext3dDevice9;

	SKYBOX_TOP =			"Res\\Pic\\SkyBoxImage\\top.jpg";
	SKYBOX_BOTTOM =	"Res\\Pic\\SkyBoxImage\\bottom.jpg";
	SKYBOX_LEFT =			"Res\\Pic\\SkyBoxImage\\left.jpg";
	SKYBOX_RIGHT =		"Res\\Pic\\SkyBoxImage\\right.jpg";
	SKYBOX_FRONT =		"Res\\Pic\\SkyBoxImage\\front.jpg";
	SKYBOX_BACK =			"Res\\Pic\\SkyBoxImage\\back.jpg";
}


CD3DSkyBox::~CD3DSkyBox(void)
{
}

HRESULT CD3DSkyBox::Init(){
	if (FAILED(InitVertices()))
	{
		return E_FAIL;
	}

	if (FAILED(InitTexture()))
	{
		return E_FAIL;
	}

	return S_OK;
}

HRESULT CD3DSkyBox::InitVertices(){
	const float size = 10.0f;
	const float o = 0.0f;
	const float t = 1.0f;

	// top
	m_Verts[TOP][0].pos = D3DXVECTOR3(-size,size,size);m_Verts[TOP][0].u =o;m_Verts[TOP][0].v =t;
	m_Verts[TOP][1].pos = D3DXVECTOR3(-size,size,-size);m_Verts[TOP][1].u =o;m_Verts[TOP][1].v =o;
	m_Verts[TOP][2].pos = D3DXVECTOR3(size,size,size);m_Verts[TOP][2].u =t;m_Verts[TOP][2].v =t;
	m_Verts[TOP][3].pos = D3DXVECTOR3(size,size,-size);m_Verts[TOP][3].u =t;m_Verts[TOP][3].v =o;

	// bottom
	m_Verts[BOTTOM][0].pos = D3DXVECTOR3(-size,-size,-size);m_Verts[BOTTOM][0].u =o;m_Verts[BOTTOM][0].v =t;
	m_Verts[BOTTOM][1].pos = D3DXVECTOR3(-size,-size,size);m_Verts[BOTTOM][1].u =o;m_Verts[BOTTOM][1].v =o;
	m_Verts[BOTTOM][2].pos = D3DXVECTOR3(size,-size,-size);m_Verts[BOTTOM][2].u =t;m_Verts[BOTTOM][2].v=t;
	m_Verts[BOTTOM][3].pos = D3DXVECTOR3(size,-size,size);m_Verts[BOTTOM][3].u = t;m_Verts[BOTTOM][3].v =o;

	// left
	m_Verts[LEFT][0].pos = D3DXVECTOR3(-size,-size,-size);m_Verts[LEFT][0].u =o;m_Verts[LEFT][0].v =t;
	m_Verts[LEFT][1].pos = D3DXVECTOR3(-size,size,-size);m_Verts[LEFT][1].u = o;m_Verts[LEFT][1].v =o;
	m_Verts[LEFT][2].pos = D3DXVECTOR3(-size,-size,size);m_Verts[LEFT][2].u = t;m_Verts[LEFT][2].v =t;
	m_Verts[LEFT][3].pos = D3DXVECTOR3(-size,size,size);m_Verts[LEFT][3].u = t;m_Verts[LEFT][3].v = o;

	// right
	m_Verts[RIGHT][0].pos = D3DXVECTOR3(size,-size,size);m_Verts[RIGHT][0].u = o;m_Verts[RIGHT][0].v =t;
	m_Verts[RIGHT][1].pos = D3DXVECTOR3(size,size,size);m_Verts[RIGHT][1].u =o;m_Verts[RIGHT][1].v =o;
	m_Verts[RIGHT][2].pos = D3DXVECTOR3(size,-size,-size);m_Verts[RIGHT][2].u =t;m_Verts[RIGHT][2].v =t;
	m_Verts[RIGHT][3].pos = D3DXVECTOR3(size,size,-size);m_Verts[RIGHT][3].u =t;m_Verts[RIGHT][3].v =o;

	// back
	m_Verts[BACK][0].pos = D3DXVECTOR3(size,-size,-size);m_Verts[BACK][0].u =o;m_Verts[BACK][0].v =t;
	m_Verts[BACK][1].pos = D3DXVECTOR3(size,size,-size);m_Verts[BACK][1].u =o;m_Verts[BACK][1].v =o;
	m_Verts[BACK][2].pos = D3DXVECTOR3(-size,-size,-size);m_Verts[BACK][2].u =t;m_Verts[BACK][2].v =t;
	m_Verts[BACK][3].pos = D3DXVECTOR3(-size,size,-size);m_Verts[BACK][3].u =t;m_Verts[BACK][3].v =o;

	// front
	m_Verts[FRONT][0].pos = D3DXVECTOR3(-size,-size,size);m_Verts[FRONT][0].u =o;m_Verts[FRONT][0].v =t;
	m_Verts[FRONT][1].pos = D3DXVECTOR3(-size,size,size);m_Verts[FRONT][1].u =o;m_Verts[FRONT][1].v =o;
	m_Verts[FRONT][2].pos = D3DXVECTOR3(size,-size,size);m_Verts[FRONT][2].u =t;m_Verts[FRONT][2].v =t;
	m_Verts[FRONT][3].pos = D3DXVECTOR3(size,size,size);m_Verts[FRONT][3].u =t;m_Verts[FRONT][3].v =o;

	for (int i = 0;i < 6;i++)
	{
		if (FAILED(m_pDirect3dDevice->CreateVertexBuffer(
			4*sizeof(SkyboxVertices),
			0,
			SkyboxVertices::FVF,
			D3DPOOL_MANAGED,
			&m_Buffer[i],
			NULL
			)))
		{
			return E_FAIL;
		}

		SkyboxVertices *pVertices;

		if (FAILED(m_Buffer[i]->Lock(0,4 * sizeof(SkyboxVertices),(void**)&pVertices,0)))
		{
			return E_FAIL;
		}

		pVertices[0] = m_Verts[i][0];
		pVertices[1] = m_Verts[i][1];
		pVertices[2] = m_Verts[i][2];
		pVertices[3] = m_Verts[i][3];

		m_Buffer[i]->Unlock();
	}

	return S_OK;
}

HRESULT CD3DSkyBox::InitTexture(){
	if(	FAILED(SetSkyBoxTexture(TOP,SKYBOX_TOP)))
		return S_FALSE;
	if(	FAILED(SetSkyBoxTexture(BOTTOM,SKYBOX_BOTTOM)))
		return S_FALSE;
	if(	FAILED(SetSkyBoxTexture(LEFT,SKYBOX_LEFT)))
		return S_FALSE;
	if(	FAILED(SetSkyBoxTexture(RIGHT,SKYBOX_RIGHT)))
		return S_FALSE;
	if(	FAILED(SetSkyBoxTexture(BACK,SKYBOX_BACK)))
		return S_FALSE;
	if(	FAILED(SetSkyBoxTexture(FRONT,SKYBOX_FRONT)))
		return S_FALSE;	

	return S_OK;
}

HRESULT CD3DSkyBox::SetSkyBoxTexture( SKYBOX_SIDE side , const char* texture ){
	if(FAILED(D3DXCreateTextureFromFile(m_pDirect3dDevice, texture,
		&m_Texture[side])))
	{
		return S_FALSE;
	}
	return S_OK;
}


void CD3DSkyBox::Render(D3DXVECTOR3 _position){
	D3DXMATRIX matWorld;
	D3DXMatrixTranslation(&matWorld,_position.x,_position.y,_position.z);
	m_pDirect3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

	m_pDirect3dDevice->SetRenderState(D3DRS_LIGHTING,false);
	m_pDirect3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
	m_pDirect3dDevice->SetTexture(0,NULL);

	if(FAILED(Draw(TOP)))
		return;
	if(FAILED(Draw(BOTTOM)))
		return;
	if(FAILED(Draw(LEFT)))
		return;
	if(FAILED(Draw(RIGHT)))
		return;
	if(FAILED(Draw(BACK)))
		return;
	if(FAILED(Draw(FRONT)))
		return;

	// »Ö¸´³õÊ¼×´Ì¬
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	m_pDirect3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);

	D3DXMatrixIdentity(&matWorld);
	m_pDirect3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
}

void CD3DSkyBox::RenderReflect(D3DXVECTOR3 _position, float waterLevel){
	D3DXVECTOR3 m_reflectPosition = _position;
	m_reflectPosition.y = 2 * waterLevel - m_reflectPosition.y;

	D3DXMATRIX  matWorld;
	D3DXMatrixTranslation(&matWorld,m_reflectPosition.x,m_reflectPosition.y,m_reflectPosition.z);

	m_pDirect3dDevice->SetTransform(D3DTS_WORLD, &matWorld);

	m_pDirect3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
	m_pDirect3dDevice->SetTexture(0,NULL);

	if(FAILED(Draw(TOP)))
		return;
	if(FAILED(Draw(BOTTOM)))
		return;
	if(FAILED(Draw(LEFT)))
		return;
	if(FAILED(Draw(RIGHT)))
		return;
	if(FAILED(Draw(BACK)))
		return;
	if(FAILED(Draw(FRONT)))
		return;

	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	m_pDirect3dDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	m_pDirect3dDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);

	D3DXMatrixIdentity(&matWorld);
	m_pDirect3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
}

HRESULT CD3DSkyBox::Draw(int flag){
	m_pDirect3dDevice->SetStreamSource(0,m_Buffer[flag],0,sizeof(SkyboxVertices));
	m_pDirect3dDevice->SetFVF( SkyboxVertices::FVF );
	m_pDirect3dDevice->SetTexture( 0 , m_Texture[flag] );
	m_pDirect3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
	return S_OK;
}