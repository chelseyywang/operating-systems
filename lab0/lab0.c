#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


//option can be --input something or --input=something
//if it only accepts long strings then use "" 
//last parameter in getopt_long points to a var that is set to index of struct
void errorHandler(int sigNum)
{
    if (sigNum == SIGSEGV)
    {
        fprintf(stderr, "%s", "Caught segfault"); 
        exit(4); 
    }
}
int main(int argc, char** argv)
{
    int c; 
    int structIndex; 
    int segfaultBool = 0; 
    int catchBool = 0; 
    //{const char *name; int has_arg; int *flag; int val;}
    static struct option options[] = {
        {"input", required_argument, NULL, 1}, 
        {"output", required_argument, NULL, 2}, 
        {"segfault", no_argument, NULL, 3}, 
        {"catch", no_argument, NULL, 5}, 
        {0,0,0,0}
    };
    int fd0 = 0; 
    int fd1 = 1; 
    // fprintf(stderr,"%s", "wassup"); 
    
    while ((c = getopt_long(argc, argv, "", options, &structIndex))!=-1)
    {
        //returns val, the single char, if flag is null 
        //optarg holds the string argument 
        switch (c) {
            case 1: //input
                // printf("%s", "input: "); 
                // printf("%s", optarg); 
                //fprintf(stderr, "%s", "entered case 1: \n"); 
                if ((fd0=open(optarg, O_RDONLY))==-1)
                {
                    fprintf(stderr, "Error with argument --input, file %s, due to: %s\n", optarg, strerror(errno)); 
                    // printf("Error with argument --input, unable to open %s, due to: %s\n", optarg, strerror(errno)); 
                    exit(2); 
                }
                //file redirectionf
                close(0); 
                dup(fd0); 
                close(fd0); 

                break; 
            case 2: //output
                //fprintf(stderr, "%s", "entered case 2: \n"); 
                
                if ((fd1=open(optarg, O_CREAT | O_WRONLY, 0666))==-1)
                {
                    fprintf(stderr, "Error with argument --output, file %s, due to: %s\n", optarg, strerror(errno)); 
                    exit(3); 
                }
                close(1); 
                dup(fd1); 
                close(fd1); 
                // printf("%s", "fd1: "); 
                // printf("%i\n", fd1); 
                break; 
            case 3: //segfault
                // fprintf("%s", "make a segfault"); 
                segfaultBool = 5; 
                // char * chPtr = NULL; 
                // chPtr[0] = 'h'; 
                break; 
            case 5: //catch
                // fprintf("%s", "catch the segfault"); 
                catchBool = 5; 
                // signal(SIGSEGV, SIG_DFL)
                // exit(4); 
                break; 
            default: 
                fprintf(stderr, "%s", "Incorrect or extra arguments; use --input=filename, --output=filename, --segfault, --catch\n"); 
                exit(1); 

        }//end of switch 
    }//end of while loop
    // printf("%s", "finished switch"); 
    //check if catch was called
        //catch segfault
    // if (segfaultBool == 5 && catchBool == 5)
    // {
    //     //fprintf(stderr, "%s", "catching segfault"); 
    //     signal(SIGSEGV, SIG_DFL); 
    //     exit(4);
    // }
        //no segfault to catch
    if (catchBool == 5)
    {
        //fprintf( stderr,"%s", "catching nothing"); 
        signal(SIGSEGV, errorHandler);
    }
    //check if segfault was called
        //make segfault 
    if (segfaultBool == 5)
    {
        char * chPtr = NULL; 
        chPtr[0] = 'h'; 
    }

    //read and write byte by byte
    char* s = (char*) malloc(sizeof(char)); 
    int r; 
    int w; 
    while((r = read(0, &s, 1)) != 0)
    {
        // printf("%s", "u"); 
        if (r == -1)
        {
            fprintf(stderr, "%s", "failed reading"); 
            exit(1); 
        }
        // printf("%s", "fd1: "); 
        // printf("%i\n", fd1); 
        // printf("buffer: "); 
        // printf("%c\n", s); 
        w = write(1, &s, 1); 
        // printf("W: "); 
        // printf("%i", w); 
        if (w==-1)
        {
            fprintf(stderr, "%s", "failed writing"); 
            exit(1); 
        }
    }

    //free(s); 
    exit(0); 
}