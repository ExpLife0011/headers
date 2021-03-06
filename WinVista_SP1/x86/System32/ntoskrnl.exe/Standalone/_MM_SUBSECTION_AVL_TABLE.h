typedef struct _MMSUBSECTION_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned short SubsectionAccessed : 1; /* bit position: 0 */
    /* 0x0000 */ unsigned short Protection : 5; /* bit position: 1 */
    /* 0x0000 */ unsigned short StartingSector4132 : 10; /* bit position: 6 */
  }; /* bitfield */
  struct /* bitfield */
  {
    /* 0x0002 */ unsigned short SubsectionStatic : 1; /* bit position: 0 */
    /* 0x0002 */ unsigned short GlobalMemory : 1; /* bit position: 1 */
    /* 0x0002 */ unsigned short DirtyPages : 1; /* bit position: 2 */
    /* 0x0002 */ unsigned short Spare : 1; /* bit position: 3 */
    /* 0x0002 */ unsigned short SectorEndOffset : 12; /* bit position: 4 */
  }; /* bitfield */
} MMSUBSECTION_FLAGS, *PMMSUBSECTION_FLAGS; /* size: 0x0004 */

typedef struct _MMSUBSECTION_NODE
{
  union // _TAG_UNNAMED_153
  {
    union
    {
      /* 0x0000 */ unsigned long LongFlags;
      /* 0x0000 */ struct _MMSUBSECTION_FLAGS SubsectionFlags;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u;
  /* 0x0004 */ unsigned long StartingSector;
  /* 0x0008 */ unsigned long NumberOfFullSectors;
  union // _TAG_UNNAMED_154
  {
    union
    {
      /* 0x000c */ long Balance : 2; /* bit position: 0 */
      /* 0x000c */ struct _MMSUBSECTION_NODE* Parent;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u1;
  /* 0x0010 */ struct _MMSUBSECTION_NODE* LeftChild;
  /* 0x0014 */ struct _MMSUBSECTION_NODE* RightChild;
} MMSUBSECTION_NODE, *PMMSUBSECTION_NODE; /* size: 0x0018 */

typedef struct _MM_SUBSECTION_AVL_TABLE
{
  /* 0x0000 */ struct _MMSUBSECTION_NODE BalancedRoot;
  struct /* bitfield */
  {
    /* 0x0018 */ unsigned long DepthOfTree : 5; /* bit position: 0 */
    /* 0x0018 */ unsigned long Unused : 3; /* bit position: 5 */
    /* 0x0018 */ unsigned long NumberGenericTableElements : 24; /* bit position: 8 */
  }; /* bitfield */
  /* 0x001c */ void* NodeHint;
} MM_SUBSECTION_AVL_TABLE, *PMM_SUBSECTION_AVL_TABLE; /* size: 0x0020 */

