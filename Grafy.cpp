#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <string>

using namespace std;

void KahnmGrafu(int** tab, int a, int b, int* pom)
{
	int p = 2* a + 2;
	int c = 0;
	bool czy_wyp = 1;
	stack<int> stos;
	while (c < a)
	{
		bool pomocniczy = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				int wartp = tab[j][a];
				int wartk = tab[j][wartp-1];
				if (tab[j][i] ==wartk)
				{
					pomocniczy = 0;
					break;
				}
				else if (tab[j][i] == p)
				{
					pomocniczy = 0;
					break;
				}
				else
					pomocniczy = 1;
			}
			if (pomocniczy)
				stos.push(i);
		}
		if (!stos.empty())
		{
			while (!stos.empty())
			{
				pom[c] = stos.top();
				for (int i = 0; i < a; i++)
				{
					tab[stos.top()][i] = 0;
				}
				c++;
				tab[stos.top()][stos.top()] = p;
				stos.pop();
			}
		}
		else
		{
			cout << "Graf zawiera cykl, sortowanie niemozliwe!" << endl;
			czy_wyp = 0;
			break;
		}
	}
	//wypisywanie kahna
	if (czy_wyp)
	{
		for (int i = 0; i < a; i++)
		{
			cout << pom[i] + 1 << " ";
		}
		std::cout << endl;
	}


}

void KahnmSasiedztwa(int** tab, int a, int b,int *pom)
{
	int c=0;
	bool czy_wyp = 1;
	stack<int> stos;
	while (c < a)
	{
		bool pomocniczy = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if (tab[j][i] == 1)
				{
					pomocniczy = 0;
					break;
				}
				else if(tab[j][i] == 2)
				{
					pomocniczy = 0;
					break;
				}
				else
					pomocniczy = 1;
			}
			if (pomocniczy)
				stos.push(i);
		}
		if (!stos.empty())
		{
			while (!stos.empty())
			{
				pom[c] = stos.top();
				for (int i = 0; i < a; i++)
				{
					tab[stos.top()][i] = 0;
				}
				c++;
				tab[stos.top()][stos.top()] = 2;
				stos.pop();
			}
		}
		else
		{
			cout << "Graf zawiera cykl, sortowanie niemozliwe!" << endl;
			czy_wyp = 0;
			break;
		}
	}
	//wypisywanie kahna
	if (czy_wyp)
	{
		for (int i = 0; i < a; i++)
		{
			cout << pom[i] + 1 << " ";
		}
		std::cout << endl;
	}
}

void DFSmSasiedztwa(int **tab,int a,int b)
{
	int pom;
	int started=1;
	//cout << "Podaj wierzcholek pocztakowy: ";
	//cin >> started;
	bool* wierzch=new bool[a];
	for(int i=0;i<a;i++)
	{
		wierzch[i] = 0;
	}
	bool** visited = new bool* [a];
	for (int i = 0; i < a; i++)
	{
		visited[i] = new bool[a];
		for(int j=0;j<a;j++)
		{
			visited[i][j] = false;
		}
	}
	
	stack<int> stos;
	stos.push(started-1);
	cout << started << " ";
	while(!stos.empty())
	{
		for (int i = 0; i < a; i++)
		{
			//cout <<"i: "<<i << " tab: " << tab[stos.top()-1][i] << " vis: " << visited[stos.top()-1][i] << endl;
			if (tab[stos.top()][i] == 1 && visited[stos.top()][i] == 0)
			{
				pom = i; break;
			}
			else
				pom = -1;
		}
		if (pom >= 0)
		{
			visited[stos.top()][pom] = 1;
			stos.push(pom);
			if(wierzch[pom] ==0)
				cout << pom+1 << " ";
			wierzch[pom] = 1;
		}
		else
		{
			stos.pop();
		}
	}
	cout << endl;
}

void DFSmGrafu(int**tab,int a,int b)
{
	int pom;
	int started = 1;
	//cout << "Podaj wierzcholek pocztakowy: ";
	//cin >> started;
	int wartp = tab[started - 1][a];
	int wartk = tab[started - 1][wartp - 1];
	bool* wierzch = new bool[a];
	
	for (int i = 0; i < a; i++)
	{
		wierzch[i] = 0;
	}
	bool** visited = new bool* [a];
	for (int i = 0; i < a; i++)
	{
		visited[i] = new bool[a];
		for (int j = 0; j < a; j++)
		{
			visited[i][j] = false;
		}
	}
	stack<int> stos;
	stos.push(started - 1);
	wartp = tab[stos.top() ][a];
	wartk = tab[stos.top() ][wartp - 1];
	cout << started << " ";
	while (!stos.empty())
	{
		
		for (int i = 0; i <= a; i++)
		{
			//cout <<"i: "<<i << " tab: " << tab[stos.top()-1][i] << " vis: " << visited[stos.top()-1][i] << endl;
			if (tab[stos.top()][i] == wartk && visited[stos.top()][i] == 0)
			{
				pom = i; break;
			}
			else
				pom = -1;
		}
		if (pom >= 0)
		{
			visited[stos.top()][pom] = 1;
			stos.push(pom);
			wartp = tab[stos.top() ][a];
			wartk = tab[stos.top() ][wartp - 1];
			if (wierzch[pom] == 0)
				cout << pom + 1 << " ";
			wierzch[pom] = 1;
		}
		else
		{
			stos.pop();
			if (!stos.empty()) {
				wartp = tab[stos.top()][a];
				wartk = tab[stos.top()][wartp - 1];
			}
		}
	}
	cout << endl;
}
 
