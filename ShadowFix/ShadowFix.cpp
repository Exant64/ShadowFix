#include "stdafx.h"
#include "SA2ModLoader.h"
#include "ninja_functions.h"
#include "Shadow.h"
#include <vector>
#include "IniFile.h"

struct FRUIT_INFO
{
	float growth;
	float AimGrowth;
	int SwingCounter;
	NJS_POINT3 pos;
	int angx;
	int angy;
};

#pragma pack(push, 8)
struct __declspec(align(4)) ALO_GrowTreeExecutor_Data
{
	EntityData1 entityData;
	char kind;
	char state;
	__int16 field_32;
	float growth;
	int life;
	int water;
	int pos_num;
	FRUIT_INFO fruit[3];
	float scale;
	float ScaleSpd;
	int ThirstyFlag;
	int WaterFlag;
	int LeafRotAng;
	float LeafWidth;
	int LeafDispNum;
	int FruitRotAng;
	float FruitWidth;
	int FruitDispNum;
	int SwingFlag;
	int SwingCountFlag;
	float SwingDist;
	int RollAngle;
	int TouchAngle;
	int ChaoSwingPhase;
	int RollPhase;
	int garden;
	void* pMySaveInfo;
	NJS_TEXLIST* texlist;
	NJS_OBJECT* pLocalObject;
	NJS_OBJECT* pShadowObject;
	NJS_OBJECT* pCopyObject;
};
#pragma pack(pop)

struct  TextureData
{
	int* dword0;
	int dword4;
	int dword8;
	void* D3DTexture;
	int dword10;
	char gap14[4];
	char byte18;
	char gap19[15];
	int dword28;
	int dword2C;
	char gap30[4];
	char byte34;
	char gap35[15];
	int dword44;
	int dword48;
	int dword4C;
	int dword50;
	int dword54;
	int dword58;
	int dword5C;
	int dword60;
	int dword64;
	int dword68;
	int dword6C;
	int byte70;
};

struct  WeirdChunkTexIndexThing
{
	TextureData* texturePointer;
	int a3;
	int a2;
	int tes3;
	int tes4;
	int tes5;
	int bank;
};

#pragma pack(push, 8)
struct __declspec(align(4)) ShadowData
{
	float matrix[12];
	WeirdChunkTexIndexThing weirdchunktexindexthing30;
	float gap4C;
	int sizeOfTextureMaybe;
	TextureData* dword54;
};
#pragma pack(pop)

