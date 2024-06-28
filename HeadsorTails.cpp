#include <iostream>
#include <random>

using namespace std;

int main()
{
    random_device seed_generator; //hardware random value generator
    mt19937 engine(seed_generator()); //Using Mersenne twister 
    bernoulli_distribution distribution(0.5); //Make a bernoulli_distribution -> random value = 0.5
    int headsCounter = 0; //counter for heads
    int tailsCounter = 0; //counter for tails


    cout << "Tossing a coin\n";

    for(int i = 0 ; i < 3 ; i++)
    {

        cout << "Round " << i + 1 << ": ";

        switch(distribution(engine))
        {
            case true: 
                cout << "Heads";
                headsCounter++;
                break;
            case false:
                cout << "Tails";
                tailsCounter++;
                break;
        }

        cout << "\n";
    }

    cout << "Heads: " << headsCounter << ", Tails: " << tailsCounter << "\n";

    if(headsCounter > tailsCounter)
        cout << "You won\n";
    else if(tailsCounter > headsCounter)
        cout << "You lost\n";
}