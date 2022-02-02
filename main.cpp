//
// main.cpp
// Created on 21/10/2018
//
#include "Media.h"
#include "Video.h"
#include "Photo.h"
#include "Film.h"
#include "Group.h"
#include "Master.h"

#include <iostream>
#include <string>
#include <memory>

#include <sstream>
#include "tcpserver.h"

using namespace std;
using PhotoPtr = shared_ptr<Photo>;
using VideoPtr = shared_ptr<Video>;

#define VERSION_2


#ifdef VERSION_1

int main(int argc, const char* argv[])
{
    cout 
    << "Hello brave new world"
    << endl;
    string path = "~/Documents/telecom/INF224/data";
    /*
    Media ** tab = new Media*[10];
    tab[0] = new Photo("logo-long.png", path, 3, 4);
    tab[1] = new Video("defi-confession-nocturne.mpeg", path, 5);
    tab[2] = new Photo("paul-frambot.png", path, 3, 4);
    tab[3] = new Video("conf-paul-frambot.mp4", path, 5);
    for(int i = 0; i < 4; i++) {
        tab[i]->play_media();
    }
    delete[] tab;*/

    /*
    int chaptersT[4] = {40,30,20,30};
    Film  *tarantino = new Film("Pulp Fiction", "C/", 120, 4, chaptersT);
    tarantino->print_values(cout);
    delete tarantino;*/

    /* PhotoPtr logo( new Photo("logo-long.png", path, 3, 4));
    PhotoPtr frambot( new Photo("paul-frambot.png", path, 3, 4));
    VideoPtr confFrambot( new Video("conf-paul-frambot.mp4", path, 5));
    Group *tbf = new Group("tbf");
    tbf->push_back(logo);
    tbf->push_back(frambot);
    tbf->push_back(confFrambot);
    tbf->print_values(cout);

    tbf->pop_front();
    tbf->pop_front();
    tbf->pop_front();*/

    Master  *bdd = new Master();
    FilmPtr jb = bdd->createFilm("James Bond");
    PhotoPtr mariage = bdd->createPhoto("Marriage");

    bdd->printObject("Marriage");
    bdd->printObject("Test");

    return 0;

}

#endif

#ifdef VERSION_2



const int PORT = 3331;


int main(int argc, char* argv[])
{
  // cree le TCPServer
  auto* server =
  new TCPServer( [&](string const& request, string& response) {

    // the request sent by the client to the server
    cout << "request: " << request << endl;

    // the response that the server sends back to the client
    response = "RECEIVED: " + request;

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}



#endif