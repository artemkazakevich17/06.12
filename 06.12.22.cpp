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
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//�������� �������� ����
	//�������
	RectangleShape leftBat, rightBat;
	leftBat.setSize(batSize);
	rightBat.setSize(batSize);
	leftBat.setFillColor(leftBatColor);
	rightBat.setFillColor(rightBatColor);
	leftBat.setPosition(batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	//�����
	CircleShape ball(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);

	float arr_speed[]{ -5.f, -4.f, -3.f, -2.f, -1.f, 1.f, 2.f, 3.f, 4,f, 5.f };
	float index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];

	

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
	//1 ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//2 ���������� ��������
		//�����
		//�������� ������
		ball.move(ball_speedx, ball_speedy);
		if (ball.getPosition().x <= 0 || ball.getPosition().x >=
			(WINDOW_WITH - 2 * ballRadius))
		}
		// �������� ��� x ��������� �� ���������������
		ball_speedx = -ball_speedx;
		}
		if (ball.getPosition().y <= 0 || ball.getPosition().y >=
			(WINDOW_HEIGHT - 2 * ballRadius))
		{
		//��������� �� ��� � ��������� �� ���������������
		ball_speedy = -ball_speedy;
		}
		//�������� ������� ������
		//���� ������� W ������
		if (Keybord::isKeyPressed(Keybord::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keybord::isKeyPressed(Keybord::S)) {
			leftBatSpeedY = batSpeed;
		}
		//������� �������
		leftBat.move(0, leftBatSpeedY);
		// � ����� �� �������� ��������
		leftBatSpeedY = 0;









		//3 ��������� ����
		//3.1 ������� ����
		window.clear();
		//3.2 ��������� �������� (� ������!)
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		//3.3 ����� �� �����
		window.display();
	}

	return 0;
}