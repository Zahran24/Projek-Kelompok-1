#include <iostream>
#include <iomanip>
//tes
struct data1 {
    std::string namaBarang;
    std::string jumlahBarang;
    std::string kodeBarang;

    data1 *next;
};

struct data2{
    std::string namaBarang;
    int jumlahBarang;
    std::string kodeBarang;

    data2 *next;
    data2 *prev;
    data2(std::string namaBarang, int jumlahBarang, std::string kodeBarang){
        this -> namaBarang = namaBarang;
        this -> jumlahBarang = jumlahBarang;
        this -> kodeBarang = kodeBarang;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
}

using data1ptr = data1*;
using data2ptr = data2*;
using linkedlist = data1ptr;

data2ptr headbarangRusak = nullptr;

void newList(linkedlist& headName, linkedlist& headSum, linkedlist& headCode){
    headName = nullptr;
    headSum = nullptr;
    headCode = nullptr;
}

data1ptr createElement (data1ptr& headName, data1ptr& headSum, data1ptr& headCode){
    std::string name, sum, code;
    std::cout << "Masukkan Nama Barang : ";
    std::cin >> name;
    headName = new data1;
    headName->namaBarang = name;
    std::cout << "Masukkan Jumlah Barang : ";
    std::cin >> sum;
    headSum = new data1;
    headSum->jumlahBarang = sum;
    std::cout << "Masukkan Kode Barang : ";
    std::cin >> code;
    headCode = new data1;
    headCode->kodeBarang = code;
    return headName, headSum, headCode;
}

void insertFirst(data1ptr& headName, data1ptr& headSum, data1ptr& headCode, data1ptr nodesName, data1ptr nodesSum, data1ptr nodesCode) {
    if(headName ==  nullptr) {
        headName = nodesName;
    } else {
        nodesName->next=headName;
        headName = nodesName;
    }
    if(headSum ==  nullptr) {
        headSum = nodesSum;
    } else {
        nodesSum->next=headSum;
        headSum = nodesSum;
    }
    if(headCode ==  nullptr) {
        headCode = nodesCode;
    } else {
        nodesCode->next=headCode;
        headCode = nodesCode;
    }
}

void headerdata1(){
    std::cout << std::setw(69) << std::right << "Rekapan Barang yang Tersedia" << std::endl
              << "=========================================================================================================================\n"
              << std::setw(30) << std::left << "Nama Barang"
              << std::setw(30) << std::left << "Jumlah Barang"
              << std::setw(30) << std::left << "Kode Barang"
              << std::endl
              << "=========================================================================================================================\n";  
}
void coutdata (data1ptr& headName, data1ptr& headSum, data1ptr& headCode){
    std::cout << std::setw(30) << std::left << headName->namaBarang
              << std::setw(30) << std::left << headSum->jumlahBarang
              << std::setw(30) << std::left << headCode->kodeBarang;
    std::cout << std::endl;
}

void main_template(){
    std::cout << "===========================================================";
    std::cout << "\nRekapan Data\n";
    std::cout << "===========================================================\n";
    std::cout << "1.Data Barang yang Tersedia\n";
    std::cout << "2.Data\n";
    std::cout << "3.Data\n";
    std::cout << "4.Keluar\n";
}

void data_1(){
    char input_data1;
    linkedlist headName, headSum, headCode;
    data1ptr ptrName, ptrSum, ptrCode;
    std::cout << "========================"<< "\n";
    std::cout << "Rekapan Data 1\n";
    std::cout << "========================" << "\n";
    std::cout << "1.Masukkan Data\n";
    std::cout << "2.Hapus Data\n";
    std::cout << "3.Tampilkan Data\n";
    std::cout << "Masukkan Input : "; std::cin >> input_data1;
    if (input_data1 == '1')
    {
        createElement(ptrName, ptrSum, ptrCode);
        insertFirst(headName, headSum, headCode, ptrName, ptrSum, ptrCode);
    }
    if (input_data1 == '3')
    {
        headerdata1();
        coutdata(ptrName, ptrSum, ptrCode);
    }
}

void addData2(){
    std::string kode, namaBarang;
    int jumlah;
    std::cout << "========================" << "\n";
    std::cout << "Tambah Data Barang Rusak" << "\n";
    std::cout << "========================" << "\n";
    std::cout << "Kode Barang : ";
    std::getline(std::cin, kode);
    std::cout << "Nama Barang : ";
    std::getline(std::cin, namaBarang);
    std::cout << "Jumlah Barang : ";
    (std::cin >> jumlah).get();
    data2ptr baru = new data2(namaBarang, jumlah, kode);
    if (headbarangRusak == nullptr){
        headbarangRusak = baru;
    }else{
        data2ptr temp = headbarangRusak;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next = baru;
        baru -> prev = temp;
    }
}

void delData2(){
    std::string kode;
    int jumlah;
    std::cout << "========================" << "\n";
    std::cout << "Hapus Data Barang Rusak" << "\n";
    std::cout << "========================" << "\n";
    std::cout << "Kode Barang : ";
    std::getline(std::cin, kode);
    std::cout << "Jumlah Barang : ";
    (std::cin >> jumlah).get();
    data2ptr temp = headbarangRusak;
    while(temp != nullptr){
        if(temp -> kodeBarang = kode){
            break;
        }
        temp = temp -> next;
    }
    if(temp != nullptr){
        temp -> jumlahBarang -= jumlah;
        if(temp -> jumlahBarang <= 0){
            temp -> prev -> next = temp -> next;
            temp -> next -> prev = temp -> prev;
            temp -> next = nullptr;
            temp -> prev = nullptr;
            delete temp; 
        }
    }
}

void trasversalData2(){
    std::cout << "============================================================" << "\n";
    std::cout << "Kode Barang\tNama Barang\tKuantitas" << "\n";
    std::cout << "============================================================" << "\n";
    data2ptr temp = headbarangRusak;
    while(temp != nullptr){
        std::cout << temp -> kodeBarang << "\t" << temp -> namaBarang << "\t" << temp -> jumlahBarang << '\n';
        temp = temp -> next;
    }
}

void data_2(){
    int input_data2;
    std::cout << std::setfill('=') << std::setw(31) << "\n";
    std::cout << std::setw(4) << "Rekapan Data 2\n";
    std::cout << std::setfill('=') << std::setw(31) << "\n";
    std::cout << "1.Masukkan Data\n";
    std::cout << "2.Hapus Data\n";
    std::cout << "3.Tampilkan Data\n";
    (std::cin >> input_data2).get();
    switch (input_data2)
    {
    case 1 :
        addData2();
        break;
    case 2 :
        delData2();
        break;
    case 3 :
        trasversalData2();
        break;    
    
    default :
        break;
    }

}

void dat_akhir(){

}
int main() {
    char input;
    linkedlist headName, headSum, headCode;
    data1ptr ptrName, ptrSum, ptrCode;
    newList(headName, headSum, headCode);
    do
    {
        main_template();
        std::cin >> input;
        switch (input) {
            case '1' :
                data_1();
                break;
            case '2' :
                data_2();
                break;
            case '3' :
                break;
            case '4' :
                std::cout << "Program Selesai";
                break;
            default:
                break;
        }
        getchar();
    } while (input!='4');
    
    

}