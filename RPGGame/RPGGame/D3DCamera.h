#pragma once

#include "header.h"
#include "StructDefine.h"
#include "D3DInput.h"

enum CameraType
{
	LANDOBJECT,
	AIRCRAFT
};

class CD3DCamera
{
public:
	CD3DCamera(void);
	~CD3DCamera(void);

	void strafe(float units);//right
	void fly(float units);//up
	void walk(float units);//look

	void pitch(float angle);//right ¸©Ñö
	void yaw(float angle);//up Æ«º½
	void roll(float angle);//look ¹ö¶¯

	void getViewMatrix(D3DXMATRIX *V);

	D3DXVECTOR3 getPosition();
	void setPosition(const D3DXVECTOR3 *pos);

	void ProcInput(CD3DInput *gameInput);

private:
	D3DXVECTOR3 g_vRight , g_vUp , g_vLook;
	D3DXVECTOR3 g_vPos;
	CD3DInput *m_input;
	CameraType m_cameraType;
};

