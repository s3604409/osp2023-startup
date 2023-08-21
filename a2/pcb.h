#include <unistd.h>

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <sstream>
#include "types.h"

#pragma once
class pcb {
    osp2023::id_type id;
    osp2023::time_type total_time;
    osp2023::time_type time_used;
    osp2023::priority_type priority;
    osp2023::time_type time_since_promoted;
    osp2023::time_type blocked_time;
    osp2023::time_type total_blocked_time;
    osp2023::time_type total_wait_time;
    osp2023::time_type last_on_cpu;
    double io_fraction;
    static osp2023::id_type next_id;
    friend std::ostream& operator<<(std::ostream&, const pcb&);

   public:
    constexpr static std::size_t max_time() { return MAX_DURATION; }
    constexpr static osp2023::priority_type lowest_priority() {
        return LOWEST_PRIORITY;
    }
    static osp2023::id_type get_next_id() { return next_id++; }
    static constexpr osp2023::time_type MAX_DURATION = 5000;
    static constexpr osp2023::priority_type LOWEST_PRIORITY = 20;
    static void set_next_id(osp2023::id_type theid) { next_id = theid; }
};
