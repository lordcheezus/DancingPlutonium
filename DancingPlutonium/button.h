#pragma once

#include<SFML/Graphics.hpp>

class Button
{
public:
	Button(const sf::String _name, const sf::Color& _fillColor, const sf::Color& _boarderColor, int _size, bool _clickable);
	Button(const Button& _ref);
	~Button() {}
	void Draw(sf::RenderTarget& _rt) const;
	void Update(float _dt, sf::RenderWindow& _window);
	bool IsClicked();
	sf::String getName() const;
	void setOrigin(const sf::Vector2f _pos);
	void setPosition(const sf::Vector2f _pos);
	void fadeIn(float _dt);
	void fadeOut(float _dt);
	sf::FloatRect getBounds() const;

private:
	bool isFading;
	bool isClickable;
	bool isClicked;
	float accumulator;

	sf::Uint8 alpha;
	sf::Text buttonName;
	sf::Color buttonFillColor;
	sf::Color buttonBoarderColor;
	sf::Vector2f location;
	sf::FloatRect bounds;
	sf::Font font;

private:
	void setColor(const sf::Color& _fillColor, const sf::Color& _boarderColor);
	void loadFont();
};