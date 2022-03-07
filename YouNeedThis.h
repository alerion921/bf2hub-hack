//BLACK SS CREDITS - 3p1c

//INCLUDES START ------------------->
#pragma once
#define WIN32_LEAN_AND_MEAN
#include "stdio.h"
#include "Models.h"
#include <stdlib.h> 
#include <stdint.h>
#include <time.h>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <Tlhelp32.h>
#include <intrin.h>
#include <fstream>
#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment (lib, "d3dx9.lib")
#pragma comment (lib, "d3d9.lib")
#include "detours.h"
#pragma comment (lib, "detours.lib")
#pragma warning( disable: 4244 )
#define M_PI 3.14159265358979323846
#include "stdafx.h"
//INCLUDES END ------------------->

//Setup STD Namespace
using namespace std;

//Mixed Defines
#define HOOK(func,addy) o##func = (t##func)DetourFunction((PBYTE)addy,(PBYTE)hk##func) //hook using detours 1.5
#define UNHOOK(func,addy) o##func = (t##func)DetourFunction((PBYTE)addy,(PBYTE)o##func) //unhook using detours 1.5
#define D3D_RELEASE(D3D_PTR) if( D3D_PTR ){ D3D_PTR->Release(); D3D_PTR = NULL; }
#define ES 0 //EndScene
#define DIP 1 //DrawIndexPrimitive
#define RES 2 //Reset
#define SSS 3 //SetStreamSource
#define SRS 4 //SetRenderState
#define menukey VK_DELETE
#define espkey VK_INSERT
#define JMP32_SZ 6 // the size of JMP <address>
#define NOP 0x90 // opcode for NOP
#define JMP 0xE9 // opcode for JUMP

//Required for Log File
ofstream outputFile1;
char buff[20];
struct tm* sTm;

//DWORDS
DWORD dwRendBase = NULL;
DWORD dwRendDX9Base = NULL;
DWORD dwBF2Base = NULL;
DWORD dwD3D9Base = NULL;
DWORD dwRendDx9Size = NULL;
DWORD dwBF2Size = NULL;
DWORD dwD3D9Size = NULL;
DWORD pbclBase = NULL;
DWORD pbclSize = NULL;
DWORD bf2pid = NULL;
DWORD dwBridgeAddress = 0;



DWORD dwUtilityBase;
DWORD dwSupply;
DWORD dwVehicle;
DWORD ParachuteHUDBase = { 0x009FFCB0 };
DWORD ParaHUDOffsets[] = { 0x71C, 0x24, 0x4b8, 0x454, 0x30 }; //5 LEVEL Pointer
DWORD dwTeamSwitchBase = { 0xA08F60 };
DWORD TeamSwitchOffsets[] = { 0x60, 0xD8 }; //2 LEVEL Pointer
DWORD TeamBase;
BYTE dwFogBase;
DWORD CurrentTeam;
DWORD dwSwitch;
DWORD Minimap;
DWORD Nametags;
DWORD Healthbars;
DWORD DistanceTags;
DWORD GameBase;
DWORD RendBase;

///////////////////////////
DWORD dwCommanderBase;
DWORD dwForceCommander;
DWORD dwCommand;
DWORD dwResign;
//////////////////////////////

//////////////////////////////
DWORD dwSquadLeaderBase;
DWORD dwForceSquadLead;
DWORD dwSquadLead;
///////////////////////////////

//Bools
bool CMlog = false;
bool PMlog = false;
bool HMlog = false;
bool OBJlog = false;
bool forcecom = false;
bool unlimassets = false;
bool Classes_Intialized = false;
bool bInitOnce = true;
bool bNameESP = false;
bool bHealthESP = false;
bool bDistanceESP = false;
bool bCircleESP = false;
bool bClassESP = false;
bool bRadar2D = false;
bool bRadar3D = false;
bool bWarning = false;
bool Generate = true;


int original_team = 0;

//Const Chars
const char* CMKEY;
const char* PMKEY;
const char* OMKEY;

//Ints
int GetFogBase = 0;
int ParaHudIcon = 0;
int Team = 1;
int iESP_A = 255;
int iEnemyESP_R = 250;
int iEnemyESP_G = 5;
int iEnemyESP_B = 0;
int iFriendlyESP_R = 0;
int iFriendlyESP_G = 5;
int iFriendlyESP_B = 250;
//////////////////////////////////////
int wireframe = 0;
int wallhack = 0;
int playerchams = 0;
int explosivechams = 0;
int vehiclechams = 0;
int weaponchams = 0;
int nofog = 0;
int knifecham = 0;
int nosky = 0;
int nosea = 0;
int DrawCrossHair = 0;
///////////////////////////////////
int One = 0;
int Two = 0;
int Three = 0;
int Four = 0;
int Five = 0;
int Six = 0;
int Seven = 0;
int Eight = 0;
int Nine = 0;
int Ten = 0;
int Eleven = 0;
int Twelve = 0;
int Thirteen = 0;
int Fourteen = 0;
int Fifthteen = 0;
int Sixteen = 0;
int Seventeen = 0;
int Eighteen = 0;
int Nineteen = 0;
int Twenty = 0;
int Twentyone = 0;
int Twentytwo = 0;
int Twentythree= 0;
int Twentyfour = 0;
int Twentyfive = 0;
int Twentysix = 0;
int Twentyseven = 0;
int Twentyeight = 0;
/////////////////////////////
int Menux;
int Menuy;
int Menu;
int mMenuSelection;
int SwitchTeams = 0;
//
int DoOnceTeamSwitch = 0;
int DoOnceResignCommander = 0;
int DoOnceForceCommander = 0;
int DoOnceForceSquadLead = 0;
//
int forceCommander = 0;
int forceSquadLead = 0;
int resignCommander = 0;
//
int EnableWM = 0;

//////////////Removables by D3D//////////////
int RemoveSky = 0;
int RemoveHands = 0;
int RemoveOverlay = 0;
int RemoveWater = 0;
int RemoveTV = 0;
//////////////Removables by D3D//////////////


//Bytes
BYTE TEAM1 = 1;
BYTE TEAM2 = 2;
BYTE ON = 1;
BYTE OFF = 0;
BYTE Nop6Bytes[6] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
BYTE Nop4Bytes[4] = { 0x90, 0x90, 0x90, 0x90 };
BYTE Nop3Bytes[3] = { 0x90, 0x90, 0x90 };
BYTE Nop2Bytes[2] = { 0x90, 0x90 };
BYTE ONE[1] = { 0x01 };
BYTE ZERO[1] = { 0x00 };
BYTE bKitIcons1[1];
BYTE bKitIcons2[7];
BYTE bKitIcons3[4];
BYTE bLockCrosshair[2];
BYTE bMinimap1[2];
BYTE bMinimap2[2];
BYTE bMinimap3[2];
BYTE bMinimap4[2];
BYTE bMinimap5[2];
BYTE bMinimap6[2];
BYTE bMinimap7[2];
BYTE bHealthArmor1[2];
BYTE bHealthArmor2[2];
BYTE bHealthArmor3[2];
BYTE bTVStatic[3];
BYTE bEnemyMines;
BYTE bDistanceTagz[2];
BYTE bPlayerDist[2];
BYTE b3DMap[6];
BYTE bNightvision;
BYTE bShellshock;
BYTE bMinimapKits1[3];
BYTE bMinimapKits2[3];

//Strings
string MMSTRING = "Disabled";
string NTSTRING = "Disabled";
string HBSTRING = "Disabled";
string DTSTRING = "Disabled";
string WUSTRING = "Disabled";
string FCSTRING = "Disabled";
string UASTRING = "Disabled";

