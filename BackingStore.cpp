/* Class implementation file: Backing Store (Hardware) */

#include "BackingStore.hpp"

using namespace std;

/* TODO: Run test with page_number */

BackingStore* BackingStore::b_store;
ifstream BackingStore::bin_file;

BackingStore* BackingStore::instance(){
    if (b_store = nullptr){
        b_store = new BackingStore();
    }
    return b_store;
    cout << "Backing store created" << endl;
}

void BackingStore::read(unsigned char page_number, char* arr){
    bin_file.seekg(page_number * PAGE_SIZE); //Finds frame number by multiplying page number (unsigned hex) and page size (256)
    bin_file.read(arr, PAGE_SIZE); // Saves frame number to page entry
}

BackingStore::~BackingStore(){
    bin_file.close();
    delete b_store;
    b_store = nullptr;
    cout << "Backing store destroyed" << endl;
}

BackingStore::BackingStore(){
    bin_file.exceptions(ifstream::failbit | ifstream::badbit);

    try {
        bin_file.open("BACKING_STORE.bin", ifstream::binary); // Read existing binary file
    } catch (ifstream::failure error){
        cerr << "Error opening BACKING_STORE.bin" << error.what() << endl;
    }
}