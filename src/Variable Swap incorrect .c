#include <stdio.h>

//  FUNCIÓN INCORRECTA (sin punteros)
void swap_incorrecto(int firstVariable, int secondVariable)
{
    int temp;
    
    printf("\n--- DENTRO DE FUNCIÓN INCORRECTA ---\n");
    printf("Solo estamos trabajando con COPIA de valores\n");
    
    temp = firstVariable;
    firstVariable = secondVariable;
    secondVariable = temp;
    
    // Estos cambios solo afectan las copias locales
    printf("Valores dentro de la función: a=%d, b=%d\n", firstVariable, secondVariable);
}

int main(void)
{
    int a = 100;
    int b = 200;
    
    printf("=== DEMOSTRACIÓN INCORRECTA ===\n");
    printf("Antes de swap incorrecto: a=%d, b=%d\n", a, b);
    
    // LLAMADA INCORRECTA (sin &)
    swap_incorrecto(a, b);  // Pasa valores, no direcciones
    
    printf("Después de swap incorrecto: a=%d, b=%d\n", a, b);
    printf(" LOS VALORES NO CAMBIARON - SOLO SE COPIARON\n");
    
    return 0;
}