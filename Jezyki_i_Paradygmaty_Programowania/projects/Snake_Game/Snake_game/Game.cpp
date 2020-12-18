#include <SFML/Graphics/CircleShape.hpp>

#include "Game.hpp"
#include "MainMenu.hpp"
// Inicjalizacja m_context, poniewaz jest to shared pointer(wyeksponowany wskaznik) dlatego uzywam make_shared
Game::Game() : m_context(std::make_shared<Context>())
{
    // Tworzenie nowego okna, do tego uzywam metody create na zmiennej m_window przechowywanej w m_context
    // Rozmiar okna, tytul wyswietlany w pasku tytuowym, parametr odpowiadajacy za zmiane wielkosci okna u mnie brak pozwolenia
	m_context->m_window->create(sf::VideoMode(640, 352), "Snake Game", sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game() 
{

}

void Game::Run()
{
    // tworzenie obiektu na podstawie dyrektywy Clock
    sf::Clock clock;
    // Potrzebujemy rowniez przechowywac ilosc czasu ktory uplynal od ostatniego odswiezenia okna
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context->m_window->isOpen())
    {
        // Przechowanie czasu ktory uplynal od ostatniej iteracji
        timeSinceLastFrame += clock.restart();

        // Wykonujemy w momencie gdy zmienna ktora przchowuje czas od ostatniego odswiezenia jest wieksza od wczesniej ustalonej wartosci 1/60;
        while (timeSinceLastFrame > TIME_PER_SECOND)
        {
            timeSinceLastFrame -= TIME_PER_SECOND;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_SECOND);
            m_context->m_states->GetCurrent()->Draw();
        }   
    }
}
