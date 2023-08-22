#include <unistd.h>

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
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
    osp2023::priority_type priority;
    // the last time this process was promoted
    osp2023::time_type time_since_promoted;
    // how much of the time for this process has it spent being blocked?
    osp2023::time_type blocked_time;
    // how much time has this process spent waiting for the cpu?
    osp2023::time_type total_wait_time;
    // what time was this process last on the cpu?
    osp2023::time_type last_on_cpu;
    // what percentage of time should this process spend dealing with io?
    double io_fraction;
    friend std::ostream& operator<<(std::ostream&, const pcb&);

   public:
    constexpr static std::size_t max_time() { return MAX_DURATION; }
    constexpr static osp2023::priority_type lowest_priority() {
        return LOWEST_PRIORITY;
    }
    static constexpr osp2023::time_type MAX_DURATION = 5000;
    static constexpr osp2023::priority_type LOWEST_PRIORITY = 20;
};
