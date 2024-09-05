#include "MainMenuState.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

void MainMenuState::Enter(Game& game)
{
	std::cout << "Entering Main Menu\n";
}

void MainMenuState::HandleInput(Game& game)
{
	sf::Event event;
	while (game.GetWindow().pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.key.code==sf::Keyboard::Escape)
		{
			game.GetWindow().close();
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
			std::cout << "Entering Play State\n";
			game.ChangeState(std::make_unique<PlayState>());
		}
	}
}

void MainMenuState::Update(Game& game)
{
}

void MainMenuState::Draw(Game& game, sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
}

void MainMenuState::Exit(Game& game)
{
	std::cout << "Exiting Main Menu\n";
}
