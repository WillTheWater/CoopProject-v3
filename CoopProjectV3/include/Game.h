#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Game
{
public:
	Game();


	void						Run();
	void						ChangeState(std::unique_ptr<GameState> newState);
	sf::RenderWindow&			GetWindow();

private:
	sf::RenderWindow			mWindow;
	std::unique_ptr<GameState>	mCurrentState; // Unique pointer that holds the current active state
};