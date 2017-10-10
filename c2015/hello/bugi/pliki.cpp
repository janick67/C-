#include <dirent.h>
#include <stdio.h>
#include <string>
#include <fstream>
int i=0;
std::string srcnext( std::string src , std::string &dont, std::ofstream* drzewko) {
    i++;
    struct dirent * plik;
    DIR * sciezka;
    std::string temp=src;
    int tak =0, pos=0, ile;
    if(( sciezka = opendir( src.c_str() ) ) ) {
        while(( plik = readdir( sciezka ) ) ){
           src.append(plik->d_name);
            if (opendir(src.c_str())!=NULL &&  src.find( "." ) == std::string::npos)// jeżeli ścieżkę da się odtworzyć jak foldet i nie ma w nazwie kropek
             {
                 if (tak==1 || dont=="0")
             {
                while (pos!=-1)//zliczanie wystąpienia backslasha
                    {
                    pos=src.find("\\",pos+1);
                    if (pos!=-1) ile++;
                    }

                for (; ile>1; ile--)//dodaje tabulatory w zależności od ilości backslashy w ścieżce
                //*drzewko<<("\t");
                //*drzewko<<plik->d_name<<"\n";
                temp=src;
                temp.append("\\kaczorek.txt");
                fopen(temp.c_str(),"w");
                dont="0";
                return src.c_str();
             }
            if (src.substr(src.rfind("\\")+1)==dont) tak=1;
             }
            src=temp;
             }
             if (dont!="0" && src=="C:\\") return "0";
        closedir( sciezka );
    }
    else
        return "0";
return "1";

}



main( int argc, char ** argv ) {
    std::string src, last, dont="0";
    std::ofstream drzewko;
    drzewko.open("plik.txt");
    src="C:\\";// dysk który ma przeszukiwać
    while (src!="1") {
            if (i>50) return 0;
    last=src;
    if (src.rfind("\\")<src.length()-1) src.append("\\"); //dodaj backslash
    src=srcnext(src,dont,&drzewko); //otwiera podfolder i zwraca do niego sciezke
    if (src == "1") //nie ma kolejnego podfolderu
      { if (last.rfind("\\")==last.length()-1) last.erase(last.rfind("\\"),std::string::npos);
        dont=last.substr(last.rfind("\\")+1);//zapisuje na jakim folderze skończył szukanie
          last.erase(last.rfind("\\")+1,std::string::npos); //usuwa wszystko po ostatnim backslashu
        src=last;
        }
      if (src=="/0") return 0;
    }
}
