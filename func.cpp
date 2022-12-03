#include "Header.h"
#include <iostream>
#include <fstream>
#include <vector>

void graph:: matrix_output() {
	std::cout << std::endl;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			std::cout << mtx[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void graph::graph_traversal(int top, int counter, vector<int>& variant) {
	for (int i = 1; i < count; i++) {	
		if ((mtx[top][i] == 1)&&(visited[i] != 1)) {
			visited[i] = 1;
			buff[counter] = i;
			counter++;
			if (mtx[0][i] == main_top) {
				if (counter <= ds) {
					variant.push_back(main_top);
					cout << main_top << " -> ";
					for (int r = 0; r < counter; r++) {
						variant.push_back(buff[r]);
						cout << buff[r] << " -> ";
					}
					cout << endl;
				}
				visited[main_top] = 0;
				counter--;
				buff[counter] = 0;
			}
			else {
				graph_traversal(i, counter, variant);
				counter--;
				visited[buff[counter]] = 0;
				buff[counter] = 0;
				
			}
		}
	}
}

void graph::make_graph(FILE* Dop_File, vector<int> variant) {
	int flag = 0;
	ofstream fout(Dop_File);
	fout << "digraph A{\n";
	for (size_t i = 1; i < count; i++) {
		fout << i <<";"<< "\n";
	}
	for (size_t i = 1; i < count; i++) {
		for (size_t j = 1; j < count; j++) {
			if ((mtx[i][j] == 1)&&(variant.size() > 0)) {
			for (size_t k = 0; k < variant.size()-1; k++) {
				if ((i == variant[k]) && (j == variant[k+1])) {
					fout << i << "->" << j << "[color=\"blue\"];" << "\n";
					flag = 1;
				}
			}
			if (flag != 1)
				fout << i << "->" << j << "[color=\"red\"];" << "\n";
			else
				flag = 0;
			}
		}
	}
	fout << "}\n";
	
}
/*

0 1 2 3 4 5
1 0 1 1 1 0
2 1 0 0 0 1
3 0 1 0 1 0
4 1 0 0 0 0
5 1 1 0 0 0

digraph A{
0;
1;
2;
3;
4;
5;
6;
7;
8;
9;
10;
11;
12;
13;
14;
0->4 [label=1, weight=1];
0->6 [label=0.5, weight=0.5];
0->1 [label=2.5, weight=2.5];
1->6 [label=4.3, weight=4.3];
1->11 [label=1, weight=1];
2->6 [label=1, weight=1];
2->9 [label=1, weight=1];
2->11 [label=1, weight=1];
3->4 [label=1, weight=1];
4->5 [label=1, weight=1];
5->8 [label=1, weight=1];
6->7 [label=1, weight=1];
7->8 [label=1, weight=1];
8->13 [label=1, weight=1];
9->10 [label=1, weight=1];
10->13 [label=1, weight=1];
11->12 [label=1, weight=1];
12->13 [label=1, weight=1];
13->14 [label=1, weight=1];
}

*/