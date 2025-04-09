/*
In C++, when you define a class in a header file (Ball.h) and then implement the functions in a source file (Ball.cpp), you use the ClassName:: scope resolution operator to tell the compiler:

“This function belongs to the Ball class.”

Without Ball::, the compiler would think you're defining a standalone function,
not one tied to your Ball class.

*/


#include "Ball.h"

// Constructor: initializes the ball's position and shape
Ball::Ball(float startX, float startY) {
    m_Position.x = startX;
    m_Position.y = startY;

    // Set size of the ball to 10x10 pixels
    m_shape.setSize(sf::Vector2f(10, 10));
    m_shape.setPosition(m_Position);
}

// Get the bounding rectangle of the ball (used for collision detection)
FloatRect Ball::getPosition() {
    return m_shape.getGlobalBounds();
}

// Get the shape of the ball (for drawing on screen)
RectangleShape Ball::getShape() {
    return m_shape;
}

// Get the X-axis velocity of the ball
float Ball::getXVelocity() {
    return m_DirectionX;
}

// Reverse X direction (used when ball hits left or right wall)
void Ball::reboundSides() {
    m_DirectionX = -m_DirectionX;
}

// Reverse Y direction (used when ball hits the bat or top wall)
void Ball::reboundBatOrTop() {
    m_DirectionY = -m_DirectionY;    
}

// Reverse Y direction and reset position (used when ball hits the bottom)
void Ball::reboundBottom() {
    m_Position.y = 0;
    m_Position.x = 500;  // Reset position
    m_DirectionY = -m_DirectionY;
}

// Update the ball's position based on time and velocity
void Ball::update(Time dt) {
    m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
    m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

    m_shape.setPosition(m_Position);
}

