/* Class header file for Memory Manager (Operating System) */

#pragma once

#include "BackingStore.hpp"
#include "ProcessControlBlock.hpp"
#include "Ram.hpp"
#include "PageReplacementAlgorithm.hpp"

class MemoryManager {
public:
    MemoryManager(); //(+1 overload)
    //MemoryManager& instance;
    //MemoryManager& operator=(); //(+1 overload)

    /* Handles page fault/trap (new page not in memory) determined by MMU */
    void pageIn(uint32_t pNum); //If page fault, page in from backing store into RAM

    /* TODO:
    Create list of free frames
    Update frame status
    */

private:
    //FreeFramesList free_frames;
    //bool isFreeFrame; // Default: Frame does not have any page
    //Gives you which frame is loaded with / unallocated to page
    Ram r;
    BackingStore b;
    ProcessControlBlock p;
    //PageReplacementAlgorithim pra;

};
