#pragma once
#include "GameState.h"

class GameOverState : public GameState
{
public:
	GameOverState() = default;
	~GameOverState() = default;

	void					Enter(Game& game) override;
	void					HandleInput(Game& game) override;
	void					Update(Game& game) override;
	void					Draw(Game& game, sf::RenderWindow& window) override;
	void					Exit(Game& game) override;

private:
	sf::Sprite				mBgTexture;
	sf::Sprite				mC1;
	sf::Sprite				mC2;
	sf::Sprite				mC3;
	sf::Sprite				mC4;
	sf::Sprite				mC5;
	sf::Sprite				mC6;
};
