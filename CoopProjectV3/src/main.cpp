#include "Game.h"
#include "BallSimulation.h"

int main()
{
    Game game;
    game.Run();

    //sf::RenderWindow window(sf::VideoMode(1280, 900), "State Game", sf::Style::Close);
    //BallSimulation testbox(800, 600, window, 0, 500, 10, 50, 10);
    //window.setFramerateLimit(60);

    //sf::CircleShape circle(20);
    //circle.setFillColor(sf::Color::Blue);
    //circle.setPosition(0, 100);

    //sf::Clock clock; 

    //double deltaTime = 0;

    //sf::Event e;  

    //while (window.isOpen())
    //{
    //    window.clear(sf::Color::Black);
    //    testbox.update(deltaTime);
    //    testbox.handleCollisionBox();
    //    testbox.handleCollisionBall();
    //    testbox.applyFriction(deltaTime);
    //    testbox.pollMouse(); // Not working yet
    //    testbox.render();
    //    window.display();
    //
    //    testbox.testMouseHeld(e);
    //    
    //    testbox.incrementMouseHeldTime(deltaTime);
    //    
    //    deltaTime = clock.restart().asSeconds();
    //    
    //}
    //

        
    return 0;
}