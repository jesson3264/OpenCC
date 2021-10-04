/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 邓俊兴 (Deng Junxing)
 * Email : jesson3264@163.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#define CLIENTSIZE 50
#define BUFFERSIZE 512

char ch_char(char c) {
	if(c >= 'a' && c <= 'z') 
		return c - 32;
	return c;
}

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, " usage :%s port !\n", argv[0]);
		exit(1);
	}
	int server_listen, sockfd, max_fd;
	int client[CLIENTSIZE] = {0};
	memset(client, -1, sizeof(client));
	if ((server_listen = socket_create(argv[1])) < 0) 
	{
		perror("socket_create");
		exit(1);
	}
	make_nonblock(server_listen);//转换为非阻塞状态
	fd_set rfds, wfds, efds;
	max_fd = server_listen;

	int i = 0;
	while (1) {
		FD_ZERO(&rfds);
		FD_ZERO(&wfds);
		FD_ZERO(&efds);

		FD_SET(server_listen, &rfds);

		for(i = 0 ; i < CLIENTSIZE; i++){
			if(client[i] == server_listen){
				continue;
			}
			if(client[i] > 0) {//有效的文件描述符
				if(max_fd < client[i]) max_fd = client[i];
				FD_SET(client[i], &rfds);
			}
		}

		if(select(max_fd + 1, &rfds, NULL, NULL, NULL) < 0){
			perror("select");
			return 1;
		}

		if(FD_ISSET(server_listen, &rfds)) {
			printf("connect ready on server_listen!\n");
			if((sockfd = accept(server_listen, NULL, NULL)) < 0){
				perror("accept");
				return 1;
			}
			if(sockfd > CLIENTSIZE){
				printf("too many clients!\n");
				close(sockfd);
			}else{
				make_nonblock(sockfd);
				if(client[sockfd] == -1)
					client[sockfd] = sockfd;
			}
		}

		for(i = 0; i < CLIENTSIZE; i++) {
			if(i == server_listen) continue;
			if(FD_ISSET(i, &rfds)) {
				char buffer[BUFFERSIZE] = {0};
				int retval = recv(i ,buffer, BUFFERSIZE, 0);
				if(retval <= 0){
					printf("logout!\n");
					client[i] = -1;
					close(1);
					continue;
				}
				printf("recev : %s", buffer);
				int j = 0;
				for(j = 0; j < strlen(buffer); j++) {
					buffer[j] = ch_char(buffer[j]);
				}
				send(i, buffer, strlen(buffer), 0);
			}
		}
	}

	return 0;
}

