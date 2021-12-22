#include <stdio.h>
#include <stdlib.h>
//#define  _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#define    BUF_SIZE     1024

int main(int argc, char *argv[])
{
  int sockfd; // ���ݳs�u�� socket id
  int new_fd; // �s�����s�u��s��socket id
  struct sockaddr_in my_addr; //�s���A�����a��IP��port
  struct sockaddr_in client_addr; //�s�w�g�s�u��client ��IP��port
  char buf[BUF_SIZE];
  int retVal;
  int sin_size;
  WSADATA wsd;
  char  *client_IP;

  retVal = WSAStartup(MAKEWORD(2,2),&wsd);
  if (retVal != 0)
  {
    printf("Winsock Startup failed!\n");
    getchar(); //�������q�i�[���ԭz
    return -1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sockfd == -1)
  {
    printf("Socket() failed!\n");
    WSACleanup();
    getchar();
    return -1;
  }
  my_addr.sin_family = AF_INET;
  my_addr.sin_addr.s_addr = htonl(INADDR_ANY); //���ݳs�u�������d = ����
  my_addr.sin_port = htons((short)7);
  sin_size = sizeof(my_addr);
  retVal = bind(sockfd, (struct sockaddr *) &my_addr, sin_size);
  if (retVal == -1)
  {
    printf("Binding failed !\n"); //�Q�@�Qԣ���p�|�j�w���ѡH
    closesocket(sockfd);
    WSACleanup();
    getchar();   
    return - 1;
  }

  retVal = listen(sockfd, 10);
  if (retVal == -1)
  {
    printf("Listening failed!\n"); //�Q�@�Qԣ���p�|�i�J��ť���ѡH
    closesocket(sockfd);
    WSACleanup();
    getchar();
    return -1;
  }
  printf("Server is running .....\n");
  while (1)
  {
    new_fd = accept(sockfd, (struct sockaddr *) &client_addr, &sin_size);
	if (new_fd == -1)
	{
      printf("Accepting failed!\n");
       continue;
	}
	client_IP =inet_ntoa(client_addr.sin_addr);
	printf("Client: %s is connected\n", client_IP);
    memset(buf, 0, BUF_SIZE);
    retVal=recv(new_fd, buf, BUF_SIZE, 0);
	if (retVal <= 0)
	{
        printf("recv error: close connection!\n");
        closesocket(new_fd);
	}
    buf[retVal] = '\0';
    printf("received: %s\n",buf);
	retVal=send(new_fd, buf, strlen(buf), 0);
	if (retVal <= 0)
	{
		printf("send error: close connection!\n");
		closesocket(new_fd);
	}
	closesocket(new_fd);
  }
return 0;
}