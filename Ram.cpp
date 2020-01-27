
/*==========================HARDWARE================================*/

#include <Ram.hpp>

Ram::Ram(){
	ramV.reserve(RAM_SIZE);
}

void Ram::read(unsigned char* frame){
	if(ramV.size() < RAM_SIZE){
		this->ramV.push_back(frame);
	} else {
		std::cout << "Error: Attempting to add to ram with no space" << std::endl;
	}
}

vector<unsigned char*> Ram::ramV;
