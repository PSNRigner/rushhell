#include <iostream>
#include <vector>
#include "Machine.hpp"

void end(std::vector<std::string> &tokens, const std::string &token)
{
    if (!token.empty())
        tokens.push_back(token);
    std::cout << "Consumed : " << std::endl;
    for (int i = 0; i < tokens.size(); ++i)
        std::cout << tokens[i] << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 1;
    std::string alphabet = "mechant";
    std::vector<std::string> tokens;
    std::string token;
    eState state = S0;
    bool ok = false;
    for (int i = 0; av[1][i]; ++i)
    {
        size_t index = alphabet.find(av[1][i]);
        if (index == std::string::npos)
            index = alphabet.size();
        eAction action = gActionTable[state][index];
        state = gStateTable[state][index];
        if (action == MA)
            token.push_back(av[1][i]);
        else if (action == ACTION_ERROR)
        {
            std::cout << "KO (Action error)" << std::endl;
            end(tokens, token);
            return 1;
        }
        if (state == STATE_ERROR)
        {
            std::cout << "KO (State error)" << std::endl;
            end(tokens, token);
            return 1;
        }
        if (state == S7)
        {
            ok = true;
        }
        if (action == HR)
        {
            tokens.push_back(token);
            token.clear();
            state = S0;
        }
    }

    std::cout << (ok ? "OK" : "KO") << std::endl;
    end(tokens, token);
    return 0;
}