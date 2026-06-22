#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key = ftok("msgqfile",65);

    int msgid = msgget(key, IPC_CREAT | 0666);

    struct message msg;

    msg.msg_type = 1;

    strcpy(msg.msg_text,"Hello, message queue!");

    msgsnd(msgid,&msg,sizeof(msg.msg_text),0);

    printf("Producer: %s\n",msg.msg_text);

    msgrcv(msgid,&msg,sizeof(msg.msg_text),1,0);

    printf("Consumer: %s\n",msg.msg_text);

    msgctl(msgid,IPC_RMID,NULL);

    return 0;
}
