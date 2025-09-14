#include <stdio.h>  

void swap(int *pFirstVariable, int *pSecondVariable)
{
    int temp;
    
    printf("\n--- DENTRO DE LA FUNCION SWAP ---\n");
    printf("Direccion de pFirstVariable: %p\n", (void*)&pFirstVariable);
    printf("Direccion de pSecondVariable: %p\n", (void*)&pSecondVariable);
    printf("Direccion de temp: %p\n", (void*)&temp);
    
    printf("Valor apuntado por pFirstVariable: %d\n", *pFirstVariable);
    printf("Valor apuntado por pSecondVariable: %d\n", *pSecondVariable);
    
    // Intercambio de valores usando punteros desreferenciados
    temp = *pFirstVariable;
    *pFirstVariable = *pSecondVariable;
    *pSecondVariable = temp;
}

int main(void)
{
    int a = 100;
    int b = 200;
    
    printf("=== VARIABLE SWAP CON PUNTEROS ===\n\n");
    
    printf("--- ANTES DEL SWAP ---\n");
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    printf("Direccion de memoria de a: %p\n", (void*)&a);
    printf("Direccion de memoria de b: %p\n", (void*)&b);
    
    printf("\n--- INFORMACION SOBRE MEMORIA ---\n");
    printf("Las variables 'a' y 'b' fueron alojadas en:\n");
    printf("- Segmento de STACK (pila) de la funcion main\n");
    printf("- Son variables locales automaticas\n");
    printf("- Su memoria se libera al finalizar la funcion main\n");
    
    // Llamar a la función swap
    swap(&a, &b);
    
    printf("\n--- DESPUES DEL SWAP ---\n");
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    printf("Direccion de memoria de a: %p (se mantiene igual)\n", (void*)&a);
    printf("Direccion de memoria de b: %p (se mantiene igual)\n", (void*)&b);
    
    printf("\n=== CONCLUSION ===\n");
    printf("Se intercambiaron los VALORES, no las DIRECCIONES de memoria.\n");
    printf("Las variables permanecen en las mismas ubicaciones de memoria.\n");
    
    return 0;
}