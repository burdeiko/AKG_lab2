// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include "SDL.h"
#include <math.h>

SDL_Point* GetFirstPolygon();
void DrawPolygon(SDL_Renderer *renderer, SDL_Point *points);
void DrawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);
void GetNextPolygon(SDL_Point *points);



// TODO: reference additional headers your program requires here
