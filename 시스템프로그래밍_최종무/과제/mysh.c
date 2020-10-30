/*Simple shell,Sehyun Lim(tpgus0510@naver.com)*/
/*System programming 'make shell' assignment*/
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define MAX_BUF 64
typedef struct _COMMAND{
	char*name;
	char*info;
	bool (*func)(int argc,char*argv[]);
}COMMAND;

bool cmd_cd(int argc,char*argv[]);
bool cmd_exit(int argc,char*argv[]);
bool cmd_help(int argc,char*argv[]);

COMMAND builtin_cmd[] =
{
	{"cd", "디렉토리 변경",cmd_cd},
	{"exit","쉘 종료",cmd_exit},
	{"help","도움말 출력",cmd_help},
};
bool cmd_cd(int argc,char*argv[]){
	if(argc==1)
		chdir(getenv("HOME"));
	else if(argc == 2){
		if(chdir(argv[1]))
			printf("디렉토리가 존재하지 않음\n");
	}
	else
		printf("커맨드를 정확히 입력해주세요\n");
	return true;
}
bool cmd_exit(int argc,char*argv[]){
	return false;
}
bool cmd_help(int argc,char*argv[]){
	int i;
	for(i =0; i<sizeof(builtin_cmd)/sizeof(COMMAND);i++){
		if(argc ==1||strcmp(builtin_cmd[i].name,argv[1])==0)
			printf("%-10s: %s\n",builtin_cmd[i].name,builtin_cmd[i].info);
	}
	return true;
}

int tokenize(char*buf,char*delims,char*tokens[],int maxTokens){
	int token_count = 0;
	char*token;
	token = strtok(buf, delims);
	while(token != NULL && token_count < maxTokens){
		tokens[token_count] = token;
		token_count++;
		token = strtok(NULL,delims);	
	}
	tokens[token_count] = NULL;
	return token_count;
}
int redir_in(char**tokens){
	int i,fdin;
	for(i=0;tokens[i]!=NULL;i++){
		if(!strcmp(tokens[i],"<"))
			break;
	}
	if(tokens[i]){
		if(!tokens[i+1]){
			printf("입력 오류\n");
			return -1;
		}
		else{
			if((fdin=open(tokens[i+1],O_RDONLY))==-1){
				printf("파일을 잘못 입력\n");
				return -1;
			}
			dup2(fdin,0);
			close(fdin);
			for(i=i;tokens[i]!=NULL;i++){
				tokens[i] = tokens[i+2];
			}
			tokens[i] = NULL;
		}
		return 0;
	}
		
}
int redir_out(char**tokens){
	int i, fdout;
	for(i=0;tokens[i]!=NULL;i++){
		if(!strcmp(tokens[i],">"))
			break;
	}
	if(tokens[i]){
		if(!tokens[i+1]){
			printf("입력 오류\n");
			return -1;
		}
		else{
			if((fdout=open(tokens[i+1],O_RDWR|O_CREAT,0644))==-1){
				printf("파일을 잘못입력\n");
				return -1;
			}
			dup2(fdout,1);
			close(fdout);
			for(i=i;tokens[i]!=NULL;i++){
				tokens[i] = tokens[i+2];
			}
			tokens[i] = NULL;
		}
		return 0;
	}
}
	
bool run(char*line){
	char delims[]="\r\n\t ";
	char*tokens[128];
	int token_count;
	bool back=false;
	int i;
	pid_t child;
	for(i=0;i<strlen(line);i++){
		if(line[i]=='&'){
			back=true;
			line[i]=' ';
			break;
		}
	}
	
	token_count = tokenize(line,delims,tokens,sizeof(tokens)/sizeof(char*));
	if (token_count==0)
		return 0;
	for(i=0;i<sizeof(builtin_cmd)/sizeof(COMMAND);i++){
		if(strcmp(builtin_cmd[i].name,tokens[0])==0)
			return builtin_cmd[i].func(token_count,tokens);
	}
	if((child=fork())==0){
		redir_in(tokens);
		redir_out(tokens);
		execvp(tokens[0],tokens);
		exit(0);	
	}
	if(back==false)
		wait();
	return true;
}
int main(){
	char line[1024];
	while(1){
		printf("[%s]$ ",get_current_dir_name());
		fgets(line,sizeof(line)-1,stdin);
		if(run(line)==false)
			break;
	}
	return 0;
}

