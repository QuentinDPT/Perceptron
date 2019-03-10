#include "Preceptron.hpp"

#include <math.h>
#include <iostream>


int error(char *errorType, int errorCode){
    std::cout << errorType << '\n' << "code erreur : " << errorCode << '\n' ;
    return errorCode ;
}


Preceptron::Preceptron(unsigned int nbInput){
    //ctor

    weights = new float[nbInput] ;
    weightsNumbr = nbInput ;

    activationFunc = HEAVYSIDE ;

    learnRate = 0.1 ;

    for(unsigned int i(0) ; i < weightsNumbr ; i++ )
        weights[i] = 0.5 ;
}

Preceptron::~Preceptron(){
    //dtor
}

float Preceptron::guess(float *input){

    float product(0) ;

    for(unsigned int i(0) ; i<weightsNumbr ; i++)
        product += input[i] * weights[i] ;

    return activationFunction(product, activationFunc) ;
}

void Preceptron::learn(float *inputs, float expected){
    float difference = expected-guess(inputs) ;

    for(unsigned int i(0) ; i < weightsNumbr ; i++)
        weights[i] = weights[i] + learnRate*difference*inputs[i] ;
}


float activationFunction(float x, ACTIVATION_TYPE functionType){
    float result = 0;
    switch(functionType){
    case HEAVYSIDE :
        if(x<0)
            result = float(-1.0) ;
        else
            result = float(1.0) ;
    case SIGMOID :
        result = float(1/(1+exp(double(-x)))) ;
    }
    return result ;
}

