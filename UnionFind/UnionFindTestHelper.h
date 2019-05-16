#pragma once
#include<ctime>
#include<cstdlib>
#include<iostream>
#include"UnionFind4.h"

//using namespace std;

namespace UnionFindTestHelper {
	void testUF4(int n) {

		srand((unsigned)time(NULL));

		UF4::UnionFind uf = UF4::UnionFind(n);

		time_t startTime = clock();

		for (int i = 0; i < n; i++) {
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}

		for (int i = 0; i < n; i++) {
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}

		time_t endTime = clock();

		cout << "UF4," << 2 * n << " ops ," << double(endTime - startTime) / CLOCKS_PER_SEC << endl;

	}
}