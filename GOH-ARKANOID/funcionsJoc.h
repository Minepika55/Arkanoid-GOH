#include <iostream>
#include <SFML/Graphics.hpp>



//Constants globals
const std::string title = "ARKANOID";
const float ballSpeedBase = 7.0f;
const float playerSpeed = 9.0f;
const int x_min = 0, x_max = 800;
const int y_min = 0, y_max = 600;
const int incre_xr = 10, incre_yr = 10;
const int longitut = 100, amplada = 20, radi = 25;



void Dibuixa(RenderWindow& finestre, Sprite& bola, Sprite& player);