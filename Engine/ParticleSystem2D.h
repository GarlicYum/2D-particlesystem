#pragma once

#include "Source/Particle.h"
#include "Graphics.h"
#include "Source/Vec2D.h"
#include "Source/ParticleSystemData.h"
#include <vector>

class ParticleSystem2D
{
public:
	ParticleSystem2D(ParticleSystemData& data);
	ParticleSystem2D() = default;
	void Advance(float dt);
	void Render(Graphics& gfx);

private:
	void Spawn();

	ParticleSystemData m_Data;
	std::vector<Particle> m_Particles;
	float m_SpawnTimer;
};