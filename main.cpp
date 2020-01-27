#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <MemoryManager.hpp>
#include <MemoryManagementUnit.hpp>

using namespace std;

int main(){

	MemoryManagementUnit mmu;
	MemoryManager mm;

	ifstream inpFile;
	inpFile.open("addresses.txt");

	if(inpFile.is_open()){

		string line;

		while(!inpFile.eof()){

			inpFile >> line;

			if(!inpFile.eof()){

				Address currentAddr(line);
				try{
					mmu.read(currentAddr);
				} catch(pageFault& pF){

					mm.pageIn(pF.pageNumber_);
					cout << "FOUND PAGE FAULT" << endl;
					mmu.read(currentAddr);

				}

			}
		}
	}

	cout << dec << "Page Accesses: " << mmu.pageAccesses() << endl;
	cout << dec <<"Page Faults: " << mmu.pageFaults() << endl;
	cout << dec << "TLB Accesses: " << mmu.tlbAccesses() << endl;
	cout << dec <<"TLB Faults: " << mmu.tlbFaults() << endl;

	return 0;
}

// page table in process control block?
// output values type?
// what structure is the tlb?
// memory manager used only in page replacement?
// rubric, physical address correctly identified, need to be stored?
// what should address.frame() return? index in ram?
// page replacement only for tlb? ram is size 128 or 256?