//Required for DirectX
DETOUR_TRAMPOLINE(DWORD WINAPI fGetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId), GetWindowThreadProcessId);
typedef HRESULT(WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene = NULL;
typedef HRESULT(WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;
typedef HRESULT(WINAPI* tReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
tReset oReset = NULL;
D3DVIEWPORT9 Viewport;
ID3DXFont* dFont[14];
ID3DXLine* dLine[6];
ID3DXFont* pFont;
ID3DXLine* pLine;
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
UINT Offset = 0;
DWORD VTable[3] = { 0 };
typedef void(__stdcall* RenderScreen_t)(void* a, void* b, void* c);
RenderScreen_t pRenderScreen = NULL;
LPD3DXSPRITE SPRITE = NULL;
LPDIRECT3DPIXELSHADER9 Green2, Red2, Blue2, Yellow2, Orange2, Purple2, Teal2, Pink2, Trans2;
LPDIRECT3DTEXTURE9 SPRITE_TEX;
LPDIRECT3DTEXTURE9 TexRed = NULL;
LPDIRECT3DTEXTURE9 TexYellow = NULL;
LPDIRECT3DTEXTURE9 TexGreen = NULL;
LPDIRECT3DTEXTURE9 TexBlue = NULL;
LPDIRECT3DTEXTURE9 TexPink = NULL;
LPDIRECT3DTEXTURE9 TexTrans = NULL;
LPDIRECT3DTEXTURE9 TexPurple = NULL;
LPDIRECT3DTEXTURE9 TexOrange = NULL;
LPDIRECT3DTEXTURE9 TexLB = NULL;
FLOAT Fps = 0.0f;
FLOAT LastTickCount = 0.0f;
FLOAT CurrentTickCount;
CHAR FrameRate[50] = { 0 };

//Colour Defines
#define d3dColorWhite D3DCOLOR_XRGB( 255, 255, 255 )
#define d3dColorRed D3DCOLOR_XRGB( 255, 0, 0 )
#define d3dColorBlue D3DCOLOR_ARGB(155, 0, 0, 255 )
#define d3dColorYellow D3DCOLOR_XRGB( 255, 255, 0 )
#define d3dColorGreen D3DCOLOR_XRGB(0, 255, 0 )
#define d3dColorLightBlue D3DCOLOR_XRGB(0, 191, 255 )
#define d3dColorBlack D3DCOLOR_XRGB(0, 0, 0 )
#define d3dColorGrey D3DCOLOR_ARGB( 160 ,160, 160, 160 )

//Class Defines
#define BF2_MAINCONSOLE            "MainConsole"
#define BF2_PROFILEMANAGER        "ProfileManager"
#define BF2_INPUTMANAGER        "InputManager"
#define BF2_SERVERSETTINGS        "ServerSettingsManager"
#define BF2_PHYSICSMANAGER        "BasicPhysicsSystem"
#define BF2_INPUTDEVICEMANAGER    "InputDeviceManager"
#define BF2_CONTROLMAPMANAGER    "ControlMapManager"
#define BF2_OBJECTMANAGER        "ObjectManager"
#define BF2_TEMPLATEMANAGER        "TemplateManager"
#define BF2_PLAYERMANAGER        "PlayerManager"
#define BF2_HUDMANAGER            "HudManager"
#define BF2_DEBUGTEXTWRITER        "DebugTextWriter"
#define BF2_DEBUGLINEDRAWER        "DebugLineDrawer"
#define RENDDX9_RENDERER        "Renderer"
#define BF2_CLASSMANAGER			0x9FF960
#define BF2_PLAYERMANAGER_OFFSET	0xA08F60 
#define BF2_CGAME					0x99E348
#define BF2_ACTIONBUFFER			0x9FFCCC
#define BF2_SPREADTABLE				0x9F4DB0
#define BF2_INPUTDEVICEMANOFFSET	0x9CFE1C
#define BF2_HUDMANOFFSET			0xA33348 //0x82DEC6 [BF2.exe+0x42DEC6]
#define BF2_RENDEREROFFSET			RendDX9 + 0x0023c970
#define BF2_DEBUGTEXTWRITEROFFSET	RendDX9 + 0x00248c50
#define BF2_CONSOLEOFFSET			0x99B92C
#define BF2_BASE					0x400000

//CLASSES START--->
class CInfo;
class CPlayerManager;
class CPlayer;
class CPlayerInfo;
class CObject;
class CHealth;
class CLocalProfile;
class CSpreadTable;
class CTextWriter;
class CSoldierPtr;
class CSoldier;
class CWeapon;
class CDeviation;
class CSkeleton;
class CBone;
class CRenderer;
class CGlobalSettings;
class CHudText;
class CHudTextMngr;
class CPhysicsManager;
class CPhysicsNode;
class CComponent;
class CTemplate;
class CCamera;
class CViewMatrix;
class CVehicle;
class CVehicleHealth;
class CMainConsole;
class CInputManager;
class CActionBuffer;
class CControlMapManager;
class CHudManager;
class CCommander_Assets;
class CControlMap;
class CObjectManager;
class CRayTest;
class CTemplateManager;
class CDebugTextWriter;
class CDebugLineDrawer;
class CProfileManager;
class CActiveAccount;
class CInputDeviceManger;
class CInputDevice;

class CInfo
{
public:
	char _0x0000[4];
	CObject* Ptr; //0x0004  CRef<CObject*>ObjPtr;
	CPlayerInfo* PlayerInfo; //0004
	char _0x0008[52];

};//Size=0x003C

class CProfileManager
{
public:
	char cUnknown1[8];
	CActiveAccount* ActiveAccount; //0008
};

class CActiveAccount
{
public:
	char cUnknown1[4];
	char EMail[16]; //0004
	char cUnknown2[12];
	char Password[16]; //0020
	char cUnknown3[24];
	int PID; //0048
	char cUnknown[4];
	char Name[16]; //0050
};

class CInputDeviceManger
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual CInputDevice* GetDevice(int code);

	byte unknown0[4];
	map<int, CInputDevice*> devices; //0008
};

class CInputDevice
{
};

class CPlayerInfo
{
public:
	DWORD Unknown0; //0000
	char unknown1[4];
	DWORD Unknown2; //0008
	DWORD Unknown3; //000C
	char unknown4[4];
	CVehicle* Vehicle; //0014
	char unknown5[32];
	DWORD* Matrixstuff; //0038
	CVehicleHealth* VehicleHealth; //003C
	char Unknown6[120]; //0040
	float px; //00B8
	float py; //00BC
	float pz; //00C0
	DWORD Unknown7; //00C4
	char Unknown8[80]; //00C8
	char Unknown9[100]; //0118
	char Unknown10[100]; //017C
	BYTE SelectedWeapon; //01E0
	char Unknown11[27]; //01E1
	DWORD Unknown12; //01FC
	DWORD Unknown13; //0200
	char Unknown14[32]; //0204
	float pYAW; //0224
	float speedVr; //0228
	float speedVf; //022C
	__int32 Posture; //0230
	__int32 Posture2; //0234
	float pPITCH; //0238
	float Unknown15; //023C
	float YAWFactor; //0240
	__int32 Unknown16; //0244
	float YAWChangeSpeed; //0248
	BYTE PostureKey; //024C
	float Unknown17; //024D
	float Unknown18; //0251
};

class CDebugLineDrawer
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void DrawLine(void* pLine, DWORD dwColor, float flLength);
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	DWORD dwUnknown; // 4 
	DWORD dwUnknown1; // 8 
	ID3DXLine* m_pLine;

	void DrawFilledRect(float x0, float y0, float x1, float y1, DWORD dwColor)
	{
		float w = x1 - x0;
		float h = y1 - y0;

		m_pLine->SetWidth(h);
		m_pLine->SetAntialias(0);

		D3DXVECTOR2 VertexList[2];

		VertexList[0].x = x0;
		VertexList[0].y = y0 + (h / 2.0f);

		VertexList[1].x = x0 + w;
		VertexList[1].y = y0 + (h / 2.0f);

		m_pLine->Begin();
		m_pLine->Draw(VertexList, 2, dwColor);
		m_pLine->End();
	}

	void OutlineRect(float x, float y, float w, float h, DWORD dwColor, float flLineWidth = 1.0f)
	{
		m_pLine->SetWidth(flLineWidth);
		m_pLine->SetAntialias(0);

		D3DXVECTOR2 VertexList[5];

		VertexList[0].x = x;
		VertexList[0].y = y;

		VertexList[1].x = x + (w / 2.0f);
		VertexList[1].y = y;

		VertexList[2].x = x + (w / 2.0f);
		VertexList[2].y = y + (h / 2.0f);

		VertexList[3].x = x;
		VertexList[3].y = y + (h / 2.0f);

		VertexList[4].x = x;
		VertexList[4].y = y;

		m_pLine->Begin();
		m_pLine->Draw(VertexList, 5, dwColor);
		m_pLine->End();
	}
};

class CRayTest
{
public:
	CRayTest(CObject* obj);
	virtual BYTE TestObject(CObject* obj);
	virtual int  iGetMask(void);
	virtual BYTE function2(int a);
	virtual BYTE TestMaterial(int material);

	int mask;
	CObject* ignore_object;
};

class CDebugTextWriter
{
public:
	virtual void	AddRef(void);
	virtual int		GetRef(void);
	virtual void	Destructor(void);
	virtual bool	bVerifyGUID(DWORD dwId);
	virtual bool	bSetFontNeedsReload(bool bTest);
	virtual bool	bIsFontLoaded(void);
	virtual bool	bSetVisible(bool bVisible);
	virtual DWORD	dwGetTextColor();
	virtual void	SetColor(DWORD dwColor);

	virtual void DrawColouredTextin3dSpaceEX(void);
	virtual void DrawColouredTextin3dSpace(D3DXVECTOR3* pPos, DWORD dwColor, string* strText, float flTest);

	virtual void DrawTextColouredEX();
	virtual void DrawTextColoured(int x, int y, DWORD dwTextColor, string* strText, BOOL bIsConFont = 0);

	virtual void DrawTextCenteredin3dSpaceEX();
	virtual void DrawTextCenteredin3dSpace(D3DXVECTOR3* pPos, string* strText, float flTest);

	virtual void DrawTextEx(int x, int y, BOOL bIsConFont, BOOL bIsUnknown = 0, string* strText = NULL, BOOL bIsUnknown2 = 0);
	virtual void DrawText(int x, int y, string* strText, BOOL bIsConFont = 0);

	virtual void LoadFont();
	virtual void DestroyFont();
	DWORD		m_dwUnknown;
	void* m_pOverlay;

	void LoadNewFont(string* pstrFont) // Fonts/BF1942.font // Fonts/system_8x11 
	{
		//	if( m_pOverlay ) 
		//		m_pOverlay->Load( pstrFont ); 
	}
	// 2D is font loaded 
	// 30 is color 
};

class CMainConsole
{
public:
	virtual void Function0();// 0 
	virtual void Function1(); // 4 
	virtual void Exec(string* strCommand /*&string("command")*/, string* strUnknown/* = &string("")*/, int iUnknown1 = 0, int iUnknown2 = 0, int iUnknown3 = 0, int iUnknown4 = 0, int iUnknown5 = 0); // 8 
	virtual void Function3(); // C 
	virtual void Print(string* strText); // 10 
	virtual void Function5();// 14 
	virtual void Function6();// 18 
	virtual void Function7();// 1C 
	virtual void Draw(int iNumOfLines);// 20 
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual bool bIsConsoleOpen(void);
	BYTE m_bOpen; //0004 
	char unknown0[39];
	__int32 Unknown1; //002C 
	char unknown2[28];
	char m_szText[128]; //004C 
	char unknown3[8];
	__int32 m_iCharCount; //00D4 
};

class CTemplateManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	char unknown0[80];
	CTemplate* active_template; //0054 
};

