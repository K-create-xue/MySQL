  /*************************************************************************
      > File Name: mysql_test.c
      > Author: Black_K
      > Mail: xzp01@foxmail.com 
      > Created Time: 2021年10月19日 星期二 21时00分13秒
   ************************************************************************/
  
  #include<stdio.h>
  #include<unistd.h>
  #include<stdlib.h>
  #include<string.h>
  #include<mysql/mysql.h>
W>int main(int argc,char* argv[]){
  //"start coding K:"
      //初始化句柄
       MYSQL *mysql=NULL;
       mysql=mysql_init(NULL);
       if(mysql==NULL){
           printf("mysql init error\n");
           return -1;
       }                                                                                                                                                                                                            
      //mysql_real_connect(句柄，服务器IP，用户名，密码，数据库名称
      //，端口号，套接字文件，客户端标志)；
      if(mysql_real_connect(mysql,"172.22.226.182","root","1","dbname",
              3306,NULL,0)==NULL){
          printf("connect failed: %s \n",mysql_error(mysql));
          return -1;
      }
      if(mysql_set_character_set(mysql,"utf8")!=0){
          printf("set character failed: %s \n",mysql_error(mysql));
          mysql_close(mysql);
          return -1;
      }
W>    char *insert="insert tbname values(NULL,'宋江',1,99.66,now());";
      if(mysql_query(mysql,insert)!=0){
          printf("query failed: %s \n",mysql_error(mysql));
          return -1;
      }
  
      mysql_close(mysql);
      return 0;
  }
