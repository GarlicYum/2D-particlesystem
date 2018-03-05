#pragma once

#include "Vec2D.h"

enum Shapes { SHAPE_CIRCLE, SHAPE_SQUARE };

struct ParticleSystemData
{
	Shapes shape;
	Vec2D gravity;
	Vec2D position;
	int spawnRate;
	float minSize;
	float maxSize;
	Color birthColor;
	Color deathColor;
	float lifeTime;
	Vec2D minVel;
	Vec2D maxVel;
};

struct ParticleData
{
	Vec2D position;
	Vec2D velocity;
	float size;
	Color birthColor;
	Color deathColor;
	Shapes shape;
	float lifeTime;
};