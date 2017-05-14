/**
 * Project:		GameStateManager
 * File Name:	Level2.c
 * Author:		����
 * Date:		2017-4-22
 * Purpose:		�ؿ�2
 */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Input.h"
#include "Level2.h"
#include "AEEngine.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------
static AEGfxVertexList*	pMesh2;				// ����2������(mesh)ģ��
static float obj2X, obj2Y;		// ����2��λ��

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	// ��ʼ��Ӷ���2
	AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	pMesh2 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh2, "Failed to create mesh 2!!");

	// ǩ��
	fprintf(fp, "Level2:Load\n");
}

void Ini2(void)
{
	// ����2�ĳ�ʼλ��
	obj2X = 0.0f;
	obj2Y = 0.0f;

	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);   // ����ɫRGB
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// ǩ��
	fprintf(fp, "Level2:Initialize\n");
}

void Update2(void)
{
	// ״̬�л�
	if (KeyPressed[KeyR])
		Next = GS_Restart;
	if (KeyPressed[KeyESC])
		Next = GS_Quit;
	if (KeyPressed[Key1])
		Next = GS_L1;

	// ��������
	Input_Initialize();

	// ǩ��
	fprintf(fp, "Level2:Update\n");
}

void Draw2(void)
{
	// ������2
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(obj2X, obj2Y);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetTransparency(2);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(pMesh2, AE_GFX_MDM_TRIANGLES);

	// ǩ��
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// ǩ��
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	AEGfxMeshFree(pMesh2);		// ע�������Ķ���

								// ǩ��
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------