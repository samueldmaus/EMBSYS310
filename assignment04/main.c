#include <assert.h>

int main()
{
  int result = 0;
  int num = 1;
  if(*(char*)&num == 1)
  {
    result = 1;
  }

  assert(result == 1);
  return 0;
}