#ifndef STATEMAP_H
#define STATEMAP_H

#include "state.h"

class StateMap {
public:
    State &operator[](const std::string &key) {
        return map[key];
    }

    void apply_defaults(const State &defaults) {
        std::unordered_map<std::string, State>::iterator i = map.begin();
        while (i != map.end()) {
            i->second.set_name(i->first);
            i->second.set_defaults(defaults);
            i++;
        }
    }

private:
    std::unordered_map<std::string, State> map;
};

#endif // STATEMAP_H
