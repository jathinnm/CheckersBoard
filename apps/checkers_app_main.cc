#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
  char name[50];
  cout << "What is your name, warrior?" << endl;
  cin.getline(name, 50);
  cout << "You better move fast, " << name << ". The goblins are attacking the city." << endl;
  cout << "\n----------------------Press any key to continue----------------------" << endl;
  return 0;
}
