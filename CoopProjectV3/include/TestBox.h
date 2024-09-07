#include "Ball.h"
#include "Vec2.h"

#include <SFML/Graphics.hpp>
#include "Random.h"
#include <Vector>
#include <iostream>
#include <string>
#include <cmath>



class TestBox
{
public:
	TestBox(int width, int height, sf::RenderWindow& window, int minVel, int maxVel, int minRad, int maxRad, int numBalls);

	~TestBox();

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

private:

	int m_width;
	int m_height;
	int m_minRanVel;
	int m_maxRanVel;
	int m_maxRanRadius;
	int m_minRanRadius;
	int m_ballsToGenerate;

	std::vector<Ball*> m_balls;
	sf::RenderWindow& m_windowRef;
	Ball* m_selectedBall;
	sf::RectangleShape m_rect;


};