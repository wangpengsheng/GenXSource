// xImaCodec.cpp : Encode Decode functions
/* 07/08/2001 v1.00 - Davide Pizzolato - www.xdp.it
 * CxImage version 5.99a 08/Feb/2004
 */

#include "ximage.h"

#if CXIMAGE_SUPPORT_JPG
#include "ximajpg.h"
#endif

#if CXIMAGE_SUPPORT_GIF
#include "ximagif.h"
#endif

#if CXIMAGE_SUPPORT_PNG
#include "ximapng.h"
#endif

#if CXIMAGE_SUPPORT_MNG
#include "ximamng.h"
#endif

#if CXIMAGE_SUPPORT_BMP
#include "ximabmp.h"
#endif

#if CXIMAGE_SUPPORT_ICO
#include "ximaico.h"
#endif

#if CXIMAGE_SUPPORT_TIF
#include "ximatif.h"
#endif

#if CXIMAGE_SUPPORT_TGA
#include "ximatga.h"
#endif

#if CXIMAGE_SUPPORT_PCX
#include "ximapcx.h"
#endif

#if CXIMAGE_SUPPORT_WBMP
#include "ximawbmp.h"
#endif

#if CXIMAGE_SUPPORT_WMF
#include "ximawmf.h" // <vho> - WMF/EMF support
#endif

#if CXIMAGE_SUPPORT_J2K
#include "ximaj2k.h"
#endif

#if CXIMAGE_SUPPORT_JBG
#include "ximajbg.h"
#endif

#if CXIMAGE_SUPPORT_JASPER
#include "ximajas.h"
#endif

