#include <iostream> //Esta es la biblioteca que utilizamos en la clase
#include <stdlib.h>
#include <time.h> //Estos dos se requieren para poder generar numeros aleatorios.
using namespace std;

int main ()

{
	int i, p, l, c, x, j, s, n, sumapesomin, nmin;
	int valor[1000], peso[1000], max[1000], posf[1000], num[1000];
	long m, sumapeso, sumamax, sumavalor, k;
	srand (time(NULL));

	
	cin>>n>>m; //Se lee la cantidad de productos y la capacidad del carrito.
	
	for (i=0;i<n;i++) //Se lee el peso y valor de n cantidad de productos.
	{
		cin>>peso[i];
		cin>>valor[i];
	}
	
	//Todos los contadores empiezan en 0.
	sumapeso=0;
	sumavalor=0;
	sumamax=0;
	l=0;
	s=0;
	nmin=0-n;
	
	for (k=0;k<205000;k++) //se repite todo este ciclo muchas veces para tener el valor maximo.
	{
		l=0;
		sumapeso=0;
		sumavalor=0;
for(i=nmin;i<n;i++) //se le asigna un valor de 100 a los números
	{
		num[i]=100;
	}
		for (i=0;i<n;i++)
		{
			l=0;
			num[i]=rand() % n+0; //se obtiene un numero aleatorio entre 0 y n que va a indicar la posicion de lo que se agrega.
			for (j=0;j<n;j++)
			{
				if (num[i]!=num[n-j-1]) 
				{
					l++;
				}
			}
			if (l==n-1) //Si este numero no se habia utilizado antes
		{
			sumapeso+=peso[num[i]];//se le suma el peso del producto en posicion num[i]
			if (sumapeso<=m) //si el peso de los productos no excede la capacidad del carrito
			{
				sumavalor+=valor[num[i]]; //se le suma el valor de este producto
			}	
			else
			{
				sumapeso-=peso[num[i]]; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
			}	
		}
		}
		if (sumamax<sumavalor) //si la suma de valores en esta combinación excede la sumamaxima...
		{
			sumamax=sumavalor; //se le asigna este nuevo valor de sumamaxima
		}
	}
	
	sumavalor=0; 
	sumapeso=0;
	l=0;
	sumapesomin=10000; //El peso minimo empieza siendo mayor a todos los pesos.
	
	for (k=0;k<205000;k++)
	{
		for(i=nmin;i<n;i++) //se le asigna un valor de 100 a los números
	{
		num[i]=100;
	}
		l=0;
		sumapeso=0;
		sumavalor=0;
		for (i=0;i<n;i++)
		{
			l=0;
			num[i]=rand() % n+0;
			for (j=0;j<n;j++)
			{
				if (num[i]!=num[n-j-1])
				{
					l++;
				}
			}
			if (l==n-1)
		{
			sumapeso+=peso[num[i]];//se le suma el peso del siguiente producto conveniente
			if (sumapeso<=m) //si el peso de los productos no excede la capacidad del carrito
			{
				sumavalor+=valor[num[i]];
			}	
			else
			{
				sumapeso-=peso[num[i]]; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
			}	
		}
		}
		if (sumamax==sumavalor) //Se encuentra la combinacion que de ese valor maximo con el minimo peso.
		{
			if (sumapesomin>sumapeso)
			{
				sumapesomin=sumapeso;
			}
		}
	}
	
	sumavalor=0;
	sumapeso=0;
	l=0;
	p=0;
	
	for (k=0;k<205000;k++)
	{
		l=0;
		sumapeso=0;
		sumavalor=0;
		p=0;
		for(i=nmin;i<n;i++) //se le asigna un valor de 100 a los números
	{
		num[i]=100;
	}
		for (i=0;i<n;i++)
		{
			l=0;
			num[i]=rand() % n+0;
			for (j=0;j<n;j++)
			{
				if (num[i]!=num[n-j-1])
				{
					l++;
				}
			}
			if (l==n-1)
		{
			sumapeso+=peso[num[i]];//se le suma el peso del siguiente producto conveniente
			if (sumapeso<=m) //si el peso de los productos no excede la capacidad del carrito
			{
				p++;
				sumavalor+=valor[num[i]];
				posf[p]=num[i];
			}	
			else
			{
				sumapeso-=peso[num[i]]; //se resta el peso de ese producto si el carrito ya no tenía la capacidad
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
	
	
	for (i=0;i<n;i++)
	{
		c=0;
		for (k=1;k<p+1;k++)
		{	
			if (i==posf[k])
			{
				c=1;
			}
		}
		if (c==1 && i!=n-1)
		{
			cout<<1<<" ";
		}
		else if (c==0 && i!=n-1)
		{
			cout<<0<<" ";
		}
		else if (c==1 && i==n-1)
		{
			cout<<1;
		}
		else if (c==0 && i==n-1)
		{
			cout<<0;
		}
	
	}
	
	
	return 0;
}
