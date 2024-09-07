#include "TestBox.h"


TestBox::TestBox(int width, int height, sf::RenderWindow& window, int minVel, int maxVel, int minRad, int maxRad, int numBalls)
	: m_width{ width }
	, m_height{ height }
	, m_balls{}
	, m_windowRef{ window }
	, m_minRanVel(minVel)
	, m_maxRanVel(maxVel)
	, m_minRanRadius(minRad)
	, m_maxRanRadius(maxRad)
	, m_ballsToGenerate(numBalls)
	, m_rect{ sf::Vector2f(width, height) }
	, m_offsetX{0}
	, m_offsetY{0}
	, m_mouseDown{ false }
{
	m_rect.setFillColor(sf::Color::Green);
	createRandomBalls();
	m_offsetX = (m_windowRef.getSize().x - m_rect.getSize().x) / 2;
	m_offsetY = (m_windowRef.getSize().y - m_rect.getSize().y) / 2;
}

TestBox::~TestBox()
{
	destroyBalls();
}

void TestBox::resetBalls()
{
	destroyBalls();
	createRandomBalls();
}

void TestBox::destroyBalls()
{
	for (Ball* b : m_balls)
	{
		if (b != nullptr)
		{
			delete b;
			b = nullptr;
		}
	}
	m_balls.clear();
}

void TestBox::createRandomBalls()
{
	for(int i{0}; i < m_ballsToGenerate; i++)
	{
		Vec2 pos{ Random::getRandomDouble(0,m_width), Random::getRandomDouble(0,m_height) };
		Vec2 vel{ Random::getRandomDouble(m_minRanVel,m_maxRanVel), Random::getRandomDouble(m_minRanVel,m_maxRanVel) };
		double radius = Random::getRandomDouble(m_minRanRadius, m_maxRanRadius);
		m_balls.push_back(new Ball(radius, pos, vel, 0));
	}
}

void TestBox::render()
{
	m_rect.setPosition(m_offsetX, m_offsetY);

	m_windowRef.draw(m_rect);
	for (Ball* b : m_balls)
	{
		

		// Render the circle
		double circlePosX = b->getCircle().getPosition().x;
		double circlePosY = b->getCircle().getPosition().y;
		double radius = b->getRadius();
		b->getCircle().setPosition(circlePosX + m_offsetX, circlePosY + m_offsetY);
		m_windowRef.draw(b->getCircle());

		// Render the velocity vector line
		double velx = b->getVelocity().getx();
		double vely = b->getVelocity().gety();
		double vel_linex = circlePosX + 0.3 * velx;
		double vel_liney = circlePosY + 0.3 * vely;

		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(circlePosX + m_offsetX + radius, circlePosY + m_offsetY + radius);
		lines[0].color = sf::Color::Red;
		lines[1].position = sf::Vector2f(vel_linex + m_offsetX + radius, vel_liney + m_offsetY + radius);
		lines[1].color = sf::Color::Red;
		m_windowRef.draw(lines);		


	}

	if (m_selectedBall)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			double brad = m_selectedBall->getRadius();
			double bposx = m_selectedBall->getPosition().getx() + m_offsetX;
			double bposy = m_selectedBall->getPosition().gety() + m_offsetY;

			sf::Vector2i mousePos = sf::Mouse::getPosition(m_windowRef);
			double mPosx = mousePos.x;
			double mPosy = mousePos.y;
			sf::VertexArray lines(sf::LinesStrip, 2);
			lines[0].position = sf::Vector2f(bposx, bposy);
			lines[0].color = sf::Color::Red;
			lines[1].position = sf::Vector2f(mPosx, mPosy);
			lines[1].color = sf::Color::Red;
			m_windowRef.draw(lines);

		}
	}
}

void TestBox::update(double deltaTime)
{
	for (Ball* b : m_balls)
	{
		b->updatePosition(deltaTime);
	}
}

