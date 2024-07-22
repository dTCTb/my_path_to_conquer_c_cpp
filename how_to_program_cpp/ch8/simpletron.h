#include <iostream>

typedef enum instruction {
    READ = 10,
    WRITE,
    LOAD = 20,
    STORE,
    ADD = 30,
    SUBTRACT,
    DIVIDE,
    MULTIPLY,
    BRANCH = 40,
    BRANCHNEG,
    BRANCHZERO,
    HALT,
    QUIT = 99,
    CMD_RESET,
    DEBUG = 0,
    HELP = -1,
} instruct;

class Simpletron {
  private:
    int memory[100];
    int accumulator;
    unsigned cmd_count;
    static const std::string wel_msg[];
    static const std::string help_msg[];
    static const std::string bye_msg;

  public:
    bool debug;
    enum instruction ins;
    unsigned adr;

    Simpletron(bool debug_mode = false);
    ~Simpletron();
    static void simpletron_driver(Simpletron &);
    void display_wel_msg() const;
    int valid(const int &val);
    void cmd_analysis(const int &cmd);
    void get_cmd();
    void read();
    void write() const;
    void load();
    void store();
    void add();
    void subtract();
    void divide();
    void multiply();
    void branch();
    void branchneg();
    void branchzero();
    void halt();
    void display_memory();
    void toggle_debug();
    void reset_cmd_count();
    void help() const;
};

void simpletron_driver(Simpletron &host);
