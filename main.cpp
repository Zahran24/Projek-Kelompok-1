#include <iostream>
#include <iomanip>

struct data1 {
    std::string namaBarang;
    std::string jumlahBarang;
    std::string kodeBarang;

    data1 *next;
    data1(std::string namaBarang, std::string jumlahBarang, std::string kodeBarang){
        this -> namaBarang = namaBarang;
        this -> jumlahBarang = jumlahBarang;
        this -> kodeBarang = kodeBarang;
        this -> next = nullptr;
    }
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
};

struct data3{
    std::string kritik;
    std::string saran;

    data3 *next;
    data3 *prev;
    data3(std::string kritik, std::string saran){
        this -> kritik = kritik;
        this -> saran = saran;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

using data1ptr = data1*;
using data2ptr = data2*;
using data3ptr = data3*;

data1ptr headBrngTrsedia = nullptr;
data2ptr headbarangRusak = nullptr;
data3ptr headkritikSaran = nullptr;


void addData1(){
    std::string name, sum, code;
    std::cout << "=============================" << "\n";
    std::cout << " Tambah Data Barang Tersedia" << "\n";
    std::cout << "=============================" << "\n";
    std::cout << "Nama Barang   : ";
    std::getline(std::cin, name);
    std::cout << "Jumlah Barang : ";
    std::getline(std::cin, sum);
    std::cout << "Kode Barang   : ";
    std::getline(std::cin, code);
    data1ptr input = new data1(name, sum, code);
    if (headBrngTrsedia == nullptr){
        headBrngTrsedia = input;
    } else{
        input -> next = headBrngTrsedia;
        headBrngTrsedia = input;
    }
}

void headerdata1(){
    std::cout << "                          Rekapan Barang yang Tersedia\n" ;
    std::cout << "=========================================================================================="<< "\n";
    std::cout << std::setw(30) << std::left << "Nama Barang";
    std::cout << std::setw(30) << std::left << "Jumlah Barang";
    std::cout << std::setw(30) << std::left << "Kode Barang" <<"\n";
    std::cout << "=========================================================================================="<<"\n";
}

void coutdata1 (){
    data1ptr tempTraversal = headBrngTrsedia;
    while (tempTraversal != nullptr)
    {
        std::cout << std::setw(30) << std::left << tempTraversal->namaBarang;
        std::cout << std::setw(30) << std::left << tempTraversal->jumlahBarang;
        std::cout << std::setw(30) << std::left << tempTraversal->kodeBarang << "\n";
        tempTraversal->next;
    }
}

void deleteFirst_data1 (){
    data1ptr delFirst;
    if (headBrngTrsedia == nullptr){
        delFirst = nullptr;
    } else {
        delFirst = headBrngTrsedia;
        headBrngTrsedia = headBrngTrsedia->next;
        delFirst->next = nullptr;
    }
    delete delFirst;
}

void deleteLast_data1(){
    if(headBrngTrsedia==nullptr){
        return;
    } else if( headBrngTrsedia->next == nullptr){
        delete headBrngTrsedia;
        headBrngTrsedia = nullptr;
    } else {
        data1ptr prelast = headBrngTrsedia;
        data1ptr last = prelast->next;
        while (last->next != nullptr)
        {
            prelast = last;
            last = last->next;
        }
        prelast->next = nullptr;
        delete last;
    }
}

void deleteList_data1(){
    if(headBrngTrsedia == nullptr){
        return;}
    data1ptr delNode_data1 = headBrngTrsedia;
    data1ptr next_delNode = nullptr;
    while (delNode_data1!=nullptr){
        next_delNode = delNode_data1->next;
        delete delNode_data1;
        delNode_data1 = next_delNode;
    }
    headBrngTrsedia = nullptr;
}

void data_1(){
    char input_data1;
    data1ptr ptrName, ptrSum, ptrCode;
    std::cout << "\n======================================"<< "\n" ;
    std::cout << "  Rekapan Data Barang yang Tersedia\n";
    std::cout << "======================================" << "\n";
    std::cout << "1.Masukkan Data \n";
    std::cout << "2.Hapus Data di awal\n";
    std::cout << "3.Hapus Data di akhir\n";
    std::cout << "4.Hapus Seluruh data\n";
    std::cout << "5.Tampilkan Data\n";
    std::cout << "Masukkan Input : " ;
    (std::cin >> input_data1).get();
        switch (input_data1)
        {
        case '1' :
            addData1();
            break;
        case '2' :
            deleteFirst_data1();
            break;
        case '3' :
            deleteLast_data1();
            break;
        case '4' :
            deleteList_data1();
            break;
        case '5' :
            headerdata1();
            coutdata1();
            break;
        default:
            break;
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
        if(temp -> kodeBarang == kode){
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
    std::cout << "========================================================================" << "\n";
    std::cout << std::setw(30) << std::left << "Kode Barang" << std::setw(30) << std::left <<"Nama Barang"<< std::setw(30) << std::left <<"Kuantitas" << "\n";
    std::cout << "========================================================================" << "\n";
    data2ptr temp = headbarangRusak;
    while(temp != nullptr){
        std::cout << std::setw(30) << std::left << temp -> kodeBarang << std::setw(30) << std::left << temp -> namaBarang << std::setw(30) << std::left << temp -> jumlahBarang << '\n';
        temp = temp -> next;
    }
}

void data_2(){
    int input_data2;
    std::cout << "=========================================" << "\n";
    std::cout << std::setw(4) << "Rekapan Data 2\n";
    std::cout << "=========================================" << "\n";
    std::cout << "1.Masukkan Data\n";
    std::cout << "2.Hapus Data\n";
    std::cout << "3.Tampilkan Data\n";
    std::cout << "Masukan Input : ";
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

void addData3(){
    std::string kritik, saran;
    std::cout << "========================" << "\n";
    std::cout << "    Kritik dan Saran    " << "\n";
    std::cout << "========================" << "\n";
    std::cout << "Kritik : ";
    std::getline(std::cin, kritik);
    std::cout << "Saran ";
    std::getline(std::cin, saran);
    data3ptr baru = new data3(kritik, saran);
    if (headkritikSaran == nullptr){
        headkritikSaran = baru;
    }else{
       baru -> next = headkritikSaran;
       headkritikSaran -> prev = baru;
       headkritikSaran = baru;
    }
}

void lihatkritikSaran(){
    data3ptr temp = headkritikSaran;
    std::cout << "============================================================" << "\n";
    std::cout << "Krtik dan Saran" << "\n";
    std::cout << "============================================================" << "\n";
    while(temp != nullptr){
        std::string command;
        std::cout << "Kritik : " << temp -> kritik << "\n";
        std::cout << "Saran : " << temp -> saran << "\n";
        std::cout << "============================================================" << "\n";
        std::getline(std::cin, command);
        std::cout << "============================================================" << "\n";
        if(command == "next"){
            temp = temp -> next;
        }else{
            break;
        }
    }
}

void data_3(){
    int input_data3;
    std::cout << "=========================================" << "\n";
    std::cout << std::setw(4) << "Kritik dan Saran \n";
    std::cout << "=========================================" << "\n";
    std::cout << "1. Input Kritik dan Saran\n";
    std::cout << "2. Lihat Kritik dan Saran\n";
    std::cout << "Masukan Input : ";
    (std::cin >> input_data3).get();
    switch (input_data3)
    {
    case 1 :
        addData3();
        break;
    case 2 :
        lihatkritikSaran();
        break;    
    
    default :
        break;
    }

}

int main() {
    char input;
    do
    {
        std::cout << "===========================================================";
        std::cout << "\nRekapan Data\n";
        std::cout << "===========================================================\n";
        std::cout << "1.Data Barang yang Tersedia\n";
        std::cout << "2.Data Barang yang Rusak\n";
        std::cout << "3.Kritik dan Saran\n";
        std::cout << "4.Keluar\n";
        std::cout << "Masukan Pilihan Menu :";
        std::cin >> input;
        switch (input) {
            case '1' :
                data_1();
                break;
            case '2' :
                data_2();
                break;
            case '3' :
                data_3();
                break;
            case '4' :
                std::cout << "Program Selesai";
                break;
            default:
                break;
        }
    } while (input!='4');
}