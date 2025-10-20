#include <iostream>
#include <sstream>
#include <string>
#include "EditController.hpp"
using namespace std;

int main(int argc, char** argv){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  EditController ec;
  if(argc>1){
    if(!ec.open(argv[1])){
      cerr<<"Error: could not open "<<argv[1]<<"\n";
    }else{
      cout<<"Loaded "<<argv[1]<<"\n";
      cout<<ec.view(0);
    }
  }else{
    cout<<"Type 'open <path>' to load a file.\n";
  }

  string line;
  while(true){
    cout<<"> ";
    if(!getline(cin, line)) break;
    istringstream iss(line);
    string cmd; iss>>cmd;
    if(cmd=="quit" || cmd=="exit") break;
    else if(cmd=="open"){
      string path; iss>>std::ws; getline(iss, path);
      if(path.empty()){ cout<<"Usage: open <path>\n"; continue; }
      if(ec.open(path)){ cout<<"Loaded "<<path<<"\n"<<ec.view(0); }
      else cout<<"Open failed.\n";
    }else if(cmd=="view"){
      size_t off=0; iss>>std::hex>>off;
      cout<<ec.view(off);
    }else if(cmd=="edit"){
      size_t off=0; string mode,val;
      iss>>std::hex>>off>>mode>>val;
      if(mode!="hex"){ cout<<"Only hex supported. Use: edit <offset> hex <byte>\n"; continue; }
      if(ec.editHex(off,val)) cout<<"OK\n";
      else cout<<"Edit failed.\n";
    }else if(cmd=="save"){
      string path; iss>>path;
      if(ec.save(path)) cout<<"Saved.\n";
      else cout<<"Save failed.\n";
    }else if(cmd.empty()){
      continue;
    }else{
      cout<<"Commands: open <path> | view <offset> | edit <offset> hex <byte> | save [path] | quit\n";
    }
  }
  return 0;
}
