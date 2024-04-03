#include <iostream>
using namespace std;

struct Mobil
{
    string nopol, tipeKendaraan, merkMobil, warna;
};

struct orderList
{
    string namaPemilik, serviceList;
    int harga;
    struct Mobil mobil;
    orderList *next;
} *head = NULL;

struct Service
{
    string namaService;
    int harga;
} services[3];

string jenisKendaraan[2] = {"Mobil", "Motor"};

// membuat daftar menu
void declareService()
{
    services[0].namaService = "Steam Sabun";
    services[0].harga = 25000;
    services[1].namaService = "Cuci Kilat";
    services[1].harga = 10000;
    services[2].namaService = "Cuci Luar Dalam";
    services[2].harga = 45000;
}

// list menu
void serviceList()
{
    declareService();
    cout << "\n\n";
    cout << "No. \tNama Pelayanan\t\tHarga\n";
    cout << "------------------------------------\n";

    for (int i = 0; i < 3 ; i++)
    {
        cout << i + 1 << ". \t" << services[i].namaService << "\t\t" << services[i].harga << endl;
    }
}

// menampilkan daftar menu
void displayService()
{
    char input;
    while (!(input == 'y' || input == 'Y'))
    {
        serviceList();
        cout << "\nKembali? (y) : ";
        cin >> input;
    }
}

// Menghitung total harga
double calculateTotalPrice(string nopol)
{
    double totalPrice = 0;
    orderList *current = head;
    while (current != NULL)
    {
        if (current->mobil.nopol == nopol)
        {

            for (int i = 0; i < 3; i++)
            {
                totalPrice = current->harga;
            }
            return totalPrice;
        }

        current = current->next;
    }
    return 0;
}

orderList *findOrder(string nopol)
{
    orderList *current = head;
    if (current != NULL)
    {
        do
        {
            if (current->mobil.nopol == nopol)
            {
                return current;
            }
            current = current->next;
        } while (current != NULL);
        return NULL;
    }
    return NULL;
}

orderList *getLast()
{
    orderList *current = head;
    if (current != NULL)
    {
        do
        {
            current = current->next;
        } while (current != NULL);
        return current;
    }
    return NULL;
}

// menampilkan daftar pesanan
void displayOrder()
{
    double totalPrice = 0;
    char input;
    string nopol;

    cout << "Masukan Nomor Polisi Kendaraan : ";
    getline(cin >> ws, nopol);
    orderList *current = findOrder(nopol);
    if (current != NULL)
    {
        while (!(input == 'y' || input == 'Y'))
        {
            cout << "Nama Pemilik : " << current->namaPemilik;
            cout << "\n\nDaftar Pemesanan\n";
            cout << "No. \tNama Pelayanan\t\tHarga\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < 3; i++)
            {
                if(current->harga != 0){

                cout << i + 1 << "\t" << current->serviceList[i] << "\t\t" << current->harga << "\n";
                }
            }
            cout << "-----------------------------------------------\n";

            cout << "Total harga : " << calculateTotalPrice(nopol);
            cout << "\n\nKembali? (y) : ";
            cin >> input;
        }
    }
    else
    {
        cout << "\nAnda belum memesan pelayanan Kami!\n\n";
    }
}

void jenisKendaraanList()
{
    for (int i = 0; i < 2; i++)
    {
        cout << i + 1 << ". " << jenisKendaraan[i] << endl;
    }
}

// function untuk menambahkan pesanan
void placeOrder()
{
    int orderNum;
    char input = 'y';
    int i = 0;
    orderList *current = getLast();
    orderList *temp = new orderList();
    cout << "Masukan Nama Pemilik : ";
    getline(cin >> ws, temp->namaPemilik);
    cout << "Masukan No Polisi Kendaraan : ";
    getline(cin >> ws, temp->mobil.nopol);
    cout << "Masukan Merk Kendaraan : ";
    getline(cin >> ws, temp->mobil.merkMobil);
    cout << "\n\nJenis Kendaraan :\n";
    jenisKendaraanList();
    cout << "Pilih jenis kendaraan (1/2) : ";
    cin >> orderNum;
    temp->mobil.tipeKendaraan = jenisKendaraan[orderNum - 1];
    cout << "Masukan Warna Kendaraan : ";
    cin >> temp->mobil.warna;
        serviceList();
        cout << "\nPilihlah Pelayanan (1/2/3) : ";
        cin >> orderNum;
        temp->serviceList = services[orderNum - 1].namaService;
        temp->harga = services[orderNum - 1].harga;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        head->next = temp;
        current = head->next;
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n\nPilih salah satu dari pilihan berikut:\n";
        cout << "1. Lihat Menu Pelayanan\n";
        cout << "2. Pesan Pelayanan\n";
        cout << "3. Lihat Struk\n";
        cout << "4. Keluar\nPilihan (1/2/3/4) : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayService();
            break;
        case 2:
            placeOrder();
            break;
        case 3:
            displayOrder();
            break;
        case 4:
            cout << "Program berhenti";
            return 0;
        default:
            cout << "Tidak ada pilihan, silahkan pilihan yang ada";
        }
    }
    return 0;
}