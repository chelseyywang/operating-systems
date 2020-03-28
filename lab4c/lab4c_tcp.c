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
#include <strings.h>
#include <mraa/gpio.h>
#include <mraa/aio.h>
#include <signal.h>
#include <math.h>
#include <time.h>
#include <stropts.h>
#include <poll.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>

// globals
int fd = 1; 
int timeout = 1000;
int id = 0;
char host[50]; 
const int B = 4275; 
const int R0 = 100; 
int bbywereadin = 1; 
int startBool = 1; 
int sockfd; 
int connectfd; 
int portNum; 
char tempBuff[50] = {0};
int size = 0; 
int logBool = 0; 
int hostBool = 0; 
int idBool = 0; 

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
		printf("%d:%d:0%d", hour2, min2, sec2);						
        printf(" SHUTDOWN\n");
	}										
    else
	{
		printf("%d:%d:%d", hour2, min2, sec2);
		printf(" SHUTDOWN\n");
	}
	exit(0);
}

int main(int argc, char** argv)
{
    // time
    struct timeval firstTime; 
    struct timeval secTime; 
    //getpot declarations
    int c; 
    int structIndex; 
    int cBool = 0; 
    static struct option options[] = {
        {"id", required_argument, NULL, 1}, 
        {"host", required_argument, NULL, 2}, 
        {"log", required_argument, NULL, 3},
        {"period", required_argument, NULL, 5},
        {"scale", required_argument, NULL, 6},
        {0,0,0,0}
    };
    while ((c = getopt_long(argc, argv, "", options, &structIndex))!=-1)
    {
        //returns val, the single char, if flag is null 
        //optarg holds the string argument 
        switch (c) {
            case 1:  
                idBool = 1; 
                if (strlen(optarg) != 9) 
                {
                    fprintf(stderr, "ID must have 9 digits. \n"); 
                    exit(1); 
                }
                id = atoi(optarg);
                char strid[12]; 
                sprintf(strid, "%d", id);
                if (strlen(strid) != 9) 
                {
                    fprintf(stderr, "ID must have 9 digits. \n"); 
                    exit(1); 
                }
                break; 
            case 2: 
                hostBool = 1; 
                bzero(host, 50); 
                strcpy(host, optarg);
                break; 
            case 3: 
                // int fd; 
                logBool = 1; 
                fd = open(optarg, O_CREAT | O_WRONLY, 0666); 
                if (fd == -1)
                {
                    if (startBool == 1)
                        fprintf(stderr, "Error with argument --log, file %s, due to: %s\n", optarg, strerror(errno)); 
                    exit(1); 
                }
                // close(1); 
                // dup(fd); 
                // close(fd);
                break;
            case 5:
                // periodBool = 1;
                timeout = (1000*atoi(optarg));
                break;
            case 6:
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
                    exit(1); 
                }
                
                break;
            default: 
                fprintf(stderr, "%s", "Incorrect or extra arguments; use --period, --scale=F or C, --log=filename\n"); 
                exit(1); 
        }//end of switch 
    }//end of getpote while loop
    //end getpot
    if (logBool == 0)
    {
        fprintf(stderr, "Please supply --log= argument. \n"); 
        exit(1); 
    }
    if (hostBool == 0)
    {
        fprintf(stderr, "Please supply a --host= argument. \n"); 
        exit(1); 
    }
    if (idBool == 0)
    {
        fprintf(stderr, "Please supply a --id= argument. \n"); 
        exit(1); 
    }
    int portErr = 0; 
    int i; 
    for (i = optind; i < argc; i++)
    {
        if (portErr > 0)
        {
            fprintf(stderr, "Only supply one port number\n"); 
            exit(1); 
        }
        // printf ("Non-option argument %s\n", argv[i]);
        unsigned int j; 
        for (j = 0; j < strlen(argv[i]); j++)
        {
            // printf("%s", "char: "); 
            // printf("%c\n", argv[i][j]); 
            if (argv[i][j] < '0' || argv[i][j] > '9')
            {
                fprintf(stderr, "port must be all digits. \n"); 
                exit(1); 
            } 
        }
        //memcpy(portNum, argv[i], strlen(argv[i]));
        portNum = atoi(argv[i]);  
        portErr++; 

    }
    if (portErr != 1)
    {
        fprintf(stderr, "Port number provided incorrectly. \n");
        exit(1); 
    }

    // printf("ID=%d\n", id); 
     //printf("host: %s\n", host); 
    // printf("port: %d\n", portNum); 

    // declaring temp schtuff
    float tempValue; 
	float R, temperature; 
    // beaglebone stuff
    mraa_aio_context temp; 
    mraa_init(); 
    temp = mraa_aio_init(1);

    //char buffer[256];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    // fprintf(stderr, "called socket\n"); 
    if (sockfd < 0)
    {
        fprintf(stderr, "Error opening socket \n"); 
        exit(1); 
    }
    server = gethostbyname(host);
        // printf("got server\n"); 

    if (server == NULL) {
        fprintf(stderr,"Error getting host\n");
        exit(2);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portNum);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    {
        fprintf(stderr, "Error connecting\n");
        exit(2);
    }
        
    // fprintf(stderr, "connected\n"); 

    // printf("Please enter the message: ");
    // bzero(buffer,256);
    // fgets(buffer,255,stdin);
    // int n = write(sockfd,buffer,strlen(buffer));
    // if (n < 0) 
    //      fprintf(stderr, "Error writing to socket\n");
    // bzero(buffer,256);
    // n = read(sockfd,buffer,255);
    // if (n < 0) 
    //      fprintf(stderr, "Error reading from socket\n");
    // printf("%s\n",buffer);
    


    size = 0; 
    bzero(tempBuff, 50); 
    size = sprintf(tempBuff,"ID=%d\n", id);
    write(sockfd, tempBuff, size); 
    write(fd, tempBuff, size);
    // pool stfuf
    struct pollfd fds[1];
    
    int ret;
    fds[0].fd = sockfd; //stdin
    fds[0].events = POLLHUP | POLLERR | POLLIN;
    
    //DELTETEETETETETETTE
    gettimeofday(&firstTime, NULL); 
    secTime.tv_sec = 0; 
    while(1)
    {
        gettimeofday(&firstTime, NULL); 
        time_t rawtime;
        struct tm *timeStruct;
        time(&rawtime); 
        timeStruct = localtime(&rawtime);
        int hour = timeStruct->tm_hour; 
        int min = timeStruct->tm_min; 
        int sec = timeStruct->tm_sec; 
        if (startBool == 1 && (firstTime.tv_sec >= secTime.tv_sec + (timeout/1000)))
        {
            // writing tempBufferature
            // time_t rawtime;
            // struct tm *timeStruct;
            // time(&rawtime); 
            // timeStruct = localtime(&rawtime);
            // int hour = timeStruct->tm_hour; 
            // int min = timeStruct->tm_min; 
            // int sec = timeStruct->tm_sec; 
            tempValue = mraa_aio_read(temp);
            R = 1023.0/((float)tempValue)-1.0; 
            R = 100000.0*R; 
            //float temp = log(R/100000.0); 
            temperature = 1.0/(log(R/100000.0)/B+1/298.15)-273.15; 
            if (cBool == 1)
            {
                if (startBool == 1)
                {

                    size = 0; 
                    bzero(tempBuff, 50); 
                    size = sprintf(tempBuff,"%02d:%02d:%02d %0.1f\n", hour, min, sec, temperature);
                    write(sockfd, tempBuff, size); 
                    write(fd, tempBuff, size);
                    bzero(tempBuff, 50); 


                    // size = 0; 
                    // bzero(tempBuff, 50); 
                    // size = sprintf(tempBuff," ", temperature);
                    // write(sockfd, tempBuff, size); 
                    // bzero(tempBuff, 50); 
                }
                    // printf(" %0.1f\n", tempBufferature);
            }
            else
            {
                temperature = temperature*1.8000+32.00; 
                if (startBool == 1)
                {
                    size = 0; 
                    bzero(tempBuff, 50); 
                    size = sprintf(tempBuff,"%02d:%02d:%02d %0.1f\n", hour, min, sec, temperature);
                    write(sockfd, tempBuff, size); 
                    write(fd, tempBuff, size);
                    bzero(tempBuff, 50); 
                }
            }
            
            secTime = firstTime; 
        }

        //DELETE
        // pole time baby
        ret = poll(fds, 1, timeout);
        if (ret < 0)
        {
         //   if (startBool == 1)
            fprintf(stderr, "error with poll occurred \n"); 
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
                    read(sockfd, &c, 1); 
                    collect[collectIndex] = c; 
                    collectIndex++; 
                    if (c == '\n')
                    {
                        // if(fd != 1){
                        //     size = 0; 
                        //     bzero(tempBuff, 50); 
                        //     size = sprintf(tempBuff,"%s", analyze);
                        //     write(sockfd, tempBuff, size); 
                        //     bzero(tempBuff, 50);
                        // }
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
                            // printf("!!! this is amt: %d !!!\n", (1000*atoi(intBuff))); 
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
                            size = 0; 
                            bzero(tempBuff, 50); 
                            size = sprintf(tempBuff,"%s", analyze);
                            write(fd, tempBuff, size); 
                            //printf("%s", analyze); 
                            bzero(analyze, 256);
                            startBool = 0; 
                        }
                        else if(strcmp(analyze, "OFF\n") == 0)
                        {
                            size = 0; 
                            bzero(tempBuff, 50); 
                            size = sprintf(tempBuff,"%s", analyze);
                            // if (startBool == 1)
                                write(fd, tempBuff, size); 
                            // write(sockfd, tempBuff, size); 
                            bzero(tempBuff, 50);
                            size = 0;  
                            size = sprintf(tempBuff,"%02d:%02d:%02d SHUTDOWN\n", hour, min, sec);
                            // write(sockfd, tempBuff, size); 
                            // if (startBool == 1)
                                write(fd, tempBuff, size); 
                            // bzero(tempBuff, 50); 
                            // size = 0; 
                            
                            //printf("%s", analyze); 
                            bzero(analyze, 256);
                            exit(0);  
                        }
                        // write to output 
                        if (startBool == 1)
                        {
                            size = 0; 
                            bzero(tempBuff, 50); 
                            size = sprintf(tempBuff,"%s", analyze);
                            write(fd, tempBuff, size); 
                            //printf("%s", analyze); 
                            bzero(analyze, 256);
                        }
                        
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




    mraa_aio_close(temp); 
    exit(0); 
   
}