void TestBox::handleCollisionBox()
{
	for (Ball* b : m_balls)
	{
		double radius = b->getRadius();
		double velx = b->getVelocity().getx();
		double vely = b->getVelocity().gety();
		double posx = b->getPosition().getx();
		double posy = b->getPosition().gety();
		if (b->getPosition().getx() - radius < 0)
		{
			b->setVelocity({ velx * -1, vely });
			b->setPosition({ radius, posy });
		}
		if (b->getPosition().getx() + radius > m_width)
		{
			b->setVelocity({ velx * -1, vely });
			b->setPosition({ m_width-radius, posy });
		}
		if (b->getPosition().gety() - radius < 0)
		{
			b->setVelocity({velx, vely * -1});
			b->setPosition({ posx, radius });
		}
		if (b->getPosition().gety() + radius > m_height)
		{
			b->setVelocity({ velx, vely * -1 });
			b->setPosition({ posx, m_height - radius });
		}
	}
}

void TestBox::handleCollisionBall()
{
	double totalVelocity = 0;

	for (size_t i {0}; i < m_balls.size(); i++)
	{
		// Debug to check the total velocity in the system
		totalVelocity += m_balls[i]->getVelocity().magnitude();
	
		for (size_t j{ i+1 }; j < m_balls.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			if (!doBallsOverlap(*m_balls[i], *m_balls[j]))
			{
				continue;
			}

			// std::cout << "Collision resolved" << '\n';

			double b1Radius = m_balls[i]->getRadius();
			double b2Radius = m_balls[j]->getRadius();

			double b1xpos = m_balls[i]->getPosition().getx();
			double b1ypos = m_balls[i]->getPosition().gety();

			double b2xpos = m_balls[j]->getPosition().getx();
			double b2ypos = m_balls[j]->getPosition().gety();

			double b1velx = m_balls[i]->getVelocity().getx();
			double b1vely = m_balls[i]->getVelocity().gety();

			double b2velx = m_balls[j]->getVelocity().getx();
			double b2vely = m_balls[j]->getVelocity().gety();

			double b1mass = m_balls[i]->getMass();
			double b2mass = m_balls[j]->getMass();

			// What is the distance between the center of the two balls
			double distance = std::sqrt((b1xpos - b2xpos)*(b1xpos - b2xpos) + (b1ypos - b2ypos) * (b1ypos - b2ypos));
			// What is the distance they actually overlap, halved so it's the amount of overlap for each ball
			double overlap = 0.5 * (distance - b1Radius - b2Radius) ;
			
			// Resolve the position of Ball 1
			double xpos_offset = overlap * (b1xpos - b2xpos) / distance;
			double ypos_offset = overlap * (b1ypos - b2ypos) / distance;
			m_balls[i]->setPosition({ b1xpos - xpos_offset , b1ypos - ypos_offset });

			// Resolve the position of Ball2
			m_balls[j]->setPosition({ b2xpos + xpos_offset, b2ypos + ypos_offset });

			// DEBUG - Recalcuating this here seem to help with the energy conservation... Why?

			b1xpos = m_balls[i]->getPosition().getx();
			b1ypos = m_balls[i]->getPosition().gety();

			b2xpos = m_balls[j]->getPosition().getx();
			b2ypos = m_balls[j]->getPosition().gety();

			distance = std::sqrt((b1xpos - b2xpos) * (b1xpos - b2xpos) + (b1ypos - b2ypos) * (b1ypos - b2ypos));

			// !DEBUG
			
			// # Handle the changes in velocity
			// Normal Vector:

			double normalx = (b2xpos - b1xpos) / (distance);
			double normaly = (b2ypos - b1ypos) / (distance);

			// Tangent Vector:
			double tangentx = -normaly;
			double tangenty = normalx;

			// Dot product tangent
			double dpTan1 = b1velx * tangentx + b1vely * tangenty;
			double dpTan2 = b2velx * tangentx + b2vely * tangenty;

			// Dot product normal

			double dpNorm1 = b1velx * normalx + b1vely * normaly;
			double dpNorm2 = b2velx * normalx + b2vely * normaly;

			// Conservation of momentum
			double m1 = (dpNorm1 * (b1mass - b2mass) + 2.0 * b2mass * dpNorm2) / (b1mass + b2mass);
			double m2 = (dpNorm2 * (b2mass - b1mass) + 2.0 * b1mass * dpNorm1) / (b1mass + b2mass);

			// New Velocities
			double b1newVelx = tangentx * dpTan1 + normalx * m1;
			double b1newVely = tangenty * dpTan1 + normaly * m1;
			double b2newVelx = tangentx * dpTan2 + normalx * m2;
			double b2newVely = tangenty * dpTan2 + normaly * m2;

			m_balls[i]->setVelocity({ b1newVelx, b1newVely });
			m_balls[j]->setVelocity({ b2newVelx, b2newVely });
			
		}
	}
	// Debug to see the total velocity maintained in the system
	//std::cout << "Total Velocity: " << totalVelocity << '\n';
}

