#include "Game.h"
#include "MainMenuState.h"

Game::Game()
    : mWindow(sf::VideoMode(1920,1080), "State Game", sf::Style::Close)
    , mCurrentState{nullptr}
{
    mWindow.setFramerateLimit(60);
    ChangeState(std::make_unique<MainMenuState>());
}

void Game::Run()
{
    while (mWindow.isOpen())
    {
        Tick();
        if (mCurrentState) { mCurrentState->HandleInput(*this); }
        if (mCurrentState) { mCurrentState->Update(*this); }
        if (mCurrentState) { mCurrentState->Draw(*this, mWindow); }
        mWindow.display();
    }
}

void Game::ChangeState(std::unique_ptr<GameState> newState)
{
    if (newState) { newState->Enter(*this); } // Enter new state
    if (mCurrentState) { mCurrentState->Exit(*this); } // Exits previous state for seamless transition
    mCurrentState = std::move(newState); // Unique pointer ensures deletion of previous state
}

sf::RenderWindow& Game::GetWindow()
{
    return mWindow;
}

TextureManager& Game::GetTextureManager()
{
    return mTextureManager;
}

float Game::GetDeltaTime() const
{
    return mDeltaTime;
}

void Game::InitializeSim()
{
    mBallSim = std::make_unique<BallSimulation>(1600, 800, mWindow, 0, 500, 10, 50, 20);
}

void Game::UpdateSim()
{
    mBallSim->update(mDeltaTime);
    mBallSim->handleCollisionBox();
    mBallSim->handleCollisionBall();
    mBallSim->applyFriction(mDeltaTime);
}

void Game::DrawingSim()
{
    mBallSim->render();
}

void Game::HandleInputSim()
{
    mBallSim->pollMouse();
    mBallSim->testMouseHeld();
    mBallSim->incrementMouseHeldTime(mDeltaTime);
}

void Game::ResetSim()
{
    mBallSim->resetBalls();
}

bool Game::isSimInitialized()
{
    if(mBallSim)
    {
        return true;
    }

    return false;
}

void Game::Tick()
{
    mDeltaTime = mClock.restart().asSeconds();
}
