#include <assert.h>

int main()
{
  int result = 0;
  int num = 1;
  if(*(char*)&num == 1)
  {
    result = 1;
  }

  // result should be 1 for little endian or 0 for big endian
  assert(result == 1);
  return 0;
}