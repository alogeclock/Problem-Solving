#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long

int space[105], rate[105], weight[2020];
int car_queue[2020];
int N, M, front, back;
ll revenue;

void input() {
	scanf(" %d %d", &N, &M);
	for (int i = 1; i <= N; i++) { scanf(" %d", &rate[i]); }
	for (int i = 1; i <= M; i++) { scanf(" %d", &weight[i]); }
}

void enqueue(int car_number) {
	for (int i = 1; i <= N; i++) {
		if (space[i]) continue;
		revenue += weight[car_number] * rate[i];
		space[i] = car_number;
		return;
	}

	// 주차를 수행하지 못했을 경우
	car_queue[back++] = car_number;
}

void dequeue(int car_number) {
	for (int i = 1; i <= N; i++) { // 차를 찾은 뒤 삭제
		if (space[i] != car_number) continue;
	  space[i] = 0;

		// 기다리고 있는 차가 있을 경우 자리를 바꿈
		if (front != back) {
			enqueue(car_queue[front++]);
		}
	}
}

int main() {
	input();

	for (int i = 1; i <= 2 * M; i++) {
		int car_number; scanf(" %d", &car_number);
		if (car_number > 0) enqueue(car_number);
		else dequeue(-car_number);
	}

	printf("%lld\n", revenue);

	return 0;
}