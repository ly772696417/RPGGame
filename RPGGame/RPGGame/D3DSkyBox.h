#pragma once

#include "header.h"

enum SKYBOX_SIDE
{
	TOP = 0,
	BOTTOM,
	LEFT,
	RIGHT,
	BACK,
	FRONT,
	NUMBER
};

struct SkyboxVertices{
	SkyboxVertices(){}
	SkyboxVertices(D3DXVECTOR3 tp, 
		float tu, float tv)
	{
		pos = tp;
		u = tu;
		v = tv;
	}
	D3DVECTOR	pos;
	float		u;
	float		v;
	static const DWORD	FVF;
};

class CD3DSkyBox
{
public:
	CD3DSkyBox(LPDIRECT3DDEVICE9  _pDirext3dDevice9);
	~CD3DSkyBox(void);

	HRESULT	Init();
	HRESULT	InitVertices();
	HRESULT	InitTexture();

	HRESULT	SetSkyBoxTexture( SKYBOX_SIDE side , const char* texture );

	HRESULT	Draw(int flag);

	void	Render(D3DXVECTOR3 _position);
	void	RenderReflect(D3DXVECTOR3 _position, float waterLevel);

private:
	LPDIRECT3DDEVICE9		m_pDirect3dDevice;
	LPDIRECT3DVERTEXBUFFER9 m_Buffer[NUMBER];
	LPDIRECT3DTEXTURE9		m_Texture[NUMBER];
	SkyboxVertices			m_Verts[6][4]; 

	char* SKYBOX_TOP;
	char* SKYBOX_BOTTOM;
	char* SKYBOX_LEFT;
	char* SKYBOX_RIGHT;
	char* SKYBOX_BACK;
	char* SKYBOX_FRONT;
};

