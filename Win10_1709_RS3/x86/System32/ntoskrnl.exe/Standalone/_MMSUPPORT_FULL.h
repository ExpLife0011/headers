typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _MMSUPPORT_FLAGS
{
  union
  {
    struct
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned char WorkingSetType : 3; /* bit position: 0 */
        /* 0x0000 */ unsigned char Reserved0 : 3; /* bit position: 3 */
        /* 0x0000 */ unsigned char MaximumWorkingSetHard : 1; /* bit position: 6 */
        /* 0x0000 */ unsigned char MinimumWorkingSetHard : 1; /* bit position: 7 */
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0001 */ unsigned char SessionMaster : 1; /* bit position: 0 */
        /* 0x0001 */ unsigned char TrimmerState : 2; /* bit position: 1 */
        /* 0x0001 */ unsigned char Reserved : 1; /* bit position: 3 */
        /* 0x0001 */ unsigned char PageStealers : 4; /* bit position: 4 */
      }; /* bitfield */
    }; /* size: 0x0002 */
    /* 0x0000 */ unsigned short u1;
  }; /* size: 0x0002 */
  /* 0x0002 */ unsigned char MemoryPriority;
  union
  {
    struct /* bitfield */
    {
      /* 0x0003 */ unsigned char WsleDeleted : 1; /* bit position: 0 */
      /* 0x0003 */ unsigned char SvmEnabled : 1; /* bit position: 1 */
      /* 0x0003 */ unsigned char ForceAge : 1; /* bit position: 2 */
      /* 0x0003 */ unsigned char ForceTrim : 1; /* bit position: 3 */
      /* 0x0003 */ unsigned char NewMaximum : 1; /* bit position: 4 */
      /* 0x0003 */ unsigned char CommitReleaseState : 2; /* bit position: 5 */
    }; /* bitfield */
    /* 0x0003 */ unsigned char u2;
  }; /* size: 0x0001 */
} MMSUPPORT_FLAGS, *PMMSUPPORT_FLAGS; /* size: 0x0004 */

typedef struct _MMSUPPORT_INSTANCE
{
  /* 0x0000 */ unsigned short NextPageColor;
  /* 0x0002 */ unsigned short LastTrimStamp;
  /* 0x0004 */ unsigned long PageFaultCount;
  /* 0x0008 */ unsigned long TrimmedPageCount;
  /* 0x000c */ struct _MMWSL_INSTANCE* VmWorkingSetList;
  /* 0x0010 */ struct _LIST_ENTRY WorkingSetExpansionLinks;
  /* 0x0018 */ unsigned long AgeDistribution[8];
  /* 0x0038 */ struct _KGATE* ExitOutswapGate;
  /* 0x003c */ unsigned long MinimumWorkingSetSize;
  /* 0x0040 */ unsigned long WorkingSetLeafSize;
  /* 0x0044 */ unsigned long WorkingSetLeafPrivateSize;
  /* 0x0048 */ unsigned long WorkingSetSize;
  /* 0x004c */ unsigned long WorkingSetPrivateSize;
  /* 0x0050 */ unsigned long MaximumWorkingSetSize;
  /* 0x0054 */ unsigned long PeakWorkingSetSize;
  /* 0x0058 */ unsigned long HardFaultCount;
  union // _TAG_UNNAMED_13
  {
    /* 0x005c */ void* InstancedWorkingSet;
  } /* size: 0x0004 */ u1;
  /* 0x0060 */ unsigned long Reserved0;
  /* 0x0064 */ struct _MMSUPPORT_FLAGS Flags;
} MMSUPPORT_INSTANCE, *PMMSUPPORT_INSTANCE; /* size: 0x0068 */

typedef struct _MMSUPPORT_SHARED
{
  /* 0x0000 */ volatile long WorkingSetLock;
  /* 0x0004 */ unsigned long ReleasedCommitDebt;
  /* 0x0008 */ unsigned long ResetPagesRepurposedCount;
  /* 0x000c */ void* WsSwapSupport;
  /* 0x0010 */ void* CommitReleaseContext;
  /* 0x0014 */ void* AccessLog;
  /* 0x0018 */ volatile unsigned long ChargedWslePages;
  /* 0x001c */ unsigned long ActualWslePages;
  /* 0x0020 */ long GoodCitizenWaiting;
} MMSUPPORT_SHARED, *PMMSUPPORT_SHARED; /* size: 0x0024 */

typedef struct _MMSUPPORT_FULL
{
  /* 0x0000 */ struct _MMSUPPORT_INSTANCE Instance;
  /* 0x0068 */ struct _MMSUPPORT_SHARED Shared;
} MMSUPPORT_FULL, *PMMSUPPORT_FULL; /* size: 0x008c */

