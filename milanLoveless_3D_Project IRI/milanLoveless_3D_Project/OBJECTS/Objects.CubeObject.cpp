//Objects.CubeObject.cpp
///////////////////////////////////////////////////

#include "..\GameCore.h"

namespace OBJECTS
{
	void CubeObject::_Initialize()
	{
		//Initialize Cube////////////////////////
		
		this->rotation = 0.0;

		//Bounding region for cube
		//float xmin = -100.0, xmax = 100.0;
		//float ymin = -100.0, ymax = 100.0;
		//float zmin = -100.0, zmax = 100.0;

		//Vertices for cube
		this->_mesh.num_v = 20;
		this->_mesh.vb = new _VERTEX4F[20];

		//Initialize cube verticies
		_VERTEX4F cube_v[] = {
			_VERTEX4F(0.0, 0.0, 0.0, 1.0), // 0
			_VERTEX4F(0.0, 50.0, -50.0, 1.0), // 1
			_VERTEX4F(50.0, 50.0, 0.0, 1.0), // 2
			_VERTEX4F(-50.0, 50.0, 0.0, 1.0), // 3
			_VERTEX4F(0.0, 100.0, 0.0, 1.0), //4
			_VERTEX4F(0.0, 50.0, 50.0, 1.0), // 5
			_VERTEX4F(-75.0, 50.0, -25.0, 1.0), // 6
			_VERTEX4F(-75.0, 50.0, 25.0, 1.0), // 7
			_VERTEX4F(-75.0, 0.0, 0.0, 1.0), // 8
			_VERTEX4F(-75.0, 100.0, 0.0, 1.0), // 9
			_VERTEX4F(-100.0, 50.0, 0.0, 1.0), // 10
			_VERTEX4F(75.0, 50.0, -25.0, 1.0), // 11
			_VERTEX4F(75.0, 50.0, 25.0, 1.0), // 12
			_VERTEX4F(75.0, 0.0, 0.0, 1.0), // 13
			_VERTEX4F(75.0, 100.0, 0.0, 1.0), //14
			_VERTEX4F(100.0, 50.0, 0.0, 1.0), // 15
			_VERTEX4F(0.0, 200.0, -50.0, 1.0), // 16
			_VERTEX4F(0.0, 200.0, 50.0, 1.0), // 17
			_VERTEX4F(50.0, 200.0, 0.0, 1.0), // 18
			_VERTEX4F(-50.0, 200.0, 0.0, 1.0), // 19
			_VERTEX4F(0.0, 300.0, 0.0, 1.0) // 20
		};

		for(int n = 0; n < 21; n++)
		{
			this->_mesh.vb[n] = cube_v[n];
		}

		// Triangles for cube
		this->_mesh.num_i = 32;
		this->_mesh.ib = new _TRIANGLE3I[32];
		
		_TRIANGLE3I cube_i[] = {
			{ 0, 1, 2 }, { 0, 3, 1 },
			{ 2, 1, 4 }, { 4, 1, 3 },
			{ 4, 3, 5 }, { 5, 2, 4 },
			{ 3, 0, 5 }, { 0, 2, 5 },

			{ 6, 9, 3 }, { 6, 10, 9 },
			{ 3, 8, 6 }, { 8, 10, 6 },
			{ 7, 10, 8 }, { 3, 7, 8 },
			{ 3, 9, 7 }, { 7, 9, 10 },

			{ 2, 14, 11 }, { 14, 15, 11 },
			{ 2, 11, 13 }, { 11, 15, 13 },
			{ 12, 15, 14 }, { 2, 12, 14 },
			{ 2, 13, 12 }, { 13, 15, 12 },

			{ 4, 16, 18 }, { 4, 19, 16 },
			{ 16, 19, 20 }, { 18, 16, 20 },
			{ 17, 18, 20 }, { 17, 20, 19 },
			{ 17, 4, 18 }, { 17, 19, 4 },
		};

		for(int n = 0; n < 32; n++)
		{
			this->_mesh.ib[n] = cube_i[n];
		}

		//Color channel for cube
		this->_mesh.num_c = 32;
		this->_mesh.cb = new _COLOR4F[32];

		_COLOR4F c0 = { 1.0, 1.0, 0.0, 0.0 };
		_COLOR4F c1 = { 1.0, 0.0, 0.0, 1.0 };
		_COLOR4F c2 = { 1.0, 0.0, 1.0, 0.0 };

		for(int n = 0; n < 24; n++)
		{
			if((n%3) == 0)
			{
				this->_mesh.cb[n] = c0;
			}
			if((n%3) == 1)
			{
				this->_mesh.cb[n] = c1;
			}
			if((n%3) == 2)
			{
				this->_mesh.cb[n] = c2;
			}
		}
	}



	void CubeObject::_Uninitialize()
	{
		delete [] this->_mesh.vb;
		delete [] this->_mesh.ib;
		delete [] this->_mesh.cb;
	}

	void CubeObject::_Draw(float *zb, int *video, int nWidth, int nHeight)
	{
		this->rotation += 3.0;
		for(int n = 0; n < this->_mesh.num_i; n++)
		{
			_TRIANGLE3I &triangle = this->_mesh.ib[n];
			
			_VERTEX4F v0 = this->_mesh.vb[triangle.a];
			_VERTEX4F v1 = this->_mesh.vb[triangle.b];
			_VERTEX4F v2 = this->_mesh.vb[triangle.c];

			_COLOR4F &c0 = this->_mesh.cb[triangle.a];
			_COLOR4F &c1 = this->_mesh.cb[triangle.b];
			_COLOR4F &c2 = this->_mesh.cb[triangle.c];
			
			_MATRIX16F nn;
			nn = _MATRIX16F::_Translate(_VERTEX4F(0.0, -150.0, 0.0, 0.0));
			v0 = nn._Multiply(v0);
			v1 = nn._Multiply(v1);
			v2 = nn._Multiply(v2);
			_MATRIX16F m;
			m = _MATRIX16F::_RotateZ(1.0*this->rotation);
			v0 = m._Multiply(v0);
			v1 = m._Multiply(v1);
			v2 = m._Multiply(v2);
			m = _MATRIX16F::_RotateY(1.5*this->rotation);
			v0 = m._Multiply(v0);
			v1 = m._Multiply(v1);
			v2 = m._Multiply(v2);

			_VERTEX4F origin(nWidth/2.0, nHeight/2.0, 0.0, 0.0);
			v0 = v0 + origin;
			v1 = v1 + origin;
			v2 = v2 + origin;

			_DrawTriangle(zb, video, nWidth, nHeight, v0, v1, v2, c0, c1, c2);
		}

	}

	void CubeObject::_RunAI()
	{

	}
}