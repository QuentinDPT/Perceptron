#include "Preceptron.hpp"

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

void learning(Preceptron *p, unsigned int example){
    float data[p->weightsNumbr] ;
    int label ;

    srand(time(NULL)) ;

    for(unsigned int i(0) ; i<example ; i++){
        data[0] = float(rand() %100) /100 ;
        data[1] = float(rand() %100) /100 ;
        cout << "waiting\n" ;
        getch() ;

        if(data[0]<data[1]){
            label = 1 ;
            cout << "zone a\n" ;
        }else{
            label = 0 ;
            cout << "zone b\n" ;
        }

        if(p->guess(data) < 0.5){
            if(label == 1){
                    cout << "fail\n" ;
                p->learn(data,float(label)) ;
            }
        }else{
            if(label == 0){
                    cout << "fail\n" ;
                p->learn(data,float(label)) ;
            }
        }
    }
}

void autoLearning(Preceptron *p, unsigned int example){
    float data[p->weightsNumbr] ;
    int label ;

    srand(time(NULL)) ;

    for(unsigned int i(0) ; i<example ; i++){
        data[0] = float(rand() %100) /100 ;
        data[1] = float(rand() %100) /100 ;

        if(data[0]<data[1]){
            label = 1 ;
        }else{
            label = 0 ;
        }

        if(p->guess(data) < 0.5){
            if(label == 1){
                p->learn(data,float(label)) ;
                cout << i << "\t> the preceptron made a mistake !\n" ;
            }
        }else{
            if(label == 0){
                p->learn(data,float(label)) ;
                cout << i << "\t> the preceptron made a mistake !\n" ;
            }
        }
    }
}

int main()
{
    Preceptron neuron(2) ;

    neuron.activationFunc = HEAVYSIDE ;

    autoLearning(&neuron,10000) ;

    cout << "weight data[0] : " << neuron.weights[0] << '\n' ;
    cout << "weight data[1] : " << neuron.weights[1] << '\n' ;

    return 0;
}

