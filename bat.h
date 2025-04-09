/*
A header file (typically ending in .h or .hpp) is used to:

1. Declare classes, functions, and variables that can be shared between multiple .cpp files.

2. Separate interface from implementation — you put declarations in the .h file and define their behavior in the .cpp file.

3. Help organize code and reduce repetition using #pragma once or #ifndef to prevent multiple inclusions of the same file.

*/
#pragma once  // Ensures the header file is only included once during compilation
#include <SFML/Graphics.hpp>  // Include the SFML graphics module
using namespace sf;  // Allows us to use SFML classes without prefixing them with 'sf::'

// Class representing the player's paddle (Bat) in the Pong game
class Bat{
	private:
    		Vector2f m_Position;        // Stores the current position of the bat
    		RectangleShape m_Shape;     // SFML shape used to draw the bat on the screen
    		float m_Speed = 1000.0f;    // Speed at which the bat moves (pixels per second)
    		bool m_MovingRight = false; // Flag to check if the bat is moving right
    		bool m_MovingLeft = false;  // Flag to check if the bat is moving left

	public:
    		// Constructor to initialize the bat at a starting position
    		Bat(float startX, float startY);

    		// Returns the bat's current position as a rectangle (for collision detection)
    		FloatRect getPosition();

    		// Returns the bat's SFML shape (used for rendering)
    		RectangleShape getShape();

    		// Methods to set movement flags
    		void moveLeft();    // Set the bat to move left
    		void moveRight();   // Set the bat to move right
    		void stopLeft();    // Stop the bat from moving left
    		void stopRight();   // Stop the bat from moving right

    		// Updates the bat's position based on elapsed time and movement flags
    		void update(Time dt);
};