struct __declspec(align(4)) ShadowThing
{
	int someIndex;
	NJS_VECTOR position;
	float someFloat;
	WeirdChunkTexIndexThing* chunkTexIndex;
	TextureData* textureData;
	ShadowData* shadowData;
};
#pragma pack(push, 8)
struct __declspec(align(4)) CHAO_GLOBAL
{
	int CalcBuyo;
	int DispWorldEntry;
	int DispOnScreen;
	int DispScreenFrame;
	int DispField;
	unsigned __int16 InitMulPotentialSkill;
	unsigned __int16 InitBaseLife;
	unsigned __int16 InitMulLife;
	unsigned __int16 InitMulForm;
	unsigned __int16 InitMulAttr;
	__int16 field_1E;
	float WalkAcc;
	float WalkSlowAcc;
	float RunAcc;
	float BoundFriction;
	float BoundFloor;
	unsigned __int16 SkillLimit;
	unsigned __int16 LifeMaxLimit;
	char EmotionMoodLimit;
	char field_39;
	unsigned __int16 EmotionStateLimit;
	char EmotionPersonalityLimit;
	char field_3D;
	char field_3E;
	char field_3F;
	float DeformLimit;
	float GrowthLimit;
	float GrowthMayuPoint;
	float NormalBoundary;
	float NeutralBoundary;
	float AddGrowthTime;
	float TimeAddGrowthChild;
	float TimeAddGrowthAdult;
	float TimeAddAttrChild;
	float TimeAddAttrAdult;
	float PartsSetProb;
	float PartsRemoveProb;
	float CamDistShadowCutLev1;
	float CamDistShadowCutLev2;
	float CamDistShadowCutLev3;
	float CamDistShadowCutLev4;
	float CamDistShadowCutLev5;
	unsigned int MayuWaitTime;
	unsigned int MayuFadeInTime;
	unsigned int MayuTypeChageTime;
	unsigned int MayuFadeOutTime;
	unsigned int MayuRelaxTime;
	float MayuExpandRatio;
	float MayuShrinkRatio;
	float MayuInitAlpha;
	__int16 SucceedBoundaryUserLike;
	unsigned __int16 SucceedBoundaryStress;
	unsigned __int16 SucceedBoundaryCondition;
	unsigned __int16 SucceedBoundaryMood;
	float FruitAddGrowthChild;
	float FruitAddGrowthAdult;
	unsigned __int16 FruitAddStaminaChild;
	unsigned __int16 FruitAddStaminaAdult;
	int FruitAddRecoverLife;
	int FruitAddLifeMax;
	int FruitAddUserLike;
	float FruitAddAttrChild;
	float FruitAddAttrAdult;
	float FruitDislikeSubAttr;
	float FruitPakuriSubAttr;
	float MinimalAddFormChild;
	float MinimalAddFormAdult;
	float MinimalAddAttrChild;
	float MinimalAddAttrAdult;
	float MinimalAddGrowthChild;
	float MinimalAddGrowthAdult;
	int MinimalAddUserLike;
	float DakkoAddAttr;
	float DamageSubAttr;
	float NadeAddAttr;
	float ThrownSubAttr;
	int DamageAddLife;
	int DamageAddLifeMax;
	unsigned __int16 NestFlowerInterval;
	unsigned __int16 nbNestFlower;
	float NestRange;
	unsigned __int16 NestWaitTime;
	unsigned __int16 SeedClock;
	unsigned __int16 SaplingClock;
	unsigned __int16 TreeClock;
	unsigned __int16 WaterSub;
	__int16 field_11A;
	float TreeFruitAddGrowth;
	unsigned __int16 FruitMaxNum;
	unsigned __int16 KwSubFear;
	unsigned __int16 KwAddDistance;
	unsigned __int16 SkillWalk;
	unsigned __int16 SkillRun;
	unsigned __int16 SkillRun2;
	float SkillRunAccBase;
	float SkillRunAccRatio;
	unsigned __int16 SkillSwimInukaki;
	unsigned __int16 SkillSwimBataashi;
	unsigned __int16 SkillSwimCrawl;
	__int16 field_13A;
	float SkillSwimAccBase;
	float SkillSwimAccRatio;
	unsigned __int16 ParamSubPleasure;
	unsigned __int16 ParamSubAnger;
	unsigned __int16 ParamSubSorrow;
	unsigned __int16 ParamSubFear;
	unsigned __int16 ParamSubSurprise;
	unsigned __int16 ParamSubPain;
	unsigned __int16 ParamSubRelax;
	unsigned __int16 ParamAddSleepy;
	unsigned __int16 ParamSubSleepy;
	unsigned __int16 ParamAddSleepDepth;
	unsigned __int16 ParamSubSleepDepth;
	unsigned __int16 ParamWakeUpSleepDepth;
	unsigned __int16 ParamAddHunger;
	unsigned __int16 ParamSubHunger;
	unsigned __int16 ParamAddBreed;
	unsigned __int16 ParamAddTediousCuriosity;
	unsigned __int16 ParamAddTediousAggressive;
	unsigned __int16 ParamAddTediousCalm;
	unsigned __int16 ParamSubTediousWalk;
	unsigned __int16 ParamSubTediousSwim;
	unsigned __int16 ParamAddLonely;
	unsigned __int16 ParamAddLonelyGreet;
	unsigned __int16 ParamAddLonelySuri;
	unsigned __int16 ParamAddLonelyAttack;
	unsigned __int16 ParamAddTireNormal;
	unsigned __int16 ParamSubTireSleep;
	unsigned __int16 ParamSubTireRest;
	unsigned __int16 ParamAddTireWalk;
	unsigned __int16 ParamAddTireRun;
	unsigned __int16 ParamAddTireSwim;
	unsigned __int16 ParamSubTireSwimStop;
	unsigned __int16 ParamSubNourishment;
	unsigned __int16 ParamAddConditionN;
	unsigned __int16 ParamConditionTriggerAddN;
	unsigned __int16 ParamSubConditionN;
	unsigned __int16 ParamConditionTriggerSubN;
	unsigned __int16 ParamSubConditionS;
	unsigned __int16 ParamConditionTriggerS;
	unsigned __int16 ParamSubConditionP;
	unsigned __int16 ParamConditionTriggerP;
	unsigned __int16 ParamAddConditionRest;
	unsigned __int16 ParamAddThirsty;
	unsigned __int16 ParamSubThirstySwim;
	unsigned __int16 ChaoTimerBaseInterval;
	unsigned __int16 ChaoTimerLifeInterval;
	unsigned __int16 ChaoTimerEmotionInterval;
	unsigned __int16 ChaoTimerMoodInterval;
	unsigned __int16 ChaoTimerKnowledgeInterval;
	unsigned __int16 ChaoTimerIllInterval;
	__int16 field_1A6;
	float IntentionScoreRandomRatio;
	float IntentionMinScore;
	unsigned int IntentionAngerTrigger;
	unsigned int IntentionAngerPlayerTrigger;
	float IntentionAngerMinScore;
	float IntentionAngerMaxScore;
	unsigned int IntentionFearTrigger;
	unsigned int IntentionFearPlayerTrigger;
	float IntentionFearMinScore;
	float IntentionFearMaxScore;
	unsigned int IntentionSorrowTrigger;
	float IntentionSorrowMinScore;
	float IntentionSorrowMaxScore;
	unsigned int IntentionPainTrigger;
	float IntentionPainMinScore;
	float IntentionPainMaxScore;
	unsigned int IntentionPleasureTrigger;
	float IntentionPleasureMinScore;
	float IntentionPleasureMaxScore;
	unsigned int IntentionHungerGooMinInterval;
	unsigned int IntentionHungerGooIntervalRange;
	unsigned int IntentionHungerGooTrigger;
	float IntentionHungerGooMaxScore;
	unsigned int IntentionHungerFruitGoToEatTrigger;
	float IntentionHungerFruitGoToEatMaxScore;
	unsigned int IntentionHungerFruitSearchTrigger;
	float IntentionHungerFruitSearchMaxScore;
	unsigned int IntentionAkubiMinInterval;
	unsigned int IntentionAkubiIntervalRange;
	unsigned int IntentionAkubiTrigger1;
	unsigned int IntentionAkubiTrigger2;
	unsigned int IntentionAkubiTrigger3;
	float IntentionAkubiMaxScore;
	unsigned int IntentionPlayerGreetLonelyTrigger;
	float IntentionPlayerGreetMaxScore;
	unsigned int IntentionPlayerSuriSuriLonelyTrigger;
	float IntentionPlayerSuriSuriMaxScore;
	unsigned int IntentionSleepTrigger;
	float IntentionSleepMaxScore;
	unsigned int IntentionHimaTrigger;
	float IntentionHimaMaxScore;
	unsigned int IntentionThirstyTrigger;
	float IntentionThirstyMaxScore;
	unsigned int IntentionApproachNestTrigger;
	float IntentionApproachNestMaxScore;
	unsigned int IntentionJyouroThirstyTrigger;
	float IntentionJyouroMaxScore;
	unsigned int IntentionRestTrigger1;
	unsigned int IntentionRestTrigger2;
	float IntentionRestMaxScore;
	unsigned int IntentionRestEndTrigger;
	unsigned int RaceIntervalSubStamina;
	unsigned int RaceSubStaminaSwim;
	unsigned int RaceSubStaminaFly;
	unsigned int RaceSubStaminaRun;
	unsigned int RaceSubStaminaClimb;
	unsigned int RaceSubStaminaTree;
	unsigned int RaceSubStaminaOther;
	unsigned int RaceAddStaminaSit;
	unsigned int RaceCheerInterval;
	unsigned int RaceCheerDecAimStamina;
	unsigned int RaceCheerDecStamina;
	float RaceTurboRatioSwim;
	float RaceTurboRatioFly;
	float RaceTurboRatioRun;
	float RaceTurboRatioClimb;
	float RaceTurboRatioTree;
	float RaceTurboRatioOther;
};
#pragma pack(pop)

