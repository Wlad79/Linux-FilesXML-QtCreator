// reading a text file
// http://www.cplusplus.com/doc/tutorial/files/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//parsing XML:
// XmlParser.cpp : Defines the entry point for the console application.
//https://www.codeguru.com/cpp/i-n/internet/xml/article.php/c3451/STLbased-nonvalidating-XML-Parser.htm
#include "./XML-Parser/StdAfx.h"
#define DebugDisplay
#include "./XML-Parser/XmlStream.h"
#include <sys/ioctl.h>//https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux
#include <termios.h>//https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux
#if defined(_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
stringstream strm;
stringstream strm2;

int main () {
  string line;
  ifstream myfile ("./wartungs-plan-za_nnb.xml");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      strm << line << '\n';
    }
    myfile.close();
  }
  else cout << "Unable to open file";

  // parse document
  string str = strm.str();
  XmlStream xml;
  xml.parse( (char *) str.c_str(), str.size() - 1 );

  cout << "##############################################";

  /////////////////////////////////////
  ifstream myfile2 ("./wartungsplan-old.xml");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      strm2 << line << '\n';
    }
    myfile2.close();
  }
  else cout << "Unable to open file";

  // parse document
  string str2 = strm2.str();
  XmlStream xml2;
  xml2.parse( (char *) str2.c_str(), str2.size() - 1 );

  return 0;
}
