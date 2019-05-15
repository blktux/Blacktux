/*-----------------------------
Copyright (c) 2019 M.I.T. License

Author(s):
- Jordan S.H. (blktux)

Note(s):
- This library is based on C-
  style support and syntax.
-----------------------------*/

#ifdef __cplusplus
extern "C" {
#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef CONST
#define CONST
#endif

typedef int BOOL;
typedef BOOL *PBOOL, *LPBOOL;
typedef long LONG;
typedef LONG LRESULT, LPARAM, HRESULT, WPARAM;
typedef unsigned short WORD;
typedef WORD ATOM, *PWORD, *LPWORD;
typedef unsigned long DWORD;
typedef DWORD *PDWORD, *LPDWORD;
typedef unsigned char BYTE;
typedef BYTE *PBYTE, *LPBYTE;
typedef unsigned int UINT;
typedef UINT, *PUINT, *LPUINT;
typedef CONST void *PCVOID, *LPCVOID;
typedef float FLOAT;
typedef FLOAT *PFLOAT, *LPFLOAT;

#ifdef __cplusplus
}
#endif

#endif // __cplusplus