DataPointer(CHAO_GLOBAL, ChaoGlobal, 0x01312C48);

const int sub_540FD0Ptr = 0x540FD0;
void sub_540FD0(NJS_VECTOR* v, float f)
{
	__asm
	{
		push f
		mov eax, v
		call sub_540FD0Ptr
	}
}

DataArray(ShadowThing, ShadowThingArray, 0x19ED3F8, 64);

const int sub_6BD4C0Ptr = 0x6BD4C0;
void  sub_6BD4C0(int a1, ShadowData* a2)
{
	//int result;
	__asm
	{
		mov edi, a1
		mov esi, a2
		call sub_6BD4C0Ptr
		//mov result, eax
	}
	//return result;
}

const int sub_42B5A0Ptr = 0x42B5A0;
void sub_42B5A0(int a1)
{
	__asm
	{
		mov ebx, a1
		call sub_42B5A0Ptr
	}
}

const int sub_6BD1E0Ptr = 0x6BD1E0;
void sub_6BD1E0(ShadowData* a1, float a2, float a3, float a4, NJS_VECTOR* a5)
{
	__asm
	{
		push a5
		push[a4]
		push[a3]
		push[a2]
		mov ebx, a1
		call sub_6BD1E0Ptr
		add esp, 16
	}
}

VoidFunc(sub_6BD450, 0x6BD450);

const int sub_495D20Ptr = 0x495D20;
void sub_495D20(int a1, float a2, WeirdChunkTexIndexThing* a3, TextureData* a4, ShadowData* a5, NJS_VECTOR* a6)
{
	__asm
	{
		push[a5]
		push[a4]
		push[a3]
		push[a2]
		push[a1]
		mov ecx, [a6]
		call sub_495D20Ptr
		add esp, 20
	}
}

const int ScaleObjectMaster_XYZPtr = 0x0054AC70;
int ScaleObjectMasterXYZ(ObjectMaster* a1, float a2, float a3, float a4)
{
	int ret;
	__asm
	{
		push a4
		push a3
		push a2
		mov eax, a1
		call ScaleObjectMaster_XYZPtr
		add esp, 12
		mov ret, eax
	}
	return ret;
}

VoidFunc(sub_42D340, 0x42D340);
//FunctionPointer(void *, __cdecl sub_495D20, (int a1, float a2, int a3, int a4, int a5),0x495D20);
DataPointer(struc_33, stru_1DCFF40, 0x1DCFF40);
FunctionPointer(int, __cdecl sub_420210, (float arg0, float a2, float a3, float a4, float MinZ, float MaxZ), 0x420210);
FunctionPointer(int, __cdecl sub_420390, (float a1, float a2, float a3, float a4), 0x420390);
const int sub_41B160Ptr = 0x41B160;
void sub_41B160(TextureData* result)
{
	__asm
	{
		mov eax, result
		call sub_41B160Ptr
	}
}

#pragma region ShadowQueueSystem

struct GJ_MATRIX { float m[12]; };

struct shadowentry { ObjectMaster* obj; ObjectFuncPtr shadowDrawFunc; };
std::vector<shadowentry> shadowQueue;

void QueueShadow(ObjectMaster* obj, ObjectFuncPtr func)
{
	shadowQueue.push_back({ obj , func});
}
void ClearShadowQueue()
{
	shadowQueue.clear();
}

