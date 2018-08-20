#include <stdio.h>
#include <obliv.h>
#include <memory.h>
#include "median.h"
#include"../common/util.h"

double lap;

int main(int argc,char *argv[])
{
  ProtocolDesc pd;
  protocolIO io;
  u_int currentParty;
  //needed parameters: program name, party (<1|2>), 1st cart. coord. of curr. party, 2nd cart. coord. of curr. party, TCP port number
  if(argc < 5)
  {
    fprintf(stderr, "Usage: %s <1|2> <coordinate> <coordinate> <port>\n", argv[0]);
    return 1;
  }

  //read data from command line
  sscanf(argv[1], "%u", &currentParty);
  sscanf(argv[2], "%u", &(io.length));


  int i;
  for (i = 0; i < io.length; i++){
	sscanf(argv[i+3], "%u", &(io.list[i]));
  }


  const char port[4];    //the tcp functions accept const char parameters
  sscanf(argv[io.length+3], "%s", port);

  if(currentParty == 1){
    if(protocolAcceptTcp2P(&pd, port) != 0) {
      fprintf(stderr, "TCP accept failed\n");
      exit(1);
    }
  }
  else{
    if(protocolConnectTcp2P(&pd, "localhost", port) != 0){
       fprintf(stderr, "TCP connect failed\n");
       exit(1);
    }
  }

  setCurrentParty(&pd, currentParty);
  execYaoProtocol(&pd, median, &io);     //call exactProximityTesting routine from .oc file
  cleanupProtocol(&pd);
  fprintf(stderr, "Result: %d\n", io.res);

  return 0;
}
