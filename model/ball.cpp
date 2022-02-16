#include "../lib/ball.hpp"
#include <iostream>


Ball::Ball(int size, Vector color, Vector poz){
    this->size = size;
    this->color = color;
    this->poz = poz;
    this->vitess = Vector(0,0,0);
    this->accel = Vector(0,-981.,0);
}

Ball::~Ball(){}

void Ball::update(float dT){
    //Position update
    this->poz.x += this->vitess.x*dT;
    this->poz.y += this->vitess.y*dT;

    //Vitesse update
    this->vitess.x += this->accel.x*dT;
    this->vitess.y += -this->accel.y*dT;
}

bool Ball::collision(Ball ball){
    return false;
}

bool Ball::collision(){
    if(this->poz.y + this->size > 500){
        this->vitess.y = -this->vitess.y + this->vitess.y*0.023;
        this->poz.y = 500 - this->size;
        return true;
    }
    return false;
}

void Ball::render(){
    renderCircle(this->poz, this->color, this->size);
}