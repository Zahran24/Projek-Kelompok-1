#include <iostream>
#include <iomanip>

struct data1 {
    std::string namaBarang;
    std::string jumlahBarang;
    std::string kodeBarang;

    data1 *next;
};

using data1ptr = data1*;
using linkedlist = data1ptr; 

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

void data_2(){
    char input_data2;
    std::cout << std::setfill('=') << std::setw(31) << "\n";
    std::cout << std::setw(4) << "Rekapan Data 2\n";
    std::cout << std::setfill('=') << std::setw(31) << "\n";
    std::cout << "1.Masukkan Data\n";
    std::cout << "2.Hapus Data\n";
    std::cout << "3.Tampilkan Data\n";
    std::cin >> input_data2;
    switch (input_data2)
    {
    case '1' :
        break;
    
    default:
        break;
    }

}

void dat_akhir(){

}
main() {
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