#pragma once
#include "Component.h"

#include <DirectXMath.h>
using namespace DirectX;

#define TYPE_TRANSFORM "transform"

class Transform:
	public Component
{
public:
	Transform();
	~Transform();
	XMVECTOR * getPosition();
	XMVECTOR * getRotation();
	XMVECTOR * getScale();
	void getForward(XMVECTOR * forward);
	void getUp(XMVECTOR * up);
	void getLeft(XMVECTOR * left);
	void getRotationMatrix(XMMATRIX * matrix);
private:
	XMVECTOR position;
	XMVECTOR rotation;
	XMVECTOR scale;
};

