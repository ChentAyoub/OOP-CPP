
#include <iostream>
using namespace std;
int nombre_appels = 0;
void appel_numero3()
{   
	nombre_appels++;
	cout << "Appel numero " << nombre_appels << endl;
}
int main()
{
    appel_numero3();
    appel_numero3();
    appel_numero3();

   
}
