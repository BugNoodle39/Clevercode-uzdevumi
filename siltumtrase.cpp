#include <iostream>
using namespace std;

static int res = 0;

bool next(string dir, int tile, int tile2) {
    if(dir == "right") {
        switch(tile) {
            case 2: return false;
            case 4: return false;
            default:{
                if(tile2!=1 && tile2!=4 && tile2!=5) return true;
                else return false;
            }
        }
    }
    else {
        switch(tile) {
            case 1: return false;
            case 3: return false;
            default:{
                if(tile2!=2 && tile2!=3 && tile2!=5) return true;
                else return false;
            }
        }
    }
}

void trase(int **a, int Fx, int Fy, int x=0, int y=0) {
    if(x == Fx-1 && y == Fy-1){
        int n = a[x][y];
        if(n == 0 || n == 1 || n == 3){
            res++;
        }
    }

    if(y != Fy-1) {
        if(next("right", a[x][y], a[x][y+1])) {
            trase(a, Fx, Fy, x, y+1);
        }
    }

    if(x != Fx-1) {
        if(next("down", a[x][y], a[x+1][y])) { 
            trase(a, Fx, Fy, x+1, y);
        }
    }
}

int main() {
    int Fy, Fx, **arr;
    cin >> Fy >> Fx;
    arr = new int*[Fx];

    for(int i=0; i<Fx; i++) {
        arr[i] = new int[Fy];
    }

    for(int i=0; i<Fx; i++) {
        for(int j=0; j<Fy; j++) {
            cin >> arr[i][j];
        }
    }

    trase(arr, Fx, Fy);
    cout << res;

    return 0;
}
