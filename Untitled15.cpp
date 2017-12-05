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
int * valor, * peso;

// Contadores
long  sumapeso, sumamax, sumavalor;
int l, sumapesomin;

// M�todos
void configurarTienda();
void configurarProductos();
void inicializarContadores();
long encontrarMaximos(Modalidades modalidad);



int main ()
{
    int p, c, j;
    int posf[1000], num[1000];
    long k;

    sumamax=0; // Limpieza pendiente

    srand (time(NULL));

    configurarTienda();

    valor = new int[cantidadDeProductos];
    peso = new int[cantidadDeProductos];

    configurarProductos();

    //Todos los contadores empiezan en 0.
    inicializarContadores();

    // Encontrar maximo
    sumamax = encontrarMaximos(Primera);

    sumapesomin = 10000; //El peso minimo empieza siendo mayor a todos los pesos.

    sumapesomin = (int) encontrarMaximos(Segunda);

    for (k=0;k<205000;k++)
    {
        inicializarContadores();

        p=0;
        for(int i= 0;i<cantidadDeProductos;i++) //se le asigna un valor de 100 a los n�meros
        {
            num[i]=100;
        }
        for (int i=0;i<cantidadDeProductos;i++)
        {
            l=0;
            num[i]=rand() % cantidadDeProductos+0;
            for (j=0;j<cantidadDeProductos;j++)
            {
                if (num[i]!=num[cantidadDeProductos-j-1])
                {
                    l++;
                }
            }
            if (l==cantidadDeProductos-1)
            {
                sumapeso+=peso[num[i]];//se le suma el peso del siguiente producto conveniente
                if (sumapeso<=pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
                {
                    p++;
                    sumavalor+=valor[num[i]];
                    posf[p]=num[i];
                }
                else
                {
                    sumapeso-=peso[num[i]]; //se resta el peso de ese producto si el carrito ya no ten�a la capacidad
                }
            }
        }
        if (sumamax==sumavalor && sumapesomin==sumapeso)
        {
            break;
        }
    }

    cout<<endl;

    c=0;


    for (int i=0;i<cantidadDeProductos;i++)
    {
        c=0;
        for (k=1;k<p+1;k++)
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



long encontrarMaximos(Modalidades modalidad)
{
    long result = 0;
    long sumatoria;
    int  * productos = new int[cantidadDeProductos];
    for (int k = 0;k < 205000; k++) //se repite todo este ciclo muchas veces para tener el valor maximo.
    {
        sumatoria = 0;
        inicializarContadores();
        for(int i = 0 ;i < cantidadDeProductos; i++) //se le asigna un valor de 100 a los n�meros
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
                sumapeso+=peso[productos[i]];//se le suma el peso del producto en posicion num[i]
                if (sumapeso <= pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
                {
                    sumatoria += valor[productos[i]]; //se le suma el valor de este producto
                }
                else
                {
                    sumapeso -= peso[productos[i]]; //se resta el peso de ese producto si el carrito ya no ten�a la capacidad
                }
            }
        }
        switch (modalidad) {
            case Primera:
                if (result < sumatoria) //si la suma de valores en esta combinaci�n excede la sumamaxima...
                {
                    result = sumatoria; //se le asigna este nuevo valor de sumamaxima
                }
                break;
            case Segunda:
                if (sumamax==sumatoria) //Se encuentra la combinacion que de ese valor maximo con el minimo peso.
                {
                    if (sumapesomin > sumapeso)
                    {
                        sumapesomin = sumapeso;
                    }
                }
                break;
            default:
                break;
        }
    }
    if(modalidad == Segunda) {result = sumapesomin; }
    return result;
}

