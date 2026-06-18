#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace chrono;

// -----------------------------
// Recursive version
// -----------------------------
void hanoiRecursive(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    hanoiRecursive(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    hanoiRecursive(n - 1, auxiliary, source, destination);
}

// -----------------------------
// Helper function for iterative moves
// -----------------------------
void moveDisk(char fromRod, char toRod, int &fromTop, int &toTop) {
    cout << "Move disk " << fromTop << " from " << fromRod << " to " << toRod << endl;
    toTop = fromTop;
    fromTop = 0;
}

// -----------------------------
// Iterative version
// -----------------------------
void hanoiIterative(int n, char source, char auxiliary, char destination) {
    int totalMoves = pow(2, n) - 1;

    char src = source, aux = auxiliary, dest = destination;


    if (n % 2 == 0) {
        swap(aux, dest);
    }

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            cout << "Step " << i << ": Move between " << src << " and " << dest << endl;
        } else if (i % 3 == 2) {
            cout << "Step " << i << ": Move between " << src << " and " << aux << endl;
        } else {
            cout << "Step " << i << ": Move between " << aux << " and " << dest << endl;
        }
    }
}

// -----------------------------
// Main
// -----------------------------
int main() {
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\n--- Recursive Solution ---\n";
    auto start = steady_clock::now();
    hanoiRecursive(n, 'A', 'B', 'C');
    auto endd = steady_clock::now();
    auto time = duration_cast<microseconds>(endd - start).count();
    cout << "Recursive solution time : " << time << " ms. " << endl;

    cout << "\n--- Iterative Solution ---\n";
    auto start2 = steady_clock::now();
    hanoiIterative(n, 'A', 'B', 'C');
    auto endd2 = steady_clock::now();
    auto time2 = duration_cast<microseconds>(endd2 - start2).count();
    cout << "Iterative solution time : " << time2 << " ms. " << endl;

    cout << "\nTotal moves required: " << pow(2, n) - 1 << endl;

    return 0;
}
