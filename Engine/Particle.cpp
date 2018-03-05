#include "Particle.h"

Particle::Particle(const Vec2D & pos, const Vec2D & velocity, float size, 
	Graphics& gfx, Color& color, Shapes shape) :
	  m_Position(pos)
	, m_Velocity(velocity)
	, m_Dead(false)
	, m_Size(size)
	, m_Gfx(gfx)
	, m_Color(color)
	, m_Shape(shape)
{
}

void Particle::Advance()
{
	m_Position += m_Velocity;

	m_Dead = m_Position.x < 0 || m_Position.x > m_Gfx.ScreenWidth ||
		m_Position.y < 0 || m_Position.y > m_Gfx.ScreenHeight;
}

void Particle::AddVelocity(const Vec2D & velocity)
{
	m_Velocity += velocity;
}

bool Particle::IsDead() const
{
	return m_Dead;
}

void Particle::Draw()
{


	m_Gfx.DrawSquare(m_Position, m_Size, m_Color);
}
