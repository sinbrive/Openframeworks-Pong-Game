#pragma once

class Paddle
{

public:

	Paddle(float, float, float, float);

	void update();
	void draw();

	float x;
	float y;
	float w;
	float h;
	int step = 0;
};

