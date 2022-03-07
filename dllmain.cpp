#include "stdafx.h"

//============================================================================================================
//DX hkReset
//============================================================================================================
HRESULT WINAPI hkReset(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* PresP)
{
	//Reset
	D3D_RELEASE(pFont);
	D3D_RELEASE(pLine);

	if (pFont)
		pFont->OnLostDevice();

	if (pLine)
		pLine->OnLostDevice();

	HRESULT hRet = oReset(pDevice, PresP);

	if (hRet == D3D_OK){

		if (pFont)
			pFont->OnResetDevice();

		if (pLine)
			pLine->OnResetDevice();
	}

	return hRet;
}

//============================================================================================================
//DX hkEndScene (ES)
//============================================================================================================
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	//Setup Shaders ETC
	if (bInitOnce == true){
		Draw.InitStuff(pDevice);
		outputFile1 << "Shaders + Textures Generated" << endl;
	}

	//Setup D3D9 Stuff
	if (pFont == NULL) D3DXCreateFont(pDevice, 15, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "red", &pFont);
	if (pLine == NULL) D3DXCreateLine(pDevice, &pLine);

	if (EnableWM == 1){
		D3DVIEWPORT9 pViewPort;
		pDevice->GetViewport(&pViewPort);
		float SCX = (float)pViewPort.Width / 2; //Horizontal Position
		DrawShadowText(SCX - 100, 5, d3dColorBlue, "Krilu92's BF2Hub Private", 0);
	}

	//Setup Clock + FPS Stuff
	CurrentTickCount = clock() * 0.001f;
	++Fps;
	if ((CurrentTickCount - LastTickCount) > 1.0f) {
		LastTickCount = CurrentTickCount;
		sprintf_s(FrameRate, "[ Frames: %d ]", int(Fps));
		Fps = 0;
	}

	//Shoe/Hide Menu
	if (GetAsyncKeyState(VK_DELETE) & 1) { Menu = !Menu; }
	for (int x = 0; x < Menu_Max + 1; x++) {
		if (Menu && mMenuSelection == x) {
			CaseFunction();

			Draw.FilledBox(6, 95, 300, 550, 155, 0, 0, 0); //Overall Background

			Button(pDevice, 6, 95, 300, 550, d3dColorWhite); // Outline

			Button(pDevice, 6, 130 + (15 * x), 300, 15, d3dColorWhite); // Selection

			if (One) DrawShadowText(12, 130, d3dColorGreen, "Minimap - On", 0);
			else DrawShadowText(12, 130, d3dColorRed, "Minimap - Off", 0);
			//
			if (Two) DrawShadowText(12, 145, d3dColorGreen, "Nametags - On", 0);
			else DrawShadowText(12, 145, d3dColorRed, "Nametags - Off", 0);
			//
			if (Three) DrawShadowText(12, 160, d3dColorGreen, "Distance Tags - On", 0);
			else DrawShadowText(12, 160, d3dColorRed, "Distance Tags - Off", 0);
			//
			if (Four) DrawShadowText(12, 175, d3dColorGreen, "Health Bars - On", 0);
			else DrawShadowText(12, 175, d3dColorRed, "Health Bars - Off", 0);
			//
			if (Five) DrawShadowText(12, 190, d3dColorGreen, "Weapon Unlocks - On", 0);
			else DrawShadowText(12, 190, d3dColorRed, "Weapon Unlocks - Off", 0);
			//
			if (Six) DrawShadowText(12, 205, d3dColorGreen, "Crosshair - On", 0);
			else DrawShadowText(12, 205, d3dColorRed, "Crosshair - Off", 0);
			//
			if (Seven) DrawShadowText(12, 220, d3dColorGreen, "Player Chams - On", 0);
			else DrawShadowText(12, 220, d3dColorRed, "Player Chams - Off", 0);
			//
			if (Eight) DrawShadowText(12, 235, d3dColorGreen, "Vehicle Chams - On", 0);
			else DrawShadowText(12, 235, d3dColorRed, "Vehicle Chams - Off", 0);
			//
			if (Nine) DrawShadowText(12, 250, d3dColorGreen, "Weapon Chams - On", 0);
			else DrawShadowText(12, 250, d3dColorRed, "Weapon Chams - Off", 0);
			//
			if (Ten) DrawShadowText(12, 265, d3dColorGreen, "Explosives Chams - On", 0);
			else DrawShadowText(12, 265, d3dColorRed, "Explosives Chams - Off", 0);
			//
			if (Eleven) DrawShadowText(12, 280, d3dColorGreen, "Remove Fog - On", 0);
			else DrawShadowText(12, 280, d3dColorRed, "Remove Fog - Off", 0);
			//
			if (Twelve) DrawShadowText(12, 295, d3dColorGreen, "No Sky - On", 0);
			else DrawShadowText(12, 295, d3dColorRed, "No Sky - Off", 0);
			//
			if (Thirteen) DrawShadowText(12, 310, d3dColorGreen, "No Hands- On", 0);
			else DrawShadowText(12, 310, d3dColorRed, "No Hands - Off", 0);
			//
			if (Fourteen) DrawShadowText(12, 325, d3dColorGreen, "No Overlays - On", 0);
			else DrawShadowText(12, 325, d3dColorRed, "No Overlays - Off", 0);
			//
			if (Fifthteen) DrawShadowText(12, 340, d3dColorGreen, "No Water - On", 0);
			else DrawShadowText(12, 340, d3dColorRed, "No Water - Off", 0);
			//
			if (Sixteen) DrawShadowText(12, 355, d3dColorGreen, "No TV Static - On", 0);
			else DrawShadowText(12, 355, d3dColorRed, "No TV Static - Off", 0);
			//
			if (Seventeen) DrawShadowText(12, 370, d3dColorGreen, "Team Swap - On", 0);
			else DrawShadowText(12, 370, d3dColorRed, "Team Swap - Off", 0);
			//
			if (Eighteen) DrawShadowText(12, 385, d3dColorGreen, "Force Commander - On", 0);
			else DrawShadowText(12, 385, d3dColorRed, "Force Commander - Off", 0);
			//
			if (Nineteen) DrawShadowText(12, 400, d3dColorGreen, "Resign Commander - On", 0);
			else DrawShadowText(12, 400, d3dColorRed, "Resign Commander - Off", 0);
			//
			if (Twenty) DrawShadowText(12, 415, d3dColorGreen, "Force Squadleader - On", 0);
			else DrawShadowText(12, 415, d3dColorRed, "Force Squadleader - Off", 0);
			//
			if (Twentyone) DrawShadowText(12, 430, d3dColorGreen, "Wallhack - On", 0);
			else DrawShadowText(12, 430, d3dColorRed, "Wallhack - Off", 0);
			//
			if (Twentytwo) DrawShadowText(12, 445, d3dColorGreen, "Wireframe - On", 0);
			else DrawShadowText(12, 445, d3dColorRed, "Wireframe - Off", 0);
			//
			if (Twentythree) DrawShadowText(12, 460, d3dColorGreen, "Max View Distance - On", 0);
			else DrawShadowText(12, 460, d3dColorRed, "Max View Distance - Off", 0);
			//
			if (Twentyfour) DrawShadowText(12, 475, d3dColorGreen, "Enemy Mines - On", 0);
			else DrawShadowText(12, 475, d3dColorRed, "Enemy Mines - Off", 0);
			//
			if (Twentyfive) DrawShadowText(12, 490, d3dColorGreen, "Nametags Over 120m - On", 0);
			else DrawShadowText(12, 490, d3dColorRed, "Nametags Over 120m - Off", 0);
			//
			if (Twentysix) DrawShadowText(12, 505, d3dColorGreen, "3D Map (alt switch) - On", 0);
			else DrawShadowText(12, 505, d3dColorRed, "3D Map (alt switch) - Off", 0);
			//
			if (Twentyseven) DrawShadowText(12, 520, d3dColorGreen, "Player Kit Icons - On", 0);
			else DrawShadowText(12, 520, d3dColorRed, "Player Kit Icons - Off", 0);
			//
			if (Twentyeight) DrawShadowText(12, 535, d3dColorGreen, "Radars/Bridges Icons  - On", 0);
			else DrawShadowText(12, 535, d3dColorRed, "Radars/Bridges Icons - Off", 0);

			//DrawShadowText(115, 105, D3DCOLOR_XRGB(255, 255, 255), "BF2Hub Private", 0); // Cyan

			//Button(pDevice, 6, 95, 300, 35, d3dColorWhite); // Outline

			//DrawShadowText(115, 365, D3DCOLOR_XRGB(255, 255, 255), "by Krilu92", 0);
			//DrawString(115, 380, D3DCOLOR_XRGB(255, 255, 255), FrameRate, 0);

		}
	}

	if (DrawCrossHair){
		DrawXHair(pDevice, d3dColorRed);	
	}

	return oEndScene(pDevice);
}

