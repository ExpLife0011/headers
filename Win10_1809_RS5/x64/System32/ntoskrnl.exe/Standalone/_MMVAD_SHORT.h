typedef struct _RTL_BALANCED_NODE
{
  union
  {
    /* 0x0000 */ struct _RTL_BALANCED_NODE* Children[2];
    struct
    {
      /* 0x0000 */ struct _RTL_BALANCED_NODE* Left;
      /* 0x0008 */ struct _RTL_BALANCED_NODE* Right;
    }; /* size: 0x0010 */
  }; /* size: 0x0010 */
  union
  {
    /* 0x0010 */ unsigned char Red : 1; /* bit position: 0 */
    /* 0x0010 */ unsigned char Balance : 2; /* bit position: 0 */
    /* 0x0010 */ unsigned __int64 ParentValue;
  }; /* size: 0x0008 */
} RTL_BALANCED_NODE, *PRTL_BALANCED_NODE; /* size: 0x0018 */

typedef struct _EX_PUSH_LOCK
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned __int64 Locked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned __int64 Waiting : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned __int64 Waking : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned __int64 MultipleShared : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned __int64 Shared : 60; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned __int64 Value;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0008 */
} EX_PUSH_LOCK, *PEX_PUSH_LOCK; /* size: 0x0008 */

typedef struct _MMVAD_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned long VadType : 3; /* bit position: 0 */
    /* 0x0000 */ unsigned long Protection : 5; /* bit position: 3 */
    /* 0x0000 */ unsigned long PreferredNode : 6; /* bit position: 8 */
    /* 0x0000 */ unsigned long PrivateMemory : 1; /* bit position: 14 */
    /* 0x0000 */ unsigned long PrivateFixup : 1; /* bit position: 15 */
    /* 0x0000 */ unsigned long Graphics : 1; /* bit position: 16 */
    /* 0x0000 */ unsigned long Enclave : 1; /* bit position: 17 */
    /* 0x0000 */ unsigned long PageSize64K : 1; /* bit position: 18 */
    /* 0x0000 */ unsigned long ShadowStack : 1; /* bit position: 19 */
    /* 0x0000 */ unsigned long Spare : 6; /* bit position: 20 */
    /* 0x0000 */ unsigned long HotPatchAllowed : 1; /* bit position: 26 */
    /* 0x0000 */ unsigned long NoChange : 1; /* bit position: 27 */
    /* 0x0000 */ unsigned long ManySubsections : 1; /* bit position: 28 */
    /* 0x0000 */ unsigned long DeleteInProgress : 1; /* bit position: 29 */
    /* 0x0000 */ unsigned long LockContended : 1; /* bit position: 30 */
    /* 0x0000 */ unsigned long Lock : 1; /* bit position: 31 */
  }; /* bitfield */
} MMVAD_FLAGS, *PMMVAD_FLAGS; /* size: 0x0004 */

typedef struct _MMVAD_FLAGS1
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned long CommitCharge : 31; /* bit position: 0 */
    /* 0x0000 */ unsigned long MemCommit : 1; /* bit position: 31 */
  }; /* bitfield */
} MMVAD_FLAGS1, *PMMVAD_FLAGS1; /* size: 0x0004 */

typedef struct _MMVAD_SHORT
{
  union
  {
    struct
    {
      /* 0x0000 */ struct _MMVAD_SHORT* NextVad;
      /* 0x0008 */ void* ExtraCreateInfo;
    }; /* size: 0x0010 */
    /* 0x0000 */ struct _RTL_BALANCED_NODE VadNode;
  }; /* size: 0x0018 */
  /* 0x0018 */ unsigned long StartingVpn;
  /* 0x001c */ unsigned long EndingVpn;
  /* 0x0020 */ unsigned char StartingVpnHigh;
  /* 0x0021 */ unsigned char EndingVpnHigh;
  /* 0x0022 */ unsigned char CommitChargeHigh;
  /* 0x0023 */ unsigned char SpareNT64VadUChar;
  /* 0x0024 */ long ReferenceCount;
  /* 0x0028 */ struct _EX_PUSH_LOCK PushLock;
  union // _TAG_UNNAMED_124
  {
    union
    {
      /* 0x0030 */ unsigned long LongFlags;
      /* 0x0030 */ struct _MMVAD_FLAGS VadFlags;
      /* 0x0030 */ volatile unsigned long VolatileVadLong;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u;
  union // _TAG_UNNAMED_125
  {
    union
    {
      /* 0x0034 */ unsigned long LongFlags1;
      /* 0x0034 */ struct _MMVAD_FLAGS1 VadFlags1;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u1;
  /* 0x0038 */ struct _MI_VAD_EVENT_BLOCK* EventList;
} MMVAD_SHORT, *PMMVAD_SHORT; /* size: 0x0040 */

