#ifndef DEQUE_INT_H_
#define DEQUE_INT_H_

typedef struct t_deque *t_deque;

t_deque init();
void insertFirst(int i,t_deque d);
void insertLast(int i,t_deque d);
int removeFirst(t_deque d);
int removeLast(t_deque d);
int size(t_deque d);
int isEmpty(t_deque d);
int first(t_deque d);
int last(t_deque d);
void display(t_deque d);

#endif