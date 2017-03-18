#ifndef STATE_H
#define STATE_H

#include <algorithm>
#include <string>
#include <unordered_map>

class State {
public:
    State() {
        std::fill_n(edges, 256, static_cast<const State *>(0));
        std::fill_n(emits, 256, static_cast<const char *>(0));
    }

    void set_name(const std::string &new_name) {
        name = new_name;
    }

    State &set(unsigned int min, unsigned int max, const State &dst) {
        for (unsigned int i = min; i <= max; i++) {
            edges[i] = &dst;
        }
        return *this;
    }

    State &set(unsigned int min, unsigned int max, const char *emit) {
        for (unsigned int i = min; i <= max; i++) {
            emits[i] = emit;
        }
        return *this;
    }

    State &set(unsigned int min, unsigned int max, const State &dst, const char *emit) {
        for (unsigned int i = min; i <= max; i++) {
            edges[i] = &dst;
            emits[i] = emit;
        }
        return *this;
    }

    void set_defaults(const State &defaults) {
        for (unsigned int i = 0; i < 256; i++) {
            if (edges[i] == 0) {edges[i] = defaults.edges[i];}
            if (emits[i] == 0) {emits[i] = defaults.emits[i];}
        }
    }

    const State *follow_edge(unsigned int index) const {
        return edges[index];
    }
    const char *get_emit(unsigned int index) const {
        return emits[index];
    }
    const std::string &get_name() const {
        return name;
    }

private:
    std::string name;
    const State *edges[256];
    const char *emits[256];
};

#endif // STATE_H
