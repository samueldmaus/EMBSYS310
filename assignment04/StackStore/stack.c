#include "stack.h"

#define STACK_SIZE 5

int stackStore[STACK_SIZE];
int size = -1;

void init()
{
  for(int i = 0; i < STACK_SIZE; i++)
  {
    stackStore[i] = 0;
  }
}

int isEmpty()
{
  if(size == -1)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

int isFull()
{
  if(size == STACK_SIZE - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int push(int num)
{
  if(!isFull())
  {
    size++;
    stackStore[size] = num;
  }
  else
  {
    return -1;
  }
  return 1;
}

int pop()
{
  int num;
  if(!isEmpty())
  {
    num = stackStore[size];
    size--;
    return num;
  }
  else
  {
    return -1;
  }
}

int getCurrentStackSize()
{
  return size + 1;
}
  