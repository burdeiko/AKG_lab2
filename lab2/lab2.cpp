// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define N 3
#define ANGLE_OF_POLYGON 2 * M_PI / N

void DrawRect(SDL_Renderer *renderer, int x0, int y0, int width, double f);
int main()
{
	double angle = ANGLE_OF_POLYGON;
	SDL_Window *window = SDL_CreateWindow("lab2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	double m = 0.1;	
	double f = 0;	
	int width = 1600 / N;
	int y = 500;
	int x = 300 - width / 2;
	double deltaWidth = sqrt(m * m + (1 - m) * (1 - m) + 2 * m * (1 - m) * cos(ANGLE_OF_POLYGON));
	double deltaF = asin(m * width * sin(ANGLE_OF_POLYGON) / (width * deltaWidth));
	while (f < M_PI  )
	{
		DrawRect(renderer, x, y, width, f);
		x += roundl(m * width * cos(f));
		y -= roundl(m * width * sin(f));
		width = roundl(width * deltaWidth);
		f += deltaF;
	}
	SDL_RenderPresent(renderer);
	while (1)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
			break;
	}
    return 0;
}

void DrawRect(SDL_Renderer *renderer, int x0, int y0, int width, double f)
{
	int n = N;
	int x = x0;
	int y = y0;
	
	for (int i = 0; i < n; i++)
	{
		int newX = roundl(x + width * cos(f));
		int newY = roundl(y - width * sin(f));
		SDL_RenderDrawLine(renderer, x, y, newX, newY);
		x = newX;
		y = newY;
		f += 2 * M_PI / n;
	}
	
}

