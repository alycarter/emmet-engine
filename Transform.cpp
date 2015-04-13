#include "Transform.h"

Transform::Transform()
{
	position = XMVectorSet(0, 0, 0, 1);
	rotation = XMQuaternionIdentity();
	scale = XMVectorSet(1, 1, 1, 1);
}


Transform::~Transform()
{

}

XMVECTOR * Transform::getPosition()
{
	return &position;
}

XMVECTOR * Transform::getRotation()
{
	return &rotation;
}

XMVECTOR * Transform::getScale()
{
	return &scale;
}

void Transform::getRotationMatrix(XMMATRIX * matrix)
{
	*matrix = XMMatrixRotationQuaternion(rotation);
}

void Transform::getForward(XMVECTOR * forward)
{
	XMMATRIX rot;
	getRotationMatrix(&rot);
	*forward = XMVector3Transform(XMVectorSet(0, 0, 1, 0), rot);
}

void Transform::getUp(XMVECTOR * up)
{
	XMMATRIX rot;
	getRotationMatrix(&rot);
	*up = XMVector3Transform(XMVectorSet(0, 1, 0, 0), rot);
}

void Transform::getLeft(XMVECTOR * left)
{
	XMMATRIX rot;
	getRotationMatrix(&rot);
	*left = XMVector3Transform(XMVectorSet(1, 0, 0, 0), rot);
}