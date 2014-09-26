#include <iostream>
#include <stdlib.h>
using namespace std;

int N = 100000;

int main() {
    int cnt = 0;
    srand (time(NULL));
    for (int j = 0; j < N; j ++) {
        int prizeDoor = rand() % 3 + 1;
        int selectDoor = rand() % 3 + 1;
        //cout << prizeDoor << ":" << selectDoor << endl;
        int displayDoor = 0;
        int iter = 0; // count the doors available for display
        int *d = new int[10]; 
        for (int i = 1; i <= 3; i ++) {
            if (i != prizeDoor && i != selectDoor) {
                d[iter] = i;
                iter ++;
            }
        }
        displayDoor = d[rand() % iter];
        // change the door
        selectDoor = 1 + 2 + 3 - displayDoor - selectDoor;
        if (selectDoor == prizeDoor) cnt ++;
    }
    cout << cnt * 1.0 / N << endl;
}
