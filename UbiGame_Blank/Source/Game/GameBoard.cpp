#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h" 

using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateRaindrop();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(100.0f, 100.0f));
	m_player->SetSize(sf::Vector2f(10.0f, 10.0f));

	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>();
	GameEngine::PlayerMovementComponent* movement = m_player->AddComponent<GameEngine::PlayerMovementComponent>(); 
}

void GameBoard::CreateRaindrop()
{
	raindrop = new GameEngine::Entity(); 
	GameEngine::GameEngineMain::GetInstance()->AddEntity(raindrop);
	raindrop->SetPos(sf::Vector2f(100.0f, 100.0f));
	raindrop->SetSize(sf::Vector2f(10.0f, 10.0f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(raindrop->AddComponent<GameEngine::SpriteRenderComponent>() );

	spriteRender->SetFillColor(sf::Color::Red);
	spriteRender->SetTexture(GameEngine::eTexture::Rain);

	// Movement
	raindrop->AddComponent<GameEngine::RaindropComponent>();

}
