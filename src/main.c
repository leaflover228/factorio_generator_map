#include "factorio.h"

void parse_args(int argc, char *argv[]) {
    int opt;
    int opt_id;

    static struct option long_options[] = {
        /* data */
        {"help",    no_argument,    0,      'h'},
        {0,         0,              0,       0 }
    };

    while((opt = getopt_long(argc, argv, "hvo:w:", long_options, &opt_id)) != -1) {
        switch(opt) {
            case 'h':
                printf("Usage: %s [options]\n", argv[0]);
                printf("    -h, --help        Show help message\n");
                exit(EXIT_SUCCESS);
            case '?':
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }
    
    for(int i = optind; i < argc; i++) {
        printf("Positional argument: %s\n", argv[i]);
    }
}

int main(int argc, char *argv[]) {
    parse_args(argc, argv);
    return 0;
}