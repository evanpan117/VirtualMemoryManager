
/*==========================HARDWARE================================*/

#pragma once
#include <Configuration.hpp>
#include <vector>
#include <iostream>

using namespace std;

class Ram {

	public:
		void read(unsigned char* frame);
		static vector<unsigned char*> ramV;
		Ram();

	private:
		struct Status;


};