class CHudMouse
{
public:
	char unknown0[56];
	float mouse_pos_x; //0038 
	float mouse_pos_y; //003C 
	float Unknown1; //0040 
	float Unknown2; //0044 
};

class CMinimap
{
public:
	virtual void Function0();
	char unknown0[905];
	BYTE showKits; //038D 
};

class CObjectManager
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual BYTE Intersect(CObject** inter_obj, D3DXVECTOR3* inter_point, D3DXVECTOR3* inter_angle, int* inter_mat, D3DXVECTOR3* ray_start, D3DXVECTOR3* ray_end, CRayTest* ray, BOOL unk1, BOOL unk2, BOOL unk3, BOOL unk4, BOOL unk5 = FALSE);
	char unknown0[28];
	CObject* active_object; //0020 
	char unknown1[60];
	vector<CObject*> object_list; //0060 

};

class CInputManager
{
public:
	virtual void IncRef();
	virtual int iGetRef();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void ImportMiscStuff();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual CActionBuffer* GetActionBuffer_nextFrame(void); // hook me 
	virtual CActionBuffer* GetActionBuffer_thisFrame(void);
	virtual bool bsIsCurrentFrame();
	virtual void AdvanceToNextFrame();
	virtual void Function17();
	virtual int iGetDelta(void);
	virtual void ConstructSelf(DWORD dwDontCare);
	char unknown0[36];
	__int32 dividend; //0028 
	__int32 divisor; //002C 
	char unknown1[4];
	CActionBuffer* actionBuffer; //0034 
};

class CActionBuffer
{
public:
	float inputKeys[64]; //0000 

	__int32 Unknown1; //0100 
	__int32 Unknown2; //0104 
	__int32 Unknown3; //0108 
	__int32 Unknown4; //010C 
	BYTE Unknown5; //0110 
};

class CVehicle
{
public:
	char unknown0[400];
	char EnemyType[7]; //0190
};

class CHudManager
{
public:
	virtual void Function0();
	char unknown0[272];
	CHudMouse* hud_mouse; //0114 
	CMinimap* minimap; //0118 
	char unknown1[64];
	CCommander_Assets* assets; //015C 
	char unknown2[28];
	BYTE mouseActive; //017C 
	char unknown3[35];
	__int32 mouse_pixel_per_unit; //01A0 
	char unknown4[204];
	__int32 menuOpened; //0270 
	char unknown5[108];
	BYTE Unknown6; //02E0 
	BYTE Unknown7; //02E1 
	BYTE Unknown8; //02E2 
	BYTE Unknown9; //02E3 
	char unknown10[4];
	float Artillery1_Heath; //02E8 
	char unknown11[4];
	float CarsHealth; //02F0 
};

class CCommander_Assets
{
public:
	virtual void Function0();
	char unknown0[12];
	float Artillery1Health; //0010 
	char unknown1[4];
	float Artillery2Health; //0018 
	char unknown2[36];
	float ArtilleryReloadTime; //0040 
	BYTE ArtilleryLoading; //0044 
	char unknown3[11];
	float SuppliesReloadTime; //0050 
	char unknown4[8];
	BYTE SuppliesLoading; //005C 
	char unknown5[7];
	BYTE Unknown6; //0064 
	char unknown7[19];
	float CarsLoadTime; //0078 
	float CarsHealth; //007C 
};

class CVehicleHealth
{
public:
	char unknown0[16];
	float Health; //0010
};

class CControlMapManager
{
public:
	virtual void Function0();
	char unknown0[32];
	CControlMap* active_controlmap; //0024 
};

class CControlMap
{
public:
	virtual void Function0();
	char unknown0[4];
	string cmap_name; //0008 

	char unknown3[28];
	float Unknown4; //0040 
	float Unknown5; //0044 
	float Unknown6; //0048 
	BYTE invertMouse; //004C 
	char unknown7[3];
	float mouse_sensitivity; //0050 
	float Unknown8; //0054 
	float deg_per_pixel_x; //0058 
	float deg_per_pixel_y; //005C 
	float Unknown9; //0060 
	float Unknown10; //0064 
	float yaw_factor; //0068 
	float pitch_factor; //006C 
};

class CClassManager
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual int GetClassPtrByName(string* szClassname); //
	__int32 m_RefCount; //0x0004  
	char unknown8[40]; //0x0008
	map<string, int> m_ClassMap; //0x0030 
	char unknown60[4]; //0x003C
	map<string, int> m_SomeMap; //0x0040 
};//Size=0x004C(76)

class CPlayerManager
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual CPlayer* GetPlayerByIndex(int Index); //virtual CPlayer* GetPlayerByIndex(int Index);
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual CPlayer* GetLocalPlayer();//virtual CPlayer* GetLocalPlayer();

char _0x0004[4];
	CPlayer* ActivePlayer; //0x0008 
char _0x000C[8];
	DWORD NumberOfPlayers; //0x0014 
char _0x0018[8];
	DWORD PlayersPerTeam; //0x0020 
char _0x0024[8];
	DWORD NumberOfPlayers_; //0x002C 
char _0x0030[32];
	__int32 TotalPlayers; //0x0050 
char _0x0054[12];
	CPlayer* LocalPlayer; //0x0060 
char _0x0064[28];

};//Size=0x0080

