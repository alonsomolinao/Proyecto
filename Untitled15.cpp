#include <iostream> //Esta es la biblioteca que utilizamos en la clase
#include <stdlib.h>
#include <time.h> //Estos dos se requieren para poder generar numeros aleatorios.
using namespace std;
// Modalidades del programa
enum Modalidades {
    Primera,
    Segunda,
    Tercera
};
//Estructura de datos que engloba los valores de valor y peso.
struct Producto {
    int valor;
    int peso;
};

// caracteristicas de la tienda
long pesoMaximo;
int cantidadDeProductos;

// Arreglos de productos en tiempo de ejecucion
int  * posf;

Producto * productos;
// Contadores
long  sumapeso, sumamax, sumavalor;

int l, sumapesomin, posicion;

// MŽtodos
void configurarTienda();
void configurarProductos();
void inicializarContadores();
void encontrarMaximos(Modalidades modalidad);
void imprimirResultados();
int * inicializarPosiciones();

int main ()
{
    sumamax=0; // Limpieza pendiente
    srand(time(NULL));
    configurarTienda();
    productos = new Producto[cantidadDeProductos];
    posf = new int[cantidadDeProductos];
    configurarProductos();
    //Todos los contadores empiezan en 0.
    inicializarContadores();
    // Encontrar sumaMaxima
    encontrarMaximos(Primera);
    sumapesomin = 10000; //El peso minimo empieza siendo mayor a todos los pesos.
    //Encontrar combinaci—n con menor peso
    encontrarMaximos(Segunda);
    encontrarMaximos(Tercera);
    imprimirResultados();
    return 0;
}

void imprimirResultados()
{
    int c = 0;
    cout<<  endl;
    for (int i=0;i<cantidadDeProductos;i++)
    {
        c=0;
        for (int k=1;k<posicion+1;k++)
        {
            if (i==posf[k])
            {
                c=1;
            }
        }
        if (c==1 && i!=cantidadDeProductos-1)
        {
            cout<<1<<" ";
        }
        else if (c==0 && i!=cantidadDeProductos-1)
        {
            cout<<0<<" ";
        }
        else if (c==1 && i==cantidadDeProductos-1)
        {
            cout<<1;
        }
        else if (c==0 && i==cantidadDeProductos-1)
        {
            cout<<0;
        }

    }
}

void configurarTienda()
{
    int n = 0;
    long m = 0;
    bool accepted = false;
    while (!accepted)
    {
        cin>>n>>m;
        if (n <= 20 && m <= 10000)
        {
            accepted = true;
        }
    }
    cantidadDeProductos = n;
    pesoMaximo = m;
}

void configurarProductos()
{
    for (int i=0;i<cantidadDeProductos;i++) //Se lee el peso y valor de n cantidad de productos.
    {
        cin>>productos[i].peso;
        cin>>productos[i].valor;
    }
}

void inicializarContadores()
{
    sumapeso=0;
    sumavalor=0;
    l=0;
}

long factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

long calcularCiclos() {
    return factorial(cantidadDeProductos);
}

int * inicializarPosiciones()
{
    int  * posiciones = new int[cantidadDeProductos];
    for(int i = 0 ;i < cantidadDeProductos; i++) //se le asigna un valor de 100 a los números
    {
        posiciones[i] = 100;
    }
    return posiciones;
}

void encontrarMaximos(Modalidades modalidad)
{
    long sumatoria;

    int * posiciones;
    long limit = calcularCiclos();

    for (long k = 0; k < limit; k++) //se repite todo este ciclo muchas veces para tener el valor maximo.
    {
        posicion = 0;
        sumatoria = 0;
        inicializarContadores();
        posiciones = inicializarPosiciones();
        for (int i = 0;i < cantidadDeProductos; i++)
        {
            l = 0;
            posiciones[i] = rand() % cantidadDeProductos; //se obtiene un numero aleatorio entre 0 y la cantidad de productos que va a indicar la posicion de lo que se agrega.
            for (int j = 0; j < cantidadDeProductos; j++)
            {
                if (posiciones[i] != posiciones[cantidadDeProductos - j - 1])
                {
                    l++;
                }
            }

            if (l == cantidadDeProductos - 1) //Si este numero no se habia utilizado antes
            {
                sumapeso += productos[posiciones[i]].peso;//se le suma el peso del producto en posicion num[i]
                if (sumapeso <= pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
                {
                    posicion ++;
                    sumatoria += productos[posiciones[i]].valor; //se le suma el valor de este producto
                    posf[posicion] = posiciones[i];
                }
                else
                {
                    sumapeso -= productos[posiciones[i]].peso; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
                }
            }
        }
        switch (modalidad) {
            case Primera:
                if (sumamax < sumatoria) //si la suma de valores en esta combinación excede la sumamaxima...
                {
                    sumamax = sumatoria; //se le asigna este nuevo valor de sumamaxima
                }

                break;
            case Segunda:
                if (sumamax == sumatoria) //Se encuentra la combinacion que de ese valor maximo con el minimo peso.
                {
                    if (sumapesomin > sumapeso)
                    {
                        sumapesomin = (int)sumapeso;
                    }
                }
                break;
            case Tercera:
                if (sumamax==sumatoria && sumapesomin==sumapeso)
                {
                    k = limit;
                }
                break;
        }
    }
}



