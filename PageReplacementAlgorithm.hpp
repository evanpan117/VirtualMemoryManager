#include <Configuration.hpp>
#include <Ram.hpp>
#include <BackingStore.hpp>
#include <ProcessControlBlock.hpp>

class PageReplacementAlgorithm{
public:
  static PageReplacementAlgorithm();
  ~PageReplacementAlgorithm();
  int findVictim();
  void PageReplacementAlgorithm& getPRA();

private:
  OptionMap& options();

};
