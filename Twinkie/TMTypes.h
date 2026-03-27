#pragma once
#include <cstdint>

namespace TM
{
	template <typename T>
	struct CFastBuffer
	{
		size_t Size = 0;
		T* Ptr = nullptr;
		size_t Capacity = 0;

		T* operator[](size_t Idx)
		{
			return Ptr + Idx; // FUCK YOU BILL GATES
		}

		T* begin() { return Ptr; }
		T* end() { return Ptr + Size; }

		const T* begin() const { return Ptr; }
		const T* end() const { return Ptr + Size; }
	};

	class CMwNod
	{
	public:
		void** vftable = nullptr;
		unsigned int m_ReferenceCount = 0;
		uintptr_t m_SystemFid = 0;
		TM::CFastBuffer<CMwNod*>* m_Dependants = nullptr;
		unsigned int u1 = 0;
	};

	template <typename T>
	struct CFastArray
	{
		size_t Size = 0;
		T* Ptr = nullptr;

		T operator[](size_t Idx)
		{
			return Ptr[Idx];
		}

		T* begin() { return Ptr; }
		T* end() { return Ptr + Size; }

		const T* begin() const { return Ptr; }
		const T* end() const { return Ptr + Size; }
	};

	template <typename T>
	struct CFastBufferCat
	{
		CFastBuffer<unsigned int> Keys;
		CFastBuffer<T> Values;
		unsigned int SomeInts[3];

		T* begin() { return Values.Ptr; }
		T* end() { return Values.Ptr + Values.Size; }

		const T* begin() const { return Values.Ptr; }
		const T* end() const { return Values.Ptr + Values.Size; }
	};

	struct CFastString
	{
		int Size;
		char* Cstr;
	};

	struct CFastStringInt
	{
		int Size;
		wchar_t* Cstr;
	};

	struct GmVec3
	{
		float x;
		float y;
		float z;

		GmVec3 operator*(GmVec3 Vec)
		{
			return {x * Vec.x, y * Vec.y, x * Vec.z};
		}

		GmVec3 operator*(float F)
		{
			return { x * F, y * F, x * F };
		}

		GmVec3 operator-(GmVec3 Vec)
		{
			return { x - Vec.x, y - Vec.y, x - Vec.z };
		}

		GmVec3 operator+(GmVec3 Vec)
		{
			return { x + Vec.x, y + Vec.y, x + Vec.z };
		}
	};

	struct GmNat3
	{
		int x;
		int y;
		int z;
	};

	struct GmVec4
	{
		float x;
		float y;
		float z;
		float w;

		float& operator[](int Idx)
		{
			switch (Idx)
			{
			case 0: return x;
			case 1: return y;
			case 2: return z;
			case 3: return w;
			default: return x;
			}
		}
	};

	// might also be called GmFrustum
	struct GmMat4
	{
		GmVec4 x;
		GmVec4 y;
		GmVec4 z;
		GmVec4 t;

		GmMat4()
		{
			x = { 1.f, 0.f, 0.f, 0.f };
			y = { 0.f, 1.f, 0.f, 0.f };
			z = { 0.f, 0.f, 1.f, 0.f };
			t = { 0.f, 0.f, 0.f, 1.f };
		}

		GmMat4(GmVec4 x, GmVec4 y, GmVec4 z, GmVec4 t) : x(x), y(y), z(z), t(t) {}

		GmVec4& operator[](int Idx)
		{
			switch (Idx)
			{
			case 0: return x;
			case 1: return y;
			case 2: return z;
			case 3: return t;
			default: return x;
			}
		}

