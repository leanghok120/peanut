#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5050

int sockfd;

void sendfile(int fd, const char *path) {
  char buf[1024];
  char p[1024];
  snprintf(p, sizeof(p), "/var/peanut/%s", path);

  FILE *peanutmap = fopen(p, "r");
  if (peanutmap == NULL) {
    snprintf(buf, sizeof(buf), "page not found!\n");
    write(fd, buf, strlen(buf));
    close(fd);
    return;
  }

  while ((fgets(buf, sizeof(buf), peanutmap)) != NULL) {
    write(fd, buf, strlen(buf));
  }
  fclose(peanutmap);
}

void handle_con(int fd) {
  char buf[1024];
  int n = read(fd, buf, sizeof(buf) - 1);
  if (n <= 0) {
    close(fd);
    return;
  }
  buf[n] = '\0';
  buf[strcspn(buf, "\n")] = '\0';
  printf("%s\n", buf);

  if (strcmp(buf, "/") == 0 || strcmp(buf, "") == 0) {
    sendfile(fd, "peanutmap");
  } else {
    sendfile(fd, buf);
  }

  close(fd);
}

void init() {
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in addr = {
    .sin_family = AF_INET,
    .sin_port = htons(PORT),
    .sin_addr = inet_addr("127.0.0.1")
  };

  int err = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (err == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  err = listen(sockfd, 5);
  if (err == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

}

void loop() {
  while (1) {
    int fd = accept(sockfd, NULL, NULL);
    if (fd == -1) {
      perror("accept");
      break;
    }

    handle_con(fd);
  }
}

int main(int argc, char **argv) {
  init();
  loop();
  close(sockfd);

  return 0;
}
