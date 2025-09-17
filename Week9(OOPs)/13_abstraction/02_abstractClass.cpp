
#include<iostream>
#include "02_bird.h"
using namespace std;

void birdDoesSomethind(Bird* &bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
}

int main()
{
    Bird *bird = new sparrow;
    birdDoesSomethind(bird);
    return 0;
}