#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <algorithm>

using namespace std;

int g_DiskNumber = 0;
struct Tower
{
	string m_TowerName;
	vector<int> m_Tower = vector<int>();
	Tower()
	{
		for (int i = 0; i < g_DiskNumber; i++)
		{
			m_Tower.push_back(0);
		}
	}
};
Tower g_A = Tower();
Tower g_B = Tower();
Tower g_C = Tower();

void WriteDisk(int num)
{
	if (num == 0)
	{
		for (int i = 0; i < (g_DiskNumber + g_DiskNumber - 1); i++)
		{
			cout << " ";
		}
		cout << "|";
		return;
	}

	for (int i = 0; i < g_DiskNumber - num; ++i)
	{
		cout << " ";
	}
	for (int i = 0; i < num; ++i)
	{
		cout << "*";
	}
	for (int i = 0; i < num - 1; i++)
	{
		cout << "*";
	}
	for (int i = 0; i < g_DiskNumber - num; ++i)
	{
		cout << " ";
	}
	cout << "|";
}

void WriteTower()
{
	vector<int> tempA = g_A.m_Tower;
	vector<int> tempB = g_B.m_Tower;
	vector<int> tempC = g_C.m_Tower;

	for (int i = 0; i < g_DiskNumber; i++)
	{
		int numA = tempA[i];
		WriteDisk(numA);

		int numB = tempB[i];
		WriteDisk(numB);

		int numC = tempC[i];
		WriteDisk(numC);
		cout << endl;
	}

	cout << endl;
}

// moving disk n^th from ColA to ColB
void MovingDisk(int n, Tower& A, Tower& B)
{
	cout << "Chuyen dia " << n << " tu cot " << A.m_TowerName << " sang cot " << B.m_TowerName << endl;
	int topDiskA = A.m_Tower[A.m_Tower.size() - 1]; // index of top disk in Tower A
	// get top disk of Tower A
	for (int i = A.m_Tower.size() - 2; i >= 0; i--)
	{
		if (A.m_Tower[i] < topDiskA && A.m_Tower[i] != 0)
		{
			topDiskA = A.m_Tower[i];
		}
	}
	replace(A.m_Tower.begin(), A.m_Tower.end(), topDiskA, 0);

	int emptyPos = -1;
	for (int i = B.m_Tower.size() - 1; i >= 0; i--)
	{
		if (B.m_Tower[i] == 0) // find the first empty element
		{
			emptyPos = i;
			break;
		}
	}

	// moving top element of Tower A to top empty element of Tower B
	if (emptyPos != -1)
	{
		B.m_Tower[emptyPos] = topDiskA;
	}

	WriteTower();
}

void TowerOfHaNoi(int DiskNumber, Tower& A, Tower& B, Tower& C)
{
	if (DiskNumber > 0)
	{
		TowerOfHaNoi(DiskNumber - 1, A, C, B);
		MovingDisk(DiskNumber, A, C);
		TowerOfHaNoi(DiskNumber - 1, B, A, C);
	}
}

int main()
{
	cout << "So luong dia : ";
	cin >> g_DiskNumber;

	g_A = Tower();
	g_A.m_TowerName = "Tower A";
	g_B = Tower();
	g_B.m_TowerName = "Tower B";
	g_C = Tower();
	g_C.m_TowerName = "Tower C";

	for (int i = 0; i < g_DiskNumber; i++)
	{
		g_A.m_Tower[i] = i + 1;
	}

	TowerOfHaNoi(g_DiskNumber, g_A, g_B, g_C);
	_getch();

	return 0;
}