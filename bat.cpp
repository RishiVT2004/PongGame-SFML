#include "bat.h"

// Constructor to initialize the Bat's position and shape
Bat::Bat(float startX, float startY) {
	// Set the starting position of the bat
	m_Position.x = startX;
	m_Position.y = startY;

	// Set the size of the bat (width = 50, height = 5)
	m_Shape.setSize(sf::Vector2f(50, 5));

	// Set the initial position of the shape to the starting position
	m_Shape.setPosition(m_Position);
}

// Return the current position of the bat as a FloatRect (used for collision detection)
FloatRect Bat::getPosition() {
	return m_Shape.getGlobalBounds();
}

// Return the shape of the bat (used to draw it on the screen)
RectangleShape Bat::getShape() {
	return m_Shape;
}

// Set the flag to indicate that the bat is moving left
void Bat::moveLeft() {
	m_MovingLeft = true;
}

// Set the flag to indicate that the bat is moving right
void Bat::moveRight() {
	m_MovingRight = true;
}

// Stop the bat from moving left
void Bat::stopLeft() {
	m_MovingLeft = false;
}

// Stop the bat from moving right
void Bat::stopRight() {
	m_MovingRight = false;
}

// Update the bat's position based on the movement flags and time elapsed
void Bat::update(Time dt) {
	// Move left only if the flag is set and the bat is not beyond the left screen edge
	if (m_MovingLeft) {
		if (m_Position.x > 0)
			m_Position.x -= m_Speed * dt.asSeconds(); // Move left with speed scaled by time
	}

	// Move right only if the flag is set and the bat is not beyond the right screen edge
	if (m_MovingRight) {
		if (m_Position.x < 910) // Assumes window width allows movement up to x = 910
			m_Position.x += m_Speed * dt.asSeconds(); // Move right with speed scaled by time
	}

	// Update the bat's shape position to reflect new coordinates
	m_Shape.setPosition(m_Position);
}

