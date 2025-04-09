#pragma once  // Ensures this header is only included once during compilation
#include <SFML/Graphics.hpp>  // Include SFML graphics library for rendering shapes
using namespace sf;  // Allows using SFML types directly (like Vector2f, Time, etc.)

// Class that represents the ball in the Pong game
class Ball {

	private:
    		Vector2f m_Position;         // Current position of the ball
    		RectangleShape m_shape;      // The visual shape of the ball (a rectangle for now)
    		float m_Speed = 1200.0f;      // Speed of the ball in pixels per second
    		float m_DirectionX = 0.2f;   // X-axis direction component (positive = right, negative = left)
    		float m_DirectionY = 0.2f;   // Y-axis direction component (positive = down, negative = up)

	public:
    		// Constructor: initialize ball position
   		Ball(float startX, float startY);

    		// Get the position of the ball (used for collision detection)
    		FloatRect getPosition();

    		// Get the SFML shape (for drawing the ball)
    		RectangleShape getShape();

    		// Get the current horizontal velocity (used to bounce or reverse direction)
    		float getXVelocity();
    		
    		void reboundSides();

    		// Change Y direction when ball hits bat or top wall
    		void reboundBatOrTop();

    		// Change Y direction when ball hits bottom (missed by bat)
    		void reboundBottom();

    		// Update ball position based on its speed and direction
    		void update(Time dt);
};

