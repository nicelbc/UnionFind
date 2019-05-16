#pragma once
#include<assert.h>

using namespace std;


namespace UF3 {

	class UnionFind {

	private:
		int *parent;
		int *sz;//sz[i]:the number of  whose parent is i
		int count;

	public:
		UnionFind(int n) {

			count = n;
			parent = new int[n];
			sz = new int[count];
			for (int i = 0; i < n; i++) {
				parent[i] = i;
				sz[i] = 1;
			}
				
		}

		~UnionFind()
		{
			delete[] parent;
			delete[] sz;
		}

		int find(int p) {

			assert(p >= 0 && p < count);

			while (p != parent[p])
				p = parent[p];

			return p;


		}

		bool isConnected(int p, int q) {

			return find(p) == find(q);
		}

		void unionElements(int p, int q) {

			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;
			if (sz[pRoot] < sz[qRoot]) {
				parent[pRoot] = qRoot;
				sz[qRoot] += sz[pRoot];
			}
			else {
				parent[qRoot] = pRoot;
				sz[pRoot] += sz[qRoot];
			}
				

		}
	};


}