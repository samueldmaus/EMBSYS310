#include "stack.h"
#include <assert.h>

int main()
{
  int testNum = 5;
  int result = 0;
  
  // *******************************************************************
  // Test1: Initialize stack & try to retrive from empty stack
  // *******************************************************************
  init();
  assert(isEmpty());
  assert(!isFull());
  assert(getCurrentStackSize() == 0);
  assert(pop() == -1);
  
  // *******************************************************************
  // Test2: Push to stack & pop off stack
  // *******************************************************************
  push(1);
  push(2);
  assert(getCurrentStackSize() == 2);
  
  testNum = pop();
  assert(testNum == 2);
  assert(getCurrentStackSize() == 1);
  
  testNum = pop();
  assert(testNum == 1);
  assert(getCurrentStackSize() == 0);
  
  // *******************************************************************
  // Test3: Try to push to full stack
  // *******************************************************************
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  assert(getCurrentStackSize() == 5);
  testNum = push(6);
  assert(testNum == -1);
  assert(getCurrentStackSize() == 5);
  
  // *******************************************************************
  // Test4: Pop from stack and push last item on
  // *******************************************************************
  testNum = pop();
  assert(testNum == 5);
  assert(getCurrentStackSize() == 4);
  
  result = push(10);
  assert(getCurrentStackSize() == 5);
  assert(result == 1);
  
  return 0;
}