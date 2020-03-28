//Chelsey Wang
//705124638
//chelseyyywang@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <getopt.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <libexplain/poll.h>

// #include <stropts.h>

void errorHandler(int sigNum); 

int globalBad = 0; 
int childPID; 
struct termios ogTerm; 
struct termios myTerm; 
char de[2] = {0x0D, 0x0A};
int globeShell = 0; 

void peaceOut()
{
    if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
    {
        fprintf(stderr, "%s", "resetting failed\n"); 
        exit(1); 
    }
    if (globalBad == 5) // if bad argument 
    {
        exit(1); 
    }
    if (globeShell == 5)
    {
        int childStatus; 
        if (waitpid(childPID, &childStatus, 0) < 0)
        {
            fprintf(stderr, "%s", "Waitpid Error\r\n"); 
        }
        //  int exitSignal = childStatus&0x7f; 
        //  int exitStatus = (childStatus&0xff00) >> 8; 
        fprintf(stderr, "SHELL EXIT SIGNAL=%i STATUS=%i", WTERMSIG(childStatus), WEXITSTATUS(childStatus)); 
    }
    exit(0); 
}

int main(int argc, char** argv)
{
    atexit(peaceOut); 

    if (tcgetattr(0, &ogTerm) != 0)
    {
        globalBad = 5; 
        exit(1); 
    }
    if (tcgetattr(0, &myTerm) != 0)
    {
        globalBad = 5;
        exit(1); 
    }
    // change its settings 
    myTerm.c_iflag = ISTRIP; 
    myTerm.c_oflag = 0; 
    myTerm.c_lflag = 0; 
    if (tcsetattr(0, TCSANOW, &myTerm) != 0)
    {
        globalBad = 5;
        exit(1); 
    }

    // *** creating two pipes hehe *** //

    int pipeToShell[2]; //pipeToShell[0] -> fd for read; //pipeToShell[1] -> fd for write 
    int pipeOutShell[2]; //pipeOutShell[0] -> fd for read; //pipeOutShell[1] -> fd for write
    if ( pipe(pipeToShell) < 0 )
    {
        fprintf(stderr, "%s", "pipeToShell failed\n"); 
        globalBad = 5;
        exit(1); 
    }
    if ( pipe(pipeOutShell) < 0 )
    {
        fprintf(stderr, "%s", "pipeOutShell failed\n"); 
        globalBad = 5;
        exit(1); 
    }
    // got the pipes ready ;) //
    // check arguments
    int structIndex; 
    int shellBool = 0; 
    int debugBool = 0; 
    static struct option options[] = {
        {"shell", no_argument, NULL, 1}, 
        {"debug", no_argument, NULL, 2}, 
        {0,0,0,0}
    };
    char a; 
    while ((a = getopt_long(argc, argv, "", options, &structIndex))!=-1)
    {
        switch (a) 
        {
            case 1: //shell
                ////////////////////
                // fork time baby //
                ////////////////////
                // * aqui
                signal(SIGPIPE, errorHandler); 
                childPID = fork(); 
                // child block
                if (childPID < 0)
                {
                    fprintf(stderr, "%s", "Fork Failed. \n\r"); 
                }
                else if (childPID == 0)
                {
                    // *** rearranging file descriptors *** //
                    // close fds child will not use 
                    if ( close(pipeToShell[1]) < 0 ) 
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1); 
                    }
                    if ( close (pipeOutShell[0]) < 0 )
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1); 
                    }
                    if ( close(0) < 0 )
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1); 
                    }
                    if ( dup(pipeToShell[0]) < 0 ) 
                    {
                        fprintf(stderr, "%s", "Dup failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }
                    if ( close(pipeToShell[0]) < 0 )
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }
                    if ( close(1) < 0 ) 
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    } 
                    if ( dup(pipeOutShell[1]) < 0 )
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }
                    if ( close(2) < 0 ) 
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    } 
                    if ( dup(pipeOutShell[1]) < 0 )
                    {
                        fprintf(stderr, "%s", "Dup failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }
                    if ( close(pipeOutShell[1]) < 0 )
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }

                    // *** set her free *** //
                    char *exArgs[] = { "/bin/bash", NULL}; 
                    if (execv(exArgs[0],exArgs) < 0)
                    {
                        fprintf(stderr, "%s", "Exec failed\n\r"); 
                    }
                } // done with = 0 
                else // parent block
                { 
                    shellBool = 5; 
                    globeShell = 5; 
                    if ( close(pipeToShell[0]) < 0 ) //closing reading itself
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }
                    if ( close(pipeOutShell[1]) < 0 ) //closing writing to itself 
                    {
                        fprintf(stderr, "%s", "Closing failed. \n\r"); 
                        globalBad = 5;
                        exit(1);
                    }
                } // end of parent block 
                break; 

                // * aqui
            case 2: //debug
                debugBool = 5;
                break; 
            default: 
                globalBad = 5; 
                fprintf(stderr, "%s", "Incorrect or extra arguments; use --shell, --debug\n"); 
                exit(1); 

        }//end of switch 
    }//end of while loop
    // checking for wack arg non arg ? 
    if (optind < argc)
    {
        fprintf(stderr, "%s", "Incorrect or extra arguments; use --shell, --debug\n\r");
        globalBad = 5;
        exit(1); 
    }
    //done checking arguments
    if (shellBool == 0)
    {
        if (debugBool == 5)
            fprintf(stderr, "%s", "No arguments; proceed with no-shell terminal \n\r"); 
        while(1)
        {
            char buff[8]; 
            int amtRead = read(1, &buff, 8); 
            //check read sys call
            for (int i = 0; i < amtRead; i++)
            {
                char c = buff[i]; 

                if (c == '\004')
                {
                    if ( write(1, "^D", 2) < 0 ) 
                    {
                        fprintf(stderr, "%s", "^D failed\n"); 
                        globalBad = 5;
                        exit(1);
                    }
                    if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
                    {
                        fprintf(stderr, "%s", "resetting failed\n"); 
                        globalBad = 5;
                        exit(1); 
                    }
                    exit(0);  
                } 
                else if (c == 0x0D || c == 0x0A) //enter
                { 
                    if ( write(1, "\r\n", 2) < 0 )
                    {
                        fprintf(stderr, "%s", "enter failed \n");
                        globalBad = 5;
                        exit(1);
                    }     
                }
                else
                {
                    if ( write(1, &c, 1) < 0 )
                    {
                        fprintf(stderr, "%s", "my echoing failed\n"); 
                        globalBad = 5;
                        exit(1);
                    } 
                }
            }      
        }
        if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
        {
            fprintf(stderr, "%s", "resetting failed\n"); 
            globalBad = 5;
            exit(1); 
        }
        exit(0); 
    }


  else if (shellBool == 5) 
  {
    struct pollfd poles[2];
    int pollReturn;
    poles[0].fd = 0; 
    poles[1].fd = pipeOutShell[0];
    poles[0].events = POLLIN | POLLHUP | POLLERR; 
    poles[1].events = POLLIN | POLLHUP | POLLERR; 
    while (1) 
    {
        pollReturn = poll(poles, 2, 0);
	    if( pollReturn < 0 )
        {
            fprintf(stderr, "%s", "error using poll \n"); 
            if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
            {
                fprintf(stderr, "%s", "resetting failed\n"); 
                globalBad = 5; 
                exit(1); 
            }
            globalBad = 5; 
            exit(1); 
        }
        else 
        {
            
            if (poles[0].revents & POLLIN) 
            {
                char buff[8]; 
                int amtRead = read(0, buff, 8); 
                for (int i = 0; i < amtRead; i++)
                {
                    char c = buff[i]; 
                    if (c == '\003')
                    {
                        if ( write(1, "^C", 2) < 0 ) 
                        {
                            fprintf(stderr, "%s", "^C failed\n"); 
                            globalBad = 5;
                            exit(1);
                        }
                        // globalBad = 5; 
                        kill(childPID, SIGINT); 
                        // exit(0);
                    }
                    if (c == '\004')
                    {
                        if ( write(1, "^D", 2) < 0 ) 
                        {
                            fprintf(stderr, "%s", "^D failed\n"); 
                            globalBad = 5;
                            exit(1);
                        }
                        close(pipeToShell[1]); 
                        // int childStatus; 
                        // if (waitpid(childPID, &childStatus, 0) < 0)
                        // {
                        //     fprintf(stderr, "%s", "Waitpid Error\r\n"); 
                        // }
                        // int exitSignal = childStatus&0x007f; 
                        // // int exitStatus = (childStatus&0xff00) >> 8; 
                        // fprintf(stderr, "SHELL EXIT SIGNAL=%i STATUS=%i", exitSignal, WEXITSTATUS(childStatus)); 
                        // if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
                        // {
                        //     fprintf(stderr, "%s", "resetting failed\n"); 
                        //     exit(1); 
                        // }
                        // exit(0);  
                    } 
                    else if (c == 0x0D || c == 0x0A) //enter
                    { 
                        if ( write(pipeToShell[1], "\n", 1) < 0 )
                        {
                            fprintf(stderr, "%s", "enter failed\n"); 
                            globalBad = 5; 
                            exit(1);
                        } 
                        //stdout
                        if ( write(1, "\r\n", 2) < 0 )
                        {
                            fprintf(stderr, "%s", "enter failed\n"); 
                            globalBad = 5; 
                            exit(1);
                        }  
                    }
                    else
                    {
                        if ( write(pipeToShell[1], &c, 1) < 0 )
                        {
                            fprintf(stderr, "%s", "my echoing failed\n"); 
                            globalBad = 5;
                            exit(1); 
                        }
                        if ( write(1, &c, 1) < 0 )
                        {
                            fprintf(stderr, "%s", "my echoing failed\n"); 
                            globalBad = 5; 
                            exit(1); 
                        } 
                    }
                } 
            } // end if poles[0] POLLIN
            if ((poles[1].revents&POLLIN) == POLLIN)
            {
                char buff[8]; 
                int amtRead = read(pipeOutShell[0], buff, 8); 
                for (int i = 0; i < amtRead; i++)
                {
                    char c = buff[i]; 
                    if (c == '\004')
                    {
                        if ( write(1, "^D", 2) < 0 ) 
                        {
                            fprintf(stderr, "%s", "^D failed\n"); 
                            globalBad = 5;
                            exit(1);
                        }

                        // ^ potentailly put this back in 


                        // int childStatus; 
                        // if (waitpid(childPID, &childStatus, 0) < 0)
                        // {
                        //     fprintf(stderr, "%s", "Waitpid Error\n\r"); 
                        // }
                        // int exitSignal = childStatus&0x007f; 
                        // // int exitStatus = (childStatus&0xff00) >> 8; 
                        // fprintf(stderr, "SHELL EXIT SIGNAL=%i STATUS=%i", exitSignal, WEXITSTATUS(childStatus));  
                        // if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
                        // {
                        //     fprintf(stderr, "%s", "resetting failed\n"); 
                        //     exit(1); 
                        // }
                        exit(0);  
                    }
                    else if (c == 0x0D || c == 0x0A) //enter
                    {
                        if ( write(1, "\r\n", 2) < 0 )
                        {
                            fprintf(stderr, "%s", "enter failed\n"); 
                            globalBad = 5; 
                            exit(1);
                        }  
                    }
                    else
                    {
                        if ( write(1, &c, 1) < 0 )
                        {
                            fprintf(stderr, "%s", "my echoing failed\n"); 
                            globalBad = 5; 
                            exit(1); 
                        } 
                    }
                }
            } // if (fds[1].revents & POLLIN)



            if (poles[0].revents & POLLHUP) 
            {
                if (debugBool == 5)
                    fprintf(stderr, "%s", "POLLHUP occurred in main terminal. \n\r"); 
                exit(0); 
            }
            if (poles[1].revents & POLLHUP) 
            {
                if (debugBool == 5)
                    fprintf(stderr, "%s", "POLLHUP occurred in shell terminal. \n\r"); 
                exit(0); 
            }
            if (poles[0].revents & POLLERR) 
            {
                if (debugBool == 5)
                    fprintf(stderr, "Poll error from main terminal. \n\r"); 
                exit(0);
            }
            if (poles[1].revents & POLLERR) 
            {
                if (debugBool == 5)
                    fprintf(stderr, "Poll error from shell.\n\r"); 
                exit(0);
            }
        } 
        //end of else block

    }    
  } // end of shellBool == 5

    if (debugBool == 5)
    {
        fprintf(stderr, "%s", "debug argument called\n\r");  
    }
    // resetting
    if (tcsetattr(0, TCSANOW, &ogTerm) != 0)
    {
        fprintf(stderr, "%s", "resetting failed\n"); 
        globalBad = 5; 
        exit(1); 
    }
    exit(0); 
}

void errorHandler(int sigNum) 
{
    if (sigNum == SIGPIPE)
    {
        fprintf(stderr, "%s", "Caught sigpipe");  
        exit(0); 
    }
}