//============================================================================================================
//DX hkDrawIndexedPrimitive (DIP)
//============================================================================================================
	HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType, INT BaseVertexIndex, UINT MinIndex, UINT  NumVertices, UINT StartIndex, UINT PrimitiveCount)
	{
		if (pDevice->GetStreamSource(0, &Stream_Data, &Offset, &g_uiStride) == D3D_OK)
			Stream_Data->Release();

		//Wireframe
		if (USMCSoldiers || EUROSoldiers) {
			if (wireframe) {	
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				pDevice->SetPixelShader(Teal2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//Wireframe
		if (PLASoldiers || MECSoldiers) {
			if (wireframe) {
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
				pDevice->SetPixelShader(Orange2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//Wallhack
		if (USMCSoldiers || EUROSoldiers || PLASoldiers || MECSoldiers) {
			if (wallhack)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//USMC and EURO Chams
		if (USMCSoldiers || EUROSoldiers){
			if (playerchams)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pDevice->SetPixelShader(Blue2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pDevice->SetPixelShader(Orange2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//MEC and CHINA Chams
		if (PLASoldiers || MECSoldiers){
			if (playerchams)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pDevice->SetPixelShader(Pink2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pDevice->SetPixelShader(Purple2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//Vehicle Chams
		if (VehiclesAll || USMCAssets || MECAssets || PLAAssets){
			if (vehiclechams)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pDevice->SetPixelShader(Yellow2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pDevice->SetPixelShader(Red2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//Weapon Chams
		if (WeaponsAll || GroundWeapons){
			if (weaponchams)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pDevice->SetPixelShader(Blue2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pDevice->SetPixelShader(Green2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//Explosives Chams
		if (Explosives){
			if (explosivechams)
			{
				pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_NEVER);
				pDevice->SetPixelShader(Yellow2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
				pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
				pDevice->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESSEQUAL);
				pDevice->SetPixelShader(Red2);
				oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
			}
		}

		//Remove Sky
		if (Sky) {
			if (RemoveSky == 1){
				return 0;
			}
		}

		//remove hands
		if (all_hands || Hands) {
			if (RemoveHands == 1) {
				return 0;
			}
		}

		//remove overlays
		if (TankOverlay || ScopeOverlay) {
			if (RemoveOverlay == 1) {
				return 0;
			}
		}

		//remove water
		if (Water) {
			if (RemoveWater== 1) {
				return 0;
			}
		}

		//remove tvstatic
		if (TVSTATIC){
			if (RemoveTV == 1){
				return 0;
			}
		}

	return oDrawIndexedPrimitive(pDevice, PrimType, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
}

//============================================================================================================
//HACK FEATURES  
//============================================================================================================

void DistanceTagsOn(){
	iWrite((dwRendBase + 0x130363), (PBYTE)"\x75\x70", 2);
}

void DistanceTagsOff(){
	iWrite((dwRendBase + 0x130363), (PBYTE)"\x74\x70", 2);
}

void PlayerNoFadeOn(){
	iWrite((dwRendBase + 0x239A3E), (PBYTE)"\x16", 1);
	iWrite((dwRendBase + 0x239A3F), (PBYTE)"\x44", 1);
}

void PlayerNoFadeOff(){
	iWrite((dwRendBase + 0x239A3E), (PBYTE)"\xF0:42", 1);
}

void RadarBridgeIconsOn() {
	iWrite((dwRendBase + 0x1309F9), (PBYTE)"\x90\x90", 2);
}

void RadarBridgeIconsOff() {
	iWrite((dwRendBase + 0x1309F9), (PBYTE)"\x74\x4A", 2);
}

void Map3DOn() {
	iWrite((dwRendBase + 0x12E73D), (PBYTE)"\x90\x90", 2);
}

void Map3DOff() {
	iWrite((dwRendBase + 0x12E73D), (PBYTE)"\x75\x0E", 2);
}

void EnemyMinesOn() { 
	iWrite((dwRendBase + 0x12EA91), (PBYTE)"\x90\x90", 2);
}

void EnemyMinesOff() {
	iWrite((dwRendBase + 0x12EA91), (PBYTE)"\x75\x62", 2);
}

void KitIconsOn() { //broken bytes here (semi works) idk what they are :( 
	iWrite((dwRendBase + 0x12E28A), (PBYTE)"\x90\x90", 2);
	iWrite((dwRendBase + 0x12E2D1), (PBYTE)"\x90\x90", 2);
	iWrite((dwRendBase + 0x12E2F0), (PBYTE)"\x90\x90", 2);
}
void KitIconsOff() {
	iWrite((dwRendBase + 0x12E28A), (PBYTE)"\x74\x4A", 2);
	iWrite((dwRendBase + 0x12E2D1), (PBYTE)"\x74\x4A", 2);
	iWrite((dwRendBase + 0x12E2F0), (PBYTE)"\x74\x4A", 2);
}

void HealthBarsEnabled(){
	iWrite((dwRendBase + 0x1B394D), (PBYTE)"\x0F\x84", 2); //HB1
	iWrite((dwRendBase + 0x1B3A7E), (PBYTE)"\x0F\x84", 2); //HB2
	iWrite((dwRendBase + 0x1B3ACC), (PBYTE)"\x0F\x84", 2); //HB3
}
void HealthBarsStandard(){
	iWrite((dwRendBase + 0x1B394D), (PBYTE)"\x0F\x85", 2); //HB1
	iWrite((dwRendBase + 0x1B3A7E), (PBYTE)"\x0F\x85", 2); //HB2
	iWrite((dwRendBase + 0x1B3ACC), (PBYTE)"\x0F\x85", 2); //HB3
}

void NametagsEnabled(){
	iWrite((dwRendBase + 0x12EDCD), (PBYTE)"\x0F\x85", 2); //NT1
	iWrite((dwRendBase + 0x12EDE3), (PBYTE)"\x0F\x85", 2); //NT2
	iWrite((dwRendBase + 0x12EDF2), (PBYTE)"\x0F\x84", 2); //NT3
	iWrite((dwRendBase + 0x12D03D), (PBYTE)"\x74\x0F", 2); //NTNOFADEDELAY
}
void NametagsDisabled(){
	iWrite((dwRendBase + 0x12EDCD), (PBYTE)"\x0F\x84", 2); //NT1
	iWrite((dwRendBase + 0x12EDE3), (PBYTE)"\x0F\x84", 2); //NT2
	iWrite((dwRendBase + 0x12EDF2), (PBYTE)"\x0F\x85", 2); //NT3
	iWrite((dwRendBase + 0x12D03D), (PBYTE)"\x75\x0F", 2); //NTNOFADEDELAY
}

void WeaponUnlocksOn(){
	iWrite((0x468CBE), (PBYTE)"\x90\x90", 2);
	iWrite((0x5028C5), (PBYTE)"\x90\x90", 2);
}
void WeaponUnlocksOff(){
	iWrite((0x468CBE), (PBYTE)"\x74\x07", 2);
	iWrite((0x5028C5), (PBYTE)"\x7C\x14", 2);
}

void MiniMapEnable(){
	iWrite(0x007786D9, (PBYTE)"\x74\x0C", 2);
	iWrite(0x007786FF, (PBYTE)"\x74\x0C", 2);
	iWrite(0x00778725, (PBYTE)"\x0F\x85", 2);
	iWrite(0x007787B5, (PBYTE)"\x74\x0C", 2);
	iWrite(0x007787DB, (PBYTE)"\x74\x09", 2);
	iWrite(0x007787FE, (PBYTE)"\x75\x46", 2);
	iWrite(0x007836F9, (PBYTE)"\x74\x06", 2);
}
void MiniMapDisable(){
	iWrite(0x007786D9, (PBYTE)"\x75\x0C", 2);
	iWrite(0x007786FF, (PBYTE)"\x75\x0C", 2);
	iWrite(0x00778725, (PBYTE)"\x0F\x84", 2);
	iWrite(0x007787B5, (PBYTE)"\x75\x0C", 2);
	iWrite(0x007787DB, (PBYTE)"\x75\x09", 2);
	iWrite(0x007787FE, (PBYTE)"\x74\x46", 2);
	iWrite(0x007836F9, (PBYTE)"\x75\x06", 2);
}

void RemoveTVStaticOn() {
	iWrite(0x78B29E, (PBYTE)"\x90\x90\x90\x90\x90\x90", 6);
}
void RemoveTVStaticOff() {
	iWrite(0x78B29E, (PBYTE)"\x8B\x92\xA0\x00\x00\x00", 6);
}

DWORD MyPtr1 = 0;
BYTE ViewDistOn = 0x40;
BYTE ViewDistOff = 0x3F;

void ViewDistanceOn()
{
	memcpy(&MyPtr1, (void*)0x9A557C, 4);
	iWrite(MyPtr1 + 0x4FB, &ViewDistOn, 1);
	
}

void ViewDistanceOff()
{
	memcpy(&MyPtr1, (void*)0x9A557C, 4);
	iWrite(MyPtr1 + 0x4FB, &ViewDistOff, 1);
}



void RemoveFOG(){
	if (!dwSwitch == NULL){
		if (GetFogBase == 1){
			iWrite((dwRendBase + 0x506F9), (PBYTE)"\xD9\x46\x05", 3);
			GetFogBase = 2;
		}
	}
}
void RestoreFOG(){
	if (!dwSwitch == NULL){
		if (GetFogBase == 2){
			iWrite((dwRendBase + 0x506F9), (PBYTE)"\xD9\x46\x38", 3);
			GetFogBase = 1;
		}
	}
}

//Read Memory Values
void ReadValues()
{
	ReadProcessMemory(GetCurrentProcess(), (void*)(0xA08F60), &TeamBase, sizeof(TeamBase), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(TeamBase + 0x60), &CurrentTeam, sizeof(CurrentTeam), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(CurrentTeam + 0xD8), &dwSwitch, sizeof(dwSwitch), 0);

}

void ReadValuesCommander()
{
	ReadProcessMemory(GetCurrentProcess(), (void*)(0xA08F60), &dwCommanderBase, sizeof(dwCommanderBase), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(dwCommanderBase + 0x60), &dwForceCommander, sizeof(dwForceCommander), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(dwForceCommander + 0x110), &dwCommand, sizeof(dwCommand), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(dwForceCommander + 0x2C0), &dwResign, sizeof(dwResign), 0);
}

void ReadValuesSquad()
{
	ReadProcessMemory(GetCurrentProcess(), (void*)(0xA33348), &dwSquadLeaderBase, sizeof(dwSquadLeaderBase), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(dwSquadLeaderBase + 0x60), &dwForceSquadLead, sizeof(dwForceSquadLead), 0);
	ReadProcessMemory(GetCurrentProcess(), (void*)(dwForceSquadLead + 0x111), &dwSquadLead, sizeof(dwSquadLead), 0);
}


void SwitchTeam(){
	if (DoOnceTeamSwitch == 1){
		if (dwSwitch == 1) { iWrite((CurrentTeam + 0xD8), &TEAM2, 1); }
		else if (dwSwitch == 2)	{ iWrite((CurrentTeam + 0xD8), &TEAM1, 1); }
		DoOnceTeamSwitch = 0;
	}
}

void ResignCommander() { // does not yet work 
	if (DoOnceResignCommander == 1) {
		if (dwResign == 0) { iWrite((dwForceCommander + 0x2C0), &ON, 1); }
		else { iWrite((dwForceCommander + 0x2C0), &OFF, 1); }
		DoOnceResignCommander = 0;
	}
}

void MakeCommander() { //forces a kick online for no reason because of errors when disabeling commander
	if (DoOnceForceCommander == 1) {
		if (dwCommand == 0) { iWrite((dwForceCommander + 0x110), &ON, 1); }
		else { iWrite((dwForceCommander + 0x110), &OFF, 1); }
		DoOnceForceCommander = 0;
	}
}

void MakeSquadLeader() { // does not yet work
	if (DoOnceForceSquadLead == 1) {
		if (dwSquadLead == 0) { iWrite((dwForceSquadLead + 0x111), &ON, 1); }
		else { iWrite((dwForceSquadLead + 0x111), &OFF, 1); }
		DoOnceForceSquadLead = 0;
	}
}

//===============================================================================================================
//PBSS_BLOCKER
//===============================================================================================================
DWORD GetModuleSize(DWORD processID){
	HANDLE hSnap;
	MODULEENTRY32 xModule;
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processID);
	xModule.dwSize = sizeof(MODULEENTRY32);
	if (Module32First(hSnap, &xModule)) {
		while (Module32Next(hSnap, &xModule)) {
			if (!strncmp((char*)xModule.szModule, "pbcl.dll", 8)){
				CloseHandle(hSnap);
				return (DWORD)xModule.modBaseSize;
			}
		}
	}
	CloseHandle(hSnap);
	return 0;
}

typedef DWORD(__stdcall * GWTPID) (HWND, LPDWORD);
GWTPID pOrigGWTPID;

BOOL WINAPI myGWTPID(HWND hWnd, LPDWORD lpdwProcessId)
{
	DWORD pbclBase = (DWORD)GetModuleHandle("pbcl.dll");
	DWORD bf2pid = GetProcessId(GetCurrentProcess());
	DWORD pbclSize = GetModuleSize(bf2pid);
	DWORD returnAddress = (DWORD)_ReturnAddress();

	if ((returnAddress > pbclBase) && (returnAddress < pbclBase + pbclSize))
		return 0;

	return pOrigGWTPID(hWnd, lpdwProcessId);
}
//===============================================================================================================
//Main Loop Function - Init
//===============================================================================================================
void Init(){
	outputFile1 << "Init Function Started" << endl;

	for (;;) {
		ReadValues();
		ReadValuesCommander();
		ReadValuesSquad();

		if (One) {
			MiniMapEnable();
		}
		else {
			MiniMapDisable();
		}

		if (Two) {
			NametagsEnabled();
		}
		else {
			NametagsDisabled();
		}

		if (Three) DistanceTagsOn();
		else DistanceTagsOff();

		if (Four) HealthBarsEnabled();
		else HealthBarsStandard();

		if (Five) WeaponUnlocksOn();
		else WeaponUnlocksOff();

		if (Six) DrawCrossHair = 1;
		else DrawCrossHair = 0;

		if (Seven) playerchams = 1;
		else playerchams = 0;

		if (Eight) vehiclechams = 1;
		else vehiclechams = 0;

		if (Nine) weaponchams = 1;
		else weaponchams = 0;

		if (Ten) explosivechams = 1;
		else explosivechams = 0;

		if (Eleven) {
			GetFogBase = 1;
			RemoveFOG();
		}	
		else {
			RestoreFOG();
		}

		if (Twelve) {
			RemoveSky = 1;
		}
		else {
			RemoveSky = 0;
		}

		if (Thirteen) {
			RemoveHands = 1;
		}
		else {
			RemoveHands = 0;
		}

		if (Fourteen) {
			RemoveOverlay = 1;
		}
		else {
			RemoveOverlay = 0;
		}

		if (Fifthteen) {
			RemoveWater = 1;
		}
		else {
			RemoveWater = 0;
		}

		if (Sixteen) {
			RemoveTV = 1;
		}
		else {
			RemoveTV = 0;
		}

		if (Seventeen){
			if (SwitchTeams == 0){
				DoOnceTeamSwitch = 1;
				SwitchTeam();
				SwitchTeams = 1;
			}
		}
		else {
			if (SwitchTeams == 1){
				DoOnceTeamSwitch = 1;
				SwitchTeam();
				SwitchTeams = 0;
			}
		}

		if (Eighteen) {
			if (forceCommander == 0) {
				DoOnceForceCommander = 1;
				MakeCommander();
				forceCommander = 1;
			}
		}
		else {
			if (forceCommander == 1) {
				DoOnceForceCommander = 1;
				MakeCommander();
				forceCommander = 0;
			}
		}

		if (Nineteen) {
			if (resignCommander == 0) {
				DoOnceResignCommander = 1;
				ResignCommander();
				resignCommander = 1;
			}
		}
		else {
			if (resignCommander == 1) {
				DoOnceResignCommander = 1;
				ResignCommander();
				resignCommander = 0;
			}
		}

		if (Twenty) {
			if (forceSquadLead == 0) {
				DoOnceForceSquadLead = 1;
				MakeSquadLeader();
				forceSquadLead = 1;
			}
		}
		else {
			if (forceSquadLead == 1) {
				DoOnceForceSquadLead = 1;
				MakeSquadLeader();
				forceSquadLead = 0;
			}
		}

		if (Twentyone) wallhack = 1;
		else wallhack = 0;

		if (Twentytwo) wireframe = 1;
		else wireframe = 0;

		if (Twentythree) {
			ViewDistanceOn();
		}
		else {
			ViewDistanceOff();
		}

		if (Twentyfour) {
			EnemyMinesOn();
		}
		else {
			EnemyMinesOff();
		}

		if (Twentyfive) {
			PlayerNoFadeOn();
		}
		else {
			PlayerNoFadeOff();
		}

		if (Twentysix) {
			Map3DOn(); // kit icons gets enabled when this does?
		}
		else {
			Map3DOff();
		}

		if (Twentyseven) {
			KitIconsOn();
		}
		else {
			KitIconsOff();
		}

		if (Twentyeight) {
			RadarBridgeIconsOn();
		}
		else {
			RadarBridgeIconsOff();
		}

		//Sleep
		Sleep(200);
	}
}

//===============================================================================================================
//HOOK STUFF=====================================================================================================
//===============================================================================================================
DWORD HookVTable(PDWORD Class, DWORD function, int index)
{
	DWORD oldRights, newRights, oldAddress;
	if (!IsBadReadPtr(Class, 4))
	{
		DWORD* functionAddress = (DWORD*)((PDWORD)(*Class + (index * 4)));
		if (*functionAddress != function)
		{
			if (VirtualProtectEx(GetCurrentProcess(), functionAddress, 4, PAGE_EXECUTE_READWRITE, &oldRights))
			{
				oldAddress = *functionAddress;
				*functionAddress = (DWORD)function;
			}
			VirtualProtectEx(GetCurrentProcess(), functionAddress, 4, oldRights, &newRights);
		}
	}
	return oldAddress;
}

//===============================================================================================================
//DXINIT FUNCTION ===============================================================================================
//===============================================================================================================
LRESULT CALLBACK MsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){ return DefWindowProc(hwnd, uMsg, wParam, lParam); }
void DX_Init(DWORD* table)
{
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, "DX", NULL };
	RegisterClassEx(&wc);
	HWND hWnd = CreateWindow("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
	LPDIRECT3D9 pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	LPDIRECT3DDEVICE9 pd3dDevice;
	pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice);
	DWORD* pVTable = (DWORD*)pd3dDevice;
	pVTable = (DWORD*)pVTable[0];

	table[ES] = pVTable[42];
	table[RES] = pVTable[16];
	table[DIP] = pVTable[82];

	DestroyWindow(hWnd);

	outputFile1 << "DX Init Complete" << endl;
}

//===============================================================================================================
//RENDHOOK Function==============================================================================================
//===============================================================================================================
DWORD WINAPI RendHook(LPVOID lpParam)
{
	//Get RendDX9.dll + BF2.exe Bases
	while (dwRendBase == 0)	dwRendBase = (DWORD)GetModuleHandleA("RendDX9.dll");
	while (dwBF2Base == 0)	dwBF2Base = (DWORD)GetModuleHandleA("BF2.exe");

	//Initialize DX Stuff
	DX_Init(VTable);

	//Perform Hooks
	HOOK(EndScene, VTable[ES]);
	HOOK(Reset, VTable[RES]);
	HOOK(DrawIndexedPrimitive, VTable[DIP]);

	//Log RendDX9.dll + BF2.exe Base Addresses
	outputFile1 << "RendDX9.dll Address: ";
	outputFile1 << dwRendBase << endl;
	outputFile1 << "BF2.exe Address: ";
	outputFile1 << dwBF2Base << endl;

	//Run Main Function Loop
	Init();

	return 0;
}

//===============================================================================================================
//DLLMain Function==============================================================================================
//===============================================================================================================
BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	time_t now = time(0);
	sTm = gmtime(&now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);

	if (dwReason == DLL_PROCESS_ATTACH)	{
		CreateThread(0, 0, RendHook, 0, 0, 0);
		outputFile1.open("\\Log.txt");
		outputFile1 << "Attached Successfully :";
		outputFile1 << buff << endl;

		HMODULE user32Mod = LoadLibrary("user32.dll");
		DWORD* GWTPIDaddy = (DWORD*)GetProcAddress(user32Mod, "GetWindowThreadProcessId");

		pOrigGWTPID = (GWTPID)DetourFunction((PBYTE)GWTPIDaddy, (PBYTE)myGWTPID);
	}
	else if (dwReason == DLL_PROCESS_DETACH) {
		outputFile1 << "Detached :";
		outputFile1 << buff << endl;
		outputFile1.close();
	}
	return TRUE;
}

