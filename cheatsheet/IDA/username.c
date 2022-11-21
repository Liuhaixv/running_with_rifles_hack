void __thiscall sub_8277C0(_DWORD *this, _DWORD *a2, int a3, _DWORD *a4, int a5)
{
    int v6;           // eax
    _DWORD *v7;       // esi
    void *v8;         // eax
    void *v9;         // eax
    int v10;          // eax
    void *v11;        // eax
    void *v12;        // eax
    void *v13;        // eax
    int v14;          // eax
    void *v15;        // eax
    int **v16;        // ecx
    int v17;          // eax
    unsigned int v18; // [esp-8h] [ebp-E4h]
    char v19[28];     // [esp+14h] [ebp-C8h] BYREF
    int v20[20];      // [esp+30h] [ebp-ACh] BYREF
    int v21[20];      // [esp+80h] [ebp-5Ch] BYREF
    int v22;          // [esp+D8h] [ebp-4h]

    sub_731510(v20, "profile");
    v22 = 0;
    v6 = sub_79A900();
    sub_731710(v20, "game_version", v6);
    v7 = a4;
    if (!a4)
        v7 = (_DWORD *)sub_7A65C0((int **)(this[1] + 4872), *(_DWORD *)(a3 + 28));
    if (v7[8] < 0x10u)
        v8 = v7 + 3;
    else
        v8 = (void *)v7[3];
    sub_730290(v20, "username", v8);
    if (v7[36] < 0x10u)
        v9 = v7 + 31;
    else
        v9 = (void *)v7[31];
    sub_730290(v20, "digest", v9);
    v10 = Ogre::StringConverter::toString(v19, v7[14], 0, 32, 0);
    LOBYTE(v22) = 1;
    if (*(_DWORD *)(v10 + 24) < 0x10u)
        v11 = (void *)(v10 + 4);
    else
        v11 = *(void **)(v10 + 4);
    sub_730290(v20, "sid", v11);
    LOBYTE(v22) = 0;
    std::string::~string(v19);
    if (v7[45] < 0x10u)
        v12 = v7 + 40;
    else
        v12 = (void *)v7[40];
    sub_730290(v20, "rid", v12);
    if (v7[29] < 0x10u)
        v13 = v7 + 24;
    else
        v13 = (void *)v7[24];
    sub_730290(v20, "squad_tag", v13);
    v14 = Ogre::StringConverter::toString(v19, v7 + 9);
    LOBYTE(v22) = 2;
    if (*(_DWORD *)(v14 + 24) < 0x10u)
        v15 = (void *)(v14 + 4);
    else
        v15 = *(void **)(v14 + 4);
    sub_730290(v20, "color", v15);
    LOBYTE(v22) = 0;
    std::string::~string(v19);
    sub_731510(v21, "stats");
    v18 = *(_DWORD *)(a3 + 28);
    v16 = (int **)(this[1] + 4896);
    LOBYTE(v22) = 3;
    v17 = sub_770E20(v16, v18);
    sub_720560(v17, v21);
    sub_730060(v20, v21);
    sub_730060(a2, v20);
    LOBYTE(v22) = 0;
    sub_7316A0(v21);
    v22 = -1;
    sub_7316A0(v20);
}