		GmVec4 operator*(GmVec4 Vec)
		{
			GmVec4 Result = {};
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					Result[i] += this->operator[](i)[j] * Vec[j];
				}
			}
			return Result;
		}

		GmMat4 operator*(GmMat4 Mat)
		{
			GmMat4 Result = {};
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					for (int k = 0; k < 4; ++k)
					{
						Result[i][j] += this->operator[](i)[k] * Mat[k][j];
					}
				}
			}
			return Result;
		}
	};

	struct GmIso4
	{
		GmVec3 x = { 1.f, 0.f, 0.f };
		GmVec3 y = { 0.f, 1.f, 0.f };
		GmVec3 z = { 0.f, 0.f, 1.f };
		GmVec3 t = { 0.f, 0.f, 0.f };

		operator GmMat4()
		{
			GmMat4 mat;
			mat.x = { x.x, y.x, z.x, t.x };
			mat.y = { x.y, y.y, z.y, t.y };
			mat.z = { x.z, y.z, z.z, t.z };
			mat.t = { 0.f, 0.f, 0.f, 1.f };
			return mat;
		}

		GmVec3 operator[](int Idx)
		{
			GmVec3 Arr[] = { x, y, z, t };
			return Arr[Idx];
		}
	};

	struct GmVec2
	{
		float x;
		float y;
	};

	struct CMwId
	{
		unsigned int Value;
	};

	enum RaceState
	{
		BeforeStart = 0,
		Running = 1,
		Finished = 2
	};

	enum AccountType
	{
		Disconnected = 0,
		Nations = 1,
		United = 2
	};

	enum MaterialId
	{
		Concrete = 0,
		Pavement = 1,
		Grass = 2,
		Ice = 3,
		Metal = 4,
		Sand = 5,
		Dirt = 6,
		Turbo = 7,
		DirtRoad = 8,
		Rubber = 9,
		SlidingRubber = 10,
		Test = 11,
		Rock = 12,
		Water = 13,
		Wood = 14,
		Danger = 15,
		Asphalt = 16,
		WetDirtRoad = 17,
		WetAsphalt = 18,
		WetPavement = 19,
		WetGrass = 20,
		Snow = 21,
		ResonantMetal = 22,
		GolfBall = 23,
		GolfWall = 24,
		GolfGround = 25,
		Turbo2 = 26,
		Bumper = 27,
		NotCollidable = 28,
		FreeWheeling = 29,
		TurboRoulette = 30
	};

	struct GmIso3
	{
		GmVec3 x, y, z;
	};
}

typedef int Integer;
typedef unsigned int Bool;
typedef unsigned char Nat8;
typedef unsigned short Nat16;
typedef unsigned int Natural, Nat32;
typedef unsigned __int64 Nat64;
typedef float Real, Real32;

using pFun = void(__thiscall*)(uintptr_t);

struct CMwParam
{
	void* ptr;
};

struct CMwMemberInfo
{
	enum eType
	{
		ACTION = 0,
		BOOL = 1,
		BOOLARRAY = 2,
		BOOLBUFFER = 3,
		BOOLBUFFERCAT = 4,
		CLASS = 5,
		CLASSARRAY = 6,
		CLASSBUFFER = 7,
		CLASSBUFFERCAT = 8,
		COLOR = 9,
		COLORARRAY = 10,
		COLORBUFFER = 11,
		COLORBUFFERCAT = 12,
		ENUM = 13,

		INT = 14,
		INTARRAY = 15,
		INTBUFFER = 16,
		INTBUFFERCAT = 17,
		INTRANGE = 18,
		ISO4 = 19,
		ISO4ARRAY = 20,
		ISO4BUFFER = 21,
		ISO4BUFFERCAT = 22,
		ISO3 = 23,
		ISO3ARRAY = 24,
		ISO3BUFFER = 25,
		ISO3BUFFERCAT = 26,
		ID = 27,
		IDARRAY = 28,
		IDBUFFER = 29,
		IDBUFFERCAT = 30,
		NATURAL = 31,
		NATURALARRAY = 32,
		NATURALBUFFER = 33,
		NATURALBUFFERCAT = 34,
		NATURALRANGE = 35,
		REAL = 36,
		REALARRAY = 37,
		REALBUFFER = 38,
		REALBUFFERCAT = 39,
		REALRANGE = 40,
		STRING = 41,
		STRINGARRAY = 42,
		STRINGBUFFER = 43,
		STRINGBUFFERCAT = 44,
		STRINGINT = 45,
		STRINGINTARRAY = 46,
		STRINGINTBUFFER = 47,
		STRINGINTBUFFERCAT = 48,
		VEC2 = 49,
		VEC2ARRAY = 50,
		VEC2BUFFER = 51,
		VEC2BUFFERCAT = 52,
		VEC3 = 53,
		VEC3ARRAY = 54,
		VEC3BUFFER = 55,
		VEC3BUFFERCAT = 56,
		VEC4 = 57,
		VEC4ARRAY = 58,
		VEC4BUFFER = 59,
		VEC4BUFFERCAT = 60,
		INT3 = 61,
		INT3ARRAY = 62,
		INT3BUFFER = 63,
		INT3BUFFERCAT = 64,
		PROC = 65
	};

