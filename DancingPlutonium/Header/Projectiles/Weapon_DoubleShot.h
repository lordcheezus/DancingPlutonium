#pragma once

#include<SFML/Graphics.hpp>
#include "AbstractBaseProjectile.h"
#include "Weapon_BasicShot.h"

namespace DancingPlutonium
{
	/* Weapon_DoubleShot class is the 1st stage bullet object which has a very 'basic' pattern trajectory */
	class Weapon_DoubleShot : public AbstractBaseProjectile
	{
	private:
		#pragma region Extra projectile objects

		AbstractBaseProjectile* leftProjectile;		/* Represents a left side trajectory bullet object off the main shot */
		AbstractBaseProjectile* rightProjectile;	/* Represents a right side trajectory bullet object off the main shot */

		#pragma endregion		
	public:
		#pragma region Ctor/Dtors

		/* Weapon_DoubleShot constructor accepting RenderTarget, and Position input parameters */
		Weapon_DoubleShot(const sf::Vector2f& _pos);
		/* Weapon_DoubleShot copy constructor */
		Weapon_DoubleShot(const Weapon_DoubleShot& _ref) {}
		/* Weapon_DoubleShot destructor */
		~Weapon_DoubleShot();

		#pragma endregion

		#pragma region Methods

		/* Sets this projectiles sprite, texture and default position */
		virtual void SetSprite(const sf::Vector2f & _origin) override;
		/* Update this projectile in the world based on the clock */
		virtual void Update(float _dt) override;
		// Draw this projectile in the world
		virtual void Draw(sf::RenderTarget& _rt) override;

		#pragma endregion

		// Inherited via AbstractBaseProjectile
		virtual std::vector<sf::FloatRect> GetBounds() override;
	};
}