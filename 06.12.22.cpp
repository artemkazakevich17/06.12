#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
using namespace sf;


const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float batWidth = 20.f;
const float batHeight = 80.f;
const float batOffset = 50.f;
const sf::Vector2f batSize(20.f, 80.f);
const sf::Color leftBatColor{ 158,20,37 };
const sf::Color rightBatColor{ 20,158,49 };

const float ballRadius = 25.f;
const sf::Color ballColor{ sf::Color::Yellow }
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
	leftBat.setSize(batSize);
	rightBat.setSize(batSize);
	leftBat.setFillColor(leftBatColor);
	rightBat.setFillColor(rightBatColor);
	leftBat.setPosition(batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	//шарик
	CircleShape ball(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);

	float arr_speed[]{ -5.f, -4.f, -3.f, -2.f, -1.f, 1.f, 2.f, 3.f, 4,f, 5.f };
	float index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
	//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов
		//шарик
		//движение шарика
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0 || ball.getPosition().x >=
			(WINDOW_WITH - 2 * ballRadius))
		}
		// скорость оси x сменилась на противоположную
		ball_speedx = -ball_speedx;
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * ballRadius))
		{
		//сккорость по оси у сменилась на противоположную
		ball_speedy = -ball_speedy;
		}
		//Проверка нажатий клавиш
		//если клавиша W нажата
		if (Keybord::isKeyPressed(Keybord::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keybord::isKeyPressed(Keybord::S)) {
			leftBatSpeedY = batSpeed;
		}
		//двигаем ракетку
		leftBat.move(0, leftBatSpeedY);
		// и сразу же обнуляем скорость
		leftBatSpeedY = 0;









		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear();
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		//3.3 вывод на экран
		window.display();
	}

	return 0;
}