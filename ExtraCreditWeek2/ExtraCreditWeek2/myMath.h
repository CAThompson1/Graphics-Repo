#pragma once
#include "Defines.h"
float implicitLineEq(Vertex start, Vertex end, Vertex testPoint)
{
	//(Y1 – Y2)x + (X2 – X1)y + X1Y2 – Y1X2
	float ansReturn = (start.Position.y - end.Position.y) * testPoint.Position.x + (end.Position.x - start.Position.x) * testPoint.Position.y + start.Position.x * end.Position.y - start.Position.y * end.Position.x;
	return ansReturn;
}
Vertex FindBarycentric(Vertex A, Vertex B, Vertex C, Vertex testPoint)
{
	Vertex temp = { 0 };
	//Barycentric Interpolation: X = A * alpha + B * beta + C * gamma
	float distAlpha = implicitLineEq(B, C, testPoint);
	float distA = implicitLineEq(B, C, A);
	float alphaWeight = distAlpha / distA;

	float distBeta = implicitLineEq(A, C, testPoint);
	float distB = implicitLineEq(A, C, B);
	float BetaWeight = distBeta / distB;

	float distGamma = implicitLineEq(A, B, testPoint);
	float distC = implicitLineEq(A, B, C);
	float gammaWeight = distGamma / distC;

	temp.Position.x = alphaWeight;
	temp.Position.y = BetaWeight;
	temp.Position.z = gammaWeight;

	return temp;
}