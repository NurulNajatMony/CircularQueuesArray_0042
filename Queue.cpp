#include <iostream>
using namespace std;


class Queues {
    int FRONT, REAR, MAX = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == MAX - 1)
                REAR = 0;
            else 
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove() {
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == MAX - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

      // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            while (FRONT_position <= MAX - 1) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main() {
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "\nMenu\n";
            cout << "1. Insert data ke antrian\n";
            cout << "2. Hapus data dari antrian\n";
            cout << "3. Tampilkan isi antrian\n";
            cout << "4. Keluar\n";
            cout << "Masukkan pilihan (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1':
                q.insert();
                break;
            case '2':
                q.remove();
                break;
            case '3':
                q.display();
                break;
            case '4':
                return 0;
            default:
               