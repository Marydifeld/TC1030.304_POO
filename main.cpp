// Maryfer
// Said
// Jessica Lizzeth Rodríguez García A00839775

#include "Naranja.h"
#include "Manzana.h"
#include<iostream>

using namespace std;

int main(){
    Frutero* arr[3];
    arr[0] = new Manzana();
    arr[1] = new Naranja();
    arr[2] = new Manzana();

    for(int i = 0; i < 3; i++){
        arr[i]->ShowFruit();
    }
    return 0;
}