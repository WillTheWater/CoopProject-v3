#pragma once
#include <SFML/Graphics.hpp>

class Game;

class GameState
{ 
public:
	virtual					~GameState() = default;

	virtual void			Enter(Game& game) = 0;
	virtual void			HandleInput(Game& game) = 0;
	virtual void			Update(Game& game) = 0;
	virtual void			Draw(Game& game, sf::RenderWindow& window) = 0;
	virtual void			Exit(Game& game) = 0;
};

