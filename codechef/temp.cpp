#include <iostream>
using namespace std;
int main()
{
 int randNum = (rand() % 100) + 1;
 for (randNum = (rand() % 100) + 1; randNum != 100;randNum = (rand() % 100) + 1){
     cout << randNum << ", ";
 }
 cout << endl;
 return 0;
}