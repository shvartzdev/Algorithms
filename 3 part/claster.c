#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int prepareTime, workTime;
} task_t;

typedef struct {
    task_t *data;
    int capacity, size;
} pqueue_t;

pqueue_t init(int capacity) {
    return (pqueue_t) { 
            malloc(capacity * sizeof(task_t)), capacity, 0 
            };
}

void swap(pqueue_t *pq, int i, int j) {
    task_t temp = pq->data[i];
    pq->data[i] = pq->data[j];
    pq->data[j] = temp;
}

int less(const pqueue_t *pq, int i, int j) {
    const task_t *first = pq->data + i;
    const task_t *second = pq->data + j;
    return first->prepareTime + first->workTime < second->prepareTime + second->workTime;
}

void up(pqueue_t *pq, int j) {
    for (; ;) {
        int i = (j - 1) / 2;
        if (i == j || !less(pq, j, i)) {
            break;
        }
        swap(pq, i, j);
        j = i;
    }
}

void down(pqueue_t *pq, int i) {
    for (; ;) {
        int left = 2 * i + 1;
        if (left >= pq->size) {
            break;
        }
        int j = left;
        int right = left + 1;
        if (right < pq->size && !less(pq, left, right)) {
            j = right;
        }
        if (!less(pq, j, i)) {
            break;
        }
        swap(pq, i, j);
        i = j;
    }
}

void push(pqueue_t *pq, task_t task) {
    pq->data[pq->size++] = task;
    up(pq, pq->size - 1);
}

task_t pop(pqueue_t *pq) {
    pq->size--;
    swap(pq, 0, pq->size);
    down(pq, 0);
    return pq->data[pq->size];
}

int empty(pqueue_t pq) {
    return pq.size == 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    pqueue_t pq = init(n);
    task_t *tasks = malloc(m * sizeof(task_t));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &tasks[i].prepareTime, &tasks[i].workTime);
    }
    for (int i = 0; i < n; i++) {
        push(&pq, tasks[i]);
    }
    int finishedTime = 0;
    for (int i = n; !empty(pq);) {
        task_t finishedTask = pop(&pq);
        finishedTime = finishedTask.prepareTime + finishedTask.workTime;
        if (i < m) {
            task_t task = tasks[i];
            if (task.prepareTime < finishedTime) {
                task.prepareTime = finishedTime;
            }
            push(&pq, task);
            i++;
        }
    }
    printf("%d\n", finishedTime);

    free(pq.data);
    free(tasks);

    return 0;
}
