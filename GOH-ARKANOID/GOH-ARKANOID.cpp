#include <iostream>
#include <SFML/Graphics.hpp>
#include "funcionsJoc.h"
#include <vector>

using namespace sf;


int main() {
    int punts = 0;
    //Finestra tot aquesta part es per fer la finestra del joc.
    Vector2f viewSize(x_max, y_max);
    VideoMode vm(viewSize.x, viewSize.y);
    RenderWindow window(vm, title, Style::Default);
    window.setFramerateLimit(60); //Aquesta part d'aqui serveix per regular les frames del joc les uqlas intentaran sempre ser 60 per segon.

    //Definim com es la pilota i com reacciona amb el contacte amb les parets de la finestra i els blocs.
    Texture bolaTex;
    bolaTex.loadFromFile("graphics/bola.png"); //Aqui es carrega la textura de la pilota.
    Sprite spritepilota;
    spritepilota.setTexture(bolaTex);
    FloatRect pilotaRect = spritepilota.getLocalBounds();
    spritepilota.setOrigin(pilotaRect.left + pilotaRect.width / 2.0f, pilotaRect.top + pilotaRect.height / 2.0f); 
    spritepilota.setPosition(viewSize.x / 2, viewSize.y / 2); //Aqui s'estableix el tamany de la pilota.

    //Definim la barra del jugador la qual reacciona al input del jugador i es pot moure d'esquerra a dreta.
    Texture playerTex;
    playerTex.loadFromFile("graphics/raqueta.png"); //Aqui es carrega la textura de la barra.
    Sprite spriteplayer;
    spriteplayer.setTexture(playerTex);
    FloatRect playerRect = spriteplayer.getLocalBounds();
    spriteplayer.setOrigin(playerRect.left + playerRect.width / 2.0f, playerRect.top + playerRect.height / 2.0f);
    spriteplayer.setPosition(viewSize.x / 2, viewSize.y - 50); //Aqui s'estableix el tamany de la barra.

    //Definim la velocitat inicial de la pilota a la qual es moura constantment i sense parar.
    float bolaSpeedX, bolaSpeedY;
    bolaSpeedY = bolaSpeedBase * 1;
    bolaSpeedX = bolaSpeedBase * 1.7;
    sf::Clock clock;

    //Aqui carrego la tipografia per el HUD i el Game Over.
    sf::Font font;
    if (!font.loadFromFile("fonts/PLANK.TTF")) {

    }

    //Aquesta part d'aqui crea els blocs a la part de dalt un al costat de l'altre.
    std::vector<Sprite> blocs(numBlocs);
    Texture blocTex;
    blocTex.loadFromFile("graphics/bloc.png"); //Aquesta part carrega la textura utilitzada per tots els blocs.
    for (int i = 0; i < numBlocs; ++i) {
        blocs[i].setTexture(blocTex);
        blocs[i].setPosition(i * 100, 50); //Aquesta part controla la separacio entre els blocs i la seva posicio a la pantalla.
    }
    
    //Aquesta part defineix com es mostra el text de game over.
    sf::Text GameOverMarcador;
    GameOverMarcador.setFont(font);
    GameOverMarcador.setString("Game Over");
    GameOverMarcador.setCharacterSize(50); //Aqui es controla el tamany del text.
    GameOverMarcador.setFillColor(sf::Color::Red); //Aqui es controla el color del text.
    
    //Aquesta part defineix com es mostra el text de la puntuacio.
    sf::Text PuntsMarcador;
    PuntsMarcador.setFont(font);
    PuntsMarcador.setString("Punts: " + std::to_string(punts));
    PuntsMarcador.setCharacterSize(30); //Aqui es controla el tamany del text.
    PuntsMarcador.setFillColor(sf::Color::Blue); //Aqui es controla el color del text.
    PuntsMarcador.setPosition(viewSize.x / 80, viewSize.y / -200); //Aqui es controla la posicio del text.


    //Tot aquest codi s'executa quan la finestra esta oberta.
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        PilotaRebota(dt.asSeconds(), spritepilota, bolaSpeedX, bolaSpeedY);

        //Aqui es carrega el codi que controla la colisio entre la pilota i el jugador.
        if (PilotaRaqueta(spritepilota, spriteplayer)) {
            bolaSpeedY = -bolaSpeedY;
        }
        //Aqui es carrega el codi que controla la colisio entre la pilota i els blocs.
        for (auto& bloc : blocs) {
            if (spritepilota.getGlobalBounds().intersects(bloc.getGlobalBounds())) {
                bolaSpeedY = -bolaSpeedY;
            }
        }


        //Aqui hi ha tot el moviment del jugador, el qual nomes es pot moure d'esquerra a dreta amb les fletxes del teclat.
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

        //Aqui es on es crea la filera de blocs.
        for (auto it = blocs.begin(); it != blocs.end(); ) {
            FloatRect ballBounds = spritepilota.getGlobalBounds();
            FloatRect blocBounds = it->getGlobalBounds();
            if (ballBounds.intersects(blocBounds)) { //Si la pilota colisiona amb el bloc el bloc desapareix.
                it = blocs.erase(it);
                punts += 5;
                PuntsMarcador.setString("Punts: " + std::to_string(punts)); //Si la pilota ha colisionat amb el bloc sumem 5 punts al marcador.
            }
            else {
                ++it;
            }
        }

        //Aquesta part gestiona el game over depenent de la posicio de la pilota
        if (spritepilota.getPosition().y >= y_max) {
            bolaSpeedY = -bolaSpeedY;
            GameOverMarcador.setPosition(viewSize.x / 2, viewSize.y / 2);
            window.draw(GameOverMarcador);
            window.display();
            while (window.pollEvent(event)) {}
        }

        Dibuixa(window, spritepilota, spriteplayer, blocs, PuntsMarcador); //I aqui es dibuixen totes les parts necessaries del joc.

    }


    return 0;
}
