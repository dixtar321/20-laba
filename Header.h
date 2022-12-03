#pragma once
#include <vector>
#include <iostream>
#define n 10
using namespace std;
class graph {
private:
	int** mtx;
	int count;
	int main_top = 0;
	int ds = 0;
	int* visited;
	int* buff;
	int* tmp;
public:
	graph(int tops, FILE* myFile) {
		count = tops + 1;
		visited = new int[count];
		for (int y = 0; y < count; y++)
			visited[y] = 0;
		buff = new int[count];
		tmp = new int[count];

		srand(time(NULL));
		mtx = new int* [count];
		for (int i = 0; i < count; i++)
			mtx[i] = new int[count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				mtx[i][j] = rand() % 2 - 0;
			}
		}
		for (int i = 0; i < count; i++)
			mtx[i][0] = i;
		for (int j = 0; j < count; j++)
			mtx[0][j] = j;
		for (int q = 0; q < count; q++)
			mtx[q][q] = 0;

		char str[n];
		if (myFile == NULL)
			cout << "\nFile is not opened!\n";
		else if (myFile != NULL) {
			fgets(str, n, myFile);
			main_top = atoi(str);
			if (main_top < count + 1)
				cout << "Error";
			for (int j = 0; j < 2; j++)
				for (int i = 0; i < n; i++)
					str[i] = str[i + 1];
			ds = atoi(str);
		}

	};

	~graph() {
		for (size_t i = 0; i < count; i++) {
			delete[] mtx[i];
		}
		delete[] mtx;
	};

	int get_ds() {
		return ds;
	}

	int get_main_top() {
		return main_top;
	}

	void matrix_output();
	void graph_traversal(int top, int counter, vector<int>& variant);
	void make_graph(FILE* Dop_File, vector<int> variant);

};