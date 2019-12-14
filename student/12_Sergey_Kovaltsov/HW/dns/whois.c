#include "whois.h"
#include "regexp.h"

void check_whoice(char* ip) {
    char *data = NULL;

    get_whois(ip , &data);

    const char * regex_text;
    regex_text = "OrgName:.*\n";
    regexp(regex_text, data);
    regex_text = "Country:.*\n";
    regexp(regex_text, data);
    regex_text = "OrgTechPhone:.*\n";
    regexp(regex_text, data);
    regex_text = "RegDate:.*\n";
    regexp(regex_text, data);
    regex_text = "Updated:.*\n";
    regexp(regex_text, data);

    free(data);
}

void get_whois(char *ip , char **data)
{
    char *wch = NULL, *pch , *response = NULL;

    whois_query("whois.iana.org" , ip , &response);

    pch = strtok(response , "\n");

    while(pch != NULL)
    {
        //Check if whois line
        wch = strstr(pch , "whois.");
        if(wch != NULL)
        {
            break;
        }

        //Next line please
        pch = strtok(NULL , "\n");
    }

    if (wch != NULL) whois_query(wch , ip , data);
    else {
        *data = malloc(100);
        strcpy(*data , "No whois data");
    }

    }

int whois_query(char *server , char *query , char **response)
{
    char ip[32] , message[100] , buffer[1500];
    int sock , read_size , total_size = 0;
    struct sockaddr_in dest;

    sock = socket(AF_INET , SOCK_STREAM , IPPROTO_TCP);

    //Prepare connection structures :)
    memset( &dest , 0 , sizeof(dest) );
    dest.sin_family = AF_INET;

    hostname_to_ip(server , ip);
    dest.sin_addr.s_addr = inet_addr( ip );
    dest.sin_port = htons( 43 );

    //Now connect to remote server
    connect( sock , (const struct sockaddr*) &dest , sizeof(dest) );

    //Now send some data or message
    sprintf(message , "%s\r\n" , query);
    send(sock , message , strlen(message) , 0);

    //Now receive the response
    while( (read_size = recv(sock , buffer , sizeof(buffer) , 0) ) )
    {
        *response = realloc(*response , read_size + total_size);
        memcpy(*response + total_size , buffer , read_size);
        total_size += read_size;
    }
    fflush(stdout);

    *response = realloc(*response , total_size + 1);
    *(*response + total_size) = '&#92;&#48;';

    close(sock);
    return 0;
}

int hostname_to_ip(char * hostname , char* ip) {
    struct hostent *he;
    struct in_addr **addr_list;
    int i;

    if ((he = gethostbyname(hostname)) == NULL) {
        // get the host info
        herror("gethostbyname ");
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    for (i = 0; addr_list[i] != NULL; i++) {
        //Return the first one;
        strcpy(ip, inet_ntoa(*addr_list[i]));
        return 0;
    }

    return 0;
}
