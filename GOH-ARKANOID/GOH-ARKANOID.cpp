#include "funcionsJoc.h"
#include "funcionsJoc.cpp"
using namespace sf;

int main() {
    //Finestra
    Vector2f viewSize(x_max, y_max);
    VideoMode vm(viewSize.x, viewSize.y);
    RenderWindow window(vm, title, Style::Default);
    window.setFramerateLimit(60);

    //Definim com es la pilota
    Texture bolaTex;
    bolaTex.loadFromFile("graphics/bola.png");
    Sprite spritepilota;
    spritepilota.setTexture(bolaTex);
    FloatRect pilotaRect = spritepilota.getLocalBounds();
    spritepilota.setOrigin(pilotaRect.left + pilotaRect.width / 2.0f, pilotaRect.top + pilotaRect.height / 2.0f);
    spritepilota.setPosition(viewSize.x / 2, viewSize.y / 2);

    // Definim la barra del jugador
    Texture playerTex;
    playerTex.loadFromFile("graphics/raqueta.png");
    Sprite spriteplayer;
    spriteplayer.setTexture(playerTex);
    FloatRect playerRect = spriteplayer.getLocalBounds();
    spriteplayer.setOrigin(playerRect.left + playerRect.width / 2.0f, playerRect.top + playerRect.height / 2.0f);
    spriteplayer.setPosition(viewSize.x / 2, viewSize.y - 50);

    // Definim la velocitat inicial de la pilota
    float ballSpeedX, ballSpeedY;
    ballSpeedY = ballSpeedBase * 1;
    ballSpeedX = ballSpeedBase * 1.7;
    sf::Clock clock;

    while (window.isOpen()) {
        // Update input
        //UpdateInput(window, spriteplayer);
        // Update Game
        sf::Time dt = clock.restart();
        //  Update(dt.asSeconds(), spritepilota, spriteplayer, ballSpeedX, ballSpeedY);
          //Draw Game
        Dibuixa(window, spritepilota, spriteplayer);
        // PilotaRebota(dt.asSeconds(), spritepilota, ballSpeedX, ballSpeedY);
    }

    return 0;
}
