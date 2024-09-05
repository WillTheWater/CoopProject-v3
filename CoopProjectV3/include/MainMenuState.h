#pragma once
#include "GameState.h"

class MainMenuState : public GameState
{
public:
	MainMenuState() = default;
	~MainMenuState() = default;

	void					Enter(Game& game) override;
	void					HandleInput(Game& game) override;
	void					Update(Game& game) override;
	void					Draw(Game& game, sf::RenderWindow& window) override;
	void					Exit(Game& game) override;
};
