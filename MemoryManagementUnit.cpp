
/*==========================HARDWARE================================*/

#include <MemoryManagementUnit.hpp>

MemoryManagementUnit::MemoryManagementUnit(){
	Ram r();
	ProcessControlBlock p();

	tlb_.reserve(TLB_SIZE);

	page_access_count = 0;
	page_in_faults = 0;
	tlb_access_count_ = 0;
	tlb_faults_ = 0;
}

void MemoryManagementUnit::read(Address addr){
	/*=================Check TLB===================*/
	bool tlbMiss = true;
	
	for(unsigned int i = 0; i < tlb_.size(); i++){
		if(addr.page() == tlb_[i].PageNum){
			
			tlb_access_count_++;
			
			cout << hex << static_cast<int32_t>(r.ramV[tlb_[i].pTE.frame_number][addr.displacement()]) << endl;
			
			//Update TLB
			tlbEntry temp = tlb_[i];
			tlb_.erase(tlb_.begin() + i);
			tlb_.push_back(temp);
			tlbMiss = false;
			break;

		}
	} 
	/*==================Check Page Table===================*/
	if(tlbMiss){
		tlb_faults_++;
		if(p.myPageTable[addr.page()].valid){ // page in memory
			page_access_count++;
			
			cout << hex << static_cast<int32_t>(r.ramV[addr.frame(p.myPageTable)][addr.displacement()]) << endl;

			//Update TLB
			
			tlbEntry temp;
			temp.pTE = p.myPageTable[addr.page()];
			temp.PageNum = addr.page();

			if(tlb_.size() >= 16){
				tlb_.erase(tlb_.begin());
			}

			tlb_.push_back(temp);

	/*===================Generate Page Fault==========================*/	
		} else { 
			page_in_faults++;
			throw pageFault(addr.page());			
		}
	}
}

void MemoryManagementUnit::clearTLB(){
	tlb_.erase(tlb_.begin(),tlb_.end());
}

int MemoryManagementUnit::pageAccesses(){
	return page_access_count;
}

int MemoryManagementUnit::pageFaults(){
	return page_in_faults;
}

int MemoryManagementUnit::tlbAccesses(){
	return tlb_access_count_;
}

int MemoryManagementUnit::tlbFaults(){
	return tlb_faults_;
}
