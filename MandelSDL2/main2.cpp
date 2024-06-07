#include <SDL2/SDL.h>
#include <numeric>
#include <complex>
#include <cmath>
#include <iostream>

int is_in_set(std::complex<double> c)
{
    std::complex<double> z(0,0);
    for(int i = 0; i < 1000; i++)
    {
        z = std::pow(z,2) + c;
        if(std::norm(z) > 10)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int flag=0;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Event e;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    SDL_CreateWindowAndRenderer(
        1000,
        1000,
        SDL_RENDERER_ACCELERATED,
        &window,
        &renderer
        );

    SDL_RenderSetScale(renderer,2,2);
    auto running = true;

    while(running)
    {
        while(SDL_PollEvent(&e))
        {

            if(e.type == SDL_QUIT)
            {
                running = false;
            }

            while(flag==0)
            {
                for (double x = 0.0; x < 1.0; x += 0.0008)
                {
                    for (double y = 0.0; y < 1.0; y += 0.0008)
                    {
                        double point_x = std::lerp(-2, 2, x);
                        double point_y = std::lerp(-2, 2, y);

                        int iters = is_in_set(std::complex<double>(point_x,point_y));
                        
                        if(iters == 0)
                        {
                            SDL_SetRenderDrawColor
                            (
                                renderer, 
                                0, 
                                0, 
                                0, 
                                255
                            );
                            SDL_RenderDrawPointF
                            (
                                renderer, 
                                x*700, 
                                y*700
                            );
                        }
                        else
                        {
                            SDL_SetRenderDrawColor
                            (
                                renderer, 
                                10*iters%255, 
                                12*iters%255, 
                                14*iters%255, 
                                255
                            );
                            SDL_RenderDrawPointF
                            (
                                renderer, 
                                x*700, 
                                y*700
                            );
                        }
                    }
                }
                flag=1;
            }
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
}