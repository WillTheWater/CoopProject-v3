#include "Game.h"
#include "TestBox.h"

int main()
{
   /* Game game;
    game.Run();*/

    sf::RenderWindow window(sf::VideoMode(800, 600), "State Game", sf::Style::Close);
    TestBox testbox(800, 600, window);
    window.setFramerateLimit(60);

    testbox.createRandomBalls(10);

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(0, 100);

    sf::Clock clock; 

    double deltaTime = 0;

    while (true)
    {
        window.clear(sf::Color::Black);
        testbox.update(deltaTime);
        testbox.handleCollisionBox();
        testbox.handleCollisionBall();
        testbox.applyFriction(deltaTime);
        testbox.render();

        window.display();
        //testbox.pollMouse();
        if (testbox.ballsAtRest())
        {
            std::cout << "Balls at rest" << '\n';
        }

        deltaTime = clock.restart().asSeconds();
    }
    return 0;
}