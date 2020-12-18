#pragma once

#include <SFML/System/Time.hpp>
// Opowiada za stany, ich aktualizacje lub ladownie nowego stanu
// Bazowa klasa odpowiadajaca za wszytskie stany
// Uzycie namespace Engine pozwala na uzywanie go w innych grach nie tylko w tej
namespace Engine
{
	class State
	{
	public:
		State() {};
		virtual ~State() {}; // tworzymy virtualny destruktor poniewaz bedziemy dziedziczyc z tej klasy

		virtual void Init() = 0; // Inicjalizowanie elementow takich jak tekst i jego pozycja i tym podobne
		virtual void ProcessInput() = 0; // Odpowiada za odbieranie sygnalow klikniecia klawiatury
		virtual void Update(sf::Time deltaTime) = 0; // Odpowiada za uaktualnianie danych w trkacie gry np pozycja tekstu tekstury
		virtual void Draw() = 0; // Rysowanie tekstur oraz tekstow w stanie podczas renderowania okna aplikacji

		virtual void Pause() {}; // Potrzebne tylko w niektorych stanach, pozwalaja na zatrzymanie oraz uruchomienie gry
		virtual void Start() {};
	};
}
