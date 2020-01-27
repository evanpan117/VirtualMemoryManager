#include <Configuration.hpp>
#include <Ram.hpp>
#include <BackingStore.hpp>
#include <ProcessControlBlock.hpp>

class LRU_Replacement(){
public:
  LRU_Replacement();
  word findVictim();
  void updateUsage();

private:
  list <unsigned char> lruList ();
};
