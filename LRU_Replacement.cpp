#include <LRU_Replacement.hpp>
using namespace std;
LRU_Replacement::LRU_Replacement(){
  list <unsigned char> lruList (128);
  for (i=0; i < 128; i++){  //initial lruList with frame nums
    lruList.push_back(i);
  }
}

word LRU_Replacement::findVictim(){
  return lruList.first() ;
}

void LRU_Replacement::updateUsage(unsigned char frameNum){
  bool inRam == false;
  for (int i =0; i < 128; i++){
    if (frameNum == lruList<i>)
      lruList.erase(i);
      lruList.push_back(i);
      inRam == true;
  }
  if (inRam == false){
    lruList.pop_front();
    lruList.push_back(frameNum);
  }
}
