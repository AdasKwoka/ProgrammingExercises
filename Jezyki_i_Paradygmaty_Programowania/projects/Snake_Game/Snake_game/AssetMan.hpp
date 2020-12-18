#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine
{
	class AssetMan
	{
	private:
		// Do przechowywania tekstur i typow czcionek uzywam stead map(stabilnych map)
		std::map<int, std::unique_ptr<sf::Texture>> m_textures;
		std::map<int, std::unique_ptr<sf::Font>> m_fonts;

	public:
		AssetMan();
		~AssetMan();
		// Metody slozace do dodawania tekstur i typow czcionki
		// Odwolujemy sie do id, sciezki, jesli wantRepeated na true wtedy pozwalamy danej teksturze narysowac sie tyle razy aby wypelnilo dane okno
		void AddTexture(int id, const std::string &filePath, bool wantRepeated = false);
		void AddFont(int id, const std::string &filePath);

		// Aby zaladowac potrzebne tekstury i typy czcionek potrzebujemy uzyc ponizszych metod, obydwie metody zwroca teksture lub typ w postaci stalej referencji
		const sf::Texture& GetTexture(int id) const;
		const sf::Font& GetFont(int id) const;

	};
}