float proj_scl = 1.5f;
bool highDetailChao = true;

DataPointer(ObjectMaster*, AL_ExecShadowTex_ptr, 0x01A5D144);
void DrawShadowQueue(ObjectMaster *a1)
{
	if (shadowQueue.size() > 0) 
	{
		ShadowData* data;
		data = (ShadowData*)a1->field_4C;
		
		//first value = radius kinda thing, called "proj_scl" in some symbol thing, the higher this is the lower the res gets which is why the radius is so small
		//second = some scaling thing
		//third = offset?
		sub_6BD1E0(data, proj_scl, 1.0f, 0.0, &AL_ExecShadowTex_ptr->Data1.Entity->Position);

		for (int i = 0; i < shadowQueue.size(); i++)
			shadowQueue[i].shadowDrawFunc(shadowQueue[i].obj);

		sub_6BD450();
		sub_495D20(2, 1000.0f, &data->weirdchunktexindexthing30, data->dword54, data, &AL_ExecShadowTex_ptr->Data1.Entity->Position);
	}
}
void ShadowQueue_Main(ObjectMaster* a1) {}
void CreateShadowQueue()
{
	//TODO create deletesub

	ClearShadowQueue();

	ObjectMaster* a1 = LoadObject(4, "AL_ShadowQueue", ShadowQueue_Main, LoadObj_Data1);
	int* v2 = (int*)MemoryManager->Allocate(sizeof(ShadowData) + 4, (char*)"..\\..\\src\\ShadowFix.cpp", __LINE__); //code originally taken from meteorherd

	ShadowData* v3 = (ShadowData*)(v2 + 1);
	*v2 = 305419896;
	memset(v2 + 1, 0, 0x58u);
	a1->field_4C = v3;
	//a1->field_1C = DrawShadowQueue;
	a1->field_2C = DrawShadowQueue;
	sub_6BD4C0(480, (ShadowData*)a1->field_4C);//64 = 2, 256 = 4
}
#pragma endregion

