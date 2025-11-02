#include <iostream>
using namespace std;

class pile {
private:
    int* p;
    int taille;
    int top;
public:
    pile(int taille = 10) {
        this->taille = taille;
        p = new int[taille];
        top = -1;
    }
    void push(int valeur) {
        if (top < taille - 1) {
            p[++top] = valeur;
            cout << "PUSH: " << valeur << endl;
        }
        else {
            cout << "pile pleine" << endl;
        }
    }
    int pop() {
        if (top >= 0) {
            cout << "POP: " << p[top] << endl;
            return p[top--];
        }
        else {
            cout << "pile vide" << endl;
            return -1; 
        }
	}
};
int main()
{
    pile p1;
    pile p2;
    p1.push(180);
    p1.push(290);
    p1.push(660);
    p1.pop();
    p1.pop();
    p1.pop();
    p1.pop();
    p2.push(99);
    p2.push(8);
    p2.push(6767);
    p2.push(55);
    p2.pop();
    p2.pop();

    return 0;
}
