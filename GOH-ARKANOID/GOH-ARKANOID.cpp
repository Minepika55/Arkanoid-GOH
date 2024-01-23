#include <iostream>
#include <SFML/Graphics.hpp>
#include "funcionsJoc.h"
#include <vector>

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
    float bolaSpeedX, bolaSpeedY;
    bolaSpeedY = bolaSpeedBase * 1;
    bolaSpeedX = bolaSpeedBase * 1.7;
    sf::Clock clock;

    
    std::vector<Sprite> blocs(numBlocs);
    Texture blocTex;
    blocTex.loadFromFile("graphics/bloc.png");
    for (int i = 0; i < numBlocs; ++i) {
        blocs[i].setTexture(blocTex);
        blocs[i].setPosition(i * 100, 50); 
    }



    while (window.isOpen()) {
        // Update input
        //UpdateInput(window, spriteplayer);
        // Update Game
        sf::Time dt = clock.restart();
        //  Update(dt.asSeconds(), spritepilota, spriteplayer, ballSpeedX, ballSpeedY);
          //Draw Game 
        PilotaRebota(dt.asSeconds(), spritepilota, bolaSpeedX, bolaSpeedY);

        Dibuixa(window, spritepilota, spriteplayer, blocs);


        if (PilotaRaqueta(spritepilota, spriteplayer)) {
            bolaSpeedY = -bolaSpeedY;
        }


        //Moviment
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    spriteplayer.move(-playerSpeed, 0);
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    spriteplayer.move(playerSpeed, 0);
                }
            }
        }

        for (auto it = blocs.begin(); it != blocs.end(); ) {
            FloatRect ballBounds = spritepilota.getGlobalBounds();
            FloatRect blocBounds = it->getGlobalBounds();
            if (ballBounds.intersects(blocBounds)) {
                it = blocs.erase(it);
            }
            else {
                ++it;
            }
        }


    }
    

    return 0;
}
