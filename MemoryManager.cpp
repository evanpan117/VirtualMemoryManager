/* Class implementation file for Memory Manager (Operating System) */

#include "MemoryManager.hpp"

MemoryManager::MemoryManager() {
	Ram r();
	BackingStore b();
	ProcessControlBlock p();
	//PageReplacementAlgorithim pra();
}

void MemoryManager::pageIn(uint32_t pNum){
    //if unused frame on the free frame list, take it off the list and use it
    //else:
        //invoke a page replacement algorithm to find a victim frame
    //Restore the contents of the selected frame from the backing store
    //Update the Page Table mapping with this page/frame pair

	/*===================Check if ram is full========================*/

    if(r.ramV.size() < RAM_SIZE){ 				// change to 128 later
		unsigned char * arr = new unsigned char;

		b.read(pNum, arr); 			// read in frame to arr from backing store
 
		r.read(arr);				// read in frame into ram from arr

		p.myPageTable[pNum].valid = true;						// set page to valid in page table
		p.myPageTable[pNum].frame_number = r.ramV.size() - 1;	// set frame number to index in Ram array

	} 
	/*======================If ram is full use PRA=====================*/
	else {
		int temp = 17;
		//int temp = pra.findVictim();
		for(int i = 0; i < 256; i++){
			if(p.myPageTable[i].frame_number == temp){
				p.myPageTable[i].valid = false;
				break;
			}
		}

		unsigned char * arr = new unsigned char;
		b.read(pNum, arr); 			// read in frame to arr

		cout << dec << "Replacing ram position: " << temp << " with new page: " << pNum << endl; 

		p.myPageTable[pNum].valid = true;
		p.myPageTable[pNum].frame_number = temp;
		r.ramV[temp] = arr;


	}
}


