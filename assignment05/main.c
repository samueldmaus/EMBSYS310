#include <assert.h>

void ptrSwap(int** a, int** b);

int main()
{
  int x = 1;
  int y = 2;
  int* ptrX = &x;
  int* ptrY = &y;
  
  ptrSwap(&ptrX, &ptrY);
  
  assert(ptrY == &x);
  assert(ptrX == &y);
  
  return 0;
}

void ptrSwap(int** a, int** b)
{
  int* temp = *a;
  *a = *b;
  *b = temp;
}