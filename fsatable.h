#include <string>

class FSATable {
    friend class FSALoader;

public:
    struct Action {
        Action(unsigned int new_state, bool suck, const std::string &emit_tok)
            : new_state(new_state)
            , suck(suck)
            , emit_tok(emit_tok)
        {}

        unsigned int new_state;
        bool suck;
        const std::string &emit_tok;
    };

    class InputException : public std::exception
    {
        friend class FSATable;

    public:
        virtual const char *what() const noexcept {
            return str.c_str();
        }

    private:
        InputException(unsigned int input_char)
            : str("Invalid input with char code " + std::to_string(input_char))
        {}

        std::string str;
    };

    Action get_action(unsigned int prev_state, unsigned int input_char) {
        assert(prev_state <= num_states);
        if (input_char < char_min || input_char > char_max) {
            throw new InputException(input_char);
        }

        return map[get_state_index(prev_state, input_char)];
    }

private:
    unsigned int num_states;
    unsigned int char_min;
    unsigned int char_max;

    Action map*;
    std::vector<std::string> emit_tokens;

    unsigned int get_state_index(unsigned int prev_state, unsigned int input_char) const {
        return (input_char - char_min) * num_states + prev_state;
    }

    const std::string &push_emit_token(const std::string &str) {
        emit_tokens.push_back(str);
        return emit_tokens.back();
    }
};


/*
id 12 34 idTok id
*/
