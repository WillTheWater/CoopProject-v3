#pragma once


#include "Ball.h"
#include "Vec2.h"

#include <SFML/Graphics.hpp>
#include "Random.h"
#include <Vector>
#include <iostream>
#include <string>
#include <cmath>



class BallSimulation
{
public:
	BallSimulation(int width, int height, sf::RenderWindow& window, int minVel, int maxVel, int minRad, int maxRad, int numBalls);

	~BallSimulation();

	void createRandomBalls();

	void resetBalls();

	void destroyBalls();

	void render();

	void update(double deltaTime);

	void handleCollisionBox();

	void handleCollisionBall();

	void resolveBall2BallCollision(Ball& b1, Ball& b2);

	bool doBallsOverlap(Ball& b1, Ball& b2);

	void applyFriction(double deltaTime);

	bool ballsAtRest();

	void pollMouse();

	void shootBall();

	void incrementMouseHeldTime(double deltaTime);

	void testMouseHeld();

private:

	int m_width;
	int m_height;
	int m_minRanVel;
	int m_maxRanVel;
	int m_maxRanRadius;
	int m_minRanRadius;
	int m_ballsToGenerate;

	bool m_mouseDown;

	double m_mouseHeldTime;

	double m_offsetX;
	double m_offsetY;

	std::vector<Ball*> m_balls;
	sf::RenderWindow& m_windowRef;

	Ball* m_selectedBall;
	Ball* m_hoveredBall;
		
	sf::RectangleShape m_rect;
};