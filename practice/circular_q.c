#include <stdio.h>

int q[20], rear=0, front=0, n=20;

void enqueue(int q[], int item) {
	if ((rear + 1)%n == front) printf("\nQ full!\n");
	else {
		q[rear] = item;
		rear = (rear + 1) % n;
	}
}

int dequeue(int q[]) {
	int item;
	if (rear==front) {
		printf("\nQ empty!\n");
		return -1;
	}
	else {
		item = q[front];
		front = (front + 1) % n;
		return item;
	}
}
int main()
{
	int x;
	do {
		scanf("%d", &x);
		enqueue(q, x);
	} while(x!=0);

	while((x = dequeue(q)) != -1) printf("%d ", x);

	return 0;
}

