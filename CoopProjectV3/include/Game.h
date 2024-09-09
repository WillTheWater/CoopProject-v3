#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "TextureManager.h"
#include "BallSimulation.h"


class Game
{
public:
	Game();

	void							Run();
	void							ChangeState(std::unique_ptr<GameState> newState);
	sf::RenderWindow&				GetWindow();
	TextureManager&					GetTextureManager(); // Allows access to other states.
	float							GetDeltaTime() const;
	void							InitializeSim();
	void							UpdateSim();
	void							DrawingSim();
	void							HandleInputSim();
	void							ResetSim();
	bool							isSimInitialized();

private:
	sf::RenderWindow				mWindow;
	sf::Clock						mClock;
	float							mDeltaTime = 0.0f;
	void							Tick();
	std::unique_ptr<GameState>		mCurrentState; // Unique pointer that holds the current active state.
	TextureManager					mTextureManager;
	std::unique_ptr<BallSimulation>	mBallSim;
};