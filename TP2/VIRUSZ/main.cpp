#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "tejido.h"

using namespace std;

void leer_archivo (){
    ifstream estado;
    estado.open ("estado.txt");
    if (!estado){
        cout << "ERROR! no se pudo abrir el archivo" << endl;
        return;
    }
}

int main() {
    leer_archivo();
    return 0;
}