class CPlayer
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual char* GetName(); //virtual char* GetName();
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); // virtual CVehicle* Vehicle();
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual bool Alive();  //virtual bool Alive(); 
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual float getFOV(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void setSoldierObject(CObject* soldier); //
	virtual CObject* getSoldierObject(); //defaultvehicle
	virtual CCamera* getFreeCamera(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual int GetTeam(); //virtual int GetTeam();
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual int SquadID(); //virtual int SquadID();
	virtual void Function65(); //
	virtual bool IsCommander(); //virtual bool IsCommander();
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual int Ping(); //virtual int Ping();
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual int FlagHolder(); //virtual int FlagHolder();
	virtual CCamera* GetViewMatrix(); //virtual CCamera* GetViewMatrix();
	virtual void Function93(); //
	virtual void Function94(); //
	virtual CCamera* GetPlayerView(void); //virtual CCamera* GetPlayerView(void);
	virtual void Function96(); //
	virtual void Function97(); //

	char _0x0004[84];
	__int32 Kit; //0x0058 
	char _0x005C[4];
	string Name; //0x0060 
	char _0x007C[4];
	CInfo* PlayerObj; //0x0080 
	CCamera* Camera; //0x0084 
	char _0x0088[44];
	__int32 PlayerSeat; //0x00B4 
	__int32 PlayerCode; //0x00B8 wtf?
	char _0x00BC[4];
	float viewFOV; //0x00C0   
	float Zoom; //0x00C4 
	char _0x00C8[4];
	CSoldierPtr* SoldierObj; //0x00CC 
	char _0x00D0[5]; //0x00D0 
	BYTE iAlive; //0x00D5 
	char _0x00D6[2];
	__int32 iTeam; //0x00D8 
	char _0x00DC[28];
	DWORD iPing; //0x00F8 
	char _0x00FC[16];
	__int32 Squad_Number; //0x010C 
	BYTE commander; //0x0110 
	BYTE Squad_Leader; //0x0111 
	char _0x0112[102];
	BYTE InVehicle; //0x0178  1 = OnFoot || 2 = OnVehicle
	char N00F34823[3]; //0x0179 
	char _0x017C[8];
	BYTE primary_fire_down; //0x0184 
	BYTE secondary_fire_down; //0x0185 
	BYTE N0039672D; //0x0186 
	BYTE Sprinting; //0x0187 
	char _0x0188[68];
	__int32 Weapon_Ammo; //0x01CC 
	char _0x01D0[8];
	__int32 Weapon_MaxAmmo; //0x01D8 
	char _0x01DC[8];
	__int32 Weapon_Firemode; //0x01E4 
	char _0x01E8[8];
	__int32 Weapon_Zoomed; //0x01F0 
	char _0x01F4[8];
	__int32 Weapon_Mags; //0x01FC 
	char _0x0200[8];
	__int32 Weapon_Max_Mags; //0x0208 
	char _0x020C[8];
	float Weapon_Heat_Primary; //0x0214 
	char _0x0218[56];
	__int32 Vehicle_Pilot; //0x0250 
	BYTE weaponInfiniteAmmo; //0x0254 
	WORD N003D7618; //0x0255 
	BYTE N003D7619; //0x0257 
	float Weapon_Overheat_Primary; //0x0258 
	float Weapon_Overheat_Secondary; //0x025C 
	char _0x0260[464];

};//Size=0x0430

class CViewMatrix
{
public:
	char unknown0[184];
	float V11; //00B8
	float V12; //00BC
	float V13; //00C0
	float V14; //00C4
	float V21; //00C8
	float V22; //00CC
	float V23; //00D0
	float V24; //00D4
	float V31; //00D8
	float V32; //00DC
	float V33; //00E0
	float V34; //00E4
	float V41; //00E8
	float V42; //00EC
	float V43; //00F0
	float V44; //00F4
};

class CObject
{
public:
	char _0x0000[4];
	DWORD ObjectFlags; //0x0004 Untested
	char _0x0008[4];
	CObject* Obj_Root; //0x000C 
	char _0x0010[4];
	CTemplate* Obj_Template; //0x0014 
	char _0x0018[36];
	CHealth* Health; //0x003C 
	char _0x0040[4];
	CPhysicsNode* objectPhysics; //0x0044 
	char _0x0048[64];
	D3DXMATRIX Matrix; //0x0088 
	D3DXMATRIX N01292717; //0x00C8 
	char _0x0108[256];
};//Size=0x0208

class CHealth
{
public:
	char _0x0000[16];
	float Health; //0x0010 
	char _0x0014[108];
};//Size=0x0080

class CLocalProfile
{
public:
	string profileFolder; //0000
	string name; //001C
	string nick; //0038
	string gamespyNick; //0054
	string email; //0070
	string password; //008C
	float totalPlayedTime; //00A8
	__int32 numTimesLoggedIn; //00AC
};

class CSpreadTable
{
public:
	float table[1024]; //0x0000  
};//Size=0x0400(1024) 

const D3DCOLOR TextOutline = D3DCOLOR_RGBA(0, 0, 0, 200);

class CTextWriter
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void DrawText(int x, int y, DWORD txColor, string* Text, BOOL SomeWtfParm = 0);

	void ShadowedText(int x, int y, DWORD txColor, string* Text)
	{
		DrawText(x - 1, y, TextOutline, Text);
		DrawText(x + 1, y, TextOutline, Text);
		DrawText(x, y - 1, TextOutline, Text);
		DrawText(x, y + 1, TextOutline, Text);
		DrawText(x, y, txColor, Text);
	}
};

class CSoldierPtr
{
public:
	char _0x0000[4];
	CSoldier* Ptr; //0x0004 
	char _0x0008[56];
};//Size=0x0040

class CSoldier
{
public:
	char _0x0000[20];
	CTemplate* Obj_Template; //0x0014 
	char _0x0018[36];
	CHealth* Health; //0x003C 
	char _0x0040[4];
	CPhysicsNode* objectPhysics; //0x0044
	char _0x0048[64];
	D3DXMATRIX Matrix; //0x0088
	char _0x00C8[240];
	CWeapon* Player_Weapon; //0x01B8 
	char _0x01BC[36];
	__int32 Current_Weapon_Slot; //0x01E0 
	char _0x01E4[64];
	float N01453A9F; //0x0224 
	float N01453AA0; //0x0228 
	float N01453AA1; //0x022C 
	__int32 sPosture; //0x0230 
	__int32 sCurPosture; //0x0234 
	float Head_Pitch; //0x0238 
	float Head_Pitch_Change; //0x023C 
	float Head_Yaw; //0x0240 
	float Head_Yaw_Change; //0x0244 
	char _0x0248[64];
	CSkeleton* Skeleton_1P; //0x0288 
	char _0x028C[4];
	CSkeleton* Skeleton_3P; //0x0290 
	char _0x0294[20];
};//Size=0x02A8

class CWeapon
{
public:
	char _0x0000[136];
	D3DXMATRIX w_matrix; //0x0088 
	char _0x00C8[216];
	CDeviation* Weapon_Deviation; //0x01A0 
	char _0x01A4[68];
	CTemplate* Weapon_Template; //0x01E8 
	char _0x01EC[8];
};//Size=0x01F4

class CDeviation
{
public:
	char _0x0000[4];
	float DeviationTotal; //0x0004 
	char _0x0008[48];
};//Size=0x0038

class CSkeleton
{
public:
	char _0x0000[8];
	CBone* Bones; //0x0008 
	char _0x000C[4];
	D3DXMATRIX* matrices;; //0x0010 
	__int32 iTotBones; //0x0014 
	char _0x0018[232];
};//Size=0x0100

class CBone
{
public:
	__int32 Bone_Number; //0x0000 
	__int16 Bone_Code; //0x0004 
	__int16 Bone_Parent; //0x0006 
	char _0x0008[4];
	float Bone_Ofs_x; //0x000C 
	float Bone_Ofs_y; //0x0010 
	float Bone_Ofs_z; //0x0014 
	float Bone_Lenght; //0x0018 
	float Bone_Radius; //0x001C 
	__int32 Bone_Material; //0x0020 
	char _0x0024[28];
};//Size=0x0040

class CRenderer
{
public:
	char _0x0000[8];
	IDirect3D9* Direct3D_Device; //0x0008 
	IDirect3DDevice9* Game_Device; //0x000C  
	char _0x0010[20];
	D3DXVECTOR2 ScreenInfo; //0x0024 
	char _0x002C[1648];
	BYTE N00FA8F34; //0x069C 
	BYTE N01061B57; //0x069D 
	BYTE N01053840; //0x069E 
	BYTE bDrawWater; //0x069F 
	BYTE N00FA8F33; //0x06A0 
	BYTE N01048FDA; //0x06A1 
	BYTE N0104978B; //0x06A2 
	BYTE bShowBodies; //0x06A3 
	BYTE N00FA8F32; //0x06A4 
	BYTE bShowGround; //0x06A5 
	BYTE bShowGrass; //0x06A6 
	BYTE bShowThrees; //0x06A7 
	BYTE bShowFriendlyTags; //0x06A8 Nametags
	BYTE N00FBAEB4; //0x06A9 
	BYTE N00FC0334; //0x06AA 
	BYTE N00FBAEB5; //0x06AB 
	__int32 DrawFps; //0x06AC 
	BYTE N00DCC523; //0x06B0 
	BYTE bShowHud; //0x06B1 
	BYTE bDrawSky; //0x06B2 
	BYTE bDrawSunFlare; //0x06B3 
	BYTE bDrawConsole; //0x06B4 
};//Size=0x06B5

class CGlobalSettings
{
public:
	virtual void Function0();
	__int32 refCount; //0048
	string defaultUser; //004C
	string namePrefix; //0068
};