	enum eFlags
	{
		READ = 0b00000001,
		WRITE = 0b00000010,
		U1 = 0b00000100,
		U2 = 0b00001000,
		VIRTUAL_GET = 0b00010000,
		VIRTUAL_SET = 0b00100000,
		VIRTUAL_ADD = 0b01000000,
		VIRTUAL_SUB = 0b10000000,
	};

	eType type;
	int memberID;
	CMwParam* pParam;
	int fieldOffset;
	const char* pszName;
	int flags;
	int flags2;
};

class CMwStack
{
public:
	pFun* vftable;
	int u2;
	int u3;
	size_t m_Size;
	CMwMemberInfo** ppMemberInfos;
	int* ppTypes;
	int iCurrentPos;
};

class CMwValueStd
{
public:
	void* pValue = nullptr;
	void* pValue2 = nullptr;
	unsigned char Pad[16];
};

struct CMwParam;

struct CMwClassInfo
{
	pFun* vftable;

	int classID;
	CMwClassInfo* pParentClassInfo;
	int unknown0;
	int unknown1;
	char* pszName;
	CMwClassInfo* pNextClassInfo;
	pFun pInitiate;      // Pointer to a function that creates an instance of the class
	CMwMemberInfo** ppMemberInfos;
	unsigned int numMemberInfos;
};

struct CMwMemberInfoIntRange : public CMwMemberInfo
{
	Integer min;
	Integer max;
};

struct CMwMemberInfoRealRange : public CMwMemberInfo
{
	Real min;
	Real max;
};

struct CMwClassMemberInfo : public CMwMemberInfo {
	CMwClassInfo* pClassInfo;
};

struct CMwClassArrayMemberInfo : public CMwMemberInfo   // Specialized class for fields/properties that are a list
	// of object references (FastArray<CMwNod*>/FastBuffer<CMwNod*>)
{
	int unknown0;
	char* pszFriendlyClassName;
	int unknown1;
	CMwClassInfo* pClassInfo;                           // Class of the objects in the list
};

struct CMwActionInfo : public CMwMemberInfo             // Specialized class for member methods
{
	pFun pMethod;                                      // Pointer to the method code
};

struct CMwMethodInfo : public CMwMemberInfo             // Specialized class for member methods
{
	pFun pMethod;                                      // Pointer to the method code
	int numArgs;
	int* pArgClassIDs;                                  // Pointer to an array of numArgs ints
	char** ppszArgNames;                                // Pointer to an array of numArgs char*'s
	int* pArgFlags;                                     // Pointer to an array of numArgs ints
};

struct CMwEnumInfo : public CMwMemberInfo               // Specialized class for members that store an enum value
{
	char* pszEnumName;
	int numValues;
	char** ppszValueNames;                              // Pointer to an array of numValues char*'s
};

struct CMwEngineInfo {
	pFun* vftable;

	int m_EngineId;
	char* m_EngineName;
	TM::CFastArray<CMwClassInfo*> m_Classes;
};

struct CMwEngineManager {
	pFun* vftable;

	TM::CFastArray<CMwEngineInfo*> m_Engines;
};