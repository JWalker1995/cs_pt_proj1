
class FSALoader {
public:
    FSALoader() {
    }

    void load_file(std::istream &stream) {
        while (true) {
            Transition trans;

            std::string init_state_str;
            stream >> init_state;
            if (!stream.good()) {break;}
            trans.init_state = get_state_id(init_state_str);

            stream >> trans.char_min;
            if (!stream.good()) {break;}

            stream >> trans.char_max;
            if (!stream.good()) {break;}

            stream >> trans.emit_tok;
            if (!stream.good()) {break;}

            std::string end_state_str;
            stream >> end_state;
            if (!stream.good()) {break;}
            trans.end_state = get_state_id(end_state_str);

            transitions.push_back(trans);
        }
    }

    Table *generate_table() {
        return new Table(transitions);
        Table res;
        res.num_states = num_states;
        res.char_min = static_cast<unsigned int>(-1);
        res.char_max = 0;

        std::vector<Transition>::const_iterator i;

        i = transitions.cbegin();
        while (i != transitions.cend()) {
            if (i->char_min < res.char_min) {res.char_min = i->char_min;}
            if (i->char_max > res.char_max) {res.char_max = i->char_max;}
            i++;
        }

        res.map = new Table::Action[res.num_states * (res.char_max - res.char_min + 1)];

        i = transitions.cbegin();
        while (i != transitions.cend()) {
            res.map[res.get_state_index(i->init_state, )] = i->end_state;
            i++;
        }
    }

private:
    struct Transition {
        unsigned int init_state;
        unsigned int char_min;
        unsigned int char_max;
        std::string emit_tok;
        unsigned int end_state;
    };

    unsigned int num_states = 0;
    std::map<std::string, unsigned int> state_ids;
    std::vector<Transition> transitions;

    unsigned int get_state_id(const std::string &name) {
        unsigned int &id = state_ids[name];
        if (!id) {
            id = ++num_states;
        }
        return id;
    }
};

