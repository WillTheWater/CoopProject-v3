#pragma once
#include "GameState.h"

class PlayState : public GameState
{
public:
	PlayState() = default;
	~PlayState() = default;

	void					Enter(Game& game) override;
	void					HandleInput(Game& game) override;
	void					Update(Game& game) override;
	void					Draw(Game& game, sf::RenderWindow& window) override;
	void					Exit(Game& game) override;
};

