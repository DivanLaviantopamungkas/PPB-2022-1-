#include <iostream>
using namespace std;

struct Game{
    //data
    string judul, developer;
    int tahun;

    //pointer
    Game *next;
    Game *prev;
};

Game *nodeBaru, *cur, *head, *hapus, *bantu;

int isEmpty(){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void cetak(){
    cur = head;
    while(cur!=NULL){
        cout << cur->judul << "\n";
        cout << cur->developer << "\n";
        cout << cur->tahun << "\n";
        cout << "\n";
        cur = cur->next;
    }
}

void create(){
    head = new Game();
    cout << "Nama Game \t: ";
    getline(cin >> ws, head->judul);
    cout << "Nama Developer \t: ";
    getline(cin >> ws, head->developer);
    cout << "Tahun \t\t: ";
    cin >> head->tahun;
    cout << "\n";
    head->next = NULL;
    head->prev = NULL;
}

void tambahDepan(){
    nodeBaru = new Game();
    cout << "Nama Game \t: ";
    getline(cin >> ws, nodeBaru->judul);
    cout << "Nama Developer \t: ";
    getline(cin >> ws, nodeBaru->developer);
    cout << "Tahun \t\t: ";
    cin >> nodeBaru->tahun;
    cout << "\n";
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    if(isEmpty()==1){
        head = nodeBaru;
        head->next = NULL;
        head->prev = NULL;
    }else{
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
    }
    cout << "Data Masuk\n";
}

void tambahBelakang(){
    nodeBaru = new Game();
    cout << "Nama Game \t: ";
    getline(cin >> ws, nodeBaru->judul);
    cout << "Nama Developer \t: ";
    getline(cin >> ws, nodeBaru->developer);
    cout << "Tahun \t\t: ";
    cin >> nodeBaru->tahun;
    cout << "\n";
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;
    if(isEmpty()==1){
        head = nodeBaru;
        head->next = NULL;
        head->prev = NULL;
    }else{
        cur = head;
        while(cur->next!=NULL){
            cur = cur->next;
        }
        cur->next = nodeBaru;
        nodeBaru->prev = cur;
    }
    cout << "Data Masuk\n";
}

void hapusDepan(){
    if(isEmpty()==0){
        if(head->next!=NULL){
            hapus = head;
            head = head->next;
            head->prev = NULL;
            delete hapus;
            cout << "Data paling depan terhapus\n\n";
        }else{
            head = NULL;
            cout << "Data paling depan terhapus\n\n";
        }
    }else{
        cout << "Data masih kosong\n";
    }
}

void hapusBelakang(){
    if(isEmpty()==0){
        if(head->next!=NULL){
            bantu = head;
            while(bantu->next->next!=NULL){
                bantu = bantu->next;
            }
            hapus = bantu->next;
            bantu->next = NULL;
            delete hapus;
            cout << "Data paling belakang terhapus\n\n";
        }else{
            head = NULL;
            cout << "Data paling belakang terhapus\n\n";
        }
    }else{
        cout << "Data masih kosong\n";
    }
}

void reset(){
    bantu = head;
    while(bantu!=NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
    cout << "Data Clear!\n\n";
}

void menu(int pil){
    switch(pil){
        case 1: create(); break;
        case 2: tambahDepan(); break;
        case 3: tambahBelakang(); break;
        case 4: hapusDepan(); break;
        case 5: hapusBelakang(); break;
        case 6: cetak(); break;
        case 7: reset(); break;
        case 0: break;
        default: cout << "pilihan tidak ditemukan." << endl; break;
    }
}

int main(){
    int pilih;
    do{
        cout << "[1] Create" << "\n";
        cout << "[2] Tambah Depan" << "\n";
        cout << "[3] Tambah Belakang" << "\n";
        cout << "[4] Hapus Depan" << "\n";
        cout << "[5] Hapus Belakang" << "\n";
        cout << "[6] Cetak" << "\n";
        cout << "[7] Clear" << "\n";
        cout << "[0] Exit" << "\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilih;
        menu(pilih);
    }
    while(pilih != 0);
    return 0;
}
