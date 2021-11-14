int funcOne(int pOne, int pTwo, int pThree, int pFour, int pFive);
void funcTwo();

int run()
{
  funcTwo();
  return 0;
}

int funcOne(int pOne, int pTwo, int pThree, int pFour, int pFive)
{
  int sum;
  int one = pOne;
  int two = pTwo;
  int three = pThree;
  int four = pFour;
  int five = pFive;
  
  sum = one + two + three + four + five;
  return sum;
}

void funcTwo()
{
  funcOne(1, 2, 3, 4, 5);
}
  