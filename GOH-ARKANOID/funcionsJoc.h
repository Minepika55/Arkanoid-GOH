#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

const std::string title = "ARKANOID";
const float bolaSpeedBase = 5.0f;
const float playerSpeed = 20.0f;
const int x_min = 0, x_max = 800;
const int y_min = 0, y_max = 600;
const int incre_xr = 10, incre_yr = 10;
const int longitut = 100, amplada = 20, radi = 25;
const int numBlocs = 10;


void Dibuixa(RenderWindow& finestre, Sprite& bola, Sprite& player, std::vector<Sprite>& blocs, Text PuntsMarcador);
void PilotaRebota(float dt, Sprite& spritepilota, float& ballSpeedX, float& ballSpeedY);
bool PilotaRaqueta(Sprite& spritepilota, Sprite& spriteplayer);



