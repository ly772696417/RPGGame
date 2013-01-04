#pragma once 

//Geometry generation
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <tchar.h>
#include <math.h>

//STL
#include <string>
#include <vector>
#include <list>
#include <algorithm>

//D3D
#include <d3d9.h>
#include <d3dx9.h>

#include <dinput.h>
#include<d3dx9core.h>

#pragma  comment(lib,"d3d9.lib")
#pragma  comment(lib,"d3dx9.lib")

#pragma  comment(lib,"winmm.lib")
#pragma  comment(lib,"dinput8.lib")
#pragma  comment(lib,"dxguid.lib")

#include "Debug.h"

// Keyboard
#define KEYDOWN(vk_code)  ((GetAsyncKeyState(vk_code) & 0x8000)? 1 : 0)
#define KEYUP(vk_code)    ((GetAsyncKeyState(vk_code) & 0x8000)? 0 : 1)

//NameSpace
using namespace std;
