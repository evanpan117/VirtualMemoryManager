#include <PageReplacementAlgorithm.hpp>
using namespace std;
PageReplacementAlgorithm::PageReplacementAlgorithm(){
   int frameNum = 0 ;
}

PageReplacementAlgorithm::~PageReplacementAlgorithm(){

}

int PageReplacementAlgorithm::findVictim(){
  frameNum++;
  return (frameNum-1)%128;
}

PageReplacementAlgorithm& PageReplacementAlgorithm::getPRA(){

}
