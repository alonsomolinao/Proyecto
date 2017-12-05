#include <iostream> //Esta es la biblioteca que utilizamos en la clase
#include <stdlib.h>
#include <time.h> //Estos dos se requieren para poder generar numeros aleatorios.
using namespace std;
// Modalidades
enum Modalidades {
    Primera,
    Segunda,
    Tercera
};

// caracteristicas de la tienda
long pesoMaximo;
int cantidadDeProductos;

// Arreglos de productos en tiempo de ejecucion
int * valor, * peso, * posf;

// Contadores
long  sumapeso, sumamax, sumavalor;
int l, sumapesomin, posicion;

// MŽtodos
void configurarTienda();
void configurarProductos();
void inicializarContadores();
long encontrarMaximos(Modalidades modalidad);

int main ()
{
    int c;
    long k;

    sumamax=0; // Limpieza pendiente

    srand (time(NULL));

    configurarTienda();

    valor = new int[cantidadDeProductos];
    peso = new int[cantidadDeProductos];
    posf = new int[cantidadDeProductos];

    configurarProductos();

    //Todos los contadores empiezan en 0.
    inicializarContadores();

    // Encontrar maximo
    sumamax = encontrarMaximos(Primera);

    sumapesomin = 10000; //El peso minimo empieza siendo mayor a todos los pesos.

    //Encontrar combinaci—n con menor peso
    sumapesomin = (int) encontrarMaximos(Segunda);

    int i = (int) encontrarMaximos(Tercera);

    cout<<  endl;

    c=0;

    for (int i=0;i<cantidadDeProductos;i++)
    {
        c=0;
        for (k=1;k<posicion+1;k++)
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

    return 0;
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
        cin>>peso[i];
        cin>>valor[i];
    }
}

void inicializarContadores()
{
    sumapeso=0;
    sumavalor=0;
    l=0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int calcularCiclos() {
    if (cantidadDeProductos < 15)
    {
        return factorial(cantidadDeProductos);
    }
    else
    {
        return 205000;
    }
}

long encontrarMaximos(Modalidades modalidad)
{
    long result = 0;
    long sumatoria;
    int  * productos = new int[cantidadDeProductos];
    int ciclos =  calcularCiclos();

    for (int k = 0; k < ciclos;  k++) //se repite todo este ciclo muchas veces para tener el valor maximo.
    {
        posicion = 0;
        sumatoria = 0;
        inicializarContadores();
        for(int i = 0 ;i < cantidadDeProductos; i++) //se le asigna un valor de 100 a los números
        {
            productos[i] = 100;
        }
        for (int i = 0;i < cantidadDeProductos; i++)
        {
            l = 0;
            productos[i] = rand() % cantidadDeProductos+0; //se obtiene un numero aleatorio entre 0 y n que va a indicar la posicion de lo que se agrega.
            for (int j = 0; j < cantidadDeProductos; j++)
            {
                if (productos[i] != productos[cantidadDeProductos - j - 1])
                {
                    l++;
                }
            }
            if (l == cantidadDeProductos - 1) //Si este numero no se habia utilizado antes
            {
                sumapeso += peso[productos[i]];//se le suma el peso del producto en posicion num[i]
                if (sumapeso <= pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
                {

                    posicion ++;
                    sumatoria += valor[productos[i]]; //se le suma el valor de este producto
                    posf[posicion] = productos[i];
                }
                else
                {
                    sumapeso -= peso[productos[i]]; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
                }
            }
        }
        switch (modalidad) {
            case Primera:
                if (result < sumatoria) //si la suma de valores en esta combinación excede la sumamaxima...
                {
                    result = sumatoria; //se le asigna este nuevo valor de sumamaxima
                }
                break;
            case Segunda:
                if (sumamax == sumatoria) //Se encuentra la combinacion que de ese valor maximo con el minimo peso.
                {
                    if (sumapesomin > sumapeso)
                    {
                        sumapesomin = sumapeso;
                    }
                }
                break;
            case Tercera:
                if (sumamax==sumatoria && sumapesomin==sumapeso)
                {
                    k = ciclos;
                }
                break;
        }
    }

    if(modalidad == Segunda) {result = sumapesomin; }
    return result;
}

