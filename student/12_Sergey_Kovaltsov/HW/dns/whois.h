#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>

void check_whoice();
void get_whois(char *ip , char **data);  //Get the whois content of an ip by selecting the correct server
int whois_query(char *server , char *query , char **response);  // Perform a whois query to a server and record the response
int hostname_to_ip(char * hostname , char* ip);  // Get the ip address of a given hostname
