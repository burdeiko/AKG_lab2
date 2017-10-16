// lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define N 3
#define K 0.1

int main()
{
	SDL_Window *window = SDL_CreateWindow("lab2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_Point *points = GetFirstPolygon();
	for (int i = 0; i < 10; i++)
	{
		DrawPolygon(renderer, points);
		GetNextPolygon(points);
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

SDL_Point* GetFirstPolygon()
{
	SDL_Point *points = (SDL_Point*)malloc(sizeof(SDL_Point) * N);
	double f = 0;
	int width = 1600 / N;
	int y = 500;
	int x = 300 - width / 2;
	for (int i = 0; i < N; i++)
	{
		int newX = roundl(x + width * cos(f));
		int newY = roundl(y - width * sin(f));
		points[i].x = x;
		points[i].y = y;
		x = newX;
		y = newY;
		f += 2 * M_PI / N;
	}
	return points;
}

void DrawPolygon(SDL_Renderer *renderer, SDL_Point *points)
{
	for (int i = 0; i < N; i++)
	{
		DrawLine(renderer, points[i].x, points[i].y, points[(i + 1) % N].x, points[(i + 1) % N].y);
	}
}

void DrawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void GetNextPolygon(SDL_Point *points)
{
	SDL_Point initialPoint = points[0];
	for (int i = 0; i < N - 1; i++)
	{
		points[i].x += roundl((points[i + 1].x - points[i].x) * K);
		points[i].y += roundl((points[i + 1].y - points[i].y) * K);
	}
	points[N - 1].x += roundl((initialPoint.x - points[N - 1].x) * K);
	points[N - 1].y += roundl((initialPoint.y - points[N - 1].y) * K);
}

