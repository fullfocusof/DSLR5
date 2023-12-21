//#include <iostream>
//#include <fstream>
//
//#include <forward_list>
//#include <queue>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//vector<vector<int>> adjacencyM;
//int verts, edges;
//
//void Read_g()
//{
//	ifstream ifs("data1.txt");
//	if (ifs.is_open())
//	{
//		ifs >> verts;
//		ifs >> edges;
//		adjacencyM.resize(verts + 1, vector<int>(verts + 1));
//		for (int i = 1; i < adjacencyM.size(); i++)
//		{
//			for (int j = 1; j < adjacencyM[i].size(); j++)
//			{
//				ifs >> adjacencyM[i][j];
//			}
//		}
//		cout << "Данные успешно считаны" << endl;
//	}
//	else
//	{
//		cerr << "Ошибка открытия файла" << endl;
//	}
//	ifs.close();
//}
//
//void Print_g()
//{
//	for (int i = 1; i <= verts; i++)
//	{
//		cout << i << " вершина: ";
//		vector<int> temp;
//		for (int j = 1; j <= verts; j++)
//		{
//			if (adjacencyM[i][j] == 1)
//			{
//				temp.push_back(j);
//				cout << j << " ";
//			}
//		}
//		if (temp.empty())
//		{
//			cout << "<нет смежных вершин>";
//		}
//		cout << endl;
//	}
//}
//
//bool isConversionValid(const vector<vector<int>>& adjacencyMatrix, const vector<forward_list<int>>& adjacencyList)
//{
//	int n = adjacencyMatrix.size();
//
//	if (adjacencyList.size() != n) 
//	{
//		return false;
//	}
//
//	for (int i = 1; i <= verts; i++)
//	{
//		int cnt = 0;
//		for (auto el : adjacencyMatrix[i])
//		{
//			if (el == 1)
//			{
//				cnt++;
//			}
//		}
//
//		int cntList = 0;
//		for (auto el : adjacencyList[i])
//		{
//			cntList++;
//		}
//
//		if (cnt != cntList)
//		{
//			return false;
//		}
//	}
//
//	for (int i = 1; i <= verts; ++i) 
//	{
//		forward_list<int> temp = adjacencyList[i];
//		for (auto& el : temp)
//		{
//			if (el > verts || el < 0)
//			{
//				return false;
//			}
//
//			if (adjacencyMatrix[i][el] != 1)
//			{
//				return false;
//			}
//		}
//	}
//
//	return true;
//}
//
//vector<forward_list<int>> fromMatrixToList()
//{
//	int n = adjacencyM.size();
//	vector<forward_list<int>>adjacencyL;
//	adjacencyL.push_back(forward_list<int>());
//
//	for (int i = 1; i < n; ++i)
//	{
//		forward_list<int> v;
//		for (int j = 1; j < n; ++j) 
//		{
//			if (adjacencyM[i][j] == 1)
//			{
//				v.push_front(j);
//			}
//		}
//		v.reverse();
//		adjacencyL.push_back(v);
//	}
//
//	return adjacencyL;
//}
//
//vector<vector<int>> fromListToMatrix(vector<forward_list<int>>& adjacencyL)
//{
//	int n = adjacencyL.size();
//	vector<vector<int>> adjacencyMatrix(n, vector<int>(n));
//
//	for (int i = 1; i < n; ++i)
//	{
//		for (auto& el : adjacencyL[i])
//		{
//			adjacencyMatrix[i][el] = 1;
//		}
//	}
//
//	return adjacencyMatrix;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//
//	Read_g();
//	if (adjacencyM.empty())
//	{
//		cout << "Данные отсутствуют";
//	}
//	else
//	{
//		Print_g();
//	}
//	cout << endl;
//	system("pause");
//
//	system("cls");
//	vector<forward_list<int>> adjL = fromMatrixToList();
//	cout << "Статус преобразования - " << (isConversionValid(adjacencyM, adjL) ? "успешно" : "безуспешно") << endl << endl;
//	cout << "Списки связности:" << endl;
//	for (int i = 1; i <= verts; i++)
//	{
//		cout << i << " вершина: ";
//		vector<int> temp;
//		for (auto& el : adjL[i])
//		{
//			cout << el << " ";
//			temp.push_back(el);
//		}
//		if (temp.empty())
//		{
//			cout << "<нет смежных вершин>";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	system("pause");
//
//	system("cls");
//	vector<vector<int>> adjM = fromListToMatrix(adjL);
//	cout << "Статус преобразования - " << (isConversionValid(adjM, adjL) ? "успешно" : "безуспешно") << endl << endl;
//	cout << "Матрица смежности:" << endl;
//	for (int i = 1; i <= verts; i++)
//	{
//		cout << i << " вершина: ";
//		vector<int> temp;
//		for (int j = 1; j <= verts; j++)
//		{
//			if (adjacencyM[i][j] == 1)
//			{
//				temp.push_back(j);
//				cout << j << " ";
//			}
//		}
//		if (temp.empty())
//		{
//			cout << "<нет смежных вершин>";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	system("pause");
//}