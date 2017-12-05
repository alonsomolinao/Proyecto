#include <iostream>

using namespace std;

int cantidadDeProductos;
long pesoMaximo;
int * pos, * valor, * peso, *posf;
long * ratio, * maxs;

void configurarTienda();
void ObtenerRatio();
void MayoraMenorRatio();


int main ()

{
	int l, c, h;
	long sumapeso;
	
	configurarTienda();
	
	valor = new int[cantidadDeProductos];
    peso = new int[cantidadDeProductos];
    posf = new int[cantidadDeProductos];
    pos = new int[cantidadDeProductos];
    ratio = new long[cantidadDeProductos];
    maxs = new long[cantidadDeProductos];
	
	
	ObtenerRatio();
	
	MayoraMenorRatio();
	
	
	for (int i = 0; i < cantidadDeProductos; i++) //Se le asigna un valor de 1000 a la posicion para cambiar este valor mas adelante
	{
		pos[i]=1000;
	}
	
	
	
	for (int i=0;i<cantidadDeProductos;i++)
	{
		for (int j=0;j<cantidadDeProductos;j++)
		{
			h=0;
			for (int k=0;k<cantidadDeProductos;k++)
			{
				if (j!=pos[cantidadDeProductos-k-1])
				{
					h++;
				}
			}
			
			if (ratio[j]==maxs[i] && h==cantidadDeProductos)
			{
				pos[i]=j; //es la pocision en las matrices originales en donde se encuentran los valores de mayor a menor.
			}
		}
	}
		
	sumapeso=0;
	l=0;
	
	for (int i=0;i<cantidadDeProductos;i++)
	{
		posf[i]=1000;
	}
	
	for (int i=0;i<cantidadDeProductos;i++)
	{
		sumapeso+=peso[pos[i]];//se le suma el peso del siguiente producto conveniente
		if (sumapeso<=pesoMaximo) //si el peso de los productos no excede la capacidad del carrito
		{
		l++;
		posf[l]=pos[i];
		}
		else
		{
			sumapeso-=peso[pos[i]]; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
		}
	}
	
	c=0;
	
	
	for (int i=0;i<cantidadDeProductos;i++)
	{
		c=0;
		for (int j=1;j<l+1;j++)
		{	
			if (i==posf[j])
			{
				c=1;
			}
		}
		if (c==1)
		{
			cout<<"1 ";
		}
		else if (c==0)
		{
			cout<<"0 ";
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

void ObtenerRatio()
{
	for (int i=0;i<cantidadDeProductos;i++) //Se lee el peso y valor de n cantidad de productos.
	{
		cin>>peso[i];
		cin>>valor[i];
		if (peso[i]==0)
		{
			ratio[i]=valor[i]*500;
		}
		else
		{
		ratio[i]=(valor[i])*100/(peso[i]); // este valor es la relación entre el valor y peso de un producto
		}
	}
}

void MayoraMenorRatio()
{
int temp;

for (int i=0;i<cantidadDeProductos;i++)
	{
			maxs[i]=ratio[i];
	}


for(int i=0;i<cantidadDeProductos;i++)
 	{
 		for(int j=0;j<cantidadDeProductos-i-1;j++)
 		{
 			if(maxs[j]<maxs[j+1])
			{
				temp=maxs[j];
 				maxs[j]=maxs[j+1];
				maxs[j+1]=temp;
			}
 		}
 	}
}
