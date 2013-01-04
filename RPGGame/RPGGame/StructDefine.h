#pragma once
#include "header.h"

template<class COM> 
void Release(COM t)
{
	if( t )
	{
		t->Release();
		t = NULL;
	}
}

template<class POINT> 
void Delete(POINT t)
{
	if( t )
	{
		delete t;
		t = NULL;
	}
}

struct VERTEX
{
	D3DXVECTOR3		position;
	D3DXVECTOR3		normalize ;
	DWORD        color;
	FLOAT        tu,tv;
};
#define D3DFVF_VERTEX (D3DFVF_XYZ |D3DFVF_NORMAL|D3DFVF_TEX1| D3DFVF_DIFFUSE)

//地形相关
struct TerrainVertex
{
	TerrainVertex();
	TerrainVertex(float x, float y, float z, float nx, float ny, float nz, 
		float tiledU, float tiledV, float nonTiledU, float nonTiledV);
	TerrainVertex(const D3DXVECTOR3& p, const D3DXVECTOR3& n, 
		const D3DXVECTOR2& tiledUV, const D3DXVECTOR2& nonTiledUV);

	static IDirect3DVertexDeclaration9* DECL;

	D3DXVECTOR3 pos;
	D3DXVECTOR3 tangent;
	D3DXVECTOR3 binormal;
	D3DXVECTOR3 normal;
	D3DXVECTOR2 tiledTexC;
	D3DXVECTOR2 nonTiledTexC;

};

struct TerrainInitInfo
{
	int numVertRows;  
	int numVertCols; 
	float cellSpacing;
	std::string terrainFXFilename;
	std::string heightMapFilename;
	std::string layerMapFilename0;
	std::string layerMapFilename1;
	std::string layerMapFilename2;
	std::string blendMapFilename;
	std::string normalMapFilename;
	std::string detailMapFilename;
	D3DXVECTOR2 texScale;
	D3DXVECTOR3 dirToSun;
	float       heightScale;
};

//静态模型相关;
struct Ray
{
	D3DXVECTOR3 origin;
	D3DXVECTOR3 direction;
};

struct MeshLoadInfo{
	string meshName;
	string meshPath;
	D3DXVECTOR3 pos;
	D3DXQUATERNION rotate;
	D3DXVECTOR3 scale;

};

struct SkinMeshLoadInfo{
	string meshName;
	string meshPath;
	string action;
	D3DXVECTOR3 pos;
	float angle;
	float scale;

};

//碰撞相关
struct BoundingSphere
{
	float _radius;
	D3DXVECTOR3 _center;
};
struct BoundingBox
{
	D3DXVECTOR3 _max;
	D3DXVECTOR3 _min;
};

//旋转相关
enum ROTATE
{
	XAXIS=0,YAXIS,ZAXIS
};

//输入设备相关
#define DINPUT_BUFFERSIZE 16

typedef struct  MouseState
{
	bool left;
	bool right;
	POINT pos;
}MSTATE,*PMSTATE;

struct CKeyControl
{
	unsigned int m_Up;
	unsigned int m_Down;
	unsigned int m_Left;
	unsigned int m_Right;
};