int main()
{
	int a = 1000;
	
	/// <summary>
	/// MAcierz SASiedztwa ////////////////////////////////////
	/// </summary>
	
	int b, c, d;
	
	fstream plik;
	plik.open("dane.txt",ios::in||ios::out);
	if (plik.good() == true)
	{
		plik << a << a << endl;
		srand(time(NULL));
		for (int i = 1; i <= a; i++)
		{
			int wylosowana_liczba = (std::rand() % 100);
			if (i + wylosowana_liczba > a)
			{
				plik << i << a << endl;
			}
			else
			{
				plik << i << i + wylosowana_liczba << endl;
			}
		}
		
		plik >> a >> b;//a->il wierzchołków | b->il krawedzi
		int** tab = new int* [b]; // tablica zawierajaca wszytskie wierzchołki z pliku

		for (int i = 0; i < b; i++)
		{
			plik >> c >> d;
			tab[i] = new int[3];
			tab[i][0] = c;
			tab[i][1] = d;
		}
		 
		 int** tab1 = new int* [a]; //wsk na tablice pokazujaca ilosc wierzchołków i usytuowanie krawedzi

		//lokowanie pamieci
		for (int i = 0; i < a; i++)
		{
			tab1[i] = new int[a];
			for (int j = 0; j < a; j++)
				for(int k=0;k<b;k++)
				{
					if (tab[k][0]-1 == i && tab[k][1]-1 == j)
					{
						tab1[i][j] = 1;
						break;
					}
					else {
						tab1[i][j] = 0;
					}
				}	
		}
		int* p = new int[a];// tablica pomocnicza

			//wypisywanie 
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++)
			{
				cout << tab1[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		
		DFSmSasiedztwa(tab1, a, b);
		KahnmSasiedztwa(tab1, a, b,p);

		//usuwanie tablic

		for (int i(0); i < a; ++i)
			delete[] tab1[i]; //uwolnienie pamieci
		delete[] tab1; //uwolnienie pamieci
		tab1 = NULL;
		


	/// <summary>
	/// MAcierz SASiedztwa ////////////////////////////////////
	/// </summary>
	/// 
	/// Macierz Grafu////////////////////////////////////
	/// 


		int** tab2 = new int* [a]; //wsk na tablice pokazujaca ilosc wierzchołków i usytuowanie krawedzi

		for (int i = 0; i < a; i++)
		{
			list<int> lista;
			int wartoscp;//wart poczatkowa
			int wartosck;//wart koncowa
			int pom = 2 * a + 10;
			tab2[i] = new int[a + 3];
			
			for (int j = 0; j < a; j++)
			{
				tab2[i][j] = pom;
			}
			//cout << tab2[i][3] << endl;

			
			//Nastepniki
			for(int j=0;j<b;j++)
			{
				//cout << "t:" << tab[j][0] <<"i:"<< i << i + 1 << endl;
				if(tab[j][0]==i+1)
				{
					lista.push_front(tab[j][1]);
				}
			}			

			if (!lista.empty())
			{
			/*	for (list<int>::iterator it = lista.begin(); it != lista.end(); it++)
				{
					cout << *it << " ";
				}
				cout << endl;*/
			lista.sort();
			wartoscp = lista.front();
				wartosck = lista.back();
				//cout << wartosck << " " << wartoscp << endl;
				tab2[i][a] = wartoscp;
				for (int k = 1; k <=a; k++)
				{
					if (!lista.empty())
					{
						if (k == lista.front())
						{
							tab2[i][k-1] = wartosck;
							lista.pop_front();
						}
					}
				}
				lista.clear();
			}
			else{ tab2[i][a] = 0; }
			
			//Poprzedniki
			for (int j = 0; j < b; j++)
			{
				if (tab[j][1] == i+1)
				{
					lista.push_back(tab[j][0]);
				}
			}
			if (!lista.empty()) 
			{
				lista.sort();
				wartoscp = lista.front();
				wartosck = a+lista.back();
				
				tab2[i][a + 1] = wartoscp;
				for (int k = 1; k <= a; k++)
				{
					if (!lista.empty())
					{
						if (k == lista.front())
						{
							tab2[i][k-1] = wartosck;
							lista.pop_front();
						}
					}
				}
				lista.clear();
			}
			else { tab2[i][a+1] = 0; }
		
			//puste
			for (int j = 0; j < a; j++)
			{
				if (tab2[i][j]==pom)
				{
					lista.push_back(j);
				}
			}
			if (!lista.empty())
			{
				lista.sort();
				wartoscp = lista.front();
				wartosck = -1*lista.back();
				tab2[i][a + 2] = wartoscp+1;
				for (int k = 0; k < a; k++)
				{
					if (!lista.empty())
					{
						if (k == lista.front())
						{
							tab2[i][k] = wartosck-1;
							lista.pop_front();
						}
					}
				}
				lista.clear();
			}
			else { tab2[i][a + 2] = 0; }
		}

		cout << endl;



//wypisywanie
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a+3; j++)
			{
				cout << tab2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		int* p1 = new int[a];// tablica pomocnicza
		
		DFSmGrafu(tab2,a,b);
		KahnmGrafu(tab2, a, b, p);

		//usuwanie tablic

		for (int i(0); i < a; ++i)
			delete[] tab2[i]; //uwolnienie pamieci
		delete[] tab2; //uwolnienie pamieci
		tab2 = NULL;


		for (int i(0); i < b; ++i)
			delete[] tab[i]; //uwolnienie pamieci
		delete[] tab; //uwolnienie pamieci
		tab = NULL;

	}
	else cout << "Dostep do pliku zostal zabroniony!" << endl;
	plik.close();
}

 