////////////////////////////////////////////////////////////////////////////////
#if CXIMAGE_SUPPORT_ENCODE
////////////////////////////////////////////////////////////////////////////////
bool CxImage::EncodeSafeCheck(CxFile *hFile)
{
	if (hFile==NULL) {
		strcpy(info.szLastError,CXIMAGE_ERR_NOFILE);
		return true;
	}

	if (pDib==NULL){
		strcpy(info.szLastError,CXIMAGE_ERR_NOIMAGE);
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////
//#ifdef WIN32
//bool CxImage::Save(LPCWSTR filename, DWORD imagetype)
//{
//	FILE* hFile;	//file handle to write the image
//	if ((hFile=_wfopen(filename,L"wb"))==NULL)  return false;
//	bool bOK = Encode(hFile,imagetype);
//	fclose(hFile);
//	return bOK;
//}
//#endif //WIN32
////////////////////////////////////////////////////////////////////////////////
// For UNICODE support: char -> TCHAR
bool CxImage::Save(const TCHAR * filename, DWORD imagetype)
{
	FILE* hFile;	//file handle to write the image
	if ((hFile=_tfopen(filename,_T("wb")))==NULL)  return false;	// For UNICODE support
	//if ((hFile=fopen(filename,"wb"))==NULL)  return false;
	bool bOK = Encode(hFile,imagetype);
	fclose(hFile);
	return bOK;
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Encode(FILE *hFile, DWORD imagetype)
{
	CxIOFile file(hFile);
	return Encode(&file,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Encode(BYTE * &buffer, long &size, DWORD imagetype)
{
	if (buffer!=NULL) return false; //the buffer must be empty
	CxMemFile file;
	file.Open();
	if(Encode(&file,imagetype)){
		buffer=file.GetBuffer();
		size=file.Size();
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Encode(CxFile *hFile, DWORD imagetype)
{

#if CXIMAGE_SUPPORT_BMP

	if (imagetype==CXIMAGE_FORMAT_BMP){
		CxImageBMP newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_ICO
	if (imagetype==CXIMAGE_FORMAT_ICO){
		CxImageICO newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_TIF
	if (imagetype==CXIMAGE_FORMAT_TIF){
		CxImageTIF newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_JPG
	if (imagetype==CXIMAGE_FORMAT_JPG){
		CxImageJPG newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_GIF
	if (imagetype==CXIMAGE_FORMAT_GIF){
		CxImageGIF newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_PNG
	if (imagetype==CXIMAGE_FORMAT_PNG){
		CxImagePNG newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_MNG
	if (imagetype==CXIMAGE_FORMAT_MNG){
		CxImageMNG newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_TGA
	if (imagetype==CXIMAGE_FORMAT_TGA){
		CxImageTGA newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_PCX
	if (imagetype==CXIMAGE_FORMAT_PCX){
		CxImagePCX newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_WBMP
	if (imagetype==CXIMAGE_FORMAT_WBMP){
		CxImageWBMP newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_WMF && CXIMAGE_SUPPORT_WINDOWS // <vho> - WMF/EMF support
	if (imagetype==CXIMAGE_FORMAT_WMF){
		CxImageWMF newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_J2K
	if (imagetype==CXIMAGE_FORMAT_J2K){
		CxImageJ2K newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_JBG
	if (imagetype==CXIMAGE_FORMAT_JBG){
		CxImageJBG newima;
		newima.Ghost(this);
		if (newima.Encode(hFile)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_JASPER
	if (
 #if	CXIMAGE_SUPPORT_JP2
		imagetype==CXIMAGE_FORMAT_JP2 || 
 #endif
 #if	CXIMAGE_SUPPORT_JPC
		imagetype==CXIMAGE_FORMAT_JPC || 
 #endif
 #if	CXIMAGE_SUPPORT_PGX
		imagetype==CXIMAGE_FORMAT_PGX || 
 #endif
 #if	CXIMAGE_SUPPORT_PNM
		imagetype==CXIMAGE_FORMAT_PNM || 
 #endif
 #if	CXIMAGE_SUPPORT_RAS
		imagetype==CXIMAGE_FORMAT_RAS || 
 #endif
		 false ){
		CxImageJAS newima;
		newima.Ghost(this);
		if (newima.Encode(hFile,imagetype)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif

	strcpy(info.szLastError,"Encode: Unknown format");
	return false;
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Encode(FILE * hFile, CxImage ** pImages, int pagecount, DWORD imagetype)
{
	CxIOFile file(hFile);
	return Encode(&file, pImages, pagecount,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Encode(CxFile * hFile, CxImage ** pImages, int pagecount, DWORD imagetype)
{
#if CXIMAGE_SUPPORT_TIF
	if (imagetype==CXIMAGE_FORMAT_TIF){
		CxImageTIF newima;
		newima.Ghost(this);
		if (newima.Encode(hFile,pImages,pagecount)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_GIF
	if (imagetype==CXIMAGE_FORMAT_GIF){
		CxImageGIF newima;
		newima.Ghost(this);
		if (newima.Encode(hFile,pImages,pagecount)){
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
	strcpy(info.szLastError,"Multipage Encode, Unsupported operation for this format");
	return false;
}

////////////////////////////////////////////////////////////////////////////////
#endif //CXIMAGE_SUPPORT_ENCODE
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
#if CXIMAGE_SUPPORT_DECODE
////////////////////////////////////////////////////////////////////////////////
// For UNICODE support: char -> TCHAR
bool CxImage::Load(const TCHAR * filename, DWORD imagetype)
//bool CxImage::Load(const char * filename, DWORD imagetype)
{
	/*FILE* hFile;	//file handle to read the image
	if ((hFile=fopen(filename,"rb"))==NULL)  return false;
	bool bOK = Decode(hFile,imagetype);
	fclose(hFile);*/

	/* automatic file type recognition */
	bool bOK = false;
	if ( imagetype > 0 && imagetype < CMAX_IMAGE_FORMATS ){
		FILE* hFile;	//file handle to read the image
		if ((hFile=_tfopen(filename,_T("rb")))==NULL)  return false;	// For UNICODE support
		//if ((hFile=fopen(filename,"rb"))==NULL)  return false;
		bOK = Decode(hFile,imagetype);
		fclose(hFile);
		if (bOK) return bOK;
	}

	char szError[256];
	strcpy(szError,info.szLastError); //save the first error

	// if failed, try automatic recognition of the file...
	FILE* hFile;
	if ((hFile=_tfopen(filename,_T("rb")))==NULL)  return false;	// For UNICODE support
	//if ((hFile=fopen(filename,"rb"))==NULL)  return false;
	bOK = Decode(hFile,CXIMAGE_FORMAT_UNKNOWN);
	fclose(hFile);

	if (!bOK && imagetype > 0) strcpy(info.szLastError,szError); //restore the first error

	return bOK;
}
////////////////////////////////////////////////////////////////////////////////
#ifdef WIN32
//bool CxImage::Load(LPCWSTR filename, DWORD imagetype)
//{
//	/*FILE* hFile;	//file handle to read the image
//	if ((hFile=_wfopen(filename, L"rb"))==NULL)  return false;
//	bool bOK = Decode(hFile,imagetype);
//	fclose(hFile);*/
//
//	/* automatic file type recognition */
//	bool bOK = false;
//	if ( imagetype > 0 && imagetype < CMAX_IMAGE_FORMATS ){
//		FILE* hFile;	//file handle to read the image
//		if ((hFile=_wfopen(filename,L"rb"))==NULL)  return false;
//		bOK = Decode(hFile,imagetype);
//		fclose(hFile);
//		if (bOK) return bOK;
//	}
//
//	char szError[256];
//	strcpy(szError,info.szLastError); //save the first error
//
//	// if failed, try automatic recognition of the file...
//	FILE* hFile;	//file handle to read the image
//	if ((hFile=_wfopen(filename,L"rb"))==NULL)  return false;
//	bOK = Decode(hFile,CXIMAGE_FORMAT_UNKNOWN);
//	fclose(hFile);
//
//	if (!bOK && imagetype > 0) strcpy(info.szLastError,szError); //restore the first error
//
//	return bOK;
//}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::LoadResource(HRSRC hRes, DWORD imagetype, HMODULE hModule)
{
	DWORD rsize=SizeofResource(hModule,hRes);
	HGLOBAL hMem=::LoadResource(hModule,hRes);
	if (hMem){
		char* lpVoid=(char*)LockResource(hMem);
		if (lpVoid){
			// FILE* fTmp=tmpfile(); doesn't work with network
			/*char tmpPath[MAX_PATH] = {0};
			char tmpFile[MAX_PATH] = {0};
			GetTempPath(MAX_PATH,tmpPath);
			GetTempFileName(tmpPath,"IMG",0,tmpFile);
			FILE* fTmp=fopen(tmpFile,"w+b");
			if (fTmp){
				fwrite(lpVoid,rsize,1,fTmp);
				fseek(fTmp,0,SEEK_SET);
				bool bOK = Decode(fTmp,imagetype);
				fclose(fTmp);
				DeleteFile(tmpFile);
				return bOK;
			}*/

			CxMemFile fTmp((BYTE*)lpVoid,rsize);
			return Decode(&fTmp,imagetype);
		}
	} else strcpy(info.szLastError,"Unable to load resource!");
	return false;
}
#endif //WIN32
////////////////////////////////////////////////////////////////////////////////
// File name constructor
// > filename: file name
// > imagetype: specify the image format (CXIMAGE_FORMAT_BMP,...)
// For UNICODE support: char -> TCHAR
CxImage::CxImage(const TCHAR * filename, DWORD imagetype)
//CxImage::CxImage(const char * filename, DWORD imagetype)
{
	Startup(imagetype);
	Load(filename,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
// Stream constructor
// � the file is always closed by the constructor.
// > stream: file with "rb" access
// > imagetype: specify the image format (CXIMAGE_FORMAT_BMP,...)
CxImage::CxImage(FILE * stream, DWORD imagetype)
{
	Startup(imagetype);
	Decode(stream,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
CxImage::CxImage(CxFile * stream, DWORD imagetype)
{
	Startup(imagetype);
	Decode(stream,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
CxImage::CxImage(BYTE * buffer, DWORD size, DWORD imagetype)
{
	Startup(imagetype);
	CxMemFile stream(buffer,size);
	Decode(&stream,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Decode(BYTE * buffer, DWORD size, DWORD imagetype)
{
	CxMemFile file(buffer,size);
	return Decode(&file,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Decode(FILE *hFile, DWORD imagetype)
{
	CxIOFile file(hFile);
	return Decode(&file,imagetype);
}
////////////////////////////////////////////////////////////////////////////////
bool CxImage::Decode(CxFile *hFile, DWORD imagetype)
{

	if (imagetype==CXIMAGE_FORMAT_UNKNOWN){
		DWORD pos = hFile->Tell();
#if CXIMAGE_SUPPORT_BMP
		{ CxImageBMP newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_JPG
		{ CxImageJPG newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_ICO
		{ CxImageICO newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_GIF
		{ CxImageGIF newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_PNG
		{ CxImagePNG newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_TIF
		{ CxImageTIF newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_MNG
		{ CxImageMNG newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_TGA
		{ CxImageTGA newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_PCX
		{ CxImagePCX newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_WBMP
		{ CxImageWBMP newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_WMF && CXIMAGE_SUPPORT_WINDOWS
		{ CxImageWMF newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_J2K
		{ CxImageJ2K newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_JBG
		{ CxImageJBG newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
#if CXIMAGE_SUPPORT_JASPER
		{ CxImageJAS newima; newima.CopyInfo(*this); if (newima.Decode(hFile)) { Transfer(newima); return true; } else hFile->Seek(pos,SEEK_SET); }
#endif
	}

#if CXIMAGE_SUPPORT_BMP
	if (imagetype==CXIMAGE_FORMAT_BMP){
		CxImageBMP newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_JPG
	if (imagetype==CXIMAGE_FORMAT_JPG){
		CxImageJPG newima;
		newima.CopyInfo(*this); // <ignacio>
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_ICO
	if (imagetype==CXIMAGE_FORMAT_ICO){
		CxImageICO newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			info.nNumFrames = newima.info.nNumFrames;
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_GIF
	if (imagetype==CXIMAGE_FORMAT_GIF){
		CxImageGIF newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			info.nNumFrames = newima.info.nNumFrames;
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_PNG
	if (imagetype==CXIMAGE_FORMAT_PNG){
		CxImagePNG newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_TIF
	if (imagetype==CXIMAGE_FORMAT_TIF){
		CxImageTIF newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			info.nNumFrames = newima.info.nNumFrames;
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_MNG
	if (imagetype==CXIMAGE_FORMAT_MNG){
		CxImageMNG newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			info.nNumFrames = newima.info.nNumFrames;
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_TGA
	if (imagetype==CXIMAGE_FORMAT_TGA){
		CxImageTGA newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_PCX
	if (imagetype==CXIMAGE_FORMAT_PCX){
		CxImagePCX newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_WBMP
	if (imagetype==CXIMAGE_FORMAT_WBMP){
		CxImageWBMP newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_WMF && CXIMAGE_SUPPORT_WINDOWS // vho - WMF support
	if (imagetype == CXIMAGE_FORMAT_WMF){
		CxImageWMF newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_J2K
	if (imagetype==CXIMAGE_FORMAT_J2K){
		CxImageJ2K newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_JBG
	if (imagetype==CXIMAGE_FORMAT_JBG){
		CxImageJBG newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif
#if CXIMAGE_SUPPORT_JASPER
	if (
 #if	CXIMAGE_SUPPORT_JP2
		imagetype==CXIMAGE_FORMAT_JP2 || 
 #endif
 #if	CXIMAGE_SUPPORT_JPC
		imagetype==CXIMAGE_FORMAT_JPC || 
 #endif
 #if	CXIMAGE_SUPPORT_PGX
		imagetype==CXIMAGE_FORMAT_PGX || 
 #endif
 #if	CXIMAGE_SUPPORT_PNM
		imagetype==CXIMAGE_FORMAT_PNM || 
 #endif
 #if	CXIMAGE_SUPPORT_RAS
		imagetype==CXIMAGE_FORMAT_RAS || 
 #endif
		 false ){
		CxImageJAS newima;
		newima.CopyInfo(*this);
		if (newima.Decode(hFile,imagetype)){
			Transfer(newima);
			return true;
		} else {
			strcpy(info.szLastError,newima.GetLastError());
			return false;
		}
	}
#endif

	strcpy(info.szLastError,"Decode: Unknown or wrong format");
	return false;
}
////////////////////////////////////////////////////////////////////////////////
#endif //CXIMAGE_SUPPORT_DECODE
////////////////////////////////////////////////////////////////////////////////