void TestBox::resolveBall2BallCollision(Ball& b1, Ball& b2)
{

}

bool TestBox::doBallsOverlap(Ball& b1, Ball& b2)
{
	double b1Radius = b1.getRadius();
	double b2Radius = b2.getRadius();
	
	double b1xpos = b1.getPosition().getx();
	double b1ypos = b1.getPosition().gety();

	double b2xpos = b2.getPosition().getx();
	double b2ypos = b2.getPosition().gety(); 

	double distance = std::sqrt(std::pow((b2xpos - b1xpos), 2) + std::pow((b2ypos - b1ypos), 2));
	return (distance <= b1Radius + b2Radius);
}

void TestBox::applyFriction(double deltaTime)
{
	for (Ball* b : m_balls)
	{
		double velscale = 1 - (0.4 * deltaTime);
		double velx = b->getVelocity().getx();
		double vely = b->getVelocity().gety();


		Vec2 newvel{ (velx * velscale * velscale), (vely * velscale * velscale) };
		b->setVelocity(newvel);
	}

}

bool TestBox::ballsAtRest()
{
	bool atRest = true;

	for (Ball* b : m_balls)
	{
		if (b->getVelocity().magnitude() < 1)
		{
			b->setVelocity({ 0,0 });
		}
		else
		{
			atRest = false;
		}
	}

	return atRest;
}

void TestBox::pollMouse()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_windowRef);
	double mousex = mousePos.x;
	double mousey = mousePos.y;
	
	for (Ball* b : m_balls)
	{
		double bposx = b->getPosition().getx() + m_offsetX;
		double bposy = b->getPosition().gety() + m_offsetY;

		double distance = std::sqrt(std::pow((bposx - mousex), 2) + std::pow((bposy - mousey), 2));
		if (distance < (b->getRadius()))
		{
			//b->getCircle().setFillColor(sf::Color::Red);
			b->getCircle().setOutlineThickness(5);
			b->getCircle().setOutlineColor(sf::Color::Red);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				m_selectedBall = b;
			}
		}
		else
		{
			b->getCircle().setOutlineThickness(0);
		}

	}
}


void TestBox::testMouseHeld(sf::Event& e)
{
	/*if(!ballsAtRest())
	{
		return;
	}*/

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_mouseDown = true;
	}
	else
	{
		if (m_mouseHeldTime > 0)
		{

			if (m_selectedBall)
			{
				shootBall();
			}

			m_selectedBall = nullptr;

		}

		m_mouseDown = false;

	}

	system("cls");
	std::cout << m_mouseHeldTime << '\n';
		
}

void TestBox::shootBall()
{
	if (!m_selectedBall)
	{
		return;
	}

	

	sf::Vector2i mousePos = sf::Mouse::getPosition(m_windowRef);
	double mousePosX = mousePos.x;
	double mousePosY = mousePos.y;

	double bPosx = m_selectedBall->getPosition().getx() + m_offsetX;
	double bPosy = m_selectedBall->getPosition().gety() + m_offsetY;


	Vec2 lineToPoint{ (bPosx - mousePosX), (bPosy - mousePosY) };

	lineToPoint = lineToPoint; 

	double angle = lineToPoint.angleInRads();

	double scalingFactor = lineToPoint.magnitude();

	double velX = std::cos(angle);
	double velY = std::sin(angle);

	velX = velX * 2 * scalingFactor;
	velY = velY * 2 * scalingFactor;

	m_selectedBall->setVelocity(Vec2{velX, velY});

}

void TestBox::incrementMouseHeldTime(double deltaTime)
{
	if (m_mouseDown)
	{
		m_mouseHeldTime += deltaTime;
	}
	else if(!m_mouseDown)
	{
		m_mouseHeldTime = 0;
	}
}