class CHudText
{
public:
	char unknown0[164];
	CHudTextMngr* cHudTxt; //00A8
};
class CHudTextMngr
{
public:
	char unknown0[8];
	CONST INT ChatTxt; //0008 this is where txt is to be written
};

class CTemplate
{
public:
	virtual void function0(); //
	virtual void function1(); //
	virtual void function2(); //
	virtual void function3(); //
	virtual unsigned long getTemplateID(); //
	virtual void function5(); //
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual string* getTemplateName(); //
	virtual void function11(); //
	virtual void function12(); //
	virtual void function13(); //
	virtual void function14(); //
	virtual void function15(); //
	virtual void function16(); //
	virtual void function17(); //
	virtual void function18(); //
	virtual void function19(); //
	virtual void function20(); //
	virtual void function21(); //
	virtual CComponent* getComponentByID(unsigned long); //
	char unknown4[8]; //0x0004
	string templateName; //0x000C  
	string networkLableInfo; //0x0028  
	char unknown68[4]; //0x0044
	DWORD templateFlags; //0x0048  
	map<int, CComponent*> componentMap; //0x004C  
	char unknown88[8]; //0x0058
};//Size=0x0060(96)

class CPhysicsManager
{
public:
	__int32 ID041C65F0; //0x0000  
	char unknown4[60]; //0x0004
};//Size=0x0040(64)

class CPhysicsNode
{
public:
	virtual void function0(); //
	char unknown4[12]; //0x0004
	CObject* ownerObject; //0x0010  
	char unknown20[12]; //0x0014
	D3DXVECTOR3 impulseForce; //0x0020  
	char unknown44[36]; //0x002C
	float drag; //0x0050  
	float mass; //0x0054  
	float gravityModefier; //0x0058  
	char unknown92[4]; //0x005C
	BYTE hasDriver; //0x0060  
	char unknown97[11]; //0x0061
	D3DXVECTOR3 position; //0x006C  
	D3DXVECTOR3 speed; //0x0078  
	float floaterMod; //0x0084  
	char unknown136[12]; //0x0088
	D3DXVECTOR3 rotation; //0x0094  
};//Size=0x00A0(160)

class CComponent
{
public:
	virtual int addRef(); //
	virtual int getRef(); //
	virtual int release(); //
	virtual void* queryInterface(int); //
	virtual unsigned long getComponentID(); //
	virtual unsigned long getComponentCID(); //
};//Size=0x0004(4)


class CCamera
{
public:
	virtual void function0(); //
	virtual void function1(); //
	virtual void function2(); //
	virtual void function3(); //
	virtual void function4(); //
	virtual void function5(); //
	virtual void function6(); //
	virtual void function7(); //
	virtual void function8(); //
	virtual void function9(); //
	virtual void function10(); //
	virtual void function11(); //
	virtual void function12(); //
	virtual void function13(); //
	virtual void function14(); //
	virtual void function15(); //
	virtual void function16(); //
	virtual void function17(); //
	virtual void function18(); //
	virtual void function19(); //
	virtual void function20(); //
	virtual void function21(); //
	virtual float getInsideFOV(); //
	char unknown4[4]; //0x0004
	__int32 cameraPerspective; //0x0008  
	char unknown12[172]; //0x000C
	D3DXMATRIX cameraMatrix; //0x00B8


	D3DXVECTOR3* getViewRight()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&cameraMatrix.m[0][0]);
	}

	D3DXVECTOR3* getViewUp()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&cameraMatrix.m[1][0]);
	}

	D3DXVECTOR3* getViewDirection()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&cameraMatrix.m[2][0]);
	}

	D3DXVECTOR3* getViewPosition()
	{
		return reinterpret_cast<D3DXVECTOR3*>(&cameraMatrix.m[3][0]);
	}
};//Size=0x00F8(248)

//Portable Class Manager Stuff
BYTE szClassManagerPatt;
char* szClassManagerMask;

//FindPattern Function
DWORD FindPattern(DWORD base, DWORD size, BYTE pattern[], char mask[])
{
	for (DWORD retAddress = base; retAddress < (base + size); retAddress++)
	{
		if (*(BYTE*)retAddress == (pattern[0] & 0xff) || mask[0] == '?')
		{
			DWORD startSearch = retAddress;
			for (int i = 0; mask[i] != '\0'; i++, startSearch++)
			{
				if (mask[i] == '?')
					continue;

				if ((pattern[i] & 0xff) != *(BYTE*)startSearch)
					break;

				if ((pattern[i] & 0xff) == *(BYTE*)startSearch && mask[i + 1] == '\0')
					return retAddress;
			}
		}
	}
	return NULL;
}

void iPatchIt(DWORD dest, void* src, size_t size)
{
	DWORD oProtect = NULL;
	VirtualProtect((void*)dest, size, PAGE_EXECUTE_READWRITE, &oProtect);
	memcpy((void*)dest, src, size);
	VirtualProtect((void*)dest, size, oProtect, NULL);
}

CClassManager* getBFClassManager(void)
{
	HMODULE hModule = NULL;
	while (hModule == NULL)
	{
		hModule = GetModuleHandle("RendDx9.dll");
		if (hModule == NULL) Sleep(200);
	}

	DWORD dwInitDLL = (DWORD)GetProcAddress(hModule, "initDll");
	CloseHandle(hModule);
	DWORD* ptr = 0;

	if (dwInitDLL)
	{
		DWORD dwPointerOffset = FindPattern(dwInitDLL, dwInitDLL + 512, (BYTE*)szClassManagerPatt, szClassManagerMask);
		if (dwPointerOffset)
		{
			ptr = (DWORD*)(dwPointerOffset + 2);
		}
	}

	size_t Length = strlen(szClassManagerMask);
	ZeroMemory((void*)szClassManagerPatt, Length);
	ZeroMemory((void*)szClassManagerMask, Length);

	if (ptr)
		return *((CClassManager**)((DWORD)*ptr));

	return 0;
}

//==========================================================================================
//Class Setup
//==========================================================================================
CMainConsole* MainConsole = (NULL);
CProfileManager* ProfileManager = (NULL);
CInputManager* InputManager = (NULL);
CPhysicsManager* PhysicsManager = (NULL);
CInputDeviceManger* InputDeviceManager = (NULL);
CControlMapManager* ControlMapManager = (NULL);
CObjectManager* ObjectManager = (NULL);
CTemplateManager* TemplateManager = (NULL);
CPlayerManager* PlayerManager = (NULL);
CPlayer* Player = (NULL);
CSoldier* Soldier = (NULL);
CHudManager* HudManager = (NULL);
CDebugTextWriter* TextWriter = (NULL);
CDebugLineDrawer* LineDrawer = (NULL);
CRenderer* Renderer = (NULL);
CClassManager* ClassManager = (NULL);
CSpreadTable* SpreadTable = (NULL);
CLocalProfile* LocalPlayer = (NULL);

class cPointer;

class cPointer
{
private:
public:
	CClassManager* GetClassManager(void);
	CPlayerManager* GetPlayerManager(void);
	void                UpdatePointer(void);
};

cPointer Pointer;

CClassManager* cPointer::GetClassManager(void)
{
	return *(CClassManager**)+(DWORD)BF2_CLASSMANAGER;
}

CPlayerManager* cPointer::GetPlayerManager(void)
{
	return *(CPlayerManager**)+(DWORD)BF2_PLAYERMANAGER_OFFSET;
}

void cPointer::UpdatePointer(void)
{
	ClassManager = *(CClassManager**)((PDWORD)0x09FF960);
	PlayerManager = *(CPlayerManager**)((PDWORD)0xA08F60);
	//LocalPlayer = *(CLocalProfile**)((PDWORD)(PlayerManager + 0x0060));
	ObjectManager = *(CObjectManager**)((PDWORD)BF2_BASE + 0xD9034);
	//HudManager = *(CHudManager**)(getBFClassManager()->GetClassPtrByName(&string("HudManager")));
	//Renderer = *(CRenderer**)(getBFClassManager()->GetClassPtrByName(&string("Renderer")));
	//Player = *(CPlayer**)(getBFClassManager()->GetClassPtrByName(&string("Player")));
	//Soldier = *(CSoldier**)(getBFClassManager()->GetClassPtrByName(&string("Soldier")));
	//LocalPlayer = *(CLocalProfile**)(getBFClassManager()->GetClassPtrByName(&string("LocalProfile")));
	//SpreadTable = *(CSpreadTable**)((PDWORD)0x09F4DB0);
	//MainConsole = *(CMainConsole**)(getBFClassManager()->GetClassPtrByName(&string("MainConsole")));
	//ProfileManager = *(CProfileManager**)(getBFClassManager()->GetClassPtrByName(&string("ProfileManager")));
	//InputManager = *(CInputManager**)(getBFClassManager()->GetClassPtrByName(&string("InputManager")));
	//PhysicsManager = *(CPhysicsManager**)(getBFClassManager()->GetClassPtrByName(&string("PhysicsManager")));
	//InputDeviceManager = *(CInputDeviceManger**)(getBFClassManager()->GetClassPtrByName(&string("InputDeviceManager")));
	//ControlMapManager = *(CControlMapManager**)(getBFClassManager()->GetClassPtrByName(&string("ControlMapManager")));
	//TemplateManager = *(CTemplateManager**)(getBFClassManager()->GetClassPtrByName(&string("TemplateManager")));
	//TextWriter = *(CDebugTextWriter**)(getBFClassManager()->GetClassPtrByName(&string("DebugTextWriter")));
	//LineDrawer = *(CDebugLineDrawer**)(getBFClassManager()->GetClassPtrByName(&string("DebugLineDrawer")));
	Classes_Intialized = TRUE;
}

