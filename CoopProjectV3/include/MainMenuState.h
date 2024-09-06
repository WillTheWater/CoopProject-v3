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

private:
	sf::Sprite				mBgTexture;
	sf::Sprite				mC1;
	sf::Sprite				mC2;
	sf::Sprite				mC3;
	sf::Sprite				mC4;
	sf::Sprite				mC5;
	sf::Sprite				mC6;
	sf::Sprite				mC7;
	sf::Sprite				mC8;
};
