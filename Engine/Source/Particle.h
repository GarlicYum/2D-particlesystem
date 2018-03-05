#pragma once

#include "Vec2D.h"
#include "../Graphics.h"
#include "ParticleSystemData.h"

class Particle
{
public:
	Particle(ParticleData& data);
	void AddVelocity(const Vec2D& velocity);
	bool IsDead() const;
	void Draw(Graphics& gfx);
	void Advance(float dt);

private:
	ParticleData m_Data;
	bool m_Dead;
	Color m_Color;
	float m_TotalLifeTime;
};