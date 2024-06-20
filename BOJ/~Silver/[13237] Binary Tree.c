#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

int tree[25];

int main() {
	int N; scanf(" %d", &N);
	for (int i = 1; i <= N; i++) {
		scanf(" %d", &tree[i]);
	}
	
	for (int i = 1; i <= N; i++) {
		int curNode = tree[i], depth = 0;
		while (curNode != -1) {
			curNode = tree[curNode];
			depth++;
		}
		printf("%d\n", depth);
	}
	
	return 0;
}