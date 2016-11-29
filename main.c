#include "main.h"
// No hagas #include aquí, hazlos en main.h

int main(int argc, char const *argv[])
{
    // Verifica si hay al menos de 3 parametros
    // sino entonces se imprimen las instrucciones
    // y se para la ejecución del programa
    if (argc < 3)
    {
        imprime_instrucciones();
        return 0;
    }

    return 0;
}

/* ------ Aquí va la implementación de tus funciones ------ */
