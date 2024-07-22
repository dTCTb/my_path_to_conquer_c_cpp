#include "simpletron.h"
#include <iomanip>
#include <iostream>

const std::string Simpletron::wel_msg[] = {
    "***************************************************************",
    "*** Welcome to Simpletron!                                  ***",
    "*** Please enter you program one instruction (or data word) ***",
    "*** at a time. I will type the location number and a        ***",
    "*** question mark (?). You then type the word for that      ***",
    "*** location. Type the sentinel -99999 to stop entering     ***",
    "*** your program or 99 to quit the Simpletron machine.      ***",
    "***************************************************************",
};

const std::string Simpletron::help_msg[] = {
    "***************************************************************",
    "***                          HELP                           ***",
    "*** ## ? xxyy | xx : command | yy : memory address (00~99)  ***",
    "*** ~~~~~~~~~ | ## : counts of commands (starting from 00)  ***",
    "*** 0 to open | 99 : quit | -1 : show help message          ***",
    "***   DEBUG   | 100 : reset the commands counter to zero    ***",
    "*** 10yy : read from input (-9999 ~ +9999) and put it to yy ***",
    "*** 11yy : print the value of yy to screen                  ***",
    "*** 20yy : load the value of yy to register                 ***",
    "*** 21yy : put the value of register to yy                  ***",
    "***         ~~~ result of 30 ~ 33 is stored in register ~~~ ***",
    "*** 30yy : value of register ADD value of yy                ***",
    "*** 31yy : value of register SUBTRACT value of yy           ***",
    "*** 32yy : value of register DIVIDE value of yy             ***",
    "*** 33yy : value of register MULTIPLY value of yy           ***",
    "*** 40yy : set memory address to yy                         ***",
    "*** 41yy : if value of register is negative, put it to yy   ***",
    "*** 42yy : if value of register is zero, put it to yy       ***",
    "***************************************************************",
    // "*** 43 ***"
};

const std::string Simpletron::bye_msg =
    "***          ~Thanks for using, hope see you again~         ***";

Simpletron::Simpletron(bool debug_mode)
    : memory{}, accumulator(0), cmd_count(0), debug(debug_mode),
      ins(static_cast<instruct>(0)), adr(0) {
    display_wel_msg();
}

Simpletron::~Simpletron() { std::cout << bye_msg << std::endl; }

void Simpletron::display_wel_msg() const {
    for (std::string line : wel_msg)
        std::cout << line << '\n';
    std::cout.put('\n');
}

int Simpletron::valid(const int &val) {
    return val >= 0 ? val % 10000 : val % -10000;
}

void Simpletron::cmd_analysis(const int &cmd) {
    bool special = true;
    switch (cmd) {
    case QUIT:
        ins = QUIT;
        break;
    case DEBUG:
        ins = DEBUG;
        break;
    case CMD_RESET:
        ins = CMD_RESET;
        break;
    case HELP:
        ins = HELP;
        break;
    default:
        if (cmd < 1000) {
            ins = HELP;
            break;
        }
        ins = static_cast<instruct>(cmd / 100);
        adr = cmd % 100;
        special = false;
        break;
    }
    if (special)
        cmd_count--;
}

void Simpletron::get_cmd() {
    int cmd;
    std::cout << std::setw(2) << std::setfill('0') << cmd_count++
              << std::setfill(' ') << " ? ";
    std::cin >> cmd;
    cmd_analysis(cmd);
}

void Simpletron::read() {
    int tmp;
    std::cout << "~~ < ";
    std::cin >> tmp;
    memory[adr] = valid(tmp);
}

void Simpletron::write() const {
    std::cout << "~~ > " << memory[adr] << std::endl;
}

void Simpletron::load() { accumulator = memory[adr]; }

void Simpletron::store() { memory[adr] = accumulator; }

void Simpletron::add() { accumulator = valid(accumulator + memory[adr]); }

void Simpletron::subtract() { accumulator = valid(accumulator - memory[adr]); }

void Simpletron::divide() { accumulator = valid(accumulator / memory[adr]); }

void Simpletron::multiply() { accumulator = valid(accumulator * memory[adr]); }

void Simpletron::branch() {}

void Simpletron::branchneg() {
    if (accumulator < 0)
        memory[adr] = accumulator;
}

void Simpletron::branchzero() {
    if (!accumulator)
        memory[adr] = accumulator;
}

void Simpletron::halt() {}

void Simpletron::display_memory() {
    std::cout << "MEMORY:\n";

    // heading
    std::cout << std::setw(4) << ' ';
    for (size_t i = 0; i < 10; i++)
        std::cout << std::setw(5) << i << ' ';
    std::cout.put('\n');

    // memory table
    for (size_t i = 0; i < 10; i++) {
        std::cout << std::setw(3) << i * 10 << ' ';   // row = 0 to 9
        for (size_t j = i * 10; j < i * 10 + 10; j++) // row0 to row9
            std::cout << std::showpos << std::setfill('0') << std::internal
                      << std::setw(5) << memory[j] << ' ';
        std::cout << std::noshowpos << std::setfill(' ') << std::endl;
    }
    std::cout << std::setfill('0') << std::showpos
              << "accumulator: " << accumulator << std::noshowpos
              << "\tins: " << std::setw(2) << ins << "\tadr: " << std::setw(2)
              << adr << std::setfill(' ') << std::endl;
}

void Simpletron::help() const {
    for (std::string line : help_msg)
        std::cout << line << std::endl;
    std::cout.put('\n');
}

void Simpletron::toggle_debug() { debug = !debug; }

void Simpletron::reset_cmd_count() { cmd_count = 0; }

void simpletron_driver(Simpletron &sml) {
    while (true) {
        if (sml.debug)
            sml.display_memory();
        sml.get_cmd();

        switch (sml.ins) {
        case READ:
            sml.read();
            break;
        case WRITE:
            sml.write();
            break;
        case LOAD:
            sml.load();
            break;
        case STORE:
            sml.store();
            break;
        case ADD:
            sml.add();
            break;
        case SUBTRACT:
            sml.subtract();
            break;
        case DIVIDE:
            sml.divide();
            break;
        case MULTIPLY:
            sml.multiply();
            break;
        case BRANCH:
            sml.branch();
            break;
        case BRANCHNEG:
            sml.branchneg();
            break;
        case BRANCHZERO:
            sml.branchzero();
            break;
        case HALT:
            // sml.halt();
            break;
        case QUIT:
            return;
            break;
        case CMD_RESET:
            sml.reset_cmd_count();
            break;
        case DEBUG:
            sml.toggle_debug();
            break;
        default:
            std::cout << "command is not validate" << std::endl;
        case HELP:
            sml.help();
            break;
        }
    }
}
