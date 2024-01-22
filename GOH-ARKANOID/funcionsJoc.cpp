#pragma once
#include "funcionsJoc.h"
#include "GOH-ARKANOID.cpp"


////Void per quan la pilota choca amb una paret.
//void PilotaRebota(float dt, Sprite& spritepilota, float& ballSpeedX, float& ballSpeedY) {
//    spritepilota.move(ballSpeedX * dt, ballSpeedY * dt);
//
//    //Si choca amb la part de dalt.
//    if (spritepilota.getPosition().y <= 0) {
//        ballSpeedY = -ballSpeedY;
//    }
//
//    //Si choca amb la part de baix.
//    if (spritepilota.getPosition().y >= y_max - spritepilota.getGlobalBounds().height) {
//        ballSpeedY = -ballSpeedY;
//    }
//
//    //Si choca amb la paret de la esquerra.
//    if (spritepilota.getPosition().x <= 0) {
//        ballSpeedX = -ballSpeedX;
//    }
//    //Si la pilota xoca amb la paret de la dreta.
//    if (spritepilota.getPosition().x >= x_max - spritepilota.getGlobalBounds().height) {
//        ballSpeedX = -ballSpeedX;
//    }
//
//}

void Dibuixa(RenderWindow& finestre, Sprite& bola, Sprite& player) {
    finestre.clear(sf::Color::Yellow);
    finestre.draw(bola);
    finestre.draw(player);
    finestre.display();
}