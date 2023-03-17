#include <stdio.h>

#define SIZE 5

struct Queue{
    int start;
    int member_count;
    int mem[SIZE];
};

struct Queue create_queue(){
    struct Queue queue;
    queue.start = 0;
    queue.member_count = 0;

    return queue;
}

void enque(struct Queue * qp, int val){
    if(qp->member_count == SIZE-1){
        // unable to queue
        return;
    }
    qp->mem[(qp->start + qp->member_count) % SIZE] = val;
    qp->member_count = qp->member_count + 1;
}

int deque(struct Queue * qp){
    if(qp->member_count == 0){
        return -1;
    }
    int val = qp->mem[qp->start];
    qp->start = (qp->start + 1) % 5;
    qp->member_count = qp->member_count - 1;
    return val;
}


int main(){
    struct Queue queue = create_queue();
    struct Queue *q = &queue;
    enque(q, 3);
    enque(q, 4);
    enque(q, 5);
    enque(q, 2);
    enque(q, 1);
    printf("%d\n", deque(q));
    printf("%d\n", deque(q));
    enque(q, 10);
    enque(q, 11);
    printf("%d\n", deque(q));
    printf("%d\n", deque(q));
    printf("%d\n", deque(q));
    printf("%d\n", deque(q));

}
