#include "GameOverState.h"
#include "MainMenuState.h"
#include "Game.h"
#include "PlayState.h"
#include <iostream>

void GameOverState::Enter(Game& game)
{
	std::cout << "Entering Game Over\n";
	auto bgTexture = game.GetTextureManager().GetTexture("assets/graphics/cloud3/1.png");
	auto c1T = game.GetTextureManager().GetTexture("assets/graphics/cloud3/2.png");
	auto c2T = game.GetTextureManager().GetTexture("assets/graphics/cloud3/3.png");
	auto c3T = game.GetTextureManager().GetTexture("assets/graphics/cloud3/4.png");
	mBgTexture.setTexture(*bgTexture); mBgTexture.setScale(3.4f, 3.4f);
	mC1.setTexture(*c1T); mC1.setScale(3.4f, 3.4f); mC1.setPosition(0.0f, 0.0f);
	mC2.setTexture(*c1T); mC2.setScale(3.4f, 3.4f); mC2.setPosition(mC1.getGlobalBounds().width, 0.0f);
	mC3.setTexture(*c2T); mC3.setScale(3.4f, 3.4f); mC3.setPosition(0.0f, 0.0f);
	mC4.setTexture(*c2T); mC4.setScale(3.4f, 3.4f); mC4.setPosition(mC3.getGlobalBounds().width, 0.0f);
	mC5.setTexture(*c3T); mC5.setScale(3.4f, 3.4f); mC5.setPosition(0.0f, 0.0f);
	mC6.setTexture(*c3T); mC6.setScale(3.4f, 3.4f); mC6.setPosition(mC3.getGlobalBounds().width, 0.0f);
}

void GameOverState::HandleInput(Game& game)
{
	sf::Event event;
	while (game.GetWindow().pollEvent(event))
	{
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
		{
			game.GetWindow().close();
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::P) { game.ChangeState(std::make_unique<PlayState>()); }
			if (event.key.code == sf::Keyboard::M) { game.ChangeState(std::make_unique<MainMenuState>()); }
		}
	}
}

void GameOverState::Update(Game& game)
{
	float dT = game.GetDeltaTime();
	float bgWidth = mBgTexture.getGlobalBounds().width;
	mC1.move(1.f * dT, 0.0f); mC2.move(1.f * dT, 0.0f);
	mC3.move(8.f * dT, 0.0f); mC4.move(8.f * dT, 0.0f);
	mC5.move(16.f * dT, 0.0f); mC6.move(16.f * dT, 0.0f);
	if (mC1.getPosition().x >= bgWidth) { mC1.setPosition(mC2.getPosition().x - bgWidth, 0.0f); }
	if (mC2.getPosition().x >= bgWidth) { mC2.setPosition(mC1.getPosition().x - bgWidth, 0.0f); }
	if (mC3.getPosition().x >= bgWidth) { mC3.setPosition(mC4.getPosition().x - bgWidth, 0.0f); }
	if (mC4.getPosition().x >= bgWidth) { mC4.setPosition(mC3.getPosition().x - bgWidth, 0.0f); }
	if (mC5.getPosition().x >= bgWidth) { mC5.setPosition(mC6.getPosition().x - bgWidth, 0.0f); }
	if (mC6.getPosition().x >= bgWidth) { mC6.setPosition(mC5.getPosition().x - bgWidth, 0.0f); }
}

void GameOverState::Draw(Game& game, sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	window.draw(mBgTexture);
	window.draw(mC1); window.draw(mC2);
	window.draw(mC3); window.draw(mC4);
	window.draw(mC5); window.draw(mC6);
}

void GameOverState::Exit(Game& game)
{
	std::cout << "Exiting Game Over\n";
}
