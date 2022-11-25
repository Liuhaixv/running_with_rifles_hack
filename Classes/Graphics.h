#include "EntityList.h"
#include "GUIApplication.h"
typedef unsigned char byte;
typedef int DWORD;

class Graphics
{
	_BYTE gap0[4];
	DWORD dword4;
	int* Ogre$$SceneManager_8;
	int* Ogre$$Win32Window;
	int* Ogre$$Camera;
	int* Ogre$$Viewport;
	int* Ogre$$Light;
	DWORD dword1C;
	_BYTE gap20[24];
	GUIApplication* m_pGUIApplication;
	_BYTE gap3C[32];
	int int5C;

	GUIApplication* get_GUIApplication()
	{
		return this->m_pGUIApplication;
	}
};