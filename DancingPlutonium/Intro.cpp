#include "Intro.h"

// Static variable declarations:
sf::Uint32 Intro::m_state = s_uninitialized;

void Intro::Show(sf::RenderWindow& window)
{
	// Ensure that the initialization takes place correctly here and for the first time.
	if (m_state != intro_state::s_uninitialized)
	{
		return;
	}

	m_state = intro_state::s_playing;

	// Set up the Timers.
	sf::Clock clock1, clock2;
	sf::Time dt;

	// Set up the Texts which create the splash screen.
	Button welcomeButton = Button("Welcome To Dancing Plutonium", sf::Color::Red, sf::Color::Blue, 80, false);
	welcomeButton.setPosition(sf::Vector2f(window.getSize().x / 2.0f - welcomeButton.getBounds().width / 2.0f, window.getSize().y / 3.0f - welcomeButton.getBounds().height / 2.0f));

	Button sponsor = Button("Starring and Directed by: Mario Migliacio", sf::Color::Yellow, sf::Color::Blue, 40, false);
	sponsor.setPosition(sf::Vector2f(window.getSize().x / 2.0f - sponsor.getBounds().width / 2.0f, window.getSize().y / 2.0f - sponsor.getBounds().height / 2.0f));

	// Set up the music player.
	sf::SoundBuffer sb;
	sb.loadFromFile("Content/Sounds/IntroClip.wav");

	sf::Sound menusound;
	menusound.setBuffer(sb);
	menusound.setVolume(50);
	menusound.play();

	// Perform the Introduction splash screen!
	while (m_state == intro_state::s_playing && clock1.getElapsedTime().asSeconds() <= 6.0f)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_state = intro_state::s_done;
				return;
			}
		}

		window.clear();

		dt = clock2.restart();
				
		if (clock1.getElapsedTime().asSeconds() >= 5.0f)
		{
			welcomeButton.fadeOut(dt.asSeconds());
			welcomeButton.Draw(window);
		}
		else if (clock1.getElapsedTime().asSeconds() >= 1.0f)
		{
			welcomeButton.fadeIn(dt.asSeconds());
			welcomeButton.Draw(window);
		}

		if (clock1.getElapsedTime().asSeconds() >= 5.0f)
		{
			sponsor.fadeOut(dt.asSeconds());
			sponsor.Draw(window);
		}
		else if (clock1.getElapsedTime().asSeconds() >= 2.0f)
		{
			sponsor.fadeIn(dt.asSeconds());
			sponsor.Draw(window);
		}		

		window.display();
	}

	m_state = intro_state::s_done;
}

sf::Uint32 Intro::getIntroState() const
{
	return m_state;
}