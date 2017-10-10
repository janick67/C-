#include <stdio.h>
#include <string>
#include <curl/curl.h>
#include <fstream>
#include <vector>
#include <windows.h>
#include <tchar.h>
#include "zip/zip.h"
#include "zip/unzip.h"


int main()
{
  HZIP hz; DWORD writ;
  hz = OpenZip(_T("0.zip"),0);
  SetUnzipBaseDir(hz,_T("/"));
  ZIPENTRY ze;
  GetZipItem(hz,-1,&ze);
  int numitems=ze.index;
  for (int zi=0; zi<numitems; zi++)
  { GetZipItem(hz,zi,&ze);
    UnzipItem(hz,zi,ze.name);
  }
  CloseZip(hz);
  _tprintf(_T("Unzipped 'znsimple.bmp' and 'znsimple.txt' from 'simple1.zip'\n"));
}
