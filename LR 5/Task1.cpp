#include <iostream>
#include <fstream>

#include <forward_list>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

vector<vector<bool>> adjacencyM;
int verts, edges;

void Read_g()
{
	ifstream ifs("data1.txt");
	if (ifs.is_open())
	{
		ifs >> verts;
		ifs >> edges;
		adjacencyM.resize(verts, vector<bool>(verts));
		while (!ifs.eof())
		{
			int data;
			ifs >> data;
			adjacencyM[]
		}
		cout << "Данные успешно считаны";
	}
	else
	{
		cerr << "Ошибка открытия файла";
	}
	ifs.close();
}

void Print_g()
{
	for (int i = 1; i <= verts; i++)
	{
		cout << i << " вершина: ";
		vector<int> temp;
		for (int j = 1; j <= verts; j++)
		{
			if (adjacencyM[i][j])
			{
				temp.push_back(j);
				cout << j << " ";
			}
		}
		if (temp.empty())
		{
			cout << "<нет смежных вершин>";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	Read_g();
	if (adjacencyM.empty())
	{
		cout << "Данные отсутствуют";
	}
	else
	{
		Print_g();
	}



}