#pragma once

#include <iostream>
#include "TMTypes.h"

#include <d3d9.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <Windows.h>

class __declspec(dllimport) TwinkTrackmania
{
public:
    bool TMInterfaceLoaded = false;

    const float MINRPM = 200.f;
    const float MAXRPM = 11000.f;

    // CTOR
    TwinkTrackmania();

    // DMA
    template <typename T>
    T Read(uintptr_t Addr);

    template <typename T>
    void Write(T Value, uintptr_t Addr);

    template <int Idx>
    uintptr_t Virtual(uintptr_t This);

    // GETTERS
    uintptr_t GetExeBaseAddr();
    uintptr_t GetTrackmania();
    uintptr_t GetGbxApp();
    uintptr_t GetMenuManager();
    uintptr_t GetInputPort();
    uintptr_t GetVisionViewport();
    uintptr_t GetProfileScores();
    uintptr_t GetProfile();
    uintptr_t GetNetwork();
    uintptr_t GetCoreCmdBuffer();
    uintptr_t GetMainEngine();
    uintptr_t GetGameCamera();
    uintptr_t GetSceneCamera();
    uintptr_t GetHmsPocCamera();
    uintptr_t GetSceneVehicleStruct();
    uintptr_t GetChallenge();
    uintptr_t GetDriveByIdx(size_t Idx);
    uintptr_t GetEngineByIdx(size_t Idx);
    uintptr_t GetSystemEngine();
    uintptr_t GetSceneEngine();
    uintptr_t GetDataDrive();
    uintptr_t GetEditor();
    IDirect3DDevice9* GetD3DDevice();
    uintptr_t LoadNodFromFilename(wchar_t* Filename, uintptr_t Drive);
    uintptr_t SceneEngineCreateInstance(unsigned int ClassId);

    TM::CFastStringInt GetChatText();
    std::string GetNameOfNod(uintptr_t Nod);
    std::string GetChallengeDecorationName();
    std::string GetChallengeUID();
    std::string GetChallengeName();
    std::string FormatTmDuration(unsigned int Duration);
    std::string WStringToUTF8(const std::wstring& wstr);
    std::wstring UTF8ToWString(const std::string& str);

    void GetIdName(unsigned int Ident, TM::CFastString* String);
    char* GetDriveName(uintptr_t Drive);
    int GetMwClassId(uintptr_t This);
    int GetSignedRaceTime();
    int GetCurCheckpointTime();
    int GetStuntsScore();
    int GetBestTime();
    int GetResets();
    int GetRespawns();
    int GetGear();
    int GetCheckpointCount();
    long GetRaceTime();
    float GetDisplaySpeed();
    float GetRpm();
    float GetHmsCameraFov();
    float GetHmsCameraAspectRatio();
    bool GetWaterPhysicsApplied();
    bool IsInterfaceHidden();
    bool IsOfficial();
    bool IsProfileUnited();
    bool IsGameInstallUnited();
    bool IsDeviceKeyboard(unsigned int ClassId);
    bool IsDeviceMouse(unsigned int ClassId);
    bool IsOnline();
    bool IsHmsPocHmsCamera(uintptr_t HmsPoc);
    bool IsPersonalBest();
    bool IsPaused();
    bool IsMwNodKindOf(uintptr_t Nod, unsigned int Id);
    bool IsChallengePlatform();
    bool IsPlaying();
    bool IsInEditor();
    bool IsInMediaTracker();
    bool ChallengeUsesScore();
    int ViewportOverlayDisabled();

    TM::CFastArray<uintptr_t> GetDevices();

    // SETTERS
    uintptr_t SetNodRef(uintptr_t NodRef, uintptr_t Nod);

    void ForceDevicePoll(uintptr_t Device, int MustNotPoll);
    void InitEmitter(uintptr_t Emitter, int ThatOneInt);
    void SetString(TM::CFastStringInt* String, wchar_t** CString);
    void SetString(TM::CFastString* String, char** CString);
    void SetStringLength(TM::CFastStringInt* String, size_t Length);
    void SetStringLength(TM::CFastString* String, size_t Length);
    void SetIdName(uintptr_t Nod, char* CString);
    void SetCameraZClip(bool Enable = false, float Distance = 50000.f, bool Void = false);
    void SetAnalogInfo(float Deadzone = -1.f, float Sensitivity = -1.f);
    void SetEmitterNodRefs(uintptr_t Emitter, uintptr_t Nod);
    void SetFullscreenWindowedResolution(bool Enable, unsigned int Width, unsigned int Height);

    // FUNCTIONS AND PATCHES
    void CallMenuGhostEditor();
    void CallSetOfficialRace();
    void CallSaveChallengeFromMemory();
    void CallGbxAppExit();
    void UseEmittersInVehicleStruct(uintptr_t FirstEmitter, uintptr_t SecondEmitter, uintptr_t VehicleStruct);

    bool VirtualParamGet(uintptr_t Nod, CMwStack* MwStack, void** Value);
    template<typename T>
    T* VirtualParamGet(uintptr_t Nod, CMwMemberInfo::eType Type, unsigned int MemberId);
};