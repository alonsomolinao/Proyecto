#include <iostream>

using namespace std;

struct articulo {
    int valor = 0;
    int peso = 0;
    long relacion = 0;
};

int cantidadDeProductos;
int contador;
long pesoMaximo;
int * pos, * valor, * peso, *posf;
long * relacion, * maxs;

void configurarTienda();
void obtenerRatio();
void mayoraMenorRatio();
void imprimirResultados();
void iniciarPosiciones();

int main ()
{
    int h;
    long sumaPeso;

    configurarTienda();

    valor = new int[cantidadDeProductos];
    peso = new int[cantidadDeProductos];
    relacion = new long[cantidadDeProductos];

    posf = new int[cantidadDeProductos];
    pos = new int[cantidadDeProductos];
    maxs = new long[cantidadDeProductos];

    obtenerRatio();
    mayoraMenorRatio();

    for (int i = 0; i < cantidadDeProductos; i++) //Se le asigna un valor de 1000 a la posicion para cambiar este valor mas adelante
    {
        pos[i] = 1000;
    }
    for (int i = 0; i < cantidadDeProductos; i++)
    {
        for (int j = 0; j < cantidadDeProductos; j++)
        {
            h = 0;
            for (int k = 0; k < cantidadDeProductos; k++)
            {
                if (j != pos[cantidadDeProductos - k - 1])
                {
                    h++;
                }
            }
            if (relacion[j] == maxs[i] && h == cantidadDeProductos)
            {
                pos[i] = j; //es la pocision en las matrices originales en donde se encuentran los valores de mayor a menor.
            }
        }
    }

    sumaPeso = 0;
    contador = 0;

    iniciarPosiciones();


    for (int i = 0; i < cantidadDeProductos; i++)
    {
        sumaPeso += peso[pos[i]];//se le suma el peso del siguiente producto conveniente
        if (sumaPeso <= pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
        {
            contador++;
            posf[contador] = pos[i];
        }
        else
        {
            sumaPeso -= peso[pos[i]]; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
        }
    }
    imprimirResultados();

    return 0;
}

void iniciarPosiciones()
{
    for (int i = 0; i < cantidadDeProductos; i++)
    {
        posf[i] = 1000;
    }
}

void imprimirResultados()
{
    int valor = 0;
    for (int i = 0; i < cantidadDeProductos; i++)
    {
        valor = 0;
        for (int j = 1; j < contador + 1; j++)
        {
            if (i == posf[j])
            {
                valor=1;
            }
        }
        if (valor == 1)
        {
            cout<<"1 ";
        }
        else if (valor == 0)
        {
            cout<<"0 ";
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

void obtenerRatio()
{
    for (int i = 0; i < cantidadDeProductos; i++) //Se lee el peso y valor de n cantidad de productos.
    {
        cin>>peso[i];
        cin>>valor[i];
        if (peso[i] == 0)
        {
            relacion[i] = valor[i] * 5000;
        }
        else
        {
            relacion[i] = (valor[i]) * 1000 / (peso[i]); // este valor es la relación entre el valor y peso de un producto
        }
    }
}

void mayoraMenorRatio()
{
    int temp;
    for (int i = 0; i < cantidadDeProductos; i++)
    {
        maxs[i] = relacion[i];
    }
    for(int i = 0;i<cantidadDeProductos;i++)
    {
        for(int j = 0;j<cantidadDeProductos - i - 1; j++)
        {
            if(maxs[j] < maxs[j + 1])
            {
                temp = maxs[j];
                maxs[j] = maxs[j + 1];
                maxs[j + 1] = temp;
            }
        }
    }
}

