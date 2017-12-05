#include <iostream>

using namespace std;

int n;

int main ()

{
	int l, c, temp, h;
	int * pos, * valor, * peso, *posf;
	long * ratio, * maxs;
	long m, sumapeso;
	
	cin>>n>>m; //Se lee la cantidad de productos y la capacidad del carrito.
	
	valor = new int[n];
    peso = new int[n];
    posf = new int[n];
    pos = new int[n];
    ratio = new long[n];
    maxs = new long[n];
	
	
	for (int i=0;i<n;i++) //Se lee el peso y valor de n cantidad de productos.
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
	maxs[0]=1000;
	
	for (int i=0;i<n;i++)
	{
			maxs[i]=ratio[i];
	}
	
	
for(int i=0;i<n;i++)
 {
 for(int j=0;j<n-i-1;j++)
 {
 if(maxs[j]<maxs[j+1])
 {
 temp=maxs[j];
 maxs[j]=maxs[j+1];
 maxs[j+1]=temp;
 }
 }
 }
	
	
	for (int i=0;i<n;i++)
	{
		pos[i]=1000;
	}
	
	
	h=0;
	
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			h=0;
			for (int k=0;k<n;k++)
			{
				if (j!=pos[n-k-1])
				{
					h++;
				}
			}
			
			if (ratio[j]==maxs[i] && h==n)
			{
				pos[i]=j; //es la pocision en las matrices originales en donde se encuentran los valores de mayor a menor.
			}
		}
	}
		
	sumapeso=0;
	l=0;
	
	for (int i=0;i<n;i++)
	{
		posf[i]=1000;
	}
	
	for (int i=0;i<n;i++)
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
	
	
	for (int i=0;i<n;i++)
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