#pragma region Chao
void __cdecl sub_5405D0(ObjectMaster* a1)
{
	ChaoData1* v1; // ebp
	ChaoSomeUnknownA* v2; // eax
	double v3; // st7
	float* v4; // esi
	float* v5; // eax
	float* v6; // eax
	float* v7; // eax
	int v8; // ebp
	float* v10; // eax
	unsigned int v11; // edi
	float* v12; // esi
	float* v13; // ebx
	float* v14; // ebx
	float* v15; // ebx
	NJS_VECTOR* v16; // eax
	Float a4; // ST08_4
	int v18; // ebp
	float v19; // [esp+1Ch] [ebp-34h]
	float v20; // [esp+20h] [ebp-30h]
	float v21; // [esp+24h] [ebp-2Ch]
	float v22; // [esp+28h] [ebp-28h]
	float v23; // [esp+2Ch] [ebp-24h]
	float v24; // [esp+30h] [ebp-20h]
	float v25; // [esp+34h] [ebp-1Ch]
	float v26; // [esp+38h] [ebp-18h]
	float v27; // [esp+3Ch] [ebp-14h]
	float v28; // [esp+40h] [ebp-10h]
	float v29; // [esp+44h] [ebp-Ch]
	float v30; // [esp+48h] [ebp-8h]
	float v31; // [esp+4Ch] [ebp-4h]
	float a3; // [esp+54h] [ebp+4h]
	//njPushMatrix((NJS_MATRIX_PTR)0x025F02A0);

	v1 = a1->Data1.Chao;
	v2 = (ChaoSomeUnknownA*)a1->UnknownA_ptr;
	if (v2)
	{
		v3 = v2->playerDistance;
	}
	else
	{
		v3 = 300.0;
	}
	v19 = v3;
	if (*(float*)0x1312CC4 > v19)
	{
		njPushMatrixEx();
		{
			njTranslate(_nj_current_matrix_ptr_, v1->HeadTranslationPos.x, v1->HeadTranslationPos.y, v1->HeadTranslationPos.z);
			if (v1->entity.Rotation.y)
			{
				njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
			}
			njScale(1.6f, 0.7f, 1.5f);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();

		if (*(float*)0x1312CBC > v19)
		{
			njPushMatrixEx();
			{
				if (v1->field_674 & 8)
				{
					v1->LeftHandTranslationPos.y = v1->entity.Position.y + 0.009999999776482582;
				}
				njTranslateV(&v1->LeftHandTranslationPos);
				if (v1->entity.Rotation.y)
				{
					njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
				}
				njScale(0.65, 0.6, 0.65);
				sub_42D340();
				ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
			}
			njPopMatrixEx();

			njPushMatrixEx();
			{
				if (v1->field_674 & 8)
				{
					v1->RightHandTranslationPos.y = v1->entity.Position.y + 0.009999999776482582;
				}
				njTranslateV(&v1->RightHandTranslationPos);
				if (v1->entity.Rotation.y)
				{
					njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
				}
				njScale(0.65, 0.6, 0.65);
				sub_42D340();
				ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
			}
			njPopMatrixEx();

			if (*(float*)0x1312CB8 > v19)
			{
				njPushMatrixEx();
				{
					njTranslateV(&v1->BaseTranslationPos);
					if (v1->entity.Rotation.y)
						njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
					njScale(*(float*)0xB18F54, 0.7, *(float*)0xB18F54);
					sub_42D340();
					ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
				}
				njPopMatrixEx();

				if (!a1->Data1.Chao->ChaoDataBase_ptr->HideFeet)
				{
					njPushMatrixEx();
					{
						njTranslateV(&v1->LeftLegTranslationPos);
						if (v1->entity.Rotation.y)
						{
							njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
						}
						njScale(0.60000002, 0.60000002, 0.89999998);
						sub_42D340();
						ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
					}
					njPopMatrixEx();

					njPushMatrixEx();
					{
						njTranslateV(&v1->RightLegTranslationPos);
						if (v1->entity.Rotation.y)
						{
							njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
						}
						njScale(0.6, 0.6, 0.9);
						sub_42D340();
						ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
					}
					njPopMatrixEx();
				}
				njPushMatrixEx();
				{
					if (v1->field_674 & 8)
						njTranslate(_nj_current_matrix_ptr_, a1->Data1.Chao->EmotionBallData.float90.x, v1->entity.Position.y + 0.001, a1->Data1.Chao->EmotionBallData.float90.z);
					else
						njTranslateV(&a1->Data1.Chao->EmotionBallData.float90);
					if (v1->entity.Rotation.y)
						njRotateY(_nj_current_matrix_ptr_, v1->entity.Rotation.y);
					njScale(0.5, 0.69999999, 0.5);

					sub_42D340();
					ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
				}
				njPopMatrixEx();
			}
		}
	}
	//njPopMatrixEx();
}
void __cdecl Chao_ShadowDisplay(ObjectMaster* a1)
{
	ShadowData* data;
	data = (ShadowData*)a1->field_4C;
	NJS_VECTOR vec = { 0,0,0 };
	sub_6BD1E0(data, 1.0, 1.0, 0.0, &a1->Data1.Entity->Position);

	sub_5405D0(a1);

	sub_6BD450();
	sub_495D20(1, 82.0, &data->weirdchunktexindexthing30, data->dword54, data, &a1->Data1.Entity->Position);
}
ObjectMaster* ShadowHook_CreateChao(ChaoData* chaoData, int a2, void* a3, NJS_VECTOR* position, Angle angle)
{
	ObjectMaster* ret = CreateChao(chaoData, a2, a3, position, angle);
	ObjectFunc(sub_540B60, 0x540B60);
	if(!highDetailChao)
		QueueShadow(ret, sub_5405D0);
	else QueueShadow(ret, sub_540B60);
	return ret;
}
#pragma endregion

#pragma region Tree
DataArray(int, dword_12E8AEC, 0x12E8AEC, 11);
void __cdecl sub_5479C0(ALO_GrowTreeExecutor_Data* a1)
{
	float* v1; // ebx
	float* v2; // esi
	float* v3; // eax
	float* v4; // esi
	int v5; // edx
	float* v6; // esi
	unsigned int v7; // ebp
	float* v8; // eax
	float* v9; // eax
	float* v10; // esi
	float* v11; // eax
	float* v12; // esi
	float* v13; // eax
	float* v14; // esi
	float* v15; // eax
	float* v16; // ebx
	float v17; // [esp+1Ch] [ebp-3Ch]
	float v18; // [esp+1Ch] [ebp-3Ch]
	double v19; // [esp+1Ch] [ebp-3Ch]
	float v20; // [esp+20h] [ebp-38h]
	float v21; // [esp+24h] [ebp-34h]
	float v22; // [esp+28h] [ebp-30h]
	float v23; // [esp+2Ch] [ebp-2Ch]
	float v24; // [esp+30h] [ebp-28h]
	float v25; // [esp+34h] [ebp-24h]
	float v26; // [esp+38h] [ebp-20h]
	float v27; // [esp+3Ch] [ebp-1Ch]
	float v28; // [esp+40h] [ebp-18h]
	float v29; // [esp+44h] [ebp-14h]
	float v30; // [esp+48h] [ebp-10h]
	float v31; // [esp+4Ch] [ebp-Ch]
	float v32; // [esp+50h] [ebp-8h]
	float v33; // [esp+54h] [ebp-4h]
	int a1a; // [esp+5Ch] [ebp+4h]

	njPushMatrixEx();
	{
		njTranslate(_nj_current_matrix_ptr_, a1->entityData.Position.x, a1->entityData.Position.y, a1->entityData.Position.z);
		if (a1->TouchAngle)
		{
			njRotateY(_nj_current_matrix_ptr_, a1->TouchAngle);
		}
		if (a1->RollAngle)
		{
			njRotateX(_nj_current_matrix_ptr_, a1->RollAngle);
		}
		if (a1->TouchAngle)
		{
			njRotateY(_nj_current_matrix_ptr_, -a1->TouchAngle);
		}
		if (a1->entityData.Rotation.y)
		{
			njRotateY(_nj_current_matrix_ptr_, a1->entityData.Rotation.y);
		}
		njTranslate(_nj_current_matrix_ptr_, 0.0, 20.0, 0.0);
		sub_42D340();
		ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
	}
	njPopMatrixEx();

	njPushMatrixEx();
	{
		
		njTranslate(_nj_current_matrix_ptr_, a1->entityData.Position.x, a1->entityData.Position.y, a1->entityData.Position.z);
		if (a1->TouchAngle)
		{
			njRotateY(_nj_current_matrix_ptr_, a1->TouchAngle);
		}
		if (a1->RollAngle)
		{
			njRotateX(_nj_current_matrix_ptr_, a1->RollAngle);
		}
		if (a1->TouchAngle)
		{
			njRotateY(_nj_current_matrix_ptr_, -a1->TouchAngle);
		}
		if (a1->entityData.Rotation.y != 0xFFFFE000)
		{
			njRotateY(_nj_current_matrix_ptr_, a1->entityData.Rotation.y + 0x2000);
		}
		//njTranslate(_nj_current_matrix_ptr_, 0.0, 20.0, 0.0);

		v5 = a1->LeafRotAng;
		v18 = a1->LeafWidth;
		a1a = a1->LeafRotAng;
		njPushMatrixEx();
		{
			v19 = v18 * 0.1500000059604645;
			v32 = njSin(dword_12E8AEC[0] + v5) * v19 + 7.699999809265137;
			njScale(3.0f, 2.0f, v32);
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.0, 0.85000002);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();

		njRotateY(_nj_current_matrix_ptr_, 14336);

		njPushMatrixEx();
		{
			v32 = njSin(a1a + dword_12E8AEC[1]) * v19 + 7.300000190734863;
			njScale(3.0f, 2.0f, v32);
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.0, 0.85000002);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();

		njRotateY(_nj_current_matrix_ptr_, 0x5000);

		njPushMatrixEx();
		{
			v32 = njSin(dword_12E8AEC[2] + a1a) * v19 + 7.800000190734863;
			njScale(4.0f, 2.0f, v32);
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.0, 0.85000002);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();

		njRotateY(_nj_current_matrix_ptr_, 19200);

		njPushMatrixEx();
		{
			v32 = njSin(dword_12E8AEC[3] + a1a) * v19 + 7.099999904632568;
			njScale(4.0f, 2.0f, v32);
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.0, 0.85000002);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();
	}
	njPopMatrixEx();
}
void sub_547840(ALO_GrowTreeExecutor_Data* a1)
{
	ALO_GrowTreeExecutor_Data* v3; // esi
	signed int v4; // esi

	v3 = a1;
	njPushMatrixEx();
	{
		njTranslate(_nj_current_matrix_ptr_, v3->entityData.Position.x, v3->entityData.Position.y, v3->entityData.Position.z);
		if (v3->TouchAngle)
		{
			njRotateY(_nj_current_matrix_ptr_, v3->TouchAngle);
		}
		if (v3->RollAngle)
		{
			njRotateX(_nj_current_matrix_ptr_, v3->RollAngle);
		}
		if (v3->TouchAngle)
		{
			njRotateY(_nj_current_matrix_ptr_, -v3->TouchAngle);
		}
		v4 = v3->entityData.Rotation.y;
		if (v4)
		{
			njRotateY(_nj_current_matrix_ptr_, v4);
		}
		njTranslate(_nj_current_matrix_ptr_, 0.0, 20.0, 0.0);
		sub_42D340();
		ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
	}
	njPopMatrixEx();

	njPushMatrixEx();
	{
		njScale(3, 2, 3);
		njTranslate(_nj_current_matrix_ptr_, 0.0, 0.0, 0.85000002);
		sub_42D340();
		ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
	}
	njPopMatrixEx();
}

void __cdecl GrowTree_ShadowDisplay(ObjectMaster* a1)
{
	ShadowData* data;
	data = (ShadowData*)a1->field_4C;
	ALO_GrowTreeExecutor_Data* treedata = (ALO_GrowTreeExecutor_Data*)a1->Data1.Undefined;

	//sub_6BD1E0(data, 1.0, 1.0, 0.0, &a1->Data1.Entity->Position);

	if (treedata->state == 5) {
		if (!treedata->pShadowObject)
			sub_5479C0(treedata);
	}
	else if (treedata->entityData.Action > 7)
		sub_547840(treedata);

	//sub_6BD450();
	//sub_495D20(2, 82.0, &data->weirdchunktexindexthing30, data->dword54, data, &a1->Data1.Entity->Position);
}

//they implemented a shadow object for the darktree, but they never ended up using it so this brings that back
//not using it though, cuz its pretty bad, probably why it went unused
void GrowTree_DisplaySub_(ObjectMaster* a1)
{
	ALO_GrowTreeExecutor_Data* treedata = (ALO_GrowTreeExecutor_Data*)a1->Data1.Undefined;
	ALO_GrowTreeExecutor_Display(a1);
	if (treedata->state == 5)
	{
		if (treedata->pShadowObject)
		{
			Has_texlist_batadvPlayerChara_in_it[8] = (int)treedata->texlist;
			njPushMatrixEx();
			njTranslate(_nj_current_matrix_ptr_, treedata->entityData.Position.x, treedata->entityData.Position.y + 2, treedata->entityData.Position.z);
			njCnkDrawObject(treedata->pShadowObject);
			njPopMatrixEx();
		}
	}
}

void ALO_GrowTreeExecutor_Load_(NJS_VECTOR* pos, void* data)
{
	ObjectMaster* ret = (ObjectMaster*)ALO_GrowTreeExecutor_Load((int)pos, (int)data);
	QueueShadow(ret, GrowTree_ShadowDisplay);
	//ret->field_1C = GrowTree_ShadowDisplay;
}
#pragma endregion

#pragma region Radio
void __cdecl ALO_RadicaseExecutor_ShadowDisplay(ObjectMaster* a1)
{
	ObjectMaster* v1; // ebp
	Data1Ptr v2; // ebx
	float* v3; // esi
	float* v4; // eax
	float* v5; // eax
	signed int v6; // ebx
	float* v7; // esi
	float v8; // [esp+18h] [ebp-30h]
	float v9; // [esp+1Ch] [ebp-2Ch]
	float v10; // [esp+20h] [ebp-28h]
	float v11; // [esp+24h] [ebp-24h]
	float v12; // [esp+28h] [ebp-20h]
	float v13; // [esp+2Ch] [ebp-1Ch]
	float v14; // [esp+30h] [ebp-18h]
	float v15; // [esp+34h] [ebp-14h]
	float v16; // [esp+38h] [ebp-10h]
	float v17; // [esp+3Ch] [ebp-Ch]
	float v18; // [esp+40h] [ebp-8h]
	float v19; // [esp+44h] [ebp-4h]
	float a1a; // [esp+4Ch] [ebp+4h]

	ShadowData* data;
	data = (ShadowData*)a1->field_4C;

	//sub_6BD1E0(data, 1.0, 1.0, 0.0, &a1->Data1.Entity->Position);

	v1 = a1;
	v2.Entity = (EntityData1*)a1->Data1.Entity;
	a1a = njSin(v2.Entity->Rotation.x) * 0.05000000074505806 + 1.0;
	if (ScaleObjectMasterXYZ(v1, 3.0, 3.0, 1.0))
	{
		njPushMatrixEx();
		njTranslate(_nj_current_matrix_ptr_, 0.0, -1.5, 0.0);
		njTranslate(_nj_current_matrix_ptr_, v2.Entity->Position.x, v2.Entity->Position.y, v2.Entity->Position.z);
		v6 = v2.Entity->Rotation.y;
		if (v6)
		{
			njRotateY(_nj_current_matrix_ptr_, v6);
		}
		njScale(a1a, 2.0f - a1a, 1.0f);	
		if (ChaoGlobal.CamDistShadowCutLev2 > *(float*)& v1->UnknownA_ptr->field_30)
		{
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.5, 0.0);
			njScale(2.0f, 1.0f, 1.5f);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();
	}

	//sub_6BD450();
	//sub_495D20(3, 82.0, &data->weirdchunktexindexthing30, data->dword54, data, &a1->Data1.Entity->Position);
}
void ALO_RadicaseExecutor_Load_(NJS_VECTOR* pos)
{
	ALO_RadicaseExecutor_Load((int)pos);
	ObjectMaster* ret = *(ObjectMaster**)0x01AED2E0;
	QueueShadow(ret, ALO_RadicaseExecutor_ShadowDisplay);
	/*
	int* v2 = (int*)MemoryManager->Allocate(sizeof(ShadowData) + 4, (char*)"..\\..\\src\\ShadowFix.cpp", __LINE__); //code originally taken from meteorherd

	ShadowData* v3 = (ShadowData*)(v2 + 1);
	*v2 = 305419896;
	memset(v2 + 1, 0, 0x58u);
	ret->field_4C = v3;
	ret->field_2C = ALO_RadicaseExecutor_ShadowDisplay;

	sub_6BD4C0(64, (ShadowData*)ret->field_4C);//64 = 2, 256 = 4
	*/
}
#pragma endregion

#pragma region TV
void __cdecl ALO_TVExecutor_ShadowDisplay(ObjectMaster* a1)
{
	Data1Ptr v1; // ebx
	float* v2; // eax
	float* v3; // edx
	float* v4; // eax
	Float* v5; // eax
	signed int v6; // ebx
	float* v7; // esi
	float v8; // [esp+1Ch] [ebp-30h]
	float v9; // [esp+20h] [ebp-2Ch]

	v1.Entity = (EntityData1*)a1->Data1.Entity;
	if (ScaleObjectMasterXYZ(a1, 3.0, 3.0, 1.0))
	{
		njPushMatrixEx();
		njTranslate(_nj_current_matrix_ptr_, 0.0, -1.5, 0.0);
		njTranslate(_nj_current_matrix_ptr_, v1.Entity->Position.x, v1.Entity->Position.y, v1.Entity->Position.z);
		v6 = v1.Entity->Rotation.y;
		if (v6)
		{
			njRotateY(_nj_current_matrix_ptr_, v6);
		}
		if (ChaoGlobal.CamDistShadowCutLev2 > (double) * (float*)& a1->UnknownA_ptr->field_30)
		{
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.5, 0.0);
			njScale(2, 1, 1.5);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();
	}
}
void ALO_TVExecutor_Load_(NJS_VECTOR* pos)
{
	ALO_TVExecutor_Load(pos);
	ObjectMaster* ret = *(ObjectMaster * *)0x1AED288;
	QueueShadow(ret, ALO_TVExecutor_ShadowDisplay);
}
#pragma endregion

#pragma region Horse
void __cdecl ALO_Horse_ShadowDisplay(ObjectMaster* a1)
{
	Data1Ptr v1; // ebx
	float* v2; // eax
	float* v3; // edx
	float* v4; // eax
	Float* v5; // eax
	signed int v6; // ebx
	float* v7; // esi
	float v8; // [esp+1Ch] [ebp-30h]
	float v9; // [esp+20h] [ebp-2Ch]

	v1.Entity = (EntityData1*)a1->Data1.Entity;
	if (ScaleObjectMasterXYZ(a1, 3.4000001, 3.2, 0.0))
	{
		njPushMatrixEx();
		njTranslate(_nj_current_matrix_ptr_, v1.Entity->Position.x, v1.Entity->Position.y, v1.Entity->Position.z);
		v6 = v1.Entity->Rotation.y;
		if (v6)
		{
			njRotateY(_nj_current_matrix_ptr_, v6);
		}
		if (ChaoGlobal.CamDistShadowCutLev3 > (double) * (float*)& a1->UnknownA_ptr->field_30)
		{
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.8f, 0.0);
			njScale(0.7f, 0.7f, 1.8f);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();
	}
}
void ALO_Horse_Load_(ObjectMaster* a1)
{
	ALO_Horse_Main(a1);
	QueueShadow(a1, ALO_Horse_ShadowDisplay);
}
#pragma endregion

#pragma region Box
void __cdecl ALO_Box_ShadowDisplay(ObjectMaster* a1)
{
	Data1Ptr v1; // ebx
	float* v2; // eax
	float* v3; // edx
	float* v4; // eax
	Float* v5; // eax
	signed int v6; // ebx
	float* v7; // esi
	float v8; // [esp+1Ch] [ebp-30h]
	float v9; // [esp+20h] [ebp-2Ch]

	v1.Entity = (EntityData1*)a1->Data1.Entity;
	if (ScaleObjectMasterXYZ(a1, 2.5, 2.5, 1.0))
	{
		njPushMatrixEx();
		njTranslate(_nj_current_matrix_ptr_, v1.Entity->Position.x, v1.Entity->Position.y, v1.Entity->Position.z);
		v6 = v1.Entity->Rotation.y;
		if (v6)
		{
			njRotateY(_nj_current_matrix_ptr_, v6);
		}
		//if (ChaoGlobal.CamDistShadowCutLev3 > (double) * (float*)& a1->UnknownA_ptr->field_30)
		{
			njTranslate(_nj_current_matrix_ptr_, 0.0, 0.5f, 0.0);
			njScale(1.5f, 1, 1.5f);
			sub_42D340();
			ProcessChunkModelsWithCallback((NJS_OBJECT*)& Sphere, ProcessChunkModel);
		}
		njPopMatrixEx();
	}
}
void ALO_BoxExecutor_Load_(NJS_VECTOR* a1)
{
	ALO_BoxExecutor_Load(a1);
	QueueShadow(*(ObjectMaster**)0x01AED32C, ALO_Box_ShadowDisplay);
}
#pragma endregion


void AL_NeutGardenMaster_(ObjectMaster* a1) {
	CreateShadowQueue();
	AL_NeutGardenMaster(a1);
}
void AL_HeroGardenMaster_(ObjectMaster* a1) {
	CreateShadowQueue();
	AL_HeroGardenMaster(a1);
}
void AL_DarkGardenMaster_(ObjectMaster* a1) {
	CreateShadowQueue();
	AL_DarkGardenMaster(a1);
}

extern "C"
{
	__declspec(dllexport) void Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		int radiusSetting = config->getInt("ShadowFix", "ShadowRadiusSetting", 1);
		switch(radiusSetting)
		{
		case 0 :
			proj_scl = 3.5f;
			break;
		case 1:
			proj_scl = 2.5f;
			break;
		case 2:
			proj_scl = 1.5f;
			break;
		case 3:
			proj_scl = 1.0f;
			break;
		}
		highDetailChao = config->getBool("ShadowFix", "HighDetailChao", false);

		WriteData((int*)0x0054C502, (int)AL_NeutGardenMaster_);
		WriteData((int*)0x0054CCF2, (int)AL_HeroGardenMaster_);
		WriteData((int*)0x0054B432, (int)AL_DarkGardenMaster_);

		//chao
		//kills existing circle shadow
		WriteCall((void*)0x0054FF15, nullsub_1);
		//hooks garden createchao call, only the garden and the egg ones because the rest glitch out because shadows get casted upwards for some reason
		WriteCall((void*)0x00531D91, ShadowHook_CreateChao);
		WriteCall((void*)0x0057AE58, ShadowHook_CreateChao);
		WriteCall((void*)0x0057B058, ShadowHook_CreateChao);
		WriteCall((void*)0x0057B2C9, ShadowHook_CreateChao);
		
		//tree
		WriteCall((void*)0x0052EBB9, ALO_GrowTreeExecutor_Load_);

		//toys
		WriteCall((void*)0x0054B9BA, ALO_RadicaseExecutor_Load_);
		WriteCall((void*)0x0054CADB, ALO_TVExecutor_Load_);
		WriteCall((void*)0x0054CB21, ALO_BoxExecutor_Load_);
		WriteData((int*)0x00580F38,  (int)ALO_Horse_Load_);
	}
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}

