#include "bat.h"    	// Include the Bat class header
#include "Ball.h"              
#include <sstream>               // For stringstream (used to create the HUD text)
#include <cstdlib>               // For general utilities (e.g., random functions, though not used here)
#include <SFML/Graphics.hpp>     // Include the SFML graphics module

int main()
{
	// Set up the game window with dimensions 960x540 and a title
	VideoMode vm(960, 540);
	RenderWindow window(vm, "Pong Game");

	// Initialize game variables
	int score = 0;
	int lives = 3;

	// Create a Bat object positioned at the center-bottom of the screen
	Bat bat(960 / 2, 540 - 20);
	Ball ball(960/2,0);

	// Create a text object to display score and lives (the HUD)
	Text hud;

	// Load font for the HUD text
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	// Set font properties for the HUD
	hud.setFont(font);               // Use the loaded font
	hud.setCharacterSize(30);        // Set the size of the text
	hud.setFillColor(Color::White);  // Set the text color to white
	hud.setPosition(20, 20);         // Position the text at the top-left corner

	// Clock used to measure the time between frames (for smooth movement)
	Clock clock;

	// Main game loop: runs until the window is closed
	while (window.isOpen()) {
		Event event1;
		// Handle window events (like closing)
		while (window.pollEvent(event1)) {
			if (event1.type == event1.Closed) {
				window.close();  // Close the window if the event type is "Closed"
			}
		}

		// Handle key press to close the game
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Move the bat left if the left arrow is pressed, else stop moving left
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			bat.moveLeft();
		} else {
			bat.stopLeft();
		}

		// Move the bat right if the right arrow is pressed, else stop moving right
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			bat.moveRight();
		} else {
			bat.stopRight();
		}

		// Get the time since the last frame and update bat's position accordingly
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);

		// Update the HUD text with the current score and lives
		std::stringstream ss;
		ss << "Score: " << score << "  " << "Lives: " << lives;
		hud.setString(ss.str());
		
		// ball hits the bottom 
		if(ball.getPosition().top > window.getSize().y){
			ball.reboundBottom();
			lives--;
			if(lives < 1){
				score = 0;
				lives = 3;
			}
		}
		
		// ball hits the top
		if(ball.getPosition().top < 0){
			ball.reboundBatOrTop();
			score++;
		}
		
		// ball hits the sides (left or right hand sides of the screen)
		if(ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x){
			ball.reboundSides();
		}
		
		// when ball hits the bat 
		if(ball.getPosition().intersects(bat.getPosition())){
			ball.reboundBatOrTop();
		}
			
		// Draw everything
		window.clear();                    // Clear the screen before drawing
		window.draw(hud);                  // Draw the HUD (score and lives)
		window.draw(bat.getShape());       // Draw the bat
		window.draw(ball.getShape());
		window.display();                  // Display the rendered frame
	}

	return 0;
}

