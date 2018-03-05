#include "Particle.h"

Particle::Particle(ParticleData& data) :
	  m_Data(data)
	, m_Dead(false)
	, m_Color(data.birthColor)
	, m_TotalLifeTime(data.lifeTime)
{
}

void Particle::Advance(float dt)
{
	m_Data.position += m_Data.velocity * dt;
	m_Data.lifeTime -= dt;

	float r = (float)m_Data.birthColor.GetR() + (m_TotalLifeTime - m_Data.lifeTime) / m_TotalLifeTime * (float)(m_Data.deathColor.GetR() - m_Data.birthColor.GetR());
	float g = (float)m_Data.birthColor.GetG() + (m_TotalLifeTime - m_Data.lifeTime) / m_TotalLifeTime * (float)(m_Data.deathColor.GetG() - m_Data.birthColor.GetG());
	float b = (float)m_Data.birthColor.GetB() + (m_TotalLifeTime - m_Data.lifeTime) / m_TotalLifeTime * (float)(m_Data.deathColor.GetB() - m_Data.birthColor.GetB());
	
	m_Color.SetR((unsigned char)r);
	m_Color.SetG((unsigned char)g);
	m_Color.SetB((unsigned char)b);

	m_Dead = m_Data.position.x < 0 || m_Data.position.x > Graphics::ScreenWidth ||
		m_Data.position.y < 0 || m_Data.position.y > Graphics::ScreenHeight || m_Data.lifeTime <= 0.0f;
}

void Particle::AddVelocity(const Vec2D & velocity)
{
	m_Data.velocity += velocity;
}

bool Particle::IsDead() const
{
	return m_Dead;
}

void Particle::Draw(Graphics& gfx)
{
	switch(m_Data.shape)
	{
	case SHAPE_CIRCLE:
		gfx.DrawCircle(m_Data.position, m_Data.size / 2.0f, m_Color);
		break;

	case SHAPE_SQUARE:
		gfx.DrawSquare(m_Data.position, m_Data.size, m_Color);
		break;
	}
}
