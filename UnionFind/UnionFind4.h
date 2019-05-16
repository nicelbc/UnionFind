#pragma once
#include<cassert>

using namespace std;

namespace UF4 {

	class UnionFind {

	private:
		int *parent;
		int *rank;//rank[i] : the tree level whose root is i
		int count;

	public:
		UnionFind(int count) {
			parent = new int[count];
			rank = new int[count];
			this->count = count;
			for (int i = 0; i < count; i++) {
				parent[i] = i;
				rank[i] = 1;
			}
		}

		~UnionFind()
		{
			delete[] parent;
			delete[] rank;
		}

		int size() {
			return count;
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		//path compression ?
		int find(int p) {

			assert(p >= 0 && p < count);
			//while (p != parent[p]) {
			//	parent[p] = parent[parent[p]];//???? confused
			//	p = parent[p];
			//}
			//return p;

			if (p != parent[p])//di gui  Recuersive 
				parent[p] = find(parent[p]); 
				return parent[p];
		}

		void unionElements(int p, int q) {

			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;
			if (rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else if (rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else//rank[pRoot] == rank[qRoot]
			{
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
		}
		 };


}

