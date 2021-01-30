#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    bool hidden = false;
    int opt;
    int argstart = 1;
    while ((opt = getopt(argc, argv, ":if:h")) != -1) {
        switch (opt) {
            case 'h':
                hidden = true;
                argstart += 1;
                break;
            case '?':
                break;
        }
    }
    for (int i = argstart; i < argc; i++) {
        DIR *dr;
        struct dirent *en;
        dr = opendir(argv[i]); //open all or present directory
        std::string file_name;
        if (dr) {
            std::cout << argv[i] << std::endl;
            while ((en = readdir(dr)) != NULL) {
                if (!strcmp(en->d_name, ".") || !strcmp(en->d_name, "..")) {
                    // do nothing (straight logic)
                }
                else {
                    file_name = en->d_name; // use it
                    if (file_name[0] == '.' and !hidden){
                        continue;
                    }
                    else{
                        std::cout << file_name << std::endl;
                    }

                }
            }
            closedir(dr); //close all directory
        }
        else {
            std::cout << "Cannot access " + std::string(argv[i]) << std::endl;
        }
        std::cout << "..." << std::endl;
    }
}

