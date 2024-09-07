#pragma once

#include "Vec2.h"
#include <cmath>
#include <SFML/Graphics/CircleShape.hpp>

class Ball
{
public:
	Ball() = delete;
	Ball(double radius, Vec2 pos, Vec2 vel, Vec2 accel);
	
	const Vec2 getPosition() const;
	const Vec2 getVelocity() const;
	const Vec2 getAcceleration() const;
	const double getMass() const; 
	const bool isVisible() const;
	const double getRadius() const;
	const double getWidth() const;
	const double getHeight() const; 
	sf::CircleShape& getCircle();

	void setPosition(const Vec2& position);
	void setVelocity(const Vec2& velocity);
	void setAcceleration(const Vec2& acceleration);
	void setMass(const double mass);
	void setVisiblity(bool visibility);
	void setRadius(const double radius) ;
	void setWidth (const double width );
	void setHeight (const double height);
	void setVelMagnitude(const double magnitude);

	void updatePosition(double deltaTime);

	bool isBallAtRest(Ball* ball);
	

private:
	Vec2 m_position;
	Vec2 m_velocity;
	Vec2 m_acceleration;
	double m_mass;
	double m_radius;
	double m_width;
	double m_height;
	bool m_visible;
	sf::CircleShape m_circle;

};