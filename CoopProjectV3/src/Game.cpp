#include "Game.h"
#include "MainMenuState.h"

Game::Game()
    : mWindow(sf::VideoMode(1920,1080), "State Game", sf::Style::Close)
    , mCurrentState{nullptr}
{
    ChangeState(std::make_unique<MainMenuState>());
}

void Game::Run()
{
    while (mWindow.isOpen())
    {
        if (mCurrentState) { mCurrentState->HandleInput(*this); }
        if (mCurrentState) { mCurrentState->Update(*this); }
        mWindow.clear();
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