void WriteToMemory(DWORD addressToWrite, char* valueToWrite, int byteNum)
{
	//used to change our file access type, stores the old
	//access type and restores it after memory is written
	unsigned long OldProtection;
	//give that address read and write permissions and store the old permissions at oldProtection
	VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &OldProtection);

	//write the memory into the program and overwrite previous value
	memcpy((LPVOID)addressToWrite, valueToWrite, byteNum);

	//reset the permissions of the address back to oldProtection after writting memory
	VirtualProtect((LPVOID)(addressToWrite), byteNum, OldProtection, NULL);
}

DWORD FindDmaAddy(int PointerLevel, DWORD Offsets[], DWORD BaseAddress)
{
	//DEFINES OUR ADDRESS to write to
	//if statements are crucial to make sure that the address is valid to write
	//otherwise we crash. Address will not be valid when things like map changes or game loads are happening
	DWORD Ptr = *(DWORD*)(BaseAddress); //Base Address
	if (Ptr == 0) return NULL;//prevent crash

	//this is done to allow us to have pointers up to many levels e.g.10
	for (int i = 0; i < PointerLevel; i++)
	{
		//if it = PointerLevel-1 then it reached the last element of the array
		//therefore check if that address plus the offset is valid and leave the loop
		if (i == PointerLevel - 1)
		{
			//!!make sure the last address doesnt have the asterisk on DWORD otherwise incoming crash
			Ptr = (DWORD)(Ptr + Offsets[i]);  //Add the final offset to the pointer
			if (Ptr == 0) return NULL;//prevent crash
			//we here return early because when it hits the last element
			//we want to leave the loop, specially adapted for offsets of 1
			return Ptr;
		}
		else
		{
			//if its just a normal offset then add it to the address
			Ptr = *(DWORD*)(Ptr + Offsets[i]); //Add the offsets
			if (Ptr == 0) return NULL;//prevent crash
		}
	}
	return Ptr;
}

//==========================================================================================
//DEBUGGING STUFF
//==========================================================================================
char* GetIniString(const char* IniFile, const char* section, const char* name, char* buffer, const char* def_val = 0) {

	int len = strlen(buffer);

	if (IniFile) GetPrivateProfileString(section, name, def_val, buffer, len, IniFile);
	else strcpy(buffer, def_val);

	return buffer;
}

//================================================================================
//DRAWING STUFF
//================================================================================
class CDraw
{
public:
	void Rectangle(float x, float y, float w, float h, float line_width, int transparency, int border1Col, int border2Col);
	void Rectangle2(float x, float y, float w, float h, float line_width, int a, int r, int g, int b);
	void FilledBox(float x, float y, float w, int h, int a, int r, int g, int b);
	void Crosshair(float x, float y, int a, int r, int g, int b);
	void Text(const char* text, int x, int y, int Red, int Green, int Blue, int Alpha, LPD3DXFONT Font);
	void BlackBorderText(const char* string, int x, int y, int red, int green, int blue, int alpha, LPD3DXFONT font);
	void Dot(float x, float y, int a, int r, int g, int b);
	void Circle(int X, int Y, int radius, int numSides, int a, int r, int g, int b);
	void GUIbox(int x, int y, float w, float h, float line, int alpha, int r, int g, int b, int Border1Col, int Border2Col);
	void InitStuff(IDirect3DDevice9* m_pD3Ddev);
};
CDraw Draw;

//____________________________________________________________________________________
void CDraw::Rectangle(float x, float y, float w, float h, float line_width, int transparency, int border1Col, int border2Col)
{
	if (!IsBadReadPtr(dLine, sizeof(ID3DXLine)))
	{
		D3DXVECTOR2 vLine1[2];
		D3DXVECTOR2 vLine2[2];
		D3DXVECTOR2 vLine3[2];
		D3DXVECTOR2 vLine4[2];

		dLine[0]->SetWidth(line_width);
		dLine[0]->SetAntialias(false);
		dLine[0]->SetGLLines(false);

		vLine1[0].x = x;
		vLine1[0].y = y;
		vLine1[1].x = x;
		vLine1[1].y = y + h;

		vLine2[0].x = x + w;
		vLine2[0].y = y;
		vLine2[1].x = x + w;
		vLine2[1].y = y + h;

		vLine3[0].x = x;
		vLine3[0].y = y;
		vLine3[1].x = x + w;
		vLine3[1].y = y;

		vLine4[0].x = x;
		vLine4[0].y = y + h;
		vLine4[1].x = x + w;
		vLine4[1].y = y + h;

		dLine[0]->Begin();
		dLine[0]->Draw(vLine1, 2, D3DCOLOR_ARGB(transparency, border1Col, border1Col, border1Col));
		dLine[0]->Draw(vLine2, 2, D3DCOLOR_ARGB(transparency, border2Col, border2Col, border2Col));
		dLine[0]->Draw(vLine3, 2, D3DCOLOR_ARGB(transparency, border1Col, border1Col, border1Col));
		dLine[0]->Draw(vLine4, 2, D3DCOLOR_ARGB(transparency, border2Col, border2Col, border2Col));
		dLine[0]->End();
	}
}

