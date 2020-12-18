#pragma once

#include <stack>
#include <memory>

#include "State.hpp"

namespace Engine
{
	class StateMan
	{
	private:
		// Tworze stos do przechowywania stanow gry
		std::stack<std::unique_ptr<State>> m_stateStack;
		// Unikalny wskaznik wskazujacy na nowy stan ktory zostal dodany do stosu, potrzebne po to aby nie dodawac nowego stau w momencie kiedy inny jest wykonywany
		std::unique_ptr<State> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove; // Zmienne modyfikowane przez metody Add i PopCurrent

	public:
		StateMan();
		~StateMan();

		// Metoda przyjmujaca dwie wartosci jaki Stan chcemy dodac, druga odpowiada za mozliwosc podmiany danego stanu lub nie
		void Add(std::unique_ptr<State> toAdd, bool replace = false);
		// Usuwa aktualny stan ze stosu
		void PopCurrent();
		// Metoda w ktorej stan w stosie bedzie aktualnie modyfikowany
		void ProcessStateChange();
		// Zwraca unikalny wskaznik do aktualnego stanu za pomoca referencji
		std::unique_ptr<State>& GetCurrent();
	};
}

