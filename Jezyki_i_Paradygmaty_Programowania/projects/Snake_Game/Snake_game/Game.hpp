#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetMan.hpp"
#include "StateMan.hpp"

enum AssetID
{
	MAIN_FONT = 0,
	GRASS,
	FOOD,
	WALL,
	SNAKE
};

// Struktura przechowujaca asset manager, state manager, rendering window
struct Context
{
	// tworzenie unkalnych wskaznikow do klas
	std::unique_ptr<Engine::AssetMan> m_assets;
	std::unique_ptr<Engine::StateMan> m_states;
	std::unique_ptr<sf::RenderWindow> m_window;

	Context()
	{
		// Inicjalizacja danych wskaznikow przechowujacych klasy 
		m_assets = std::make_unique<Engine::AssetMan>();
		m_states = std::make_unique<Engine::StateMan>();
		m_window = std::make_unique<sf::RenderWindow>();
	}
};
class Game
{
private:
	// Uzywam shared_ptr poniewaz context bedzie dostepny dla wszystkich stanow
	std::shared_ptr<Context> m_context;
	// Zmienna typu Time przechowujaca 60 klatek na sekunde
	const sf::Time TIME_PER_SECOND = sf::seconds(1.f / 60.f);

public:
	Game();
	~Game();

	void Run();
};

