#include <iostream>


using namespace std;
template <typename T>
T carre(T val) {
    return val*val;
}
int main() {
    int x;
    cin >> x;
    cout <<carre(x) << endl;
   float y;
    cin >> y;
    cout << carre(y) << endl;
    double z;
    cin >> z;
    cout << carre(z) << endl;
    return 0;
}