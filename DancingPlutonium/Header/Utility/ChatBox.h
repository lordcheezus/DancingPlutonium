#pragma once

#include <SFML/Graphics.hpp>
#include "InputManager.h"

namespace DancingPlutonium
{
	/*
	ChatBox class is a specialized object which utilizes sfml fonts/colors and texts to render a Chatbox
	which can have features built into it (fade in, fade out, grow, etc..)
	*/
	class ChatBox
	{
	public:
		#pragma region Ctor/Dtors

		/* ChatBox Default Constructor */
		ChatBox(const sf::String& _nameOfBox, const sf::Vector2f _sizeOfBox);

		/* ChatBox copy constructor */
		ChatBox(const ChatBox& _ref) {}

		/* ChatBox destructor */
		~ChatBox() {}

		#pragma endregion

	public:
		#pragma region Methods

		/* Draw this ChatBox sprite onto the render window _rt */
		void Draw(sf::RenderTarget& _rt) const;
		/* Update this ChatBox in the world based on the clock and render window */
		void Update(float _dt, float _killTimer);
		/* Returns the name of this ChatBox */
		sf::String GetName() const;
		/* Sets this ChatBox origin based on the _pos input parameter */
		void SetOrigin(const sf::Vector2f _pos);
		/* Returns the position that the ChatBox is currently at */
		sf::Vector2f GetPosition();
		/* Sets this ChatBox position based on the _pos input parameter */
		void SetPosition(const sf::Vector2f _pos);
		/* Returns the bounding rectangle of this ChatBox */
		sf::FloatRect GetBounds() const;
		/* Sets the message qualities of this ChatBox */
		void SetMessage(const sf::String& _msg, const int _size);
		/* Returns the RectangleShape that is internal to this ChatBox object */
		sf::RectangleShape& GetChatBoxOutline();

		//bool ShouldDisposeBox()
		
		#pragma endregion

	private:
		#pragma region Private Members
		
		bool isRead;					/* Represents the state of whether or not this ChatBox has been read */
		float accumulator;				/* Represents the accumulator value used to update this ChatBox based on the clock */
		unsigned int indexer;			/* Represents the index value used to manage the TypeWriter effect */
		sf::Text entireMessage;			/* Represents the message contained within this ChatBox */
		sf::Text typeWriterMessage;		/* Represents the substring that is drawn to the screen */
		sf::RectangleShape outLine;		/* Represents the Rectangle box that this ChatBox will occupy */
		sf::Uint8 alpha;				/* Represents the alpha color value for this ChatBox */
		sf::String chatBoxName;			/* Represents this ChatBox name */
		sf::Font font;					/* Represents the font for this ChatBox */

		#pragma endregion

	private:
		#pragma region Private Setters

		/* Sets the font of this ChatBox from the content folders font */
		void LoadFont();
		/* Employ a typewriter effect on the string messages for this ChatBox object */
		void TypeWriterEffect(float _dt);
		/* Employ a fadeout effect on the message AND chatbox entity */
		void FadeOut(float _dt);

		#pragma endregion
	};
}