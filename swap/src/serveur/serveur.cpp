#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>



#include "../socklib/bufferedreaderwriter.hpp"

using std::string;
using std::vector;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;

const size_t TAILLE_BUFF = 100;

int main(int argc, char *argv[]) {
  bool serveur;

  string port;
  string adresse;
  pid_t pid;
  int fd;

  // on teste le nombre d'arguments.
  // Attention, il y a toujours le nom du programme donc argc==
  // signifie un argument.
  if (argc == 2) {
    serveur = true;
    port = argv[1];

    cerr << "Je suis serveur sur le port " << port << endl;
    }
    else {
      cerr << "usage " << argv[0] << " <port> : pour le serveur" << endl
  	 << "      " << argv[0] << " <serveur> <port> : pour le clinet" << endl;
      exit(1);
    }
      string ligne;
    int s_serv = socklib::CreeSocketServeur(port);

    while(1)
    {
      // #########################
      // code du serveur
      // #########################

      // création de la socket d'écoute

      // attente d'un nouveau client
      size_t size_mess = 50;
      int s = socklib::AcceptConnexion(s_serv);
      if (s != -1)
      {
        pid =  fork();
        if (pid == -1)
        {
          printf("%s\n", "exit_error");
        }
        if(pid == 0)
        {
          fd = open("leader_board.txt",O_RDWR);
          socklib::BufferedReaderWriter rw(fd);
          socklib::BufferedReaderWriter rw2(s);
          while (true) {
            char  mess[50];
            bzero(&mess,50);
            int res = recv(s, &mess,50, 0);
            exit_error("serveur : lecture sur la socket", res == -1, errno);

            if (res == 1 && mess[0]=='\n') {
      	         cout << "fermeture de la connexion"  << endl;
      	          break;
            }

            lseek(fd,0, SEEK_END);
            write(fd,&mess,strlen(mess));
            char test='\n';
            write(fd,&test,1);
        //  cout << "> " << mess.data() << endl;
          }
          lseek(fd,0,SEEK_SET);
          while (true) {
          string ligne = rw.read_line();
            if (ligne == "") {
              ligne="\n";
              rw2.write(ligne);
              break;
            }
            cout<<ligne;
            rw2.write(ligne);
        //  cout << "> " << mess.data() << endl;
          }
          close(fd);
          close (s_serv);
          close (s);
        }
        printf("%s\n","parent" );
      }
      // la lecture que je fait là n'est pas très propre,
      // il faudra l'améliorer.
  }


  return 0;
}
