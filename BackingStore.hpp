/* Class header file: Backing Store (Hardware) */

#pragma once
#include "Configuration.hpp"
#include <iostream>
#include <fstream> // To use std::ifstream

class BackingStore {
public:
    /* Instantiates BackingStore */
    BackingStore* instance();

    /* Reads from page number (as unsigned hex) to find frame number */
    void read(unsigned char page_number, char* arr);

    ~BackingStore();
private:
    /* Opens backing store */
    BackingStore();

    /* Declares BackingStore object and binary file variables, global to all instances */
    static BackingStore* b_store;
    static ifstream bin_file;
};