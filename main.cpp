/*
 * Credits to Saxony for coding this shitty nametag extender "ESP" LOL
 * Learn how to dox <3
 */

#include <windows.h>

#include <iostream>

#include <vector>

#include <tchar.h>

HANDLE pHandle = NULL;
DWORD pID = NULL;
float espnbb = 2.5;
float opanbb = 0.25;
float nametagsunlb = 0.02666666918;
float espnb = 3.34;
float opanb = 0.80;
bool espenabled = true;
float nametagsunl = 0.02666666918;
std::vector < DWORD > namelist;
std::vector < DWORD > fulllist;
std::vector < DWORD > opanamelist;
std::vector < DWORD > reachlistdblr;
std::vector < DWORD > espnamelist;

void scan() {
  while (1) {
    if (espenabled) {

      HWND mc_hWnd = FindWindow(_T("LWJGL"), nullptr); /* LWJGL is the LightWeight Java Game Library. Essentially, it is what Minecraft uses for graphics, sound, and input */
      GetWindowThreadProcessId(mc_hWnd, & pID);
      pHandle = OpenProcess(THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, pID);

      constexpr unsigned CHUNK_SIZE1 = 0x10000; /* Minimum */
      constexpr unsigned MAX_ADDRESS1 = 0x9FFFFFF; /* Maximum */

      /* Keep in mind you need to make sure stack is big enough or allocate it on heap. */

      char buffer1[CHUNK_SIZE1];
      for (unsigned i = 0; i < MAX_ADDRESS1; i += CHUNK_SIZE1) {
        if (ReadProcessMemory(pHandle, (LPVOID) i, buffer1, sizeof(buffer1), nullptr)) {
          for (int j = 0; j <= CHUNK_SIZE1 - sizeof(int); ++j) {
            int address = i + j;
            int address2 = i + j;
            int address3 = i + j;
            int something;
            memcpy( & something, buffer1 + j, sizeof(int));
            if (i + j >= 0x02A0000C) {
              if (something == 1020949519) {
                for (int j11 = 0; j11 < 16; ++j11) {
                  Sleep(100);
                  float checks11s;
                  address2 = address2 + 0x4;
                  ReadProcessMemory(pHandle, (void * ) address2, & checks11s, sizeof(checks11s), 0);
                  if (checks11s == 2.5) {
                    j11 = 16;
                    address3 = i + j;
                    espnamelist.push_back(address2);
                    namelist.push_back(i + j);
                    for (int j111 = 0; j111 < 16; ++j111) {
                      Sleep(10);
                      float checks1111s;
                      address3 = address3 + 0x4;
                      ReadProcessMemory(pHandle, (void * ) address3, & checks1111s, sizeof(checks1111s), 0);
                      if (checks1111s == 0.25) {
                        j111 = 16;
                        std::cout << std::hex << "Esp ->" << address2 << std::endl;
                        std::cout << std::hex << "Nametag ->" << i + j << std::endl;
                        std::cout << std::hex << "Opacity ->" << address3 << std::endl;

                        opanamelist.push_back(address3);
                      }
                    }
                    address3 = i + j;
                    for (int j111 = 0; j111 < 16; ++j111) {
                      Sleep(10);
                      float checks1111s;
                      address3 = address3 - 0x4;
                      ReadProcessMemory(pHandle, (void * ) address3, & checks1111s, sizeof(checks1111s), 0);
                      if (checks1111s == 0.25) {
                        j111 = 16;
                        std::cout << std::hex << "Esp ->" << address2 << std::endl;
                        std::cout << std::hex << "Nametag ->" << i + j << std::endl;
                        std::cout << std::hex << "Opacity ->" << address3 << std::endl;
                        opanamelist.push_back(address3);
                      }
                    }
                  }
                }
                address2 = i + j;
                for (int j11 = 0; j11 < 16; ++j11) {
                  Sleep(100);
                  float checks11s;
                  address2 = address2 - 0x4;
                  ReadProcessMemory(pHandle, (void * ) address2, & checks11s, sizeof(checks11s), 0);
                  if (checks11s == 2.5) {
                    espnamelist.push_back(address2);
                    namelist.push_back(i + j);
                    j11 = 16;
                    address3 = i + j;
                    for (int j111 = 0; j111 < 16; ++j111) {
                      Sleep(10);
                      float checks1111s;
                      address3 = address3 + 0x4;
                      ReadProcessMemory(pHandle, (void * ) address3, & checks1111s, sizeof(checks1111s), 0);
                      if (checks1111s == 0.25) {
                        j111 = 16;
                        std::cout << std::hex << "Esp ->" << address2 << std::endl;
                        std::cout << std::hex << "Nametag ->" << i + j << std::endl;
                        std::cout << std::hex << "Opacity ->" << address3 << std::endl;
                        opanamelist.push_back(address3);
                      }
                    }
                    address3 = i + j;
                    for (int j111 = 0; j111 < 16; ++j111) {
                      Sleep(10);
                      float checks1111s;
                      address3 = address3 - 0x4;
                      ReadProcessMemory(pHandle, (void * ) address3, & checks1111s, sizeof(checks1111s), 0);
                      if (checks1111s == 0.25) {
                        j111 = 16;
                        std::cout << std::hex << "Esp ->" << address2 << std::endl;
                        std::cout << std::hex << "Nametag ->" << i + j << std::endl;
                        std::cout << std::hex << "Opacity ->" << address3 << std::endl;

                        opanamelist.push_back(address3);
                      }
                    }
                  }
                }
              }

            }
          }
        }
      }
    }

    Sleep(1000);

  }
}

void write() {
  while (1) {
    if (espenabled) {
      HWND mc_hWnd = FindWindow(_T("LWJGL"), nullptr); /* LWJGL is the LightWeight Java Game Library. Essentially, it is what Minecraft uses for graphics, sound, and input */
      GetWindowThreadProcessId(mc_hWnd, & pID);
      pHandle = OpenProcess(THREAD_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, pID);

      for (int i1 = 0; i1 < espnamelist.size(); i1++) {
        Sleep(10);
        WriteProcessMemory(pHandle, (LPVOID)(espnamelist.at(i1)), & espnb, sizeof(int), 0);
      }
      for (int i1 = 0; i1 < opanamelist.size(); i1++) {
        Sleep(10);
        WriteProcessMemory(pHandle, (LPVOID)(opanamelist.at(i1)), & opanb, sizeof(float), 0);
      }
      for (int i1 = 0; i1 < namelist.size(); i1++) {
        Sleep(10);
        WriteProcessMemory(pHandle, (void * )(namelist.at(i1)), & nametagsunl, sizeof(float), 0);
      }
      Sleep(10);
    } else {
      for (int i1 = 0; i1 < espnamelist.size(); i1++) {
        Sleep(100);
        WriteProcessMemory(pHandle, (LPVOID)(espnamelist.at(i1)), & espnbb, sizeof(int), 0);
      }
      for (int i1 = 0; i1 < opanamelist.size(); i1++) {
        Sleep(100);
        WriteProcessMemory(pHandle, (LPVOID)(opanamelist.at(i1)), & opanbb, sizeof(float), 0);
      }
      for (int i1 = 0; i1 < namelist.size(); i1++) {
        Sleep(100);
        WriteProcessMemory(pHandle, (void * )(namelist.at(i1)), & nametagsunlb, sizeof(float), 0);
      }
      Sleep(500);
    }
  }
}

int main() {

  CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) & scan, NULL, 0, 0);
  CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) & write, NULL, 0, 0);
  while (1) {

    /* Put your main code */

    Sleep(1000);
  }

  return 0;
}
