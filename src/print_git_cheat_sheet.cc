#include <iostream>
#include <map>

#define SCREENWIDTH 79


std::map<std::string, std::string> getCommands() {
    return {
        {
            "git fetch origin main:main",
            "Pull a remote main to local main without switching branches"
        },
        {
            "git push origin --delete <remote-branch-name>",
            "Delete a branch from remote origin"
        },
        {
            "git push -u origin <branch-name>",
            "Push current branch to remote origin with the given branch name"
        },
    };
}


std::string getChars(char c, int n) {
    std::string result;
    for (int i = 0; i < n; i++) {
        result += c;
    }
    return result;
}


std::string getHashes(int n) {
    return getChars('#', n);
}


std::string padLeft(std::string input_string, std::string pad) {
    return pad + input_string;
}


std::string padRight(std::string input_string, std::string pad) {
    return input_string + pad;
}


std::string padString(std::string input_string, std::string pad) {
    return padRight(padLeft(input_string, " "), " ");
}


bool checkEven(int input_int) {
    bool result = false;
    if ( input_int % 2 == 0 ) {
        result = true;
    }
    return result;
}


int computeEmptyChars(std::string input_string, std::string pad) {
    return SCREENWIDTH - (2 * pad.length()) - input_string.length();
}


std::tuple<int, int> computeHashNumbers(
    std::string input_string, std::string pad
) {
    int left_hash_number;
    int right_hash_number;
    int empty_chars = computeEmptyChars(input_string, pad);

    if (checkEven(empty_chars)) {
        left_hash_number = empty_chars / 2;
        right_hash_number = left_hash_number;
    } else {
        left_hash_number = (empty_chars + 1) / 2;
        right_hash_number = left_hash_number - 1;
    }

    return {left_hash_number, right_hash_number};
}


std::string addHashes(std::string input_string, std::string pad) {
    auto[left_hash_number, right_hash_number] = computeHashNumbers(
        input_string, pad
    );
    auto result = getHashes(left_hash_number)
        + padString(input_string, pad)
        + getHashes(right_hash_number);
    return result;
}


std::string splitLines(
    std::string input_string,
    std::string line_beginner = "# "
) {
    auto result = line_beginner;

    auto count = line_beginner.length();
    for (auto c: input_string) {
        result += c;
        count += 1;
        if (count > (SCREENWIDTH - 1)) {
            result += '\n';
            result += line_beginner;
            count = line_beginner.length();
        }
    }

    return result;
}


std::string composeText(std::string input_string, std::string pad = " ") {
    std::string result;
    if ((input_string.length() + (2 * pad.length())) < SCREENWIDTH) {
        result = addHashes(input_string, pad);
    } else {
        result = splitLines(input_string);
    }
    return result;
}


void printGitCommands(std::map<std::string, std::string> command_map) {
    using namespace std;

    for (const auto& [command, description] : command_map) {
        cout << splitLines(description, "# ") << endl;
        cout << splitLines(command, "$ ") << endl;
        cout << getChars('_', SCREENWIDTH) << endl;
    }
    cout << getHashes(SCREENWIDTH) << endl;
}


void printTitle(std::string input_string) {
    using namespace std;

    cout << getHashes(SCREENWIDTH) << endl;
    cout << composeText(input_string) << endl;
    cout << getHashes(SCREENWIDTH) << endl;
}


int main() {
    printTitle("GIT CHEAT SHEET");
    printGitCommands(getCommands());

    return 0;
}

