#include <iostream>

using namespace std;

struct Articulo {
    int valor = 0;
    int peso = 0;
    long relacion = 0;
};

Articulo  * articulos;
int cantidadDeProductos;
int contador;
long pesoMaximo;
int * pos, *posf;
long  * maxs;


void configurarTienda();
void obtenerRatio();
void mayoraMenorRatio();
void imprimirResultados();
void iniciarPosiciones();

void debug(int data[],string disclaimer);
void debug(long data[],string disclaimer);
int main ()
{
    int h;
    long sumaPeso;

    configurarTienda();

    articulos   = new Articulo[cantidadDeProductos];

    posf = new int[cantidadDeProductos];
    pos = new int[cantidadDeProductos];
    maxs = new long[cantidadDeProductos];

    obtenerRatio();
    mayoraMenorRatio();

    iniciarPosiciones();
    debug(maxs, "imprimiendo maxs");
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
            if (articulos[j].relacion == maxs[i] && h == cantidadDeProductos)
            {
                pos[i] = j; //es la pocision en las matrices originales en donde se encuentran los valores de mayor a menor.
            }
        }
    }

    debug(pos,"imprimiendo posiciones");


    sumaPeso = 0;
    contador = 0;

    iniciarPosiciones();


    for (int i = 0; i < cantidadDeProductos; i++)
    {
        sumaPeso += articulos[pos[i]].peso;//se le suma el peso del siguiente producto conveniente
        if (sumaPeso <= pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
        {
            contador++;
            posf[contador] = pos[i];
        }
        else
        {
            sumaPeso -= articulos[pos[i]].peso; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
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


void obtenerRatio()
{
    for (int i = 0; i < cantidadDeProductos; i++) //Se lee el peso y valor de n cantidad de productos.
    {
        cin>>articulos[i].peso;
        cin>>articulos[i].valor;
        if (articulos[i].peso == 0)
        {
            articulos[i].relacion =  articulos[i].valor * 5000;
        }
        else
        {
            articulos[i].relacion = (articulos[i].valor) * 1000 / (articulos[i].peso); // este valor es la relación entre el valor y peso de un producto
        }
    }
}

void mayoraMenorRatio()
{
    int temp;
    for (int i = 0; i < cantidadDeProductos; i++)
    {
        maxs[i] = articulos[i].relacion;
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

void debug(int data[], string disclaimer)
{
    printf("%s \n",disclaimer.c_str());
    int length = sizeof(*data);
    for(int i = 0; i < length-1; i++)
    {
        printf( "%i \n",data[i]);
    }
    printf("debug \n");
}
void debug(long data[], string disclaimer)
{
    printf("%s \n",disclaimer.c_str());
    long length = sizeof(*data);
    for(int i = 0; i < length-1; i++)
    {
        printf( "%i \n",data[i]);
    }
    printf("debug \n");
}
