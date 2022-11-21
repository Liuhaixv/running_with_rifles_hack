if (*(float *)&v117 != 0.0 && !HIBYTE(v116) && !sub_7545E0((_BYTE **)v117) && !sub_754180(v117))
{
    v12 = (**((int(__thiscall ***)(char *, char *, int *))v117 + 2))((char *)v117 + 8, v137, v134);
    Ogre::Vector3::operator-(v12);
    v13 = (*(int(__thiscall **)(Concurrency::details::SchedulerProxy *, char *, int *))(*(_DWORD *)v117 + 32))(
        v117,
        v136,
        v135);
    Ogre::Vector3::operator-(v13);
    v119 = 1.0;
    NumBorrowedCores = Concurrency::details::SchedulerProxy::GetNumBorrowedCores(v117);
    v126 = *sub_70CCE0(&v119, (float *)(NumBorrowedCores + 320));
    v119 = *((float *)this + 82) * v126;
    v123 = Ogre::Vector3::length((Ogre::Vector3 *)v137);
    v130 = Ogre::Vector3::length((Ogre::Vector3 *)v136);
    v118 = *sub_70CCE0(&v123, &v130);
    if (v119 < (double)v118)
    {
        v15 = *((_DWORD *)this + 2);
        v16 = sub_753CE0(v117);
        v17 = sub_7AB930(v15, v16);
        v126 = v118 / v126;
        sub_7558C0((float *)v117, v126);
        std::ostringstream::ostringstream(v133, 2, 1);
        v145 = 0;
        v18 = sub_7558E0((float *)v117);
        v19 = *(_DWORD *)(v17 + 56);
        v114 = v20;
        v21 = *(_DWORD *)(v17 + 60);
        v114 = v18;
        v112 = v21;
        v111 = v19;
        v107 = v119;
        v106 = v118;
        v22 = sub_704240((int)v133, "antihack: diff=");
        v23 = std::ostream::operator<<(v22, LODWORD(v106));
        v24 = sub_704240(v23, ", speed * add score threshold=");
        v25 = std::ostream::operator<<(v24, LODWORD(v107));
        v26 = sub_704240(v25, ", username=");
        v27 = std::operator<< <char>(v26, v17 + 8);
        v28 = sub_704240(v27, ", sid=");
        v29 = std::ostream::operator<<(v28, v111, v112);
        v30 = sub_704240(v29, ", score now=");
        std::ostream::operator<<(v30, LODWORD(v114));
        std::string::string(v143, &unk_B6E6C3);
        LOBYTE(v145) = 1;
        v31 = std::ostringstream::str(v133, v122);
        LOBYTE(v145) = 2;
        log((int)v143, v31);
        LOBYTE(v145) = 1;
        std::string::~string(v122);
        LOBYTE(v145) = 0;
        std::string::~string(v143);
        v145 = -1;
        std::ostringstream::`vbase destructor'(v133);  v119 = *((float *)this + 83);
        v32 = sub_7558E0((float *)v117);
        if (v119 < v32)
        {
            std::ostringstream::ostringstream(v133, 2, 1);
            v33 = *(_DWORD *)(v17 + 56);
            v114 = *(float *)(v17 + 60);
            v113 = v33;
            v109 = v119;
            v145 = 3;
            v34 = sub_704240((int)v133, "antihack: score over threshold ");
            v35 = std::ostream::operator<<(v34, LODWORD(v109));
            v36 = sub_704240(v35, ", kicking now, username=");
            v37 = std::operator<< <char>(v36, v17 + 8);
            v38 = sub_704240(v37, ", sid=");
            std::ostream::operator<<(v38, v113, LODWORD(v114));
            std::string::string(v143, &unk_B6E6C3);
            LOBYTE(v145) = 4;
            v39 = std::ostringstream::str(v133, v122);
            LOBYTE(v145) = 5;
            log((int)v143, v39);
            LOBYTE(v145) = 4;
            std::string::~string(v122);
            LOBYTE(v145) = 3;
            std::string::~string(v143);
            v145 = -1;
            std::ostringstream::`vbase destructor'(v133); v40 = (void(__thiscall **)(void *, int, int))(*(_DWORD *)this + 56); v41 = sub_753CE0(v117); (*v40)(this, v41, v115); HIBYTE(v116) = 1;
        }
    }
}