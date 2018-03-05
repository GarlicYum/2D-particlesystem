#include "ParticleSystem2D.h"
#include <random>

ParticleSystem2D::ParticleSystem2D(ParticleSystemData& data) :
	 m_Data(data)
{
}

void ParticleSystem2D::Spawn()
{
	for (int i = 0; i < m_Data.spawnRate; i++)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<float> xVel(m_Data.minVel.x, m_Data.maxVel.x);
		std::uniform_real_distribution<float> yVel(m_Data.minVel.y, m_Data.maxVel.y);
		std::uniform_real_distribution<float> size(m_Data.minSize, m_Data.maxSize);

		ParticleData data;
		data.birthColor = m_Data.birthColor;
		data.deathColor = m_Data.deathColor;
		data.lifeTime = m_Data.lifeTime;
		data.position = m_Data.position;
		data.shape = m_Data.shape;
		data.size = size(rng);
		data.velocity = Vec2D(xVel(rng), yVel(rng));

		m_Particles.emplace_back(Particle(data));
	}
}

void ParticleSystem2D::Advance(float dt)
{
	Spawn();

	for (size_t i = m_Particles.size() - 1; i > 0; i--)
	{
		m_Particles[i].Advance(dt);
		m_Particles[i].AddVelocity(m_Data.gravity);
		if (m_Particles[i].IsDead())
			m_Particles.erase(m_Particles.begin() + i);
	}
}

void ParticleSystem2D::Render(Graphics& gfx)
{
	for (unsigned int i = 0; i < m_Particles.size(); i++)
		m_Particles[i].Draw(gfx);
}