void CDraw::Rectangle2(float x, float y, float w, float h, float line_width, int a, int r, int g, int b)
{
	if (!IsBadReadPtr(dLine[1], sizeof(ID3DXLine)))
	{
		D3DXVECTOR2 vLine1[2];
		D3DXVECTOR2 vLine2[2];
		D3DXVECTOR2 vLine3[2];
		D3DXVECTOR2 vLine4[2];

		dLine[1]->SetWidth(line_width);
		dLine[1]->SetAntialias(false);
		dLine[1]->SetGLLines(false);

		vLine1[0].x = x;
		vLine1[0].y = y;
		vLine1[1].x = x;
		vLine1[1].y = y + h;

		vLine2[0].x = x + w;
		vLine2[0].y = y;
		vLine2[1].x = x + w;
		vLine2[1].y = y + h;

		vLine3[0].x = x;
		vLine3[0].y = y;
		vLine3[1].x = x + w;
		vLine3[1].y = y;

		vLine4[0].x = x;
		vLine4[0].y = y + h;
		vLine4[1].x = x + w;
		vLine4[1].y = y + h;

		dLine[1]->Begin();
		dLine[1]->Draw(vLine1, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[1]->Draw(vLine2, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[1]->Draw(vLine3, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[1]->Draw(vLine4, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[1]->End();
	}
}

//____________________________________________________________________________________
void CDraw::FilledBox(float x, float y, float w, int h, int a, int r, int g, int b)
{
	if (!IsBadReadPtr(dLine[2], sizeof(ID3DXLine)))
	{
		D3DXVECTOR2 vLine[2];

		dLine[2]->SetWidth(w);
		dLine[2]->SetAntialias(false);
		dLine[2]->SetGLLines(false);

		vLine[0].x = x + w / 2;
		vLine[0].y = y;
		vLine[1].x = x + w / 2;
		vLine[1].y = y + h;

		dLine[2]->Begin();
		dLine[2]->Draw(vLine, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[2]->End();
	}
}

void CDraw::GUIbox(int x, int y, float w, float h, float line, int alpha, int r, int g, int b, int Border1Col, int Border2Col)
{
	Draw.FilledBox(x, y, w, h, alpha, r, g, b);
	Draw.Rectangle(x, y, w, h, line, 255, Border1Col, Border2Col);
}

//____________________________________________________________________________________
void CDraw::Crosshair(float x, float y, int a, int r, int g, int b) //fill rgb
{
	if (!IsBadReadPtr(dLine[3], sizeof(ID3DXLine)))
	{
		D3DXVECTOR2 vLine1[2];
		D3DXVECTOR2 vLine2[2];
		dLine[3]->SetWidth(1);
		dLine[3]->SetAntialias(true);
		dLine[3]->SetGLLines(false);

		vLine1[0].x = x - 8;
		vLine1[0].y = y;
		vLine1[1].x = x + 8;
		vLine1[1].y = y;

		vLine2[0].x = x;
		vLine2[0].y = y - 8;
		vLine2[1].x = x;
		vLine2[1].y = y + 8;

		dLine[3]->Begin();
		dLine[3]->Draw(vLine1, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[3]->Draw(vLine2, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[3]->End();
	}
}

//____________________________________________________________________________________
void CDraw::Text(const char* text, int x, int y, int Red, int Green, int Blue, int Alpha, LPD3DXFONT Font)
{
	D3DCOLOR fontColor = D3DCOLOR_ARGB(Alpha, Red, Green, Blue);
	RECT rct = { x, y, 0, 0 };
	va_list va_alist;
	char logbuf[256] = { 0 };
	va_start(va_alist, text);
	_vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
	va_end(va_alist);
	Font->DrawText(NULL, logbuf, -1, &rct, DT_CALCRECT, 0);
	Font->DrawText(NULL, logbuf, -1, &rct, DT_LEFT, fontColor);
}
//____________________________________________________________________________________
void CDraw::BlackBorderText(const char* string, int x, int y, int red, int green, int blue, int alpha, LPD3DXFONT font)
{
	Draw.Text(string, x + 1, y, 0, 0, 0, 255, font);
	Draw.Text(string, x - 1, y, 0, 0, 0, 255, font);
	Draw.Text(string, x, y + 1, 0, 0, 0, 255, font);
	Draw.Text(string, x, y - 1, 0, 0, 0, 255, font);
	Draw.Text(string, x, y, red, green, blue, alpha, font);
}
//____________________________________________________________________________________
void CDraw::Dot(float x, float y, int a, int r, int g, int b)
{
	float w = 4;
	float h = 4;
	x = (x - (w / 2));
	y = (y - (h / 2));

	if (!IsBadReadPtr(dLine[4], sizeof(ID3DXLine)))
	{
		D3DXVECTOR2 vLine[2];

		dLine[4]->SetWidth(w);
		dLine[4]->SetAntialias(true);
		dLine[4]->SetGLLines(true);

		vLine[0].x = x + w / 2;
		vLine[0].y = y;
		vLine[1].x = x + w / 2;
		vLine[1].y = y + h;

		dLine[4]->Begin();
		dLine[4]->Draw(vLine, 2, D3DCOLOR_ARGB(a, r, g, b));
		dLine[4]->End();
	}
}

//____________________________________________________________________________________
void CDraw::Circle(int X, int Y, int radius, int numSides, int a, int r, int g, int b)
{
	D3DXVECTOR2 Line[128];
	float Step = M_PI * 2.0 / numSides;
	int Count = 0;
	dLine[5]->SetWidth(1);
	dLine[5]->SetAntialias(false);
	dLine[5]->SetGLLines(false);
	for (float index = 0; index < M_PI * 2.0; index += Step)
	{
		float X1 = radius * cos(index) + X;
		float Y1 = radius * sin(index) + Y;
		float X2 = radius * cos(index + Step) + X;
		float Y2 = radius * sin(index + Step) + Y;
		Line[Count].x = X1;
		Line[Count].y = Y1;
		Line[Count + 1].x = X2;
		Line[Count + 1].y = Y2;
		Count += 2;
	}
	dLine[5]->Begin();
	dLine[5]->Draw(Line, Count, D3DCOLOR_ARGB(a, r, g, b));
	dLine[5]->End();
}

ID3DXBuffer* pShaderBuf = NULL;
HRESULT GenerateShader(IDirect3DDevice9* pD3Ddev, IDirect3DPixelShader9** pShader, float r, float g, float b)
{
	char szShader[256];
	sprintf(szShader, "ps.1.4\ndef c0, %f, %f, %f, %f\nmov r0,c0", r, g, b, 1.0f);
	D3DXAssembleShader(szShader, sizeof(szShader), NULL, NULL, 0, &pShaderBuf, NULL);
	if (FAILED(pD3Ddev->CreatePixelShader((const DWORD*)pShaderBuf->GetBufferPointer(), pShader)))return E_FAIL;
	return S_OK;
}

//============================================================================================================
//Shader Stuff
//============================================================================================================
char ShaderAdd[] = "ps.1.0 def c0, 0.0f, 0.0f, 0.0f, 0.0f tex t0 add r0, c0, t0";
//unsigned int g_uiStride = NULL;

HRESULT CreateMyShader(IDirect3DDevice9* pDevice, IDirect3DPixelShader9** pShader, float red, float green, float blue, float alpha)
{
	ID3DXBuffer* MyBuffer = NULL;
	char MyShader[256];
	sprintf_s(MyShader, "ps.1.1\ndef c0, %f, %f, %f, %f\nmov r0,c0", red / 255, green / 255, blue / 255, alpha / 255);
	D3DXAssembleShader(MyShader, sizeof(MyShader), NULL, NULL, 0, &MyBuffer, NULL);
	if (FAILED(pDevice->CreatePixelShader((const DWORD*)MyBuffer->GetBufferPointer(), pShader)))return E_FAIL;
	return S_OK;
}

struct shaders
{
	IDirect3DPixelShader9* PixelShader[12];
}; shaders sa;

//====================================================================================================================
//COLOUR BYTES START =================================================================================================
//====================================================================================================================

const BYTE bred[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00
};
const BYTE byellow[60] =
{
	0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x01
};
const BYTE bgreen[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00
};
const BYTE bblue[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
};
const BYTE bpurple[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00
};
const BYTE bpink[58] =
{
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0xFF, 0x00
};
const BYTE borange[58] = {
	0x42, 0x4D, 0x3A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA5, 0xFF, 0x00
};
const BYTE blightblue[60] =
{
	0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00
};
const BYTE bPURPLE[60] =
{
	0x42, 0x4D, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01,
	0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x12, 0x0B, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x50, 0x10, 0x40, 0xD0, 0x20, 0xE1
};

//====================================================================================================================
//COLOUR BYTES END ===================================================================================================
//====================================================================================================================

void CDraw::InitStuff(IDirect3DDevice9* m_pD3Ddev)
{
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&bblue, sizeof(bblue), &TexBlue);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&bgreen, sizeof(bgreen), &TexGreen);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&bred, sizeof(bred), &TexRed);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&byellow, sizeof(byellow), &TexYellow);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&bpink, sizeof(bpink), &TexPink);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&bpurple, sizeof(bpurple), &TexPurple);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&borange, sizeof(borange), &TexOrange);
	D3DXCreateTextureFromFileInMemory(m_pD3Ddev, (LPCVOID)&blightblue, sizeof(blightblue), &TexLB);
	CreateMyShader(m_pD3Ddev, &Blue2, 0, 0, 255, 255);//blue
	CreateMyShader(m_pD3Ddev, &Green2, 0, 255, 0, 255);//green
	CreateMyShader(m_pD3Ddev, &Red2, 255, 0, 0, 255);//red
	CreateMyShader(m_pD3Ddev, &Yellow2, 255, 255, 0, 255);//yellow
	CreateMyShader(m_pD3Ddev, &Orange2, 255, 128, 0, 255);//orange
	CreateMyShader(m_pD3Ddev, &Purple2, 255, 0, 255, 255);//purple
	CreateMyShader(m_pD3Ddev, &Pink2, 255, 51, 255, 255);//pink
	CreateMyShader(m_pD3Ddev, &Teal2, 51, 255, 255, 255);//teal
	CreateMyShader(m_pD3Ddev, &Trans2, 255, 255, 255, 255);//transparent

	//fonts
	D3DXCreateFont(m_pD3Ddev, 12, 0, FW_MEDIUM, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Microsoft Sans Serif", &dFont[0]);//
	D3DXCreateFont(m_pD3Ddev, 12, 0, FW_BOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Tahoma", &dFont[1]);
	D3DXCreateFont(m_pD3Ddev, 13, 0, FW_SEMIBOLD, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Times New Roman", &dFont[2]);
	D3DXCreateFont(m_pD3Ddev, 12, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &dFont[3]);
	D3DXCreateFont(m_pD3Ddev, 13, 0, FW_SEMIBOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Comic Sans MS", &dFont[4]);
	D3DXCreateFont(m_pD3Ddev, 14, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New", &dFont[5]);
	D3DXCreateFont(m_pD3Ddev, 12, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Georgia", &dFont[6]);
	D3DXCreateFont(m_pD3Ddev, 13, 0, FW_SEMIBOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Impact", &dFont[7]);
	D3DXCreateFont(m_pD3Ddev, 10, 0, FW_SEMIBOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Lucida Console", &dFont[8]);
	D3DXCreateFont(m_pD3Ddev, 12, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Verdana", &dFont[9]);
	D3DXCreateFont(m_pD3Ddev, 12, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Times New Roman", &dFont[10]);
	D3DXCreateFont(m_pD3Ddev, 38, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &dFont[11]);
	D3DXCreateFont(m_pD3Ddev, 14, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &dFont[12]);
	D3DXCreateFont(m_pD3Ddev, 48, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Courier New", &dFont[13]);

	//creates lines
	D3DXCreateLine(m_pD3Ddev, &dLine[0]);
	D3DXCreateLine(m_pD3Ddev, &dLine[1]);
	D3DXCreateLine(m_pD3Ddev, &dLine[2]);
	D3DXCreateLine(m_pD3Ddev, &dLine[3]);
	D3DXCreateLine(m_pD3Ddev, &dLine[4]);
	D3DXCreateLine(m_pD3Ddev, &dLine[5]);

	//Complete, Now Disable this Function
	bInitOnce = false;

	//Enable Watermark
	EnableWM = 1;
}

void DrawShadowText(int x, int y, D3DCOLOR color, const char* String, const char* cFmt, ...)
{
	RECT Font;
	Font.bottom = 0;
	Font.left = x;
	Font.top = y;
	Font.right = 0;

	RECT Fonts;
	Fonts.bottom = 0;
	Fonts.left = x + 1;
	Fonts.top = y + 1;
	Fonts.right = 0;

	pFont->DrawTextA(0, String, strlen(String), &Fonts, DT_NOCLIP, 0xFF010101);
	pFont->DrawTextA(0, String, strlen(String), &Font, DT_NOCLIP, color);
}

void DrawString(int x, int y, D3DCOLOR color, const char* fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = { '\0' };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	pFont->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void DrawRect(IDirect3DDevice9* dev, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT BarRect = { x, y, x + w, y + h };
	dev->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);
}

void Button(IDirect3DDevice9* dev, int x, int y, int w, int h, D3DCOLOR Outline)
{
	DrawRect(dev, x, y, w, 1, Outline);
	DrawRect(dev, x, y, 1, h, Outline);
	DrawRect(dev, x + w, y, 1, h, Outline);
	DrawRect(dev, x, y + h, w, 1, Outline);
}

void DrawFilledBox(int x, int y, int w, int h, D3DCOLOR color)
{
	D3DXVECTOR2 vLine[2];

	pLine->SetWidth(w);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);

	vLine[0].x = x + w / 2;
	vLine[0].y = y;
	vLine[1].x = x + w / 2;
	vLine[1].y = y + h;

	pLine->Begin();
	pLine->Draw(vLine, 2, color);
	pLine->End();
}

void DrawXHair(LPDIRECT3DDEVICE9 pDevice, D3DCOLOR col)
{
	D3DVIEWPORT9 gViewPort;
	pDevice->GetViewport(&gViewPort);
	float ScreenCenterX = (float)gViewPort.Width / 2; //Horizontal Position
	float ScreenCenterY = (float)gViewPort.Height / 2; //Vertical Position
	D3DRECT rec2 = { ScreenCenterX - 10, ScreenCenterY, ScreenCenterX + 10, ScreenCenterY + 1 };
	D3DRECT rec3 = { ScreenCenterX, ScreenCenterY - 10, ScreenCenterX + 1, ScreenCenterY + 10 };

	pDevice->Clear(1, &rec2, D3DCLEAR_TARGET, col, 0, 0);
	pDevice->Clear(1, &rec3, D3DCLEAR_TARGET, col, 0, 0);
}

//============================================================================================================
//iWrite Function
//============================================================================================================
BOOL iWrite(DWORD Address, void* Data, DWORD Length)
{
	DWORD Old = 0;
	VirtualProtect((void*)(Address), Length, PAGE_EXECUTE_READWRITE, &Old);
	memcpy((void*)Address, Data, Length);
	VirtualProtect((void*)(Address), Length, Old, &Old);
	return 0;
}

//======================================================================================================================
//MENU STUFF START =====================================================================================================
//====================================================================================================================
int Menu_Max = 27;

void SetIntLimits(int controller, int max, int min)
{
	if (controller == max + 1)
	{
		controller = max;
	}
	if (controller == min - 1)
	{
		controller = min;
	}
}

void SetIntLoop(int controller, int max, int min)
{
	if (controller == max + 1)
	{
		controller = min;
	}
	if (controller == min - 1)
	{
		controller = max;
	}
}

void CaseFunction()
{
	if (Menu && ((GetAsyncKeyState(VK_UP) & 1)))
	{
		if (mMenuSelection > 0)
			mMenuSelection--;
	}

	if (Menu && ((GetAsyncKeyState(VK_DOWN) & 1)))
	{
		if (mMenuSelection < Menu_Max)
			mMenuSelection++;
	}

	if (Menu && ((GetAsyncKeyState(VK_RIGHT) & 1)))
	{
		if (Menu)
		{
			switch (mMenuSelection)
			{
			case 0:
				One = !One;
				break;
			case 1:
				Two = !Two;
				break;
			case 2:
				Three = !Three;
				break;
			case 3:
				Four = !Four;
				break;
			case 4:
				Five = !Five;
				break;
			case 5:
				Six = !Six;
				break;
			case 6:
				Seven = !Seven;
				break;
			case 7:
				Eight = !Eight;
				break;
			case 8:
				Nine = !Nine;
				break;
			case 9:
				Ten = !Ten;
				break;
			case 10:
				Eleven = !Eleven;
				break;
			case 11:
				Twelve = !Twelve;
				break;
			case 12:
				Thirteen = !Thirteen;
				break;
			case 13:
				Fourteen = !Fourteen;
				break;
			case 14:
				Fifthteen = !Fifthteen;
				break;
			case 15:
				Sixteen = !Sixteen;
				break;
			case 16:
				Seventeen = !Seventeen;
				break;
			case 17:
				Eighteen = !Eighteen;
				break;
			case 18:
				Nineteen = !Nineteen;
				break;
			case 19:
				Twenty = !Twenty;
				break;
			case 20:
				Twentyone = !Twentyone;
				break;
			case 21:
				Twentytwo = !Twentytwo;
				break;
			case 22:
				Twentythree = !Twentythree;
				break;
			case 23:
				Twentyfour = !Twentyfour;
				break;
			case 24:
				Twentyfive = !Twentyfive;
				break;
			case 25:
				Twentysix = !Twentysix;
				break;
			case 26:
				Twentyseven = !Twentyseven;
				break;
			case 27:
				Twentyeight = !Twentyeight;
				break;
			}
		}
	}

	if (Menu && ((GetAsyncKeyState(VK_LEFT) & 1)))
	{
		if (Menu)
		{
			switch (mMenuSelection)
			{
			case 0:
				One = !One;
				break;
			case 1:
				Two = !Two;
				break;
			case 2:
				Three = !Three;
				break;
			case 3:
				Four = !Four;
				break;
			case 4:
				Five = !Five;
				break;
			case 5:
				Six = !Six;
				break;
			case 6:
				Seven = !Seven;
				break;
			case 7:
				Eight = !Eight;
				break;
			case 8:
				Nine = !Nine;
				break;
			case 9:
				Ten = !Ten;
				break;
			case 10:
				Eleven = !Eleven;
				break;
			case 11:
				Twelve = !Twelve;
				break;
			case 12:
				Thirteen = !Thirteen;
				break;
			case 13:
				Fourteen = !Fourteen;
				break;
			case 14:
				Fifthteen = !Fifthteen;
				break;
			case 15:
				Sixteen = !Sixteen;
				break;
			case 16:
				Seventeen = !Seventeen;
				break;
			case 17:
				Eighteen = !Eighteen;
				break;
			case 18:
				Nineteen = !Nineteen;
				break;
			case 19:
				Twenty = !Twenty;
				break;
			case 20:
				Twentyone = !Twentyone;
				break;
			case 21:
				Twentytwo = !Twentytwo;
				break;
			case 22:
				Twentythree = !Twentythree;
				break;
			case 23:
				Twentyfour = !Twentyfour;
				break;
			case 24:
				Twentyfive = !Twentyfive;
				break;
			case 25:
				Twentysix = !Twentysix;
				break;
			case 26:
				Twentyseven = !Twentyseven;
				break;
			case 27:
				Twentyeight = !Twentyeight;
				break;
			}
		}
	}
}
//============================================================================================================
//MENU STUFF END =============================================================================================
//============================================================================================================