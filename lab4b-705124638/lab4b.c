// Chelsey Wang
// chelseyyywang@gmail.com
// 705124638

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mraa/gpio.h>
#include <mraa/aio.h>
#include <signal.h>
#include <math.h>
#include <time.h>
#include <stropts.h>
#include <poll.h>

// globals
int fd; 
int timeout = 1000;
const int B = 4275; 
const int R0 = 100; 
int bbywereadin = 1; 
int startBool = 1; 

sig_atomic_t volatile run = 1; 

void interruptFunc()
{
	time_t rawtime2; 
	struct tm *timeStruct2; 
	time(&rawtime2);
	timeStruct2 = localtime(&rawtime2); 
	int hour2 = timeStruct2->tm_hour; 
	int min2 = timeStruct2->tm_min; 
	int sec2 = timeStruct2->tm_sec; 
	//printf("Button pressed; exiting. \n");
	if (sec2 < 10)                                       
	{
		printf("%i:%i:0%i", hour2, min2, sec2);						printf(" SHUTDOWN\n");
	}										else
	{
		printf("%i:%i:%i", hour2, min2, sec2);
		printf(" SHUTDOWN\n");
	}
	exit(0);
}

int main(int argc, char** argv)
{
    //getpot declarations
    int c; 
    int structIndex; 
    // int periodBool = 0; 
    // int scaleBool = 0; 
    // int period = 1; 
    int cBool = 0; 
    // int fBool = 1; 
    static struct option options[] = {
        {"period", required_argument, NULL, 1}, 
        {"scale", required_argument, NULL, 2}, 
        {"log", required_argument, NULL, 3},
        {0,0,0,0}
    };
    while ((c = getopt_long(argc, argv, "", options, &structIndex))!=-1)
    {
        //returns val, the single char, if flag is null 
        //optarg holds the string argument 
        switch (c) {
            case 1: 
                // periodBool = 1; 
                timeout = (1000*atoi(optarg)); 
                break; 
            case 2: 
                // scaleBool = 1; 
                if (optarg[0]== 'C' && optarg[1] == '\0')
                {
                    cBool = 1; 
                    // fBool = 0; 
                }
                else if (optarg[0] == 'F' && optarg[1] == '\0')
                {
                    cBool = 0; 
                    // fBool = 1; 
                }
                else
                {
                    // if (startBool == 1)
                        printf("--scale only accepts --scale=C or --scale=F\n"); 
                }
                
                break; 
            case 3: 
                // int fd; 
                fd = open(optarg, O_CREAT | O_WRONLY, 0666); 
                if (fd == -1)
                {
                    if (startBool == 1)
                        fprintf(stderr, "Error with argument --log, file %s, due to: %s\n", optarg, strerror(errno)); 
                    exit(1); 
                }
                close(1); 
                dup(fd); 
                close(fd);
                break; 
            default: 
                //if (startBool == 1)
                    fprintf(stderr, "%s", "Incorrect or extra arguments; use --period, --scale=F or C, --log=filename\n"); 
                exit(1); 
        }//end of switch 
    }//end of getpote while loop
    //end getpot

    // declaring temp schtuff
    float tempValue; 
	float R, temperature; 
    // beaglebone stuff
    mraa_aio_context temp; 
    mraa_gpio_context button;
    mraa_init(); 
    temp = mraa_aio_init(1);
    button = mraa_gpio_init(60); 
	mraa_gpio_dir(button, MRAA_GPIO_IN); 
    mraa_gpio_isr(button, MRAA_GPIO_EDGE_RISING, &interruptFunc, NULL);
   


    // pool stfuf
    struct pollfd fds[1];
    
    int ret;
    fds[0].fd = 0; //stdin
    fds[0].events = POLLHUP | POLLERR | POLLIN;
    while(1)
    {
        // writing temperature
        time_t rawtime;
        struct tm *timeStruct;
        time(&rawtime); 
        timeStruct = localtime(&rawtime);
        int hour = timeStruct->tm_hour; 
        int min = timeStruct->tm_min; 
        int sec = timeStruct->tm_sec; 
        if (sec < 10)
        {
            if (startBool == 1)
                printf("%i:%i:0%i", hour, min, sec); 
        }  
        else
        {
            if (startBool == 1)
                printf("%i:%i:%i", hour, min, sec); 
        }
        
        tempValue = mraa_aio_read(temp);
        R = 1023.0/((float)tempValue)-1.0; 
        R = 100000.0*R; 
        //float temp = log(R/100000.0); 
        temperature = 1.0/(log(R/100000.0)/B+1/298.15)-273.15; 
        if (cBool == 1)
        {
            if (startBool == 1)
                printf(" %0.1f\n", temperature);
        }
        else
        {
            temperature = temperature*1.8000+32.00; 
            if (startBool == 1)
                printf(" %0.1f\n", temperature);
        }
        // pole time baby
        ret = poll(fds, 1, timeout);
        if (ret < 0)
        {
         //   if (startBool == 1)
                printf("error with poll occurred \n"); 
            exit(1); 
        }
        else
        {
            if (fds[0].revents == POLLIN)
            {
                // printf("polling on stdin\n"); 
                // STIN STUFF
                char collect[256]; 
                bzero(collect, 256); 
                int collectIndex = 0; 
                char analyze[256]; 
                bzero(analyze, 256); 
                int analyzeSize = 0; 
                while(1)
                {
                    char c; 
                    read(0, &c, 1); 
                    collect[collectIndex] = c; 
                    collectIndex++; 
                    if (c == '\n')
                    {
                        memcpy(analyze, collect, collectIndex); 
                        bzero(collect, 256); 
                        analyzeSize = collectIndex; 
                        collectIndex = 0; 
                        if (strcmp(analyze, "SCALE=F\n") == 0)
                        {
                            // printf("!!! fBool 1 !!!\n"); 
                            // fBool = 1; 
                            cBool = 0; 
                        }
                        else if (strcmp(analyze, "SCALE=C\n") == 0)
                        {
                            // printf("!!! cBool 1 !!!\n"); 
                            cBool = 1; 
                            // fBool = 0; 
                        }
                        else if (analyze[0] == 'P' && analyze[1] == 'E' && analyze[2] == 'R'
                        && analyze[3] == 'I' && analyze[4] == 'O' && analyze[5] == 'D' && analyze[6] == '=')
                        {
                            // printf("!!! period. !!!\n"); 
                            char intBuff[256]; 
                            bzero(intBuff, 256); 
                            int intBuffIndex = 0; 
                            int i = 0; 
                            for (i = 7; i < analyzeSize; i++)
                            {
                                intBuff[intBuffIndex] = analyze[i]; 
                                intBuffIndex++; 
                            }
                            // printf("!!! this is amt: %i !!!\n", (1000*atoi(intBuff))); 
                            timeout = 1000*atoi(intBuff); 
                            bzero(intBuff, 256); 
                            intBuffIndex = 0;
                        }
                        else if(strcmp(analyze, "START\n") == 0)
                        {
                            // printf("!!!modify start bool!!!\n"); 
                            startBool = 1; 
                        }
                        else if(strcmp(analyze, "STOP\n") == 0)
                        {
                            // printf("!!!HUHUH!!!\n"); 
                            //printf("STOP\n"); 
                            startBool = 0; 
                        }
                        else if(strcmp(analyze, "OFF\n") == 0)
                        {
                           printf("OFF\n"); 
			   if (sec < 10)
                            {
                                printf("%i:%i:0%i", hour, min, sec); 
                                printf(" SHUTDOWN\n"); 
                            }  
                            else
                            {
                                printf("%i:%i:%i", hour, min, sec); 
                                printf(" SHUTDOWN\n"); 
                            }
                            exit(0);  
                        }
                        // write to output 
                        //if (startBool == 1)
                            printf("%s", analyze); 
                        bzero(analyze, 256);
                        break; 
                    }// end of if \n
                }//end of read while loop
            }// end of (fds[0].revents == POLLIN)
	    if (fds[0].revents == POLLERR || fds[0].revents == POLLHUP)
	    {
	    	fprintf(stderr, "Poll error\n"); 
		exit(1); 
	    }
            // printf("got out of if statement\n"); 
        }// end of else 
    }// end MAIN while loop
    

   
 mraa_gpio_close(button); 
 mraa_aio_close(temp); 
 exit(0); 
}
