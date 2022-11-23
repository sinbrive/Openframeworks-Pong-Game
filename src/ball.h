#pragma once

class Ball
{

public:

	Ball(float, float, float);

	void setup();
	void update();
	void draw();
	bool isOut(int);
	void direction(int, int);

	float radius = 10;
	float x , y;
	float vx = 3.0;
	float vy = 3.0;
	int dx = 1;
	int dy = 1;	
	bool inMotion = false;

};

