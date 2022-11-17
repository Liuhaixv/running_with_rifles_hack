void __thiscall check_radio(float *a1, float a2)
{
  int unable_to_call;                        // eax
  int v4;                                    // edi
  int v5;                                    // eax
  int v6;                                    // eax
  Concurrency::details::SchedulerProxy *v7;  // ecx
  unsigned int NumBorrowedCores;             // eax
  int v9;                                    // eax
  char *v10;                                 // ecx
  Concurrency::details::SchedulerProxy *v11; // edi
  unsigned int v12;                          // eax
  void *v13;                                 // eax
  int v14;                                   // [esp-8h] [ebp-60h]
  void *v15;                                 // [esp-8h] [ebp-60h]
  int v16;                                   // [esp-4h] [ebp-5Ch]
  char v17[28];                              // [esp+14h] [ebp-44h] BYREF
  char v18[4];                               // [esp+30h] [ebp-28h] BYREF
  int v19;                                   // [esp+54h] [ebp-4h]
  float v20;                                 // [esp+5Ch] [ebp+4h]

  v20 = a1[19] - a2;
  a1[19] = v20;
  if (v20 < 0.0)
  {
    unable_to_call = *((_DWORD *)a1 + 20);
    if (unable_to_call)
    {
      if (unable_to_call == 2)
      {
        std::string::string(v17, "commander radio full");
        v7 = (Concurrency::details::SchedulerProxy *)*((_DWORD *)a1 + 17);
        v19 = 0;
        NumBorrowedCores = Concurrency::details::SchedulerProxy::GetNumBorrowedCores(v7);
        v15 = sub_48A080((_DWORD *)(NumBorrowedCores + 372), (int)v17);
        v9 = sub_7562E0(a1);
        sub_4CF750(v9, (int)v15, *(int *)&Ogre::Vector3::ZERO, -1.0, 1.0);
        v10 = v17;
      }
      else
      {
        std::string::string(v18, "Hmm, no signal");
        v11 = (Concurrency::details::SchedulerProxy *)*((_DWORD *)a1 + 17);
        v19 = 1;
        v12 = Concurrency::details::SchedulerProxy::GetNumBorrowedCores(v11);
        v13 = sub_48A080((_DWORD *)(v12 + 372), (int)v18);
        sub_464C00((int)v11, (int)v13);
        v10 = v18;
      }
      v19 = -1;
      std::string::~string(v10);
    }
    else
    {
      v4 = *((_DWORD *)a1 + 17);
      v16 = sub_464040(v4);
      v14 = sub_464030(v4);
      v5 = sub_7562E0(a1);
      v6 = sub_4AC050(v5);
      sub_50C560(v6, v14, v16, v4, 0);
    }
    (*(void(__thiscall **)(float *))(*(_DWORD *)a1 + 32))(a1);
  }
  if (sub_464620(*((_BYTE **)a1 + 17)))
    (*(void (**)(void))(*(_DWORD *)a1 + 32))();
}