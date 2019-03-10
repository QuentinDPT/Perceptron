#ifndef PRECEPTRON_H
#define PRECEPTRON_H

#include <vector>

typedef enum{HEAVYSIDE,SIGMOID}ACTIVATION_TYPE ;

class Preceptron
{
    public:
        Preceptron(unsigned int) ;
        virtual ~Preceptron() ;

        float guess(float *inputs) ;

        void learn(float *inputs, float expected) ;

        ACTIVATION_TYPE activationFunc ;

        float learnRate ;

        float *weights ;
        unsigned int weightsNumbr ;

    protected:
    private:
};

float activationFunction(float x, ACTIVATION_TYPE type) ;




#endif // PRECEPTRON_H
