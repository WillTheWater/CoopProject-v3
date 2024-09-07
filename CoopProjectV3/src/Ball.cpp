#include "Ball.h"

Ball::Ball(double radius, Vec2 pos = (0, 0), Vec2 vel = (0, 0), Vec2 accel = (0, 0))
	:m_position{pos}
	,m_velocity{vel}
	,m_acceleration{accel}
	,m_mass{std::fabs(radius * radius * 3.14)}
	,m_visible{true}
	,m_radius{radius}
	,m_height { std::fabs(radius * 2)}
	,m_width { std::fabs(radius * 2) }
{
	m_circle.setRadius(radius);
	m_circle.setFillColor(sf::Color::Blue);
	m_circle.setPosition({ (float)pos.getx(), (float)pos.gety() });
}

const Vec2 Ball::getPosition() const {
	return m_position;
}
const Vec2 Ball::getVelocity() const {
	return m_velocity;
}
const Vec2 Ball::getAcceleration() const {
	return m_acceleration;
}
const double Ball::getMass() const {
	return m_mass;
}

const double Ball::getRadius() const{
	return m_radius;
}

const double Ball::getWidth() const {
	return m_width;
}

const double Ball::getHeight() const {
	return m_height;
}

sf::CircleShape& Ball::getCircle()
{
	return m_circle;
}

const bool Ball::isVisible() const {
	return m_visible;
}

void Ball::setPosition(const Vec2& position) {
	m_position = position;
}
void Ball::setVelocity(const Vec2& velocity) {
	m_velocity = velocity;
}
void Ball::setAcceleration(const Vec2& acceleration) {
	m_acceleration = acceleration;
}
void Ball::setMass(const double mass) {
	m_mass = mass;
}

void Ball::setWidth(const double width) {
	m_width = width;
}

void Ball::setHeight(const double height) {
	m_height = height;
}

void Ball::setVelMagnitude(const double magnitude)
{
	m_velocity.setMagnitude(magnitude);
}

void Ball::setRadius(const double radius) {
	m_radius = radius;
	m_circle.setRadius(m_radius);
}

void Ball::setVisiblity(bool visibility) {
	m_visible = visibility;
}

void Ball::updatePosition(double deltaTime) {
	m_position += m_velocity * deltaTime;
	m_velocity += m_acceleration * deltaTime;
	m_circle.setPosition({ (float)m_position.getx() - (float)m_radius, (float)m_position.gety() - (float)m_radius});
}