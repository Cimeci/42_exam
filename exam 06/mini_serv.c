#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>

int sockfd = -1, max_fd = -1, next_id = 0;
int clients[1024];
char *buffer[1024];
fd_set read_fds, write_fds, all_fds;

int extract_message(char **buf, char **msg) {
    char    *newbuf;
    int    i;

    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
            if (newbuf == 0)
                return (-1);
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = newbuf;
            return (1);
        }
        i++;
    }
    return (0);
}

char *str_join(char *buf, char *add) {
    char    *newbuf;
    int        len;

    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0)
        return (0);
    newbuf[0] = 0;
    if (buf != 0)
        strcat(newbuf, buf);
    free(buf);
    strcat(newbuf, add);
    return (newbuf);
}

int error_exit(char *msg) {
    write(2, msg, strlen(msg));
    if (sockfd > 0) close(sockfd);
    exit(1);
}

void send_all(int sender, char *msg) {
    for (int i = 0; i <= max_fd; i++)
        if (FD_ISSET(i, &write_fds) && i != sender)
            send(i, msg, strlen(msg), 0);
}

void new_client(int fd) {
    clients[fd] = next_id++;
    FD_SET(fd, &all_fds);
    if (fd > max_fd) max_fd = fd;
    char msg[64] = {0};
    sprintf(msg, "server: client %d just arrived\n", clients[fd]);
    send_all(fd, msg);
}

void rm_client(int fd) {
    char msg[64] = {0};
    sprintf(msg, "server: client %d just left\n", clients[fd]);
    send_all(fd, msg);
    free(buffer[fd]);
    buffer[fd] = 0;
    FD_CLR(fd, &all_fds);
    close(fd);
}

int read_client(int fd) {
    char tmp[5120]; int bytes;
    if ((bytes = recv(fd, tmp, 5120, 0)) <= 0)
        return (rm_client(fd), 0);
    tmp[bytes] = 0;
    buffer[fd] = str_join(buffer[fd], tmp);
    char *msg, *line;
    while (extract_message(&buffer[fd], &line)) {
        msg = malloc(strlen(line) + 30);
        sprintf(msg, "client %d: %s", clients[fd], line);
        send_all(fd, msg);
        free(msg); free(line);
    }
    return 1;
}

int main(int ac, char **av) {
    if (ac != 2) {
        error_exit("Wrong number of arguments\n");
    }

    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    bzero(&addr, len);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(2130706433);
    addr.sin_port = htons(atoi(av[1]));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) error_exit("Fatal error\n");
    if (bind(sockfd, (struct sockaddr *)&addr, len))
        error_exit("Fatal error\n");
    if (listen(sockfd, 128) < 0)
        error_exit("Fatal error\n");
    
    FD_ZERO(&all_fds);
    FD_SET(sockfd, &all_fds);
    max_fd = sockfd;

    while (1) {
        read_fds = write_fds = all_fds;
        if (select(max_fd + 1, &read_fds, &write_fds, 0, 0) <= 0)
            continue;
        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &read_fds)) {
                if (fd == sockfd) {
                    int client_fd = accept(sockfd, (struct sockaddr *)&addr, &len);
                    if (client_fd >= 0) new_client(client_fd);
                } else {
                    if (!read_client(fd)) break;
                }        
            }
        }
    }
}