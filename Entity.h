#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <Windows.h>
#include "load_error.h"

namespace tank_battle
{
	class Entity : public sf::Drawable
	{
	protected:
		sf::Sprite sprite;
		sf::Texture texture;
		void draw(sf::RenderTarget&, sf::RenderStates) const override;
	public:
		Entity() = default;
		Entity(const std::string &);

		virtual ~Entity() = 0;

		void setTexture(const std::string &);

		sf::Rect <float> getGlobalBounds() const;

		sf::Vector2f getPosition();

		bool isCollision(std::shared_ptr<Entity>) const;

		void setPosition(const sf::Vector2f &);
		void rotate(float);
	};
}
