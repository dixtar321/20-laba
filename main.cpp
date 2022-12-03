#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <algorithm>
#include "Header.h"
#define n 10
using namespace std;
/*

��������������� ���� ����� � �������� �������� ���������. 
� ����� �������� �������, � ������� ���������� ����� � ����� ����� dc. 
�������� ��� �����, ����� ������� ������ dc.


������� ���� ��� �� ����
�������� ������ �� ����, ������� �� ��������� � ������
������ // ���������� �����
*/

int main() {
	int tops = 0;
	while (tops <= 1) {
		cout << "How many vertices will be in the graph?" << endl;
		cin >> tops;
	}
	cout << endl;
	FILE* myFile = fopen("myFile.txt", "r");
	graph a(tops, myFile);
	a.matrix_output();
	cout << endl;
	vector<int> variant;
	a.graph_traversal(a.get_main_top(), 0, variant);
	fclose(myFile);
	
	printf("\n//////////////////DOP///////////////////\n"); // dot -Tpng dop.dot -o dop_dot.png //
	FILE* Dop_File = fopen("dop.dot", "w");
	if ((Dop_File = fopen("dop.dot", "w")) == 0) {
		return -1;
	}
	a.make_graph(Dop_File, variant);

	return 0;
}
