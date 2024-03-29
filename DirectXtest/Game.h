#pragma once
#ifndef __GAME
#define __GAME
class Game {
private:
	HWND hWndMain;
	FrameRate frameController;
	LPDIRECT3D9 pD3D = 0;
	LPDIRECT3DDEVICE9 pDevice = 0;
	PDIRECT3DSURFACE9 pBackSurface = 0;
	PDIRECT3DSURFACE9 BitmapSurface = 0;
	D3DPRESENT_PARAMETERS SavedPresParams;
	LPDIRECT3DVERTEXBUFFER9 pVB = 0;
	int DeviceHeight, DeviceWidth;
public:
	Game();
	Game(HWND);
	~Game();
	static LRESULT CALLBACK StaticWndProc(HWND, UINT, WPARAM, LPARAM);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	void setHandle(HWND);
	HWND getHandle();
	int GameInit();
	int GameLoop();
	int GameShutdown();
	int LoadBitmapToSurface(TCHAR*, LPDIRECT3DSURFACE9*, LPDIRECT3DDEVICE9);
	int InitDirect3DDevice(HWND, int, int, BOOL, D3DFORMAT, LPDIRECT3D9, LPDIRECT3DDEVICE9*);
	int Render();
	HRESULT ValidateDevice();
	HRESULT RestoreGraphics();
	DrawLine d;
};

#endif