#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

// N * N 배열의 아래쪽 삼각형에 주목해 삼각형의 값을 누적해 더함

int m[1000][1000];
ll sum[1010];
ll row[1010];

int main() {
	// sequence A consisting of N positve integers
	int N; scanf(" %d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %d", &m[i][j]);
		}
	}
		
	if (N == 2) {
		printf("%d %d\n", m[0][1] / 2, m[0][1] / 2);	
		return 0;
	}
	
	int arr[1010];
	for (int i = 1; i < N; i++) {
		for (int j = 0; m[i][j] != 0; j++) { // 0을 만날 때까지 이동
			row[i] += m[i][j];
		}
		sum[i] += row[i]; sum[i + 1] = sum[i];
		sum[i] /= i; // 최종적으로 sum은 각각 (1+2), (1+2+3), ··· 저장
	}
	
	for (int i = 2; i < N; i++) {
		arr[i] = (row[i] - sum[i - 1]) / i;
	}
	
	arr[0] = m[0][2] - arr[2];
	arr[1] = m[0][1] - arr[0];
	
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}