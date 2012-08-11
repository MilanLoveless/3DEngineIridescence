// GameCore.h
//////////////////////////////////////////////////////////////

#pragma once
//#ifndef __GAMECORE_H_
//#define __GAMECORE_H_

#include <Windows.h>
#include <dxerr.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <MMSYSTEM.h>
#include <dsound.h>
#include <iostream>

#include <stdio.h>

using namespace std;

// Include all of your further H files here
#include "CORE\CORE.Hardware.3D.h"
#include "CORE\CORE.Hardware.Drawing.3D.h"
#include "CORE\CORE.Hardware.3D.Texture.h"

#include "OLDCORE\OLDCORE.Software.Drawing.2D.h"

#include "OBJECTS\Objects.Primitives.h"
#include "OBJECTS\Objects.CubeObject.h"
#include "OBJECTS\Objects.GameObject.h"

#include "SCENES\SCENES.TestScene.h"

// Declare any further functions or variables here
void _OnInitialize();
void _OnUninitialize();
void _OnFrame();
/** Remember to declare variables "extern" **/

//#endif