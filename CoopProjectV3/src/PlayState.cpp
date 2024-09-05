#include "PlayState.h"
#include "Game.h"
#include <iostream>

void PlayState::Enter(Game& game)
{
	std::cout << "Entering Play State\n";
}

void PlayState::HandleInput(Game& game)
{
	sf::Event event;
	while (game.GetWindow().pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			game.GetWindow().close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				std::cout << "Pause Menu\n";
			}
		}
	}
}

void PlayState::Update(Game& game)
{
}

void PlayState::Draw(Game& game, sf::RenderWindow& window)
{
	window.clear(sf::Color::Green);
}

void PlayState::Exit(Game& game)
{
	std::cout << "Exiting Play State\n";
}
