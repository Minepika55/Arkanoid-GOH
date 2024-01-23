#include "funcionsJoc.h"

void Dibuixa(RenderWindow& finestre, Sprite& bola, Sprite& player, std::vector<Sprite>& blocs) {
    finestre.clear(sf::Color::Yellow);
    finestre.draw(bola);
    finestre.draw(player);
    for (auto& bloc : blocs) {
        finestre.draw(bloc);
    }
    finestre.display();
}

//Per si la pilota xoca contra la paret.
void PilotaRebota(float dt, Sprite& spritepilota, float& ballSpeedX, float& ballSpeedY) {
    spritepilota.move(ballSpeedX, ballSpeedY);

    //Si choca amb la part de dalt.
    if (spritepilota.getPosition().y <= 0) {
        ballSpeedY = -ballSpeedY;
    }

    //Si choca amb la part de baix.
    if (spritepilota.getPosition().y >= y_max) {
        ballSpeedY = -ballSpeedY;
    }

    //Si choca amb la paret de la esquerra.
    if (spritepilota.getPosition().x <= 0) {
        ballSpeedX = -ballSpeedX;
    }
    //Si la pilota xoca amb la paret de la dreta.
    if (spritepilota.getPosition().x >= x_max) {
        ballSpeedX = -ballSpeedX;

    }

}

bool PilotaRaqueta(Sprite& spritepilota, Sprite& spriteplayer) {
    FloatRect pilotaBox = spritepilota.getGlobalBounds();
    FloatRect raquetaBox = spriteplayer.getGlobalBounds();
    return pilotaBox.intersects(raquetaBox);
}



