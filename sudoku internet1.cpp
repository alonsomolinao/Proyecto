#include <iostream>

using namespace std;

long ratio[1000];
int pos[1000];
int n;

int EncuentraMaximo(int maxant); //Funcion que encuentra el valor maximo de la matriz ratio[].

int main ()

{
	int i, p, k, l, c;
	int valor[1000], peso[1000], max[1000], posf[1000];
	long m, sumapeso;
	
	cin>>n>>m; //Se lee la cantidad de productos y la capacidad del carrito.
	
	for (i=0;i<n;i++) //Se lee el peso y valor de n cantidad de productos.
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

cout<<endl;

	p=0;
	max[0]=1000;
	
	for (i=0;i<n;i++)
	{
			if (i>0)
			{
				p=i-1; 
			}
			max[i]=EncuentraMaximo(max[p]); //Ordena la matriz ratio[] de mayor a menor.
	}
	
	
	
	for (i=0;i<n;i++)
	{
		pos[i]=1000;
	}
	
	
	for (i=0;i<n;i++)
	{
		for (k=0;k<n;k++)
		{
			if (ratio[k]==max[i])
			{
				pos[i]=k; //es la pocision en las matrices originales en donde se encuentran los valores de mayor a menor.
			}
		}
	}
	
	sumapeso=0;
	l=0;
	
	for (i=0;i<n;i++)
	{
		posf[i]=1000;
	}
	
	for (i=0;i<n;i++)
	{
		sumapeso+=peso[pos[i]];//se le suma el peso del siguiente producto conveniente
		if (sumapeso<=m) //si el peso de los productos no excede la capacidad del carrito
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
	
	
	for (i=0;i<n;i++)
	{
		c=0;
		for (k=1;k<l+1;k++)
		{	
			if (i==posf[k])
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

int EncuentraMaximo(int maxant)
{
	int i, maxVal;
	
	maxVal = 0;
	
	for(i=0; i<n; i++)
	{
		if(ratio[i] > maxVal && ratio[i]<maxant)
		{
			maxVal = ratio[i]; //saca el maximo valor en la matriz que sea menor al maximo que sacó antes la función.
		}
	}
	
	return maxVal;
}
