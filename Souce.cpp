#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Stack {
    int* rows;
    int* cols;
    int counter;
public:
    Stack() {
        rows = new int[50];
        cols = new int[50];
        counter = 0;
        for (int i = 0; i < 50; i++) {
            rows[i] = -1;
            cols[i] = -1;
        }
    }

    void insert(int r, int c) {
        rows[counter] = r;
        cols[counter] = c;
        counter++;
    }

    void pop() {
        if (counter > 0) {
            counter--;
            rows[counter] = -1;
            cols[counter] = -1;
        }
    }

    void print() {
        for (int i = counter - 1; i >= 0; i--) {
            cout << "(" << rows[i] << "," << cols[i] << ")" << endl;
        }
    }
};

class Room {
    string roomname;
    int rows;
    int cols;
    char** arr;
    int pr;
    int pc;
    Stack path;
    int bount;
public:
    Room() {
        roomname = "";
        rows = 0;
        cols = 0;
        arr = nullptr;
        pr = 0;
        pc = 0;
        bount = 0;
    }

    void addtoroom(string s) {
        roomname = s;
        ifstream io(s);
        io >> rows;
        io >> cols;
        io >> pr;
        io >> pc;
        arr = new char*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new char[cols];
            for (int j = 0; j < cols; j++) {
                io >> arr[i][j];
            }
        }
        io.close();
        arr[pr][pc] = '*'; // Player position
        bount = 0;
    }

    char moveLeft() {
        if (pc > 0 && arr[pr][pc - 1] != 'X') {
            char movedChar = arr[pr][pc];
            arr[pr][pc] = '0'; // Move off from current position
            pc--;
            arr[pr][pc] = '*'; // Move to new position
            path.insert(pr, pc);
            bount++;
            return movedChar;
        }
        return '0';
    }

    char moveRight() {
        if (pc < cols - 1 && arr[pr][pc + 1] != 'X') {
            char movedChar = arr[pr][pc];
            arr[pr][pc] = '0'; // Move off from current position
            pc++;
            arr[pr][pc] = '*'; // Move to new position
            path.insert(pr, pc);
            bount++;
            return movedChar;
        }
        return '0';
    }

    char moveUp() {
        if (pr > 0 && arr[pr - 1][pc] != 'X') {
            char movedChar = arr[pr][pc];
            arr[pr][pc] = '0'; // Move off from current position
            pr--;
            arr[pr][pc] = '*'; // Move to new position
            path.insert(pr, pc);
            bount++;
            return movedChar;
        }
        return '0';
    }

    char moveDown() {
        if (pr < rows - 1 && arr[pr + 1][pc] != 'X') {
            char movedChar = arr[pr][pc];
            arr[pr][pc] = '0'; // Move off from current position
            pr++;
            arr[pr][pc] = '*'; // Move to new position
            path.insert(pr, pc);
            bount++;
            return movedChar;
        }
        return '0';
    }

    void print() {
        cout << "Current Room: " << roomname << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Player's Path in this Room:" << endl;
        path.print();
    }

    void clearPath() {
        while (bount > 0) {
            path.pop();
            bount--;
        }
    }
};

int main() {
    ifstream yo("Haunted house.txt");
    int count;
    yo >> count;
    string* rooms = new string[count];
    for (int i = 0; i < count; i++) {
        yo >> rooms[i];
        rooms[i] = rooms[i] + ".txt";
    }
    yo.close();

    Room* r1 = new Room[count];
    for (int i = 0; i < count; i++) {
        r1[i].addtoroom(rooms[i]);
    }

    int currentRoom = 0;
    char ch = ' ';
    while (ch != 'q') {
        system("CLS");
        r1[currentRoom].print();

        if (_kbhit()) {
            ch = _getch();
            if (ch == 77) { // Right arrow
                char movedChar = r1[currentRoom].moveRight();
                if (movedChar == 'P') {
                    cout << "You found a Portal!" << endl;
                    srand(time(NULL));
                    currentRoom = rand() % count;
                    r1[currentRoom].addtoroom(rooms[currentRoom]);
                }
                else if (movedChar == 'T') {
                    cout << "Congratulations! You found the Treasure!" << endl;
                    cout << "Game Over!" << endl;
                    cout << "Path Traveled:" << endl;
                    r1[currentRoom].print();
                    ch = 'q';
                }
            }
            else if (ch == 80) { // Down arrow
                char movedChar = r1[currentRoom].moveDown();
                if (movedChar == 'P') {
                    cout << "You found a Portal!" << endl;
                    srand(time(NULL));
                    currentRoom = rand() % count;
                    r1[currentRoom].addtoroom(rooms[currentRoom]);
                }
                else if (movedChar == 'T') {
                    cout << "Congratulations! You found the Treasure!" << endl;
                    cout << "Game Over!" << endl;
                    cout << "Path Traveled:" << endl;
                    r1[currentRoom].print();
                    ch = 'q';
                }
            }
            else if (ch == 75) { // Left arrow
                char movedChar = r1[currentRoom].moveLeft();
                if (movedChar == 'P') {
                    cout << "You found a Portal!" << endl;
                    srand(time(NULL));
                    currentRoom = rand() % count;
                    r1[currentRoom].addtoroom(rooms[currentRoom]);
                }
                else if (movedChar == 'T') {
                    cout << "Congratulations! You found the Treasure!" << endl;
                    cout << "Game Over!" << endl;
                    cout << "Path Traveled:" << endl;
                    r1[currentRoom].print();
                    ch = 'q';
                }
            }
            else if (ch == 72) { // Up arrow
                char movedChar = r1[currentRoom].moveUp();
                if (movedChar == 'P') {
                    cout << "You found a Portal!" << endl;
                    srand(time(NULL));
                    currentRoom = rand() % count;
                    r1[currentRoom].addtoroom(rooms[currentRoom]);
                }
                else if (movedChar == 'T') {
                    cout << "Congratulations! You found the Treasure!" << endl;
                    cout << "Game Over!" << endl;
                    cout << "Path Traveled:" << endl;
                    r1[currentRoom].print();
                    ch = 'q';
                }
            }
        }
    }

    cout << "Game Over!" << endl;
    
    // Clean up memory
    delete[] rooms;
    delete[] r1;

    return 0;
}
