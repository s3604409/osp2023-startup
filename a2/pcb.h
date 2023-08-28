#include <iostream>
#include "types.h"

#pragma once
class pcb {
    // the unique process id
    osp2023::id_type id;
    // the total time that a process / job should run for
    osp2023::time_type total_time;
    // the time that has been used so far for this process
    osp2023::time_type time_used;
    // the priority level for this process
    // how much time has this process spent waiting for the cpu?
    osp2023::time_type total_wait_time;
    // what time was this process last on the cpu?

   public:
    constexpr static std::size_t max_time() { return MAX_DURATION; }
    static constexpr osp2023::time_type MAX_DURATION = 100;
    static constexpr osp2023::time_type MIN_DURATION = 10